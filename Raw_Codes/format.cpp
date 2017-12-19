#include <bits/stdc++.h>
#define long long long int
using namespace std;
#define Max 100010
#define mp make_pair
#define pb push_back
#define INF 1e16
#define INF2 1e9+9
#define pi 3.141592653589
#define x first
#define y second
     
long cons;
long check(long a)
{
    if(a>=cons)a%=cons;
    return a;
}
long check2(long a)
{
    if(a>0)return a;
    long b=a/cons;
    a-=b*cons;
    if(a<0)a+=cons;
    return a;
}
 
long GCD(long a,long b)
{
  if(b==0)
    return a;
  return GCD(b,a%b);
}
 
long exp(long a,long n)
{
    if(n==0)return 1;
    if (n==1)return check(a);
    long b=exp(a,n/2);
    if(n%2==0)return check(b*b);
    return check(b*check(b*a));
}
int main()
{
   ios::sync_with_stdio(false);cin.tie(0);
   cons=1e9+7;
}