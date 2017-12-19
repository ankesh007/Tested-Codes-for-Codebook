ArtPt(v){
	color[v] = gray;
	Low[v] = d[v] = ++time;
	for all w in Adj(v) do {
		if (color[w] == white){
			pred[w] = v;
			ArtPt(w) ;
			if (pred [v] == NULL) {
				if ('w' is v''s second child) output v;
			}
			else if (Low[w] >= d[v]) output v;
			Low[v] = min(Low[v], Low[w]);
		}
		else if (w != pred[v]){ 
			Low[v] = min(Low[v], d[w]);
		}
	}
	color[v] = black;
}