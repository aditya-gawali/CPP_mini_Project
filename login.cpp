#include <bits/stdc++.h>
using namespace std;
char check_name[50];
char check_password[50];
char l_name[50];
char l_password[50];
void admin_check_getdata()
{
    // system("cls");
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Admin name :  ";
    cin.getline(check_name, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter password :  ";
    cin.getline(check_password, 50);
}

void user_check_getdata()
{
    // system("cls");
    cout << "\n\n";
    tab_print(3);
    cout << "Enter User name :  ";
    cin.getline(check_name, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter password :  ";
    cin.getline(check_password, 50);
}
int log_choice;
class l
{
    // string name;
    char name[50];
    char email[50];
    char password[50];
    // string password;

public:
    void admin_getdata();
    void user_getdata();
    void show_data();
    void set_name();
    void set_password();
};

void l::admin_getdata()
{
    // system("cls");
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Admin name :  ";
    cin.getline(name, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter password :  ";
    cin.getline(password, 50);
}

void l::user_getdata()
{
    // system("cls");
    cout << "\n\n";
    tab_print(3);
    cout << "Enter User name :  ";
    cin.getline(name, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter password :  ";
    cin.getline(password, 50);
}

void l::show_data()
{
    cout << "\n name : " << name;
    cout << "\n email : " << email;
    cout << "\n password : " << password;
}

void l ::set_name()
{
    strcpy(l_name, name);
}
void l ::set_password()
{
    strcpy(l_password, password);
}

void login_option();
void admin_login();
void user_login();
void login_main();
void login()
{

    login_main();
}

void login_options()
{
    cout << "\n\n";
    tab_print(5);
    cout << " 1. Admin Login";
    tab_print(4);
    cout << " 2. User Login";
    cout << "\n\n";
    tab_print(3);
    cout << "Please enter your choice :";
    cin >> log_choice;
    cin.ignore();
    switch (log_choice)
    {
    case 1:
        admin_login();
        break;
    case 2:
        user_login();
        break;

    default:
        cout << "\n\n";
        tab_print(3);
        cout << "Please enter valid choice....";
        cin.ignore();
        cin.get();
        login_main();
        break;
    }
}
void admin_login()
{
    system("cls");
    system("color F0");
    page_heading("Admin Login");
    admin_check_getdata();
    l admin;
    ifstream inFile;
    inFile.open("admin_registration.dat", ios::binary);
    if (!inFile)
    {

        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&admin), sizeof(l)))
    {
        admin.set_name();
        admin.set_password();

        if (strcmp(l_name, check_password) == 0 && strcmp(l_password, check_password) == 0)
        {
            cout << "\n\n Login successful ....";
            cin.get();
            welcome("admin", l_name);
            flag = true;
        }
    }
    if (flag != true)
    {
        cout << "Invalid credentials....";
        cin.get();
        login_main();
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void user_login()
{
    system("cls");
    system("color F0");
    page_heading("User Login");
    user_check_getdata();
    l user;
    ifstream inFile;
    inFile.open("user_registration.dat", ios::binary);
    if (!inFile)
    {
        cout << "\n\n File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag = false;
    while (inFile.read(reinterpret_cast<char *>(&user), sizeof(l)))
    {
        user.set_name();
        user.set_password();

        if (strcmp(l_name, check_password) == 0 && strcmp(l_password, check_password) == 0)
        {
            cout << "Login successful....";
            cin.get();
            welcome("user", l_name);
            flag = true;
            }
    }
    if (flag != true)
    {
        cout << "Invalid credentials....";
        cin.get();
        login_main();
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

void login_main()
{
    system("cls");
    system("color F0");
    page_heading("Login Option");
    login_options();
}
