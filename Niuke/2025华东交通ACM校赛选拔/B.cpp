
#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int N = 2e5 + 1;
const int INF = 0x3f3f3f3f;
const ll INFF = 0x3f3f3f3f3f3f3f3f;

map<int, string> sexiang;
map<int, string> mingdu;
map<int, string> baohedu;

void init()
{
  sexiang[1] = "Red";
  sexiang[2] = "Orange";
  sexiang[3] = "Yellow";
  sexiang[4] = "Green";
  sexiang[5] = "Blue";
  sexiang[6] = "Purple";
  mingdu[0] = "Dark";
  mingdu[1] = "Bright";
  baohedu[0] = "Low";
  baohedu[1] = "Medium";
  baohedu[2] = "High";
}

void solve()
{
  int a, b, c;
  cin >> a >> b >> c;
  cout << baohedu[c] << mingdu[b] << sexiang[a] << endl;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  init();
  int t = 1;
  //   cin >> t;
  while (t--)
  {
    solve();
  }
  return 0;
}
