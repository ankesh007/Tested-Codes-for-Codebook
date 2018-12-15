void dfs(int i,int pa){
	int coun=1 ;
	for(auto itr:a[i]){
		if(itr.x!=pa){
			prod[itr.x]=check(prod[i]*itr.y) ;
			dfs(itr.x,i);
			coun+=siz[itr.x] ;
		}
	}
	siz[i]=coun ;
}
long ans=0 ; 
void add(int i,int pa,int x){
	coun[mapped_prod[i]]+=x ;
	for(auto itr:a[i])
		if(itr.x!=pa && !big[itr.x])
			add(itr.x,i,x) ;
} 
void solve(int i,int pa){
	long temp=check(multi*inv[i]);
	int xx=m[temp];
	ans+=coun[xx];
	for(auto itr:a[i])
		if(itr.x!=pa && !big[itr.x])
			solve(itr.x,i) ;	
}
void dfs2(int i,int pa,bool keep){
	int mx=-1,bigc=-1;
	for(auto itr:a[i]){
		if(itr.x!=pa){
			if(siz[itr.x]>mx)
			mx=siz[itr.x],bigc=itr.x;
		}
	}
	for(auto itr:a[i]){
		if(itr.x!=pa && itr.x!=bigc)
			dfs2(itr.x,i,0);
	} 
	if(bigc!=-1){
		dfs2(bigc,i,1);
		big[bigc]=true;
	} 
	multi=check(p*check(prod[i]*prod[i]));
	long temp=check(p*prod[i]);
	ans+=coun[m[temp]];
	coun[mapped_prod[i]]++;
	for(auto itr:a[i])
		if(itr.x!=pa && !big[itr.x]){
			solve(itr.x,i);
			add(itr.x,i,1);
		}
	if(bigc!=-1)
		big[bigc]=false;
	if(keep==0)
		add(i,pa,-1);
}