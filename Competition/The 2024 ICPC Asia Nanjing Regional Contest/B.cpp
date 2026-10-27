#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int sum = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '2') {
            cnt++;
        } else {
            int v = (s[i] == '0' ? 1 : -1);

            if (i & 1)
                sum -= v;
            else
                sum += v;
        }
    }

    int ans = max(abs(sum) - cnt, n % 2);

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}