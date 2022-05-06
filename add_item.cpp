#include <bits/stdc++.h>
using namespace std;
int item_choice;
char set_name[50];
int set_price;

void print_line(int count)
{
    for (int i = 1; i <= count; i++)
    {
        cout << "_";
    }
}
class items
{
    // protected:
public:
    int id;
    char food_name[50];
    char food_type[50];
    int food_price;

    void get_item();
    void show_item() const;
    int return_id() const;
    void set_f_name();
    void set_f_price();
    void bucket();
};

void items::get_item()
{
    // system("cls");
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Food ID :  ";
    cin >> id;
    cin.ignore();
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Food Name :  ";
    cin.getline(food_name, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter Food Type :  ";
    cin.getline(food_type, 50);
    cout << "\n\n";
    tab_print(3);
    cout << "Enter food price :  ";
    cin >> food_price;
}

void items::show_item() const
{
    cout << "\n\n";
    tab_print(3);
    cout << "Food ID:    \t" << id;
    cout << "\n";
    tab_print(3);
    cout << "Food name:  \t" << food_name;
    cout << "\n";
    tab_print(3);
    cout << "Food Type:  \t" << food_type;
    cout << "\n";
    tab_print(3);
    cout << "Food Price: \t" << food_price;
    cout << "\n";
    tab_print(2);
    print_line(50);
}

int items::return_id() const
{
    return id;
}
void items::set_f_name()
{
    strcpy(set_name, food_name);
}
void items::set_f_price()
{
    set_price = food_price;
    // strcpy(set_price, food_price);
}
void items::bucket()
{
    cout << "\n";
    tab_print(12);
    print_line(30);
    cout << "\n";
    tab_print(12);
    cout << food_name << "\t\t" << food_price;
}

void add_food_item()
{
    system("cls");
    system("color 8F");
    cout << "\n\n\t\t";
    four_print(110);
    cout << "\n\n";
    tab_print(8);
    cout << "ADD NEW FOOD ITEM";
    cout << "\n\n\t\t";
    four_print(110);
    items item;
    ofstream oFile;
    oFile.open("food_menu_list.dat", ios::binary | ios::app);
    item.get_item();
    oFile.write(reinterpret_cast<char *>(&item), sizeof(items));
    oFile.close();
    cout << "\n\n";
    tab_print(3);
    cout << "New food item added successfully...";
}

void Display_food_menu()
{
    system("cls");
    system("color 60");
    cout << "\n\n\t\t";
    four_print(110);
    cout << "\n\n";
    tab_print(8);
    cout << "FOOD MENU LIST";
    cout << "\n\n\t\t";
    four_print(110);
    items item;
    ifstream inFile;
    inFile.open("food_menu_list.dat", ios::binary);
    if (!inFile)
    {
        cout << "File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get();
    }
    while (inFile.read(reinterpret_cast<char *>(&item), sizeof(items)))
    {
        item.show_item();
    }
    inFile.close();
}

void search_food_item(int id)
{
    system("color BD");
    system("cls");
    cout << "\n\n\t\t";
    four_print(110);
    cout << "\n\n";
    tab_print(8);
    cout << "SEARCHED FOOD ITEM";
    cout << "\n\n\t\t";
    four_print(110);
    items item;
    ifstream iFile;
    iFile.open("food_menu_list.dat", ios::binary);
    if (!iFile)
    {
        cout << "File could not be opened... Press any Key to exit";
        cin.ignore();
        cin.get();
    }
    bool flag = false;
    while (iFile.read(reinterpret_cast<char *>(&item), sizeof(items)))
    {
        if (item.return_id() == id)
        {
            item.show_item();
            flag = true;
        }
    }
    iFile.close();
    if (flag == false)
        cout << "\n\nrecord does not exist";
}
void search_food_item_bucket(int id)
{
    items item;
    ifstream iFile;
    iFile.open("food_menu_list.dat", ios::binary);
    if (!iFile)
    {
        cout << "File could not be opened... Press any Key to exit";
        cin.ignore();
        cin.get();
    }
    bool flag = false;
    while (iFile.read(reinterpret_cast<char *>(&item), sizeof(items)))
    {
        if (item.return_id() == id)
        {
            item.bucket();
            item.set_f_name();
            item.set_f_price();
            flag = true;
        }
    }
    iFile.close();
    if (flag == false)
        cout << "\n\nrecord does not exist";
}

void add_food_item_homepage()
{
    int search_id;
    system("cls");
    system("color F0");
    cout << "\n\n\t\t";
    four_print(110);
    cout << "\n\n";
    tab_print(8);
    cout << "FOOD ITEM HOMEPAGE";
    cout << "\n\n\t\t";
    four_print(110);
    cout << "\n\n";
    tab_print(2);
    cout << " 1. Add new food item";
    tab_print(2);
    cout << " 2. display food menu";
    tab_print(2);
    cout << " 3. search food menu";
    tab_print(2);
    cout << " 4. Exit";
    cout << "\n\n";
    tab_print(2);
    cout << "Please enter your choice :";
    cin >> item_choice;
    switch (item_choice)
    {
    case 1:
        add_food_item();
        break;
    case 2:
        Display_food_menu();
        break;
    case 3:
        cout << "\n\n";
        tab_print(3);
        cout << "Enter Food ID to search:  ";
        cin >> search_id;
        search_food_item(search_id);
        break;
    case 4:
        system("cls");
        system("color F0");
        page_heading("Thanks you for using our software");
        cin.get();
        break;

    default:
        cout << "\n\n";
        tab_print(3);
        cout << "Please enter valid choice...";
        break;
    }
    cin.ignore();
    cin.get();
}

// do
// {
//     add_food_item_homepage();

// } while (item_choice != 4);
