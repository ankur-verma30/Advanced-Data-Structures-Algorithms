#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{

    unordered_map<string, int> menu;
//first method of inserting data inside the unordered_map
    unordered_map<string, int>m;
    pair<string,int> p=make_pair("Ankur",30);
    m.insert(p);

    cout<<"the number assignd to annkur is "<<m["Ankur"]<<endl;

    //second method of inserting data inside the unordered_map
    pair<string,int> pair2("Verma",8);
    m.insert(pair2);
    cout<<"the key of pair2 is "<<pair2.first<<" the value of the pair2 is "<<pair2.second<<endl;//In pair we use first and second keywords for the key value pair

    //third method of inserting a key value pair in the map
    menu["maggie"] = 20;
    menu["colddrink"] = 40;
    menu["dosa"] = 100;

    cout<<"the using of the predefined functions "<<endl;
    cout<<"the value of "<<menu.at("colddrink")<<endl;//for searching some value in the map
    //if we try to search any key value pair which does not exist then
    // cout<< menu.at("ankur")<<endl;
    /*
    terminate called after throwing an instance of 'std::out_of_range'
  what():  unordered_map::at   **this is the compiler error we will get**
    */
   cout<<"Accessing the unknown value using subscript operator = "<<menu["ankur"]<<endl;//this gives 0 while using at it will error because it create a unknown entry in the map with value 0 while menu.at will search for the value and does not make any new entry in the map
   //and now if we use at function after this it will not show error as the entry has been created
   cout<<"Accessing the unknown value using at function after the use of subscript operator = "<<menu.at("ankur")<<endl;

    string item;
    cout << "Enter the item you want to search ";
    cin >> item;
    if (menu.count(item)) // for checking the key or searching  the key
        cout << item << " is available " << endl;
    else
        cout << item << " is not available " << endl;

    // for getting the value of the certain item is
    cout << "The value of the maggie is " << menu["maggie"] << endl; // this gives the value

    //for updating any value inside the hashtable
    menu["dosa"]=(1+0.1)*menu["dosa"]; 
    cout<<"The updated value of the dosa is " << menu["dosa"] << endl;//shows the updated value

    return 0;
}