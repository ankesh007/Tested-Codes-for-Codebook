int pa[21][3*Max], level[3*Max];     
int lca(int u,int v)
{
    if(level[u]>level[v])return lca(v,u);
    for(long i=19;i>=0 && level[v]!=level[u];i--)
    {
        if(level[v]>=level[u]+(1<<i))
            v=pa[i][v];
    }
    if(u==v)return u;
    for(long i=19;i>=0;i--)
    {
        if(pa[i][u]!=pa[i][v])
        {
            u=pa[i][u];v=pa[i][v];
        }
    }
    return pa[0][u];
}