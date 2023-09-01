#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<int> first;
    vector<int> second(4, 20);

    auto it = second.begin();
    for (int i = 0; i < second.size(); i++)
    {
        cout << *it << " "
             << " ";
        ++it;
    }
    cout << endl;

    // another method of defining the vector
    int numbers[] = {10, 20, 30, 40, 50};
    vector<int> third(numbers, numbers + 5); // this way it an be defined using the other classical array also
    auto third_it = third.begin();
    for (int i = 0; i < third.size(); i++)
    {
        /* code */
        cout << *third_it << " ";
        ++third_it;
    }
    vector<int> fourth(third); // using the copy constructor
    cout << endl;
    cout << "The size of the second vector is " << second.size() << endl;
    cout << "the capacity of the first vector is " << first.capacity() << endl;
    cout << "the capacity of the second vector is " << second.capacity() << endl;//if the capacity is reached it doubles the capacity - this is the expensive process 
    cout << "the max_size of the second vector is " << second.max_size() << endl;

    return 0;
}