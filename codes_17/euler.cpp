vector<pair<int,int> > graph[202];
bool visited[202];
vector<int> odd;
bool used_edges[41000];
stack<int> s;
int tot_edges;
int counter[202];

void dfs(int i)
{
  visited[i]=true;

  int len=graph[i].size();
  if(len&1)
    odd.pb(i);

  for(auto itr:graph[i])
    if(!visited[itr.x])
      dfs(itr.x);
}
void euler_tour(int i)
{
    visited[i]=true;
    s.push(i); 

    int x=graph[i].size();
    while(counter[i]<x)
    {
      auto itr=graph[i][counter[i]];
      counter[i]++;

      if(!used_edges[itr.y])
      {
        used_edges[itr.y]=true;
        if(itr.y<=tot_edges)
          cout<<i<<" "<<itr.x<<"\n";
        euler_tour(itr.x);
      }
    }
    s.pop();  
}