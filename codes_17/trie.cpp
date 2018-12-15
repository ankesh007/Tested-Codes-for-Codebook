struct node{
	int ind;
	node *arr[26] ;
};
node* getnode(int ind){
	node *temp=new node() ;
	temp->ind=ind ;
	for(int i=0;i<26;i++)
		temp->arr[i]=NULL ;
	return temp ;
}
void insert(node *root,string &s,int pos){
	int x=(s.length()) ;
	for(int i=0;i<x;i++){
		int ch=s[i]-97 ;
		if(root->arr[ch]==NULL)
			root->arr[ch]=getnode(pos) ;
		root=root->arr[ch] ;
	}
}