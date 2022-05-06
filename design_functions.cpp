#include <bits/stdc++.h>
using namespace std;

void four_print(int count)
{
    for (int i = 1; i <= count; i++)
    {
        cout << "\4";
    }
}

void tab_print(int count)
{
    for (int i = 1; i <= count; i++)
    {
        cout << "\t";
    }
}

void page_heading(string name)
{
    cout << "\n\n\t\t";
    four_print(110);
    cout << "\n\n";
    tab_print(8);
    cout << name;
    cout << "\n\n\t\t";
    four_print(110);
    cout << "\n\n";
}
void page_heading(string name, char strname[50])
{
    cout << "\n\n\t\t";
    four_print(110);
    cout << "\n\n";
    tab_print(8);
    cout << name;
    cout<<" ";
    cout << strname;
    cout << "\n\n\t\t";
    four_print(110);
    cout << "\n\n";
}
