
const int N=2e5+10;
const int M=4*N;

long tree[M],lr[M];
long pos[N],w[N];
int n,q;
// long cumu_pos[N];

void buildtree(int s,int e,int n)
{
	if(s==e)
	{
		tree[n]=w[s];
		return;
	}
	int mid=(s+e)>>1;
	buildtree(s,mid,n+n);
	buildtree(mid+1,e,n+n+1);
	tree[n]=tree[n+n]+tree[n+n+1];
}

void buildlr(int s,int e,int n)
{
	if(s==e)
	{
		lr[n]=(pos[s]-s+1)*w[s];
		lr[n]=check(lr[n]);
		return;
	}
	int mid=(s+e)>>1;
	buildlr(s,mid,n+n);
	buildlr(mid+1,e,n+n+1);
	lr[n]=check(lr[n+n]+lr[n+n+1]);
}
long lef,rig,cumu_sum;
int ind(int s,int e,int n)
{
	if(s==e)
		return s;
	long sum2=tree[n+n]+cumu_sum;
	int mid=(s+e)>>1;
	if(sum2-lef>=rig-sum2)
		return ind(s,mid,n+n);
	else
	{
		cumu_sum+=tree[n+n];
		return ind(mid+1,e,n+n+1);
	}
}

void update(int s,int e,int n,int ind)
{
	if(s==e)
	{
		tree[n]=w[s];
		lr[n]=(pos[s]-s+1)*w[s];
		lr[n]=check(lr[n]);
		return;		
	}
	if(e<ind || s>ind)
		return;
	int mid=(s+e)>>1;
	update(s,mid,n+n,ind);
	update(mid+1,e,n+n+1,ind);
	lr[n]=check(lr[n+n]+lr[n+n+1]);
	tree[n]=tree[n+n]+tree[n+n+1];
}

long sum(int s,int e,int n,int qs,int qe)
{
	if(qe<qs)
		return 0;
	if(s>=qs && e<=qe)
		return tree[n];
	if(s>qe || qs>e)
		return 0;
	int mid=(s+e)>>1;
	return sum(s,mid,n+n,qs,qe)+sum(mid+1,e,n+n+1,qs,qe);
}
long other_sum(int s,int e,int n,int qs,int qe)
{
	if(qe<qs)
		return 0;
	if(s>=qs && e<=qe)
		return lr[n];
	if(s>qe || qs>e)
		return 0;
	int mid=(s+e)>>1;
	return check(other_sum(s,mid,n+n,qs,qe)+other_sum(mid+1,e,n+n+1,qs,qe));
}


long query(long x,long y)
{
	lef=sum(1,n,1,1,x-1);
	rig=sum(1,n,1,1,y);
	cumu_sum=0;
	int inde=ind(1,n,1);
	// cout<<inde<<endl;

	lef=check(cumu_sum-lef);
	rig=check(rig-cumu_sum-w[inde]);

	long ss=check2(other_sum(1,n,1,inde+1,y)-(pos[inde]-(inde-1))*rig);
	long ss2=check2((pos[n]-n)*lef-other_sum(1,n,1,x,inde-1));
	ss2=check2(ss2-(pos[n]-pos[inde]-(n-inde+1))*lef);

	return check(ss+ss2);
}