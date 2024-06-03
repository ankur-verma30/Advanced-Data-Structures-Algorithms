/*
Nowadays people have many ways to save money on accomodation when they are on vacation. One of the way is exchanging houses with other people

Here is a group of N people that want to travel around the world. They live in different cities, so they can travel to some other people's city and use someone house temporarily. Now they want to make a plan that chooses a destination for each person . They are two rules should be satisfied:

1. All the people should go to one of the other people city.
2. Two of them never go to the same city. because they are not willing to share a house.

They want to maximize the sum of all people's travel distances. The travel distance of a person is the distance between the city he lives and the city he travels to. These N cities have N-1 highways connecting them. The travelers always choose the shortest path when travelling .

Given the highways information its your job to find the best plan that maximum the total distance of all people.

Input
The first line of input contains one integer T(1<=T<=10), indicating the number of test cases;

Each test case contains several lines . The first line contains an integer N(2<=N<=10^6),representing the number of cities. The the following N-1 lines contains three integers X,Y,Z(1<=X,Y<=N,1<=Z<=10^6), means that there is a highway between city X and city Y and the length of that highway.
You can assume all the cities are connected and the highway are bi-directional.


Output
For each test case in the input print one line that represents the largest total travel distance of all people
*/
#include <bits/stdc++.h>

using namespace std;

// this dfs will give the size of the tree
int dfs(int u, int parent, vector<pair<int, int>> adj[], long long &ans, int N)
{
    int currentTreeSize = 1;
    for (auto p : adj[u])
    {
        int v = p.first;
        int wt = p.second;
        // handle for cycle case skip for the parent node
        if (v == parent)
            continue;

        int childTreesize = dfs(v, u, adj, ans, N);
        int edgeContribution = 2 * min(childTreesize, N - childTreesize) * wt;
        ans += edgeContribution;
        // update the tree size by adding child treesize
        currentTreeSize += childTreesize;
    }
    return currentTreeSize;
}

int main()
{
    int test;
    cin >> test;
    int n, u, v, w;

    // graph
    vector<pair<int, int>> adj[100005];
    int tc = 1;

    while (tc <= test)
    {
        cin >> n;
        for (int i = 0; i <= n; i++)
            adj[i].clear();
        // scan the graph
        for (int i = 1; i <= n - 1; i++)
        {
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        long long ans = 0;
        dfs(1, -1, adj, ans, n);
        cout << "Case #" << tc << " : " << ans << endl;
        tc = tc + 1;
    }

    return 0;
}