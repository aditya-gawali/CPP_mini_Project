#include <bits/stdc++.h>
using namespace std;

class history
{
    char order_Id[10];
    char cost_name[50];
    char cost_email[50];
    char mobile_no[20];
    char cost_address[50];
    char bucket_item_name[50];
    int bucket_item_price;

public:
    void show_history();
    void admin_history();
    void user_history();
};

void history::show_history()
{
    cout << "\n\n";
    tab_print(3);
    cout << "Order ID:    \t" << order_Id;
    cout << "\n";
    tab_print(3);
    cout << "Costomer Name:  " << cost_name;
    cout << "\n";
    tab_print(3);
    cout << "Costomer Email: " << cost_email;
    cout << "\n";
    tab_print(3);
    cout << "Costomer Mob:   " << mobile_no;
    cout << "\n";
    tab_print(3);
    cout << "Item Selected: \t" << bucket_item_name;
    cout << "\n";
    tab_print(3);
    cout << "Item Price: \t" << bucket_item_price;
    cout << "\n";
    tab_print(2);
    print_line(50);
}

void history::admin_history()
{
    history h1;
    ifstream inFile;
    inFile.open("place_order.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get();
    }
    while (inFile.read(reinterpret_cast<char *>(&h1), sizeof(history)))
    {
        h1.show_history();
    }
    inFile.close();
}
void history_page()
{
    system("cls");
    system("color F0");
    page_heading(" Order History");
    history h2;
    h2.admin_history();
    cin.get();
    cin.ignore();
};