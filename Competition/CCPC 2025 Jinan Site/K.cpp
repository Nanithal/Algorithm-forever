#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), cnt(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }

    set<int> ones, twos;

    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) {
            twos.insert(i);
        } else if (cnt[i] == 1) {
            ones.insert(i);
        }
    }

    vector<bool> vis(n + 1, false), hasSet(n + 1, false);
    vector<int> b(n + 1);

    int ans = 0;
    if (cnt[a[1]] == 2) {
        ans = 1;
        vis[a[1]] = true;
    }

    for (int i = 2; i <= n;) {
        if (cnt[a[i]] == 2 && !vis[a[i]]) {
            auto it = twos.begin();
            b[i - 1] = *it;
            hasSet[i - 1] = true;
            vis[a[i]] = true;
            int j = i + 1;
            while (cnt[a[j]] == 2 && !vis[a[j]]) {
                vis[a[j]] = true;
                ++j;
            }
            b[j - 1] = *it;
            hasSet[j - 1] = true;
            twos.erase(it);
            i = j + 1;
        } else {
            ++i;
        }
    }

    for (int i = n; i >= 1; --i) {
        if (!hasSet[i]) {
            if (ones.count(a[i])) {
                b[i] = a[i];
                ones.erase(a[i]);
                hasSet[i] = true;
            }
        }
    }

    vector<int> rem;
    for (auto it = twos.begin(); it != twos.end(); ++it) {
        rem.push_back(*it);
        rem.push_back(*it);
    }

    int p = 0;
    for (int i = n; i >= 1; --i) {
        if (!hasSet[i]) {
            if (!ones.empty()) {
                auto it = ones.begin();
                b[i] = *it;
                ones.erase(it);
                hasSet[i] = true;
            } else {
                // auto it = twos.begin();
                // b[i] = *it;
                // twos.erase(it);
                // hasSet[i] = true;
                b[i] = rem[p++];
                hasSet[i] = true;
            }
        }
    }

    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        cout << b[i] << ' ';
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int _ = 1;
    cin >> _;
    while (_--)
        solve();

    return 0;
}