vector<int> Z_algo(const string &str){
	int n = str.size();
	vector<int> Z(n,0);
	int L=0,R=0;
	for(int i=1 ; i<n ; i++)
		if(i>R){
			L=i; R=i;
			while(R<n && str[R]==str[R-L]) R++;
			R--; Z[i] = (R-L+1);
		}else{
			int j = i-L;
			if(Z[j]<(R-i+1)) Z[i] = Z[j];
			else{
				L=i;
				while(R<n && str[R]==str[R-L]) R++;
				R--; Z[i] = (R-L+1); 
			}
		}
	return Z;
}