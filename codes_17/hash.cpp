vector<long> hashed1[10*Max];
vector<long> hashed2[10*Max];
long p1=2350490027,p2=1628175011;
long p3=2911165193,p4=1040332871;
2350490027,2125898167,1628175011,1749241873,
1593209441,1524872353,1040332871,2911165193,
1387346491,2776808933
void calc_hashed(int ind,vector<long> &hashed,long prime){
	long val=1;
	int x=neighbour[ind].size();
	hashed.resize(x);
	for(int i=0;i<x;i++){
		if(i==0)
			hashed[i]=neighbour[ind][i];
		else
			hashed[i]=check(hashed[i-1]+neighbour[ind][i]*val) ;
		val=check(val*prime);
	}
}
