int match(char t[],char s[],int pos,int n){
	for(int i=0 ; i<t.length ; i++)
		if(pos+i==n) 
			return 1 ;
		else if(t[i]!=s[pos+i])
			return (t[i]<s[pos+i] ? -1 : 1) ;
	return 0 ;
}
int[] SufTrans(int P[][],int n){
	int suf[] = new int[n] ;
	for(int i=0 ; i<n ; i++) suf[P[19][i]] = i ;
	return suf ;
}
int LCP(int i,int j,int P[][],int n){
	if(i==j) return (n-i+1) ;
	int match=0 ;
	for(int k=19 ; i<n && j<n && k>=0 ; k--){
		if(P[k][i]==P[k][j]){
			match+=(1<<k) ;
			i+=(1<<k) ;
			j+=(1<<k) ;
		}
	}
	return match ;
}
int[][] suffix_array(char c[],int n){
	class Tuple implements Comparable<Tuple>{
		int idx ; pair p ;
		Tuple(int _idx,pair _p){
			idx = _idx ; p=_p ;
		}
		public int compareTo(Tuple _t){
			return p.compareTo(_t.p) ;
		}
	}
	int P[][] = new int[20][n] ;
	if(n!=1) 
		for(int i=0 ; i<n ; i++) P[0][i] = (int) c[i] ;
	else 
		P[0][0] = 0 ; 
	for(int i=1,pow2=1 ; i<20 ; pow2<<=1,i++){
		Tuple L[] = new Tuple[n] ;
		for(int j=0 ; j<n ; j++){
			int y = ((j+pow2)<n ? P[i-1][j+pow2] : -1) ;
			L[j] = new Tuple(j,new pair(P[i-1][j],y)) ;
		}
		Arrays.sort(L) ;
		for(int j=0 ; j<n ; j++)
			if(j>0 && L[j].compareTo(L[j-1])==0)
				P[i][L[j].idx] = P[i][L[j-1].idx] ;
			else
				P[i][L[j].idx] = j ;
	}
	return P ;
}