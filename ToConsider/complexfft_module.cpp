// Instructions for using this: Nothing it is very obvious to use

typedef complex<long double> Cld;
class FFT{
public:
	static const ld PI;
	static void cfft (vector<Cld> &L,int invert) {
		int n = (int) L.size();
		for(int i=1,j=0 ; i<n ; i++){
			int bit = n>>1 ;
			for( ; j>=bit ; bit>>=1) j-=bit ;
			j+=bit ;
			if(i<j) swap(L[i],L[j]);
		}
		for(int len=2 ; len<=n ; len<<=1){
			int l2 = (len/2);
			ld theta = (PI/l2);
			Cld wlen = polar(1.0L,(invert ? -1 : 1)*theta);
			for(int i=0 ; i<n ; i+=len){
				Cld w(1.0,0.0);
				for(int j=0 ; j<l2 ; j++, w=(w*wlen)){
					Cld u = L[i+j]; Cld v = w*L[i+j+l2];
					L[i+j] = (u+v); L[i+j+l2] = (u-v);
				}
			}
		}
		if(invert)
			for(int i=0 ; i<n ; i++) L[i] = L[i]/((ld) n);
	}
};
const ld FFT::PI = acos(-1.0);
