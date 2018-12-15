class SegTree{
	vector<lli> base;
	vector<lli> seg;
	int n; lli IDEN;
private:
	inline lli merge(lli v1,lli v2){
		return min(v1,v2);
	}
	inline lli getArr(lli s){
		return base[s];
	}
	void build(int i,int s,int e){
		if(s==e){
			seg[i] = getArr(s); return;
		}
		int m = (s+e)/2;
		build(2*i,s,m); build(2*i+1,m+1,e);
		seg[i] = merge(seg[2*i],seg[2*i+1]);
	}
	void upd(int i,int s,int e,int x,lli val){
		if(x<s || x>e) return;
		if(s==e){
			seg[i] = val; return;
		}
		int m = (s+e)/2;
		upd(2*i,s,m,x,val); upd(2*i+1,m+1,e,x,val);
		seg[i] = merge(seg[2*i],seg[2*i+1]);
	}
	lli qry(int i,int s,int e,int l,int r){
		if(l<=s && e<=r) return seg[i];
		if(r<s || e<l) return IDEN;
		int m = (s+e)/2;
		return merge(qry(2*i,s,m,l,r), qry(2*i+1,m+1,e,l,r));
	}
public:
	void update(int x,lli val){ upd(1,1,n,x,val);} 
	lli query(int l,int r){ return qry(1,1,n,l,r);}
	SegTree(vector<lli> a, lli _n, lli _IDEN){
		base = a; n = _n; IDEN = _IDEN;
		seg.resize(5*n,0);
		build(1,1,n);
	}
};