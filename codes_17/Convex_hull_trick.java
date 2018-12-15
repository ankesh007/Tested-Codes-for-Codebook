mylist hull(mylist pts){
	int n = pts.size() ;		
	if(n<2) return pts ;		
	Collections.sort(pts,new Comparator<pair>(){
		public int compare(pair p1,pair p2){ 
			if(p1.x!=p2.x) return Double.compare(p1.x,p2.x) ;
			return Double.compare(p2.y,p1.y) ;
		}
	}) ;
	mylist h = new mylist() ;
	h.add(pts.get(0)) ; h.add(pts.get(1)) ;
	int idx=1 ;
	for(int i=2 ; i<n ; i++){
		pair p = pts.get(i) ;
		while(idx>0){
			if(isOriented(h.get(idx-1),h.get(idx),p))
				break ;
			else
				h.remove(idx--) ;
		}
		h.add(p) ;
		idx++ ;
	}
	while(idx>0 && h.get(idx).x==h.get(idx-1).x) h.remove(idx--) ;
	Collections.reverse(h) ;
	return h ;
}
public boolean isOriented(pair p1,pair p2,pair p3){
	double val = ((p2.y-p1.y)*(p3.x-p2.x))-((p2.x-p1.x)*(p3.y-p2.y)) ;		
	return val>=0 ;
}