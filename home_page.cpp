#include <bits/stdc++.h>
#include "design_functions.cpp"
#include "add_item.cpp"
#include "place_oreder.cpp"
#include "order_history.cpp"
#include "welcome_page.cpp"
#include "login_page.cpp"
using namespace std;

void home_page_main();
void home_page_menu();

int home_choice;
void home_page_menu()
{
    cout << "\n\n";
    tab_print(3);
    cout << " 1. Show menu Card";
    tab_print(3);
    cout << " 2. Login/Register";
    tab_print(3);
    cout << " 3. Exit";
    cout << "\n\n";
    tab_print(3);
    cout << "Please enter your choice :";
    cin >> home_choice;
    cin.ignore();

    switch (home_choice)
    {
    case 1:
        Display_food_menu();
        cin.get();
        home_page_main();
        break;
    case 2:
        login_page_main();
        break;
    case 3:
        system("cls");
        system("color F0");
        page_heading("Thanks you for using our software");
        cin.get();
        break;

    default:
        cout << "\n\n";
        tab_print(3);
        cout << "please enter valid choice...";
        home_page_main();
        break;
    }
}
void home_page_main()
{
    system("cls");
    system("color F0");
    page_heading("Welcome to food ordering system");
    home_page_menu();
}