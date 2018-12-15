//Given an array of characters in c and
// length of array is n, find the z-array
//that is z[i]=longest prefix match of suffix
//at i and the original string
int[] Z_algo(char c[],int n){
	int Z[] = new int[n] ;
	int L=0,R=0 ;
	for(int i=1 ; i<n ; i++){
		if(i>R){
			L=i ; R=i ;
			while(R<n && c[R]==c[R-L]) R++ ;
			R-- ; Z[i] = (R-L+1) ;
		}else{
			int j = i-L ;
			if(Z[j]<(R-i+1))
				Z[i]=Z[j] ;
			else{
				L=i ;
				while(R<n && c[R]==c[R-L]) R++ ;
				R-- ; Z[i] = (R-L+1) ; 
			}
		}
	}
	return Z ;
}
	