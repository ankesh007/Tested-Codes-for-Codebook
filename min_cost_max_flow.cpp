#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int N=110,M=N*N;
int n,m,dv[N],uv[N],s,t;
int tot=1,fi[N],a[M],ne[M],cu[M],co[M];
inline void adde(int x,int y,int cup,int cost){
	a[++tot]=y;cu[tot]=cup;co[tot]=cost;ne[tot]=fi[x];fi[x]=tot;
	a[++tot]=x;cu[tot]=0;co[tot]=-cost;ne[tot]=fi[y];fi[y]=tot;
}
int min_cost,f[N],g[N];
bool inq[N];
queue<int> q;
inline bool spfa(){
	memset(f,0x3f,sizeof f);
	f[s]=0;q.push(s);
	while (!q.empty()){
		int u=q.front();q.pop();inq[u]=0;
		for (int i=fi[u];i;i=ne[i]) if (cu[i])
			if (f[u]+co[i]<f[a[i]]){
				f[a[i]]=f[u]+co[i];
				g[a[i]]=i;
				if (!inq[a[i]]) inq[a[i]]=1,q.push(a[i]);
			}
	}
	if (f[t]==f[0]) return 0;
	min_cost+=f[t];
	int pos=t;
	while (pos!=s){
		cu[g[pos]]^=1;cu[g[pos]^1]^=1;
		pos=a[g[pos]^1];
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) dv[i]=1,uv[i]=n;
	int d,x,y,z;
	for (int i=1;i<=m;++i){
		scanf("%d%d%d%d",&d,&x,&y,&z);
		if (d==1) for (int j=x;j<=y;++j) dv[j]=max(dv[j],z);
		else for (int j=x;j<=y;++j) uv[j]=min(uv[j],z);
	}
	s=2*n+1;t=2*n+2;
	for (int i=1;i<=n;++i){
		adde(s,i,1,0);
		if (dv[i]>uv[i]) return puts("-1"),0;
		for (int j=dv[i];j<=uv[i];++j) adde(i,j+n,1,0);
	}
	for (int i=n+1;i<=2*n;++i) for (int co=1;co<=2*n;co+=2) adde(i,t,1,co);
	while (spfa());
	printf("%d",min_cost);
	return 0;
}