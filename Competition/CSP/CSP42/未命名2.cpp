#include<bits/stdc++.h>
using namespace std;
const int K=41;
int n,m;
class jc
{
	public:
		int w;
		char type;
		int s,k;
		int a[K];
		int t[K];
};
jc jingc[11];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>jingc[i].type;
		if(jingc[i].type!='X')
		cin>>jingc[i].s>>jingc[i].k;
		else
		cin>>jingc[i].s>>jingc[i].w>>[i].k;
		for(int j=1;j<=2*jingc[i].k;j++)
		cin>>jingc[i].a[j]>>jingc[i].t[j];
	}
	
	
	
}
