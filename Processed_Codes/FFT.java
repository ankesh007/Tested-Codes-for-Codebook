//"root" is the primitive root such that
// root^n=1 modulo mod, where n = 2^k and
// root_i is the inverse of root
// FFT function takes an array L and a boolean
// parameter invert which tells whether to take 
// inverse fourier transform or not,gives a new
// array which is the fourier/inverse transform of L,in
// the modulo field mod, the size of the array is
// n, which is a perfect power of 2.
// Note the transform is NOT inplace
long[] FFT(long L[],boolean invert){
	int n = L.length ;		
	L = Arrays.copyOf(L,n) ;
	for(int i = 1,j = 0 ; i<n ; i++) {
        int bit = n>>1 ;
        for(; j>=bit ; bit>>=1) j-=bit ;	        
        j+=bit ;
        if(i<j){
        	long tmp = L[i] ;
        	L[i]=L[j] ; L[j]=tmp ; 
        }	        
    }
	for(int m=2 ; m<=n ; m<<=1){
		long wlen = invert ? root_i : root ;
		for(long i=m ; i<n ; i<<=1)
			wlen = (wlen*wlen)%mod ;
		long w=1 ;
		for(int i=0 ; i<m/2 ; i++){
			for(int k=i ; k<n ; k+=m){
				long u = L[k] ;				
				long v = (w*L[k+m/2])%mod ;
				L[k]=(u+v)%mod ;
				L[k+m/2]=(u-v+mod)%mod ;
			}
			w = (w*wlen)%mod ;
		}
	}
	if(invert){
		long ninv = Mod.d(1,n) ;
	 	for(int i=0 ; i<n ; i++)
			L[i]=(L[i]*ninv)%mod ;         
	}		
	return L ;
}