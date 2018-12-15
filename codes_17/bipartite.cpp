 
vector<pair<int,pair<int,bool> > > graph[1000];
vector<bool> edge_use,visited;
vector<int> parent,edge_number;
 
void dfs(int i){
	visited[i]=true;
	for(auto itr:graph[i]){
		if(visited[itr.x])
			continue;
		if(edge_use[itr.y.x] && itr.y.y){
			parent[itr.x]=i;
			edge_number[itr.x]=itr.y.x;
			dfs(itr.x);
		}
		else if(!edge_use[itr.y.x] && (!itr.y.y)){
			parent[itr.x]=i;
			edge_number[itr.x]=itr.y.x;
			dfs(itr.x);
		}				
	}
}
 
void edge_reverse(int t){
	if(t==0)
		return;
	edge_use[edge_number[t]]=!edge_use[edge_number[t]];
	edge_reverse(parent[t]);
}
// |l|,|r| are the number of vertices in the left side and right side respectively.
int s=0;
int t=(|l|+|r|+1) ;
for(int i=1;i<=h;i++){
	++edge_count;
	graph[0].pb({i,{edge_count,true}});
	graph[i].pb({0,{edge_count,false}});
}
int matching=0;
edge_use.resize(edge_count+1);
visited.resize(t+1);
edge_number.resize(t+1);
parent.resize(t+1);
for(int i=0;i<=edge_count;i++)
	 edge_use[i]=true;
while(true){
	for(int i=0;i<=t;i++){
		visited[i]=false;
		edge_number[i]=-1;
		parent[i]=-1;
	}
	dfs(s);
	if(!visited[t])
		break;
	edge_reverse(t);
	matching++;
}
