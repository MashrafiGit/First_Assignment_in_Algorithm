#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

string connected_or_not(int a, int b)
{
    if (a == b)
        return "YES";
    for (auto child : adj_list[a])
        if (child == b)
            return "YES";
    return "NO";
}

int main()
{
    int n, e;
    cin >> n >> e;

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << connected_or_not(a, b) << endl;
    }

    return 0;
}
