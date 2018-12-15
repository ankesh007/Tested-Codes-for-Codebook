vector<int> manacher(const string &str){
	int n = str.size();
	vector<int> M(n,1);
	int R = 2; int C = 1;
	for(int i=1 ; i<n ; i++){
		int len = 0;
		if(i<R) len = min(manacher[2*C-i],R-i);
		if(i+len==R){
			while(i>=len && str[i-len]==str[i+len]){
				C = i;
				len++; R++;
			}
		}
		M[i] = len;
	}
	return M;
}