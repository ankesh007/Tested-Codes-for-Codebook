struct node{
	int coun;
	node *l,*r ;
	node(int coun,node *l,node *r):
		coun(coun),l(l),r(r){}
		node *inser(int l,int r,int pos) ;
};
node* node::inser(int l,int r,int pos){
	if(l<=pos && pos<=r){
		if(l==r){
			return new node(this->coun+1,NULL,NULL);
		}
		int mid=(l+r)>>1;
		return new node(this->coun+1,this->l->inser(l,mid,pos),this->r->inser(mid+1,r,pos));
	}
	return this;
}
int query(node *lef,node *rig,int cc,int s,int e){
	if(s==e)
			return s;
	int co=rig->l->coun-lef->l->coun;
	int mid=(s+e)>>1;
	if(co>=cc)
		return query(lef->l,rig->l,cc,s,mid);
	return query(lef->r,rig->r,cc-co,mid+1,e);
}
node *null=new node(0,NULL,NULL);
node *root[100100];
null->l=null->r=null;
root[0]=null;
for(int i=1;i<=n;i++)
	root[i]=root[i-1]->inser(0,maxy,m[arr[i]]);
while(mmm-->0){
	int i,j,k;cin>>i>>j>>k;
	cout<<mm[query(root[i-1],root[j],k,0,maxy)]<<"\n";
