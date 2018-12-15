struct point{
	int x, y;
	point(int _x = 0, int _y = 0){
		x = _x, y = _y;
	}
	friend bool operator < (point a, point b){
		return (a.x == b.x) ? (a.y < b.y) : (a.x < b.x);
	}
};
point pt[2*Max], hull[2*Max];
//Here idx is the new length of the hull
int idx=0,cur;
inline long area(point a, point b, point c){
	return (b.x - a.x) * 1LL * (c.y - a.y) - (b.y - a.y) * 1LL * (c.x - a.x);
}
inline long dist(point a, point b){
	return (a.x - b.x) * 1LL * (a.x - b.x) + (a.y - b.y) * 1LL * (a.y - b.y);
}
inline bool is_right(point a, point b){
	int dx = (b.x - a.x);
	int dy = (b.y - a.y);
	return (dx > 0) || (dx == 0 && dy > 0);
}
inline bool compare(point b, point c){
	long det = area(pt[1], b, c);
	if(det == 0){
		
		if(is_right(pt[1], b) != is_right(pt[1], c))
			return is_right(pt[1], b);
		return (dist(pt[1], b) < dist(pt[1], c));
	}
	return (det > 0);
}
void convexHull(){
	int min_x = pt[1].x, min_y = pt[1].y, min_idx = 1;
	for(int i = 2; i <= cur; i++){
		if(pt[i].y < min_y || (pt[i].y == min_y && pt[i].x < min_x)){
			min_x = pt[i].x;
			min_y = pt[i].y;
			min_idx = i;
		}
	}
	swap(pt[1], pt[min_idx]);
	sort(pt + 2, pt + 1 + cur, compare);
	idx = 2;
	hull[1] = pt[1], hull[2] = pt[2];
	for(int i = 3 ; i <= cur ; i++){
		while(idx>=2 && (area(hull[idx - 1], hull[idx], pt[i]) <= 0)) idx-- ;
		hull[++idx] = pt[i] ;
	}
}