//Given an array of characters in arr and the length 
//of the array as n it simply finds the longest palindromic substring
//at each position with that position as the center of the palindrome.
// Array is 0-indexed
int[] Manacher(char c[],int n){
	int P[] = new int[n+1] ;
	int R=0,C=1 ;
	for(int i=1 ; i<=n ; i++){
		int rad=-1 ;
		if(i<=R)
			rad = min(P[2*C-i],(R-i)) ;
		else
			rad = 0 ;
		while((i+rad)<=n && (i-rad)>=1 && c[i-rad]==c[i+rad])
			rad++ ;
		P[i]=rad-1 ;
		if((i+rad)>R){
			C = i ;
			R = i+rad ; 
		}
	}
	return P ;
}