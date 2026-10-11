#include <bits/stdc++.h>

using namespace std;

void solve()
{
    double px, py, ux, uy, vx, vy;
    cin >> px >> py >> ux >> uy >> vx >> vy;

    double qy = (vx - ux) * (vx - ux) * uy + (vy - uy) * (vy - uy) * py - (vx - ux) * (vy - uy) * (ux - px);
    qy /= ((vx - ux) * (vx - ux) + (vy - uy) * (vy - uy));
    double qx = (vx - ux) * (qy - uy) / (vy - uy) + ux;

    printf("%.7lf %.7lf\n", qx, qy);
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}
