#include <bits/stdc++.h>

using namespace std;

int denominations[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};

int MinimumNotesRequired(int money)
{
    int total = 0,i = 0;

    if(money<denominations[0]) return 0;
    
    while (money > 0)
    {
        if (money > denominations[i])
            i++;
        if (money == denominations[i])
            total++;
        if (money < denominations[i])
        {
            money -= denominations[i-1];
            total++;
            i = 0;
        }
    }
    return total;
}

int main()
{
    cout << "Enter the amount of money you have ";
    int money;
    cin >> money;
    int totalcoinornote = MinimumNotesRequired(money);
    cout << "the minimum notes or coins required are " << totalcoinornote << endl;
    return 0;
}