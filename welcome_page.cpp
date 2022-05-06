#include <bits/stdc++.h>

using namespace std;
string check_type;
char check_username[50];
void welcome(string acc_type, char username[50]);
void welcome_main();
void welcome_menu(string);

void welcome(string acc_type, char username[50])
{
    system("cls");
    system("color F0");
    check_type = acc_type;
    strcpy(check_username, username);
    page_heading("Welcome", username);
    welcome_menu(acc_type);
}
int wel_choice;
void welcome_menu(string type)
{
    if (type == "admin")
    {
        cout << "\n\n";
        tab_print(2);
        cout << " 1. Add Item";
        tab_print(2);
        cout << " 2. Place Order";
        tab_print(2);
        cout << " 3. Show Menu Card";
        tab_print(2);
        cout << " 4. Order History";
        tab_print(2);
        cout << " 5. Exit";
        cout << "\n\n";
        tab_print(3);
        cout << "Please enter your choice :";
        cin >> wel_choice;
        cin.ignore();

        switch (wel_choice)
        {
        case 1:
            add_food_item();
            welcome(check_type, check_username);
            break;
        case 2:
            place_order();
            welcome(check_type, check_username);
            break;
        case 3:
            Display_food_menu();
            welcome(check_type, check_username);
            break;
        case 4:
            history_page();
            welcome(check_type, check_username);
            break;
        case 5:
            system("cls");
            system("color F0");
            page_heading("Thanks you for using our software");
            cin.get();
            cin.ignore();
            break;

        default:
            cout << "\n\n";
            tab_print(3);
            cout << "please enter valid choice...";
            welcome(check_type, check_username);
            break;
        }
    }
    else if (type == "user")
    {
        cout << "\n\n";
        tab_print(2);
        cout << " 1. Place Order";
        tab_print(2);
        cout << " 2. Show Menu Card";
        tab_print(2);
        cout << " 3. Order History";
        tab_print(2);
        cout << " 4. Exit";
        cout << "\n\n";
        tab_print(3);
        cout << "Please enter your choice :";
        cin >> wel_choice;
        cin.ignore();

        switch (wel_choice)
        {
        case 1:
            place_order();
            welcome(check_type, check_username);
            break;
        case 2:
            Display_food_menu();
            cin.get();
            cin.ignore();
            welcome(check_type, check_username);
            break;
        case 3:
            history_page();
            welcome(check_type, check_username);
            break;
        case 4:
            system("cls");
            system("color F0");
            page_heading("Thanks you for using our software");
            cin.get();
            cin.ignore();
            break;

        default:
            cout << "\n\n";
            tab_print(3);
            cout << "please enter valid choice...";
            welcome(check_type, check_username);
            break;
        }
    }
}