// Instructions for using this: Nothing it is very obvious to use

struct Complex{
	ld x,y;
	Complex operator+(const Complex &b){ return {x+b.x,y+b.y}; }
	Complex operator-(const Complex &b){ return {x-b.x,y-b.y}; }
	Complex operator*(const Complex &b){ return { x*b.x - y*b.y , x*b.y + y*b.x }; }
	Complex operator/(const ld &b){ return {x/b, y/b}; }
	ld real(){ return x;}
};
class FFT{
public:
	static const ld PI;
	static void cfft (vector<Complex> &L,int invert) {
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
			Complex wlen = { cos(theta),(invert ? -1 : 1)*sin(theta) }; 
			for(int i=0 ; i<n ; i+=len){
				Complex w = {1.0,0.0};
				for(int j=0 ; j<l2 ; j++, w=(w*wlen)){
					Complex u = L[i+j]; Complex v = w*L[i+j+l2];
					L[i+j] = (u+v); L[i+j+l2] = (u-v);
				}
			}
		}
		if(invert)
			for(int i=0 ; i<n ; i++) L[i] = L[i]/n;
	}
};
const ld FFT::PI = acos(-1.0);

cA.resize(new_n,zero);
fill(cA.begin(),cA.end(),zero);
FFT::cfft(cA,0);
for(int i=0;i<new_n;i++)
	cA[i]=cA[i]*cB[i];
for(int i=0;i<new_n;i++)	
	cD[i]+=llround(cA[i].x);
