#include <bits/stdc++.h>
using namespace std;
int reg_choice;
class r1
{
    char name[50];
    char email[50];
    char password[50];

public:
    void admin_getdata();
    void user_getdata();
};

void r1::admin_getdata()
{
    // system("cls");
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Admin name :  ";
    // getline(cin, name);
    cin.getline(name, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Email :  ";
    cin.getline(email, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter password :  ";
    cin.getline(password, 50);
}

void r1::user_getdata()
{
    cout << "\n\n";
    tab_print(3);
    cout << "Enter User name :  ";
    cin.getline(name, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Email :  ";
    cin.getline(email, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter password :  ";
    cin.getline(password, 50);
}

void register_option();
void admin_register();
void user_register();
void register_main();

int Register()
{
    int register_success = 1;
    register_main();
    return register_success;
}

void register_options()
{
    cout << "\n\n";
    tab_print(5);
    cout << " 1. Admin register";
    tab_print(4);
    cout << " 2. User register";
    cout << "\n\n";
    tab_print(3);
    cout << "Please enter your choice :";
    cin >> reg_choice;
    cin.ignore();
    switch (reg_choice)
    {
    case 1:
        admin_register();
        break;
    case 2:
        user_register();
        break;

    default:
        cout << "\n\n";
        tab_print(3);
        cout << "Please enter valid choice....";
        cin.ignore();
        cin.get();
        register_main();
        break;
    }
}
void admin_register()
{
    system("cls");
    system("color F0");
    page_heading("Admin register");
    r1 admin;
    ofstream oFile;
    oFile.open("admin_registration.dat", ios::binary | ios::app);
    admin.admin_getdata();
    oFile.write(reinterpret_cast<char *>(&admin), sizeof(r1));
    oFile.close();
    cout << "\n\n";
    tab_print(3);
    cout << "admin registeration successful...";
    cin.ignore();
    cin.get();
}
void user_register()
{
    system("cls");
    system("color F0");
    page_heading("User register");
    r1 user;
    ofstream oFile;
    oFile.open("user_registration.dat", ios::binary | ios::app);
    user.user_getdata();
    oFile.write(reinterpret_cast<char *>(&user), sizeof(r1));
    oFile.close();
    cout << "\n\n";
    tab_print(3);
    cout << "User registeration successful...";
    cin.ignore();
    cin.get();
}

void register_main()
{
    system("cls");
    system("color F0");
    page_heading("register Option");
    register_options();
}
