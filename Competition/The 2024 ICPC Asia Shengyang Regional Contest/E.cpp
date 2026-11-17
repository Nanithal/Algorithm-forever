#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
int n,m,p,q;
int f[105][105][2];


int min(int a,int b){
    return a<b?a:b;
}



int dfs(int x,int y,int st){
    if(f[x][y][st]!=-1)return f[x][y][st];
    int x1=n-x,y1=m-y;
    f[x][y][st]=inf;
    if(st==0){
        if(y1>x1+q&&x1)return f[x][y][st]=inf;
        for(int dx=0;dx<=min(x,p);dx++){
            for(int dy=0;dy<=min(y,p)&&dy+dx<=p;dy++){
                int xx=x-dx,yy=y-dy;
                dfs(xx,yy,1);
                f[x][y][0]=min(f[x][y][0],f[xx][yy][1]+1);
            }
        }
        return f[x][y][0];
    }
    else{
        if(y>x+q&&x)return f[x][y][st]=inf;
        for(int dx=0;dx<=p&&x+dx<=n;dx++){
            for(int dy=0;y+dy<=m&&dx+dy<=p;dy++){
                int xx=x+dx,yy=y+dy;
                dfs(xx,yy,0);
                f[x][y][1]=min(f[x][y][1],f[xx][yy][0]+1);
            }
        }
    }
    return f[x][y][st];
}

void solve(){
    cin>>n>>m>>p>>q;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)f[i][j][0]=f[i][j][1]=-1;
    }
    f[n][m][0]=0;
    int ans=inf;
    //dfs(0,3,1);
    for(int i=0;i<=m;i++){
        dfs(0,i,0);
        dfs(0,i,1);
        ans=min({ans,f[0][i][0],f[0][i][1]});
    }
    if(ans==inf)ans=-1;
    cout<<ans<<endl;
}

signed main(){
    int t=1;
    while(t--)   solve();
}



