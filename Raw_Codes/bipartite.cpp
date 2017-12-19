#include<bits/stdc++.h>
 
#define long long long int
using namespace std;
     
#define Max 100005+5
// #define cons 1000000000+7
#define mp make_pair
#define pb push_back
#define INF 1e16
#define INF2 1e9+9
#define pi 3.141592653589
#define x first
#define y second
     
// g++ -std=c++11 prac.cpp
// long pa[21][Max], level[Max];
     
// long lca(long u,long v)
// {
//     if(level[u]>level[v])return lca(v,u);
//     for(long i=19;i>=0 && level[v]!=level[u];i--)
//     {
//         if(level[v]>=level[u]+(1<<i))
//             v=pa[i][v];
//     }
//     if(u==v)return u;
//     for(long i=19;i>=0;i--)
//     {
//         if(pa[i][u]!=pa[i][v])
//         {
//             u=pa[i][u];v=pa[i][v];
//         }
//     }
//     return pa[0][u];
// }
  
     
long cons;
long check(long a)
{
    if(a>=cons)a%=cons;
 
    return a;
}
long check2(long a)
{
    if(a>0)return a;
    long b=a/cons;
    a-=b*cons;
    if(a<0)a+=cons;
    return a;
}
 
long GCD(long a,long b)
{
  if(b==0)
    return a;
  return GCD(b,a%b);
}
 
long exp(long a,long n)
{
    if(n==0)return 1;
    if (n==1)return check(a);
 
    long b=exp(a,n/2);
 
    if(n%2==0)return check(b*b);
    return check(b*check(b*a));
}
 
vector<pair<int,pair<int,bool> > > graph[1000];
// bool matched[1000];
// bool edge_used[]
vector<bool> edge_use,visited;
vector<int> parent,edge_number;
 
void dfs(int i)
{
    visited[i]=true;
 
    for(auto itr:graph[i])
    {
        if(visited[itr.x])
            continue;
        if(edge_use[itr.y.x] && itr.y.y)
        {
            parent[itr.x]=i;
            edge_number[itr.x]=itr.y.x;
            dfs(itr.x);
        }
        else if(!edge_use[itr.y.x] && (!itr.y.y))
        {
            parent[itr.x]=i;
            edge_number[itr.x]=itr.y.x;
            dfs(itr.x);
        }            
    }
}
 
void edge_reverse(int t)
{
    if(t==0)
        return;
 
    edge_use[edge_number[t]]=!edge_use[edge_number[t]];
    edge_reverse(parent[t]);
}
 
int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(NULL);
 
    int n;
    cin>>n;
    int iii=0;
 
    while(n--)
    {
        iii++;        
 
    vector<pair<int,int> > host,participant; 
    int h,g,k,c;
    cin>>h>>g>>k>>c;
 
    int s=0;
    int t=h+g+1;
 
    for(int i=0;i<=t;i++)
    {
        graph[i].clear();
    }
 
    for(int i=0;i<h;i++)
    {
        int x,y;
        cin>>x>>y;
        host.pb({x,y});
    }
    for(int i=0;i<g;i++)
    {
        int x,y;
        cin>>x>>y;
        participant.pb({x,y});
    }
 
    int edge_count=-1;
 
    for(int i=1;i<=h;i++)
    {
        ++edge_count;
        graph[0].pb({i,{edge_count,true}});
        graph[i].pb({0,{edge_count,false}});
    }
 
    for(int i=h+1;i<=h+g;i++)
    {
        ++edge_count;
        graph[i].pb({t,{edge_count,true}});        
        graph[t].pb({i,{edge_count,false}});        
    }
 
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=g;j++)
        {
            int dis1=abs(participant[j-1].x-host[i-1].x)+abs(participant[j-1].y-host[i-1].y);
            int dis2=abs(participant[j-1].x-k)+abs(participant[j-1].y-k);
            if(dis2+dis1<=c)
            {
                ++edge_count;
                graph[i].pb({j+h,{edge_count,true}});
                graph[j+h].pb({i,{edge_count,false}});
            }
        }
    }
 
    int matching=0;
 
    edge_use.resize(edge_count+1);
    visited.resize(t+1);
    edge_number.resize(t+1);
    parent.resize(t+1);
 
    for(int i=0;i<=edge_count;i++)
        edge_use[i]=true;
 
    while(true)
    {
        // cout<<"Hi"<<endl;
        for(int i=0;i<=t;i++)
        {
            visited[i]=false;
            edge_number[i]=-1;
            parent[i]=-1;
        }
 
        // parent[s]=-1;
 
        dfs(s);
        // cout<<"dfs"<<endl;
        if(!visited[t])
            break;
        edge_reverse(t);
        matching++;
    }
    cout<<"Case "<<iii<<": " ;
    cout<<matching<<"\n";
 
    }
} 