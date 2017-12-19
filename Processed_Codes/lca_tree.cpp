vpi auxTree[N];
int parent[N];
ll parWgt[N];
int conAuxTree(set<int, disComp> &nodes) {
    vi originalNodes(nodes.begin(), nodes.end());
    for (int i=0; i<originalNodes.size()-1; i++) {
        nodes.insert(LCA(originalNodes[i], originalNodes[i+1]));
    }
    int root = *nodes.begin();
    parent[root] = 0;
    int cur = root;
    auto sit = next(nodes.begin());
    while (sit != nodes.end()) {
        while (!isAnc(cur, *sit)) {
            assert(cur);
            cur = parent[cur];
        }
        parent[*sit] = cur;
        parWgt[*sit] = rootDis[*sit] - rootDis[cur];
        auxTree[cur].push_back({*sit, parWgt[*sit]});
        cur = *sit;
        ++sit;
    }
    return root;
}
