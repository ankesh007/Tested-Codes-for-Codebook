// BIT with range updates, inspired by Petr Mitrichev
struct BIT {
    int n;
    vector<int> slope;
    vector<int> intercept;
    // BIT can be thought of as having entries f[1], ..., f[n]
    // which are 0-initialized
    BIT(int n): n(n), slope(n+1), intercept(n+1) {}
    // returns f[1] + ... + f[idx-1]
    // precondition idx <= n+1
    int query(int idx) {
        int m = 0, b = 0;
        for (int i = idx-1; i > 0; i -= i&-i) {
            m += slope[i];
            b += intercept[i];
        }
        return m*idx + b;
    }
    // adds amt to f[i] for i in [idx1, idx2)
    // precondition 1 <= idx1 <= idx2 <= n+1 (you can't update element 0)
    void update(int idx1, int idx2, int amt) {
        for (int i = idx1; i <= n; i += i&-i) {
            slope[i] += amt;
            intercept[i] -= idx1*amt;
        }
        for (int i = idx2; i <= n; i += i&-i) {
            slope[i] -= amt;
            intercept[i] += idx2*amt;
        }
    }
};
update(ft, p, v):
  for (; p <= N; p += p&(-p))
    ft[p] += v 	 

# Add v to A[a...b] 
update(a, b, v): 	
  update(B1, a, v) 	
  update(B1, b + 1, -v) 	
  update(B2, a, v * (a-1)) 	
  update(B2, b + 1, -v * b) 	 

query(ft, b): 	
  sum = 0 	
  for(; b > 0; b -= b&(-b))
    sum += ft[b]
  return sum

# Return sum A[1...b]
query(b):
  return query(B1, b) * b - query(B2, b)

# Return sum A[a...b]
query(a, b):
return query(b) - query(a-1)