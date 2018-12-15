int m=0;
struct Trie{
	int chd[26];
	int cnt,mcnt,d=-1,p=-1,pch;
	int sLink = -1;
	Trie(int p,int pch,int d): cnt(0), mcnt(0), d(d), p(p), pch(pch){
		for(int i=0 ; i<26 ; i++) chd[i]=-1;
	}
};
const int N = 5e5;
Trie* nds[N];
void addVal(const string &str){
	int v=0;
	for(char chr : str){
		int idx = chr-'a';
		if(nds[v]->chd[idx]==-1){
			nds[v]->chd[idx] = m;
			nds[m++] = new Trie(v,idx,(nds[v]->d)+1);
		}
		v = nds[v]->chd[idx];
		nds[v]->cnt+=nds[v]->d;
	}
}
void AhoCorasick(){
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i=0 ; i<26 ; i++)
			if(nds[v]->chd[i]!=-1)
				q.push(nds[v]->chd[i]);
		if(nds[v]->p==0 || nds[v]->p==-1){
			nds[v]->sLink = 0;
			nds[v]->mcnt = nds[v]->cnt;
			continue;
		}
		int b = nds[v]->pch;
		int av = nds[nds[v]->p]->sLink;
		int nLink = 0;
		while(true){
			if(nds[av]->chd[b]!=-1){
				nLink = nds[av]->chd[b];
				break;
			}
			if(av == nds[av]->sLink) break;
			av = nds[av]->sLink;
		}
		nds[v]->sLink = nLink;
		nds[v]->mcnt = max(nds[v]->cnt,nds[nLink]->mcnt);
	}
}