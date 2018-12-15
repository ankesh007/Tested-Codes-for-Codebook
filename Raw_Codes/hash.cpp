vector<long> hashed1[10*Max];
vector<long> hashed2[10*Max];
long p1=2350490027,p2=1628175011,p3=2911165193,p4=1040332871;
2350490027,2125898167,1628175011,1749241873,1593209441,1524872353,1040332871,2911165193,1387346491,2776808933


long p1=93,p2=41;
long mod1=1e9+7,mod2=1628175011;

vector<long> hash1[N],hash2[N];
vector<long> prime1,inv_prime1,prime2,inv_prime2;

void calc_power(long p,long mod,vector<long> &prime,vector<long> &prime_inv)
{
  prime.resize(N);
  prime_inv.resize(N);
  cons=mod;
  prime[0]=1;
  prime_inv[0]=1;
  long pinv=exp(p,mod-2);
  for(int i=1;i<N;i++)
  {
    prime[i]=check(prime[i-1]*p);
    prime_inv[i]=check(prime_inv[i-1]*pinv);
  }
}

void calc_hash(long mod,string &s,vector<long> &hash,vector<long> &prime)
{
  int x=s.length();
  hash.resize(x);
  cons=mod;
  long sum=0;
  for(int i=0;i<x;i++)
  {
    sum=check(sum+s[i]*prime[i]);
    hash[i]=sum;
  }
}

long get_pref(long mod,int j,int len,vector<long> &inv,vector<long> &hash)
{
  cons=mod;
  long prefix=hash[j+len-1];
  if(j)
    prefix-=hash[j-1];
  prefix=check2(prefix);
  prefix=check(prefix*inv[j]);
  return prefix;
}


