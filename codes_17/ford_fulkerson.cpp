const int N=250;
const int M=210*26*2;

int n,m;
vector<pair<int,int> > graph[N];
int edge_count=0;
int visited_from[N];
int edge_entering[N];
int reverse_no[M];
int capacity[M];
int max_flow_dfs[N];

void addEdge(int x,int y,int cap)
{
	++edge_count;
	capacity[edge_count]=cap;
	graph[x].pb({y,edge_count});
	++edge_count;
	capacity[edge_count]=0;
	graph[y].pb({x,edge_count});
	reverse_no[edge_count]=edge_count-1;
	reverse_no[edge_count-1]=edge_count;
}

void dfs(int source)
{
	// cout<<source<<endl;
	for(auto itr:graph[source])
	{
		if(visited_from[itr.x]==-1 && capacity[itr.y])
		{
			edge_entering[itr.x]=itr.y;
			visited_from[itr.x]=source;
			max_flow_dfs[itr.x]=min(capacity[itr.y],max_flow_dfs[source]);
			dfs(itr.x);
		}
	}
	// cout<<source<<endl;
}

void reverse_edge(int i,int flow)
{
	while(visited_from[i]!=0)
	{
		capacity[edge_entering[i]]-=flow;
		capacity[reverse_no[edge_entering[i]]]+=flow;
		i=visited_from[i];
	}
}

int ford_faulkerson(int source,int sink,int n)
{
	int ans=0;
	// cout<<n<<endl;
	while(true)
	{
		for(int i=1;i<=n;i++)
			visited_from[i]=-1;
		visited_from[source]=0;
		max_flow_dfs[source]=1e9;

		dfs(source);
		if(visited_from[sink]==-1)
			break;
		ans+=max_flow_dfs[sink];
		reverse_edge(sink,max_flow_dfs[sink]);
	}
	return ans;
}
