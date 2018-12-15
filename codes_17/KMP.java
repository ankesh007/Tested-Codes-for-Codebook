//Takes an array of characters and calculate
//lcp[i] where lcp[i] is the longest proper suffix of the 
//string c[0..i] such that it is also a prefix of the string.
int[] kmp(char c[],int n){
	int lcp[] = new int[n] ;
	for(int i=1 ; i<n ; i++){
		int j = lcp[i-1] ;
		while(j!=0 && c[i]!=c[j]) j = lcp[j-1] ;
		if(c[i]==c[j]) j++ ;
		lcp[i]=j ;
	}
	return lcp ;
}