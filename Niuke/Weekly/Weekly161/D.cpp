#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 1;

char in[201][201];
int n, m;
int left1[] = {1, -1, 0, 0};
int up1[] = {0, 0, 1, -1};
int left2[] = {1, -1, 0, 0, 1, -1, 1, -1};
int up2[] = {0, 0, 1, -1, 1, 1, -1, -1};

bool vis1[201][201];
bool vis2[201][201];

void dfs1(int x, int y, int &s)
{
    s++;
    vis1[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + left1[i];
        int ny = y + up1[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || vis1[nx][ny] == 1 || in[nx][ny] == '0')
            continue;

        dfs1(nx, ny, s);
    }
}
void dfs2(int x, int y, int &s)
{
    s++;
    vis2[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + left2[i];
        int ny = y + up2[i];
        if (nx < 1 || nx > n || ny < 1 || ny > m || vis2[nx][ny] == 1 || in[nx][ny] == '0')
            continue;

        dfs2(nx, ny, s);
    }
}

void solve()
{
    int c4 = 0, c8 = 0, s4 = 0, s8 = 0;
    cin >> n >> m;
    vector<pair<int, int>> sa;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> in[i][j];
            if (in[i][j] == '1')
            {
                sa.push_back({i, j});
            }
        }
    }
    for (auto &it : sa)
    {
        if (!vis1[it.first][it.second])
        {
            int temp = 0;
            dfs1(it.first, it.second, temp);
            s4 = max(s4, temp);
            c4++;
        }
    }
    for (auto &it : sa)
    {
        if (!vis2[it.first][it.second])
        {
            int temp = 0;
            dfs2(it.first, it.second, temp);
            s8 = max(s8, temp);
            c8++;
        }
    }
    cout << c4 - c8 << ' ' << s4 << ' ' << s8 << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}