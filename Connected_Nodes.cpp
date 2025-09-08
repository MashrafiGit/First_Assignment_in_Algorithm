#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];

void connected_nodes(int x)
{
    vector<int> v;
    if (adj_list[x].empty())
    {
        cout << -1 << endl;
        return;
    }
    for (auto child : adj_list[x])
        v.push_back(child);

    sort(v.begin(), v.end(), greater<int>());

    for (auto i : v)
        cout << i << " ";
    cout << endl;
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
        adj_list[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;
        connected_nodes(x);
    }

    return 0;
}
