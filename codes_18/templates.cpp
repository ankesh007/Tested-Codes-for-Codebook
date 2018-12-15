#include <bits/stdc++.h>
typedef long double ld ;
#define long long long int
using namespace std;
#define pi 3.141592653589

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
	os << "[ ";
	for(auto v : V) os << v << " ";
	return os << "]";
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
	return os << "(" << P.first << "," << P.second << ")";
}
#define TRACE
#ifdef TRACE
	#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ',');
		cerr.write(names, comma - names) << " : " << arg1<<" | ";
		__f(comma+1, args...);
	}
#else
	#define trace(...)
#endif

long GCD(long a,long b){
	while(a && b){
		a=a%b;
		if(a!=0)
			b=b%a;
	}
	return a+b;
}
 
long exp(long a,long n){
	long ans=1;
	a=check(a);
	while(n){
		if(n&1)
			ans=check(ans*a);
		a=check(a*a);
		n=(n>>1);
	}
	return ans;
}
