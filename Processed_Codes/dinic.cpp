const int N = 20005 ;
const int E = N*1005 ;
int t, n, m;
int par[N];
/* START DINIC */
int nodes, edges;
int eu[E], ev[E], ef[E], ec[E];
int dist[N], q[N], ed[N];
vector<int> adj[N];
void init(int n) {
	::nodes = n;
	::edges = 0;
	for (int i = 0; i < nodes; ++i)
		adj[i].clear();
}
int newedge(int u, int v, int flow, int cap) {
	eu[edges] = u;
	ev[edges] = v;
	ef[edges] = flow;
	ec[edges] = cap;
	return edges++;
}
void addedge(int u, int v, int cap) {
	int uv = newedge(u, v, 0, cap);
	int vu = newedge(v, u, 0, 0);
	adj[u].push_back(uv);
	adj[v].push_back(vu);
}
bool bfs(int src, int snk) {
	memset(dist, -1, sizeof(int) * nodes);
	int h = 0, t = 0;
	dist[src] = 0;
	q[t++] = src;
	while (h != t && dist[snk] == -1) {
		int u = q[h++]; if (h == N) h = 0;
		for (int e : adj[u]) {
			int v = ev[e];
			if (dist[v] < 0 && ef[e] < ec[e]) {
				dist[v] = dist[u] + 1;
				q[t++] = v;
				if (t == N) t = 0;
			}
		}
	}
	return ~dist[snk];
}
bool dfs(int u, int snk, int flow) {
	if (flow <= 0) return 0;
	if (u == snk) return flow;
	for (int& i = ed[u]; i < (int) adj[u].size(); ++i) {
		int e = adj[u][i];
		int v = ev[e];
		if (dist[u] + 1 == dist[v]) {
			int fl = min(flow, ec[e] - ef[e]);
			int df = dfs(v, snk, fl);
			if (df == 0) continue;
			ef[e] += df;
			ef[e^1] -= df;
			return df;
		}
	}
	return 0;
}
int dinic(int src, int snk) {
	int mf = 0;
	while (bfs(src, snk)) {
		memset(ed, 0, sizeof(int) * nodes);
		int df;
		while (df = dfs(src, snk, INT_MAX))
			mf += df;
	}
	return mf;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int source = n + m;
		int sink = source + 1;
		init(sink + 1);
		for (int i = 2; i <= n; ++i) {
			scanf("%d", &par[i]);
			addedge(par[i] - 1, i - 1, INT_MAX);
		}
		for (int i = 1; i <= n; ++i) {
			addedge(i - 1, sink, 1);
		}
		for (int i = 0; i < m; ++i) {
			addedge(source, i + n, 1);
			int len;
			scanf("%d", &len);
			for (int j = 0; j < len; ++j) {
				int ai;
				scanf("%d", &ai);
				addedge(i + n, ai - 1, 1);
			}
		}
		printf("%d\n", dinic(source, sink));
	}
} 