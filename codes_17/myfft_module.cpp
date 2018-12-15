/*
    ========== Number Theoretic Transform ===========
    The code below can be used to multiply two polynomials in O(n log n).
    The multiplication happens modulo 5 * (2 ^ 25) + 1 which is around 1.6e8.
    This implementation has been thoroughly tested and can be used when
    dealing with integers. Some implementation details:
    - n should be a power of 2. Generally, if we are multiplying two degree 'd'
      polynomials, n should be the smallest power of two greater than 2 * d.
    - Changing the modulo requires some number theoretic results. Most modulos
      do not work. Here is what we do to deal with modulos:
    - Suppose the modulo is M. M must be prime and of the form 2^k * x + 1
      where k >= ceil(log n) and x >= 1. To make the code below work for a particular
      M, we need to change the 4 constants below. Here is how we find the
      constants:
       - mod: M
       - root_pw: 2^k
       - root: Let p = find_primitive_root(M). Then root = (p ^ x) % M
       - root_1: inverse(root, M)
       We can work out these values offline by using the find_primitive_root()
       and inverse() functions below, and then hardcode them into the program.
    - Suppose the modulo is not of the form 2^k * x + 1, and we know that in
      the product polynomial, the coefficients will be less than ~1e15. Then
      we can compute NTT using large primes p1, p2 (around 1e7) and then
      compute the value modulo (p1 * p2) using CRT. This will give us a
      very high precision result :)
    - P1 =  5 * (2 ^ 25) + 1
      P2 =  7 * (2 ^ 20) + 1
      P1 * P2 >= 1e15.
    ==================================================
*/

const lli MOD = 119*(1l<<23)+1 ;
const lli root_pw = 1l<<23 ;
const lli primitive_root = 3 ;
lli root,root_1 ;

inline lli mul(lli x,lli y){ return (x*y)%MOD ;}
lli powM(lli x,lli n){
    lli ans=1 ;
    for( ; n!=0 ; x=(x*x)%MOD , n/=2) if((n&1)==1) ans = mul(ans,x) ;
    return ans ;
}
inline lli inv(lli x){ return powM(x,MOD-2) ; }

inline void fft (vector<lli> &L,bool invert) {
    int n = (int) L.size();
    for(int i=1,j=0 ; i<n ; i++){
        int bit = n>>1 ;
        for( ; j>=bit ; bit>>=1) j-=bit ;
        j+=bit ;
        if(i<j) swap(L[i],L[j]);
    }
    for(int len=2 ; len<=n ; len<<=1){
        lli wlen = invert ? root_1 : root ;
        for(lli i=len ; i<root_pw ; i<<=1) wlen = mul(wlen,wlen) ; 
        for(int i=0 ; i<n ; i+=len){
            lli w=1 ;
            for(int j=0 ; j<(len/2) ; j++){
                lli u = L[i+j] ; lli v = mul(w,L[i+j+(len/2)]) ;
                L[i+j] = (u+v)<MOD ? (u+v) : (u+v-MOD) ;
                L[i+j+(len/2)] = (u-v)>=0 ? (u-v) : (u-v+MOD) ;
                w = mul(w,wlen) ; 
            }
        }
    }
    if(invert){
        lli nrev = inv(n) ;
        for(int i=0 ; i<n ; i++) L[i] = mul(L[i],nrev) ;
    }
}

