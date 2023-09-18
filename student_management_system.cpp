#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
using namespace std;

class Student
{
private:
    string name, usn, branch, contact_no;
    int age;

public:
    void menu();
    void insert();
    void modify();
    void deleting();
    void search();
    void display();
};

void Student::display()
{

    fstream file;
    system("cls");

    file.open("student.txt", ios::in);

    if (!file)
    {
        cout << "File cannot Open\n";
        exit(0);
    }

    file >> name >> usn >> age >> branch >> contact_no;
    while (!file.eof())
    {
        cout << "Student Name:" << name << endl;
        cout << "Student Usn:" << usn << endl;
        cout << "Student Age:" << age << endl;
        cout << "Student Branch:" << branch << endl;
        cout << "Student Contact_No:" << contact_no << endl;
        cout << endl;
        cout << endl;
        file >> name >> usn >> age >> branch >> contact_no;
    }
    file.close();
}

void Student::modify()
{
    system("cls");
    string roll;
    fstream file, file1;
    int flag = 0;

    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "File cannot open\n";
        exit(0);
    }
    else
    {
        file1.open("student2.txt", ios::app | ios::out);
        if (!file1)
        {
            cout << "File cannot open\n";
            exit(0);
        }

        cout << "Enter usn of student you want to modify:\n";
        cin >> roll;

        // Read the first record before entering the loop
        file >> name >> usn >> age >> branch >> contact_no;

        while (!file.eof())
        {
            if (roll != usn)
            {
                file1 << name << "   " << usn << "   " << age << "   " << branch << "    " << contact_no << "\n";
            }
            else
            {
                flag = 1;
                cout << "Student Name:" << endl;
                cin >> name;
                cout << "Student Usn:" << endl;
                cin >> usn;
                cout << "Student Age:" << endl;
                cin >> age;
                cout << "Student Branch:" << endl;
                cin >> branch;
                cout << "Student Contact_No:" << endl;
                cin >> contact_no;
                file1 << name << "   " << usn << "   " << age << "   " << branch << "    " << contact_no << "\n";
            }

            // Read the next record at the end of the loop
            file >> name >> usn >> age >> branch >> contact_no;
        }

        if (flag == 1)
        {
            cout << "\n\nRECORD MODIFIED SUCCESSFULLY\n";
        }

        if (flag == 0)
        {
            cout << "\n\nNO SUCH RECORD TO MODIFY\n";
        }
        file1.close();
        file.close();
        remove("student.txt");
        rename("student2.txt", "student.txt");
    }
}

void Student::deleting()
{
    system("cls");
    string roll;
    fstream file, file1;

    file.open("student.txt", ios::in);
    if (!file)
    {
        cout << "Cannot open file\n";
        exit(0);
    }
    else
    {
        file1.open("student2.txt", ios::app | ios::out);
        if (!file1)
        {
            cout << "Cannot open file\n";
            exit(0);
        }

        cout << "Enter usn of student you want to delete:\n";
        cin >> roll;

        // Read the first record before entering the loop
        file >> name >> usn >> age >> branch >> contact_no;

        bool deleted = false; // Flag to indicate whether the record should be deleted

        while (!file.eof())
        {
            if (roll != usn)
            {
                file1 << name << "   " << usn << "   " << age << "   " << branch << "    " << contact_no << "\n";
            }
            else
            {
                deleted = true; // Set the flag to indicate record deletion
            }
            file >> name >> usn >> age >> branch >> contact_no;
        }

        file1.close();
        file.close();
        remove("student.txt");
        rename("student2.txt", "student.txt");

        if (!deleted)
        {
            cout << "\n\nStudent with USN " << roll << " not found in the records." << endl;
        }
        else
        {
            cout << "\n\nStudent with USN " << roll << " has been deleted." << endl;
        }
    }
}

void Student::search()
{
    system("cls");

    int flag = 0;
    string roll_no;
    fstream file;
    file.open("student.txt", ios::in);

    if (!file)
    {
        cout << "Cannot open file" << endl;
        exit(0);
    }
    else
    {
        cout << "Enter usn you want to search:\n";
        cin >> roll_no;

        file >> name >> usn >> age >> branch >> contact_no;
        while (!file.eof())
        {
            if (roll_no == usn)
            {
                flag = 1;
                cout << "RECORD FOUND\n";
                cout << "Student Name:" << name << endl;
                cout << "Student Usn:" << usn << endl;
                cout << "Student Age:" << age << endl;
                cout << "Student Branch:" << branch << endl;
                cout << "Student Contact_No:" << contact_no << endl;
                break;
            }
            else
            {
                file >> name >> usn >> age >> branch >> contact_no;
            }
        }
        if (flag == 0)
        {
            cout << "\n\nRECORD NOT FOUND!!!";
        }
    }
}

void Student::insert()
{
    fstream file;
    system("cls");
    cout << "Enter Student Name:" << endl;
    cin >> name;
    cout << "Enter Student Usn:" << endl;
    cin >> usn;
    cout << "Enter Student Age:" << endl;
    cin >> age;
    cout << "Enter Student Branch:" << endl;
    cin >> branch;
    cout << "Enter Student Contact No.:" << endl;
    cin >> contact_no;

    file.open("student.txt", ios::app | ios::out);

    if (!file)
    {
        cout << "Cannot open file" << endl;
        exit(0);
    }
    file << name << "   " << usn << "   " << age << "   " << branch << "    " << contact_no << "\n";
    cout << "\n\nRECORD INSERTED SUCCESSFULLY\n";
    file.close();
}

void Student ::menu()
{

    int choice;
    system("cls");

    cout << "\t\t\t\t**************************************" << endl;
    cout << "\t\t\t\t|     STUDENT MANAGEMENT SYSTEM      |" << endl;
    cout << "\t\t\t\t**************************************" << endl;
    cout << "\t\t\t\t1-> Enter new record" << endl;
    cout << "\t\t\t\t2-> Modify the record" << endl;
    cout << "\t\t\t\t3-> Display the record" << endl;
    cout << "\t\t\t\t4-> Search the record" << endl;
    cout << "\t\t\t\t5-> Delete the record" << endl;
    cout << "\t\t\t\t6-> Exit" << endl;

    cout << endl;
    cout << "\t\t\t\t**************************************" << endl;
    cout << "\t\t\t\t Choose one of the above options:" << endl;
    cout << "\t\t\t\t**************************************" << endl;

    cout << "\nEnter your option:";
    cin >> choice;

    char ch;
    switch (choice)
    {
    case 1:
        insert();
        cout << "\n\nPlease enter 'c' to continue...." << endl;
        cin >> ch;
        if (ch == 'c')
            break;
        else
            exit(0);

    case 2:
        modify();
        cout << "\n\nPlease enter 'c' to continue...." << endl;
        cin >> ch;
        if (ch == 'c')
            break;
        else
            exit(0);

    case 3:
        display();
        cout << "\n\nPlease enter 'c' to continue...." << endl;
        cin >> ch;
        if (ch == 'c')
            break;
        else
            exit(0);

    case 4:
        search();
        cout << "\n\nPlease enter 'c' to continue...." << endl;
        cin >> ch;
        if (ch == 'c')
            break;
        else
            exit(0);

    case 5:
        deleting();
        cout << "\n\nPlease enter 'c' to continue...." << endl;
        cin >> ch;
        if (ch == 'c')
            break;
        else
            exit(0);

    case 6:
        exit(0);

    default:
        cout << "Invalid Option" << endl;
        exit(0);
    }
}

int main()
{

    Student obj;
    while (true)
    {
        obj.menu();
    }
}