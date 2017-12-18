vector<int> graph[3*Max];
int size[3*Max];
bool usable[3*Max];
int centroid_parent[3*Max];

void calc_size(int i,int pa)
{
  size[i]=1;

  for(auto itr:graph[i])
  {
    if(itr!=pa && usable[itr])
    {
      calc_size(itr,i);
      size[i]+=size[itr];
    }
  }
}

int getCentroid(int i,int len,int pa)
{
  for(auto itr:graph[i])
  {
    if(itr!=pa && usable[itr])
    {
      if(size[itr]>(len/2))
        return getCentroid(itr,len,i);
    }
  }
  return i;
}

void build_centroid(int i,int coun)
{
  queue<pair<int,int> > q;
  q.push({i,-1});

  while(!q.empty())
  {
    auto itr=q.front();
    q.pop();
    calc_size(itr.x,-1);
    int centroid=getCentroid(itr.x,size[itr.x],-1);
    centroid_parent[centroid]=itr.y;

    for(auto itr2:graph[centroid])
    {
      if(usable[itr2])
      {
        q.push({itr2,centroid});
      }
    }

    usable[centroid]=false;
  }
}
