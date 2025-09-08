#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1005][1005];
bool vis[1005][1005];
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int di = -1, dj = -1;

bool valid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

string dfs(int si, int sj)
{
    if (si == di && sj == dj)
        return "YES";

    vis[si][sj] = true;

    for (int i = 0; i < 4; i++)
    {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;

        if (valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
        {
            string res = dfs(ci, cj);
            if (res == "YES")
                return "YES";
        }
    }

    return "NO";
}

int main()
{
    cin >> n >> m;

    int si = -1, sj = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j] == 'A')
            {
                si = i, sj = j;
            }
            else if (grid[i][j] == 'B')
            {
                di = i, dj = j;
            }
        }
    }

    if (si == -1 || sj == -1 || di == -1 || dj == -1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << dfs(si, sj) << endl;
    }

    return 0;
}
