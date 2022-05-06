#include <bits/stdc++.h>
#include "payment.cpp"
using namespace std;
int s_id;

class placeorder
{
    char order_Id[10];
    char cost_name[50];
    char cost_email[50];
    char mobile_no[20];
    char cost_address[50];
    char bucket_item_name[50];
    int bucket_item_price;

public:
    void getdata();
    void show_bucket_item();
    void search_item_bucket();
    void s_t();
};

void placeorder::getdata()
{
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Order ID : ";
    cin.getline(order_Id, 10);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Customer Name : ";
    cin.getline(cost_name, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Customer Email : ";
    cin.getline(cost_email, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Customer Mobile Number : ";
    cin.getline(mobile_no, 20);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Customer Address : ";
    cin.getline(cost_address, 50);
    cout << "\n\n";
    tab_print(3);
}
void placeorder ::show_bucket_item()
{
    char ch;
    cout << "\n\n";
    tab_print(3);
    cout << "Showing menu card to select the Item using food Id : ";
    cin.get();
    cin.ignore();
    Display_food_menu();
    cin.get();
    cin.ignore();
    system("cls");
    system("color 8A");
    search_item_bucket();
    strcpy(bucket_item_name, set_name);
    bucket_item_price = set_price;

    cout << "\n\n";
    tab_print(3);
    cout << "Proceed for payment... ";
    cin.ignore();
    cin.get();
}

void placeorder ::search_item_bucket()
{
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Food ID to search:  ";
    cin >> s_id;
    s_t();
    search_food_item_bucket(s_id);
}
void placeorder::s_t()
{
    system("cls");
    system("color BD");
    cout << "\n\n\t\t";
    four_print(110);
    cout << "\n\n";
    tab_print(8);
    cout << "PLACE ORDER";
    cout << "\n\n\t\t";
    four_print(110);
    cout << "\n\n";
    tab_print(12);
    cout << "Bucket";
}

void place_order()
{
    system("cls");
    system("color F0");
    page_heading("Place Order");
    placeorder p1;
    ofstream oFile;
    oFile.open("place_order.dat", ios::binary | ios::app);
    p1.getdata();
    p1.show_bucket_item();
    payment_page();
    oFile.write(reinterpret_cast<char *>(&p1), sizeof(placeorder));
    oFile.close();
}