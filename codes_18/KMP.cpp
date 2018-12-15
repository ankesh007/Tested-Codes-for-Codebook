//Takes an array of characters and calculate
//lcp[i] where lcp[i] is the longest proper suffix of the 
//string c[0..i] such that it is also a prefix of the string.
vector<int> kmp(const string &str){
	int n = str.size();
	vector<int> lcp(n,0);
	for(int i=1 ; i<n ; i++){
		int j = lcp[i-1];
		while(j!=0 && str[i]!=str[j]) j = lcp[j-1];
		if(str[i]==str[j]) j++;
		lcp[i]=j;
	}
	return lcp;
}