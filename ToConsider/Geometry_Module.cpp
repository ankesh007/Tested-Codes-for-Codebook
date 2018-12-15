const ld EPS = 1e-12;
struct PT{
	ld x,y,z;
	PT(ld x=0,ld y=0,ld z=0): x(x),y(y),z(z){}
	bool operator<(const PT &t){ return make_tuple(x,y,z)<make_tuple(t.x,t.y,t.z); }
	bool operator==(const PT &t){ return make_tuple(x,y,z)==make_tuple(t.x,t.y,t.z); }
	PT operator+(const PT &t){ return PT(x+t.x,y+t.y,z+t.z); }
	PT operator-(const PT &t){ return PT(x-t.x,y-t.y,z-t.z); }
	PT operator*(const ld &d){ return PT(x*d,y*d,z*d); }
	PT operator/(const ld &d){ return PT(x/d,y/d,z/d); }
	ld norm2(){ return (x*x + y*y + z*z); }
	ld norm(){ return sqrtl(norm2()); }
};
PT cross(const PT &p,const PT &q){
	return PT(p.y*q.z - p.z*q.y, p.z*q.x - p.x*q.z, p.x*q.y - p.y*q.x);
}
ld dot(const PT &p, const PT &q){
	return (p.x*q.x + p.y*q.y + p.z*q.z);
}
// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p){ return PT(-p.y,p.x); }
PT RotateCW90(PT p){ return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) { 
	return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}
// project point c onto line segment through a and b
// if the projection doesn't lie on the segment, returns closest vertex
PT ProjectPointSegment(PT a, PT b, PT c) {
	double r = dot(b-a,b-a);
	if(fabs(r)<EPS) return a;
	r = dot(c-a,b-a)/r;
	if(r<0) return a;
	if(r>1) return b;
	return a+(b-a)*r;
}
// project point c onto line through a and b
// assuming a != b
PT ProjectPointLine(PT a, PT b, PT c) {
	return a + (b-a)*dot(c-a,b-a)/dot(b-a, b-a);
}
// determine if lines from a to b and c to d are parallel or collinear
bool LinesParallel(PT a, PT b, PT c, PT d) { 
	return fabs(cross(b-a, c-d)) < EPS; 
}
bool LinesCollinear(PT a, PT b, PT c, PT d) { 
	return LinesParallel(a, b, c, d)
	&& fabs(cross(a-b, a-c)) < EPS
    && fabs(cross(c-d, c-a)) < EPS; 
}
// determine if line segment from a to b intersects with 
// line segment from c to d
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
	if (LinesCollinear(a, b, c, d)) {
		if (dist2(a, c) < EPS || dist2(a, d) < EPS ||
			dist2(b, c) < EPS || dist2(b, d) < EPS) 
			return true;
		if (dot(c-a, c-b) > 0 && dot(d-a, d-b) > 0 && dot(c-b, d-b) > 0)
			return false;
		return true;
	}
	if (cross(d-a, b-a) * cross(c-a, b-a) > 0) return false;
	if (cross(a-c, d-c) * cross(b-c, d-c) > 0) return false;
	return true;
}
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
	b=b-a; d=c-d; c=c-a;
	assert(b.norm() > EPS && d.norm() > EPS);
	return (a + b*cross(c, d)/cross(b, d));
}
// determine if c and d are on same side of line passing through a and b
bool OnSameSide(PT a, PT b, PT c, PT d) {
  return (cross(c-a, c-b)*cross(d-a, d-b))>0;
}
PT ComputeCircleCenter(PT a, PT b, PT c) {
	b=(a+b)/2;
	c=(a+c)/2;
	return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}
vector<PT> CircleCircleIntersection(PT a, PT b, ld r, ld R) {
	vector<PT> ret;
	ld d = (a-b).norm();
	if (d>(r+R) || d+min(r,R) < max(r,R)) return ret;
	ld x = (d*d-R*R+r*r)/(2*d);
	ld y = sqrtl(r*r-x*x);
	PT v = (b-a)/d;
	ret.push_back(a+v*x + RotateCCW90(v)*y);
	if(y>0) ret.push_back(a+v*x - RotateCCW90(v)*y);
	return ret;
}
ld ComputeSignedArea(const vector<PT> &p) {
	ld area = 0;
	int n = p.size();
	for(int i=0 ; i<n ; i++) 
		area += cross(p[i],p[(i+1)%n]);
	return area/2.0;
}
ld ComputeArea(const vector<PT> &p) {
	return fabs(ComputeSignedArea(p));
}
bool IsSimple(const vector<PT> &p) {
	for (int i = 0; i < p.size(); i++) {
		for (int k = i+1; k < p.size(); k++) {
			int j = (i+1) % p.size(); int l = (k+1) % p.size();
			if (i == l || j == k) continue;
			if (SegmentsIntersect(p[i], p[j], p[k], p[l])) 
				return false;
		}
	}
	return true;
}
// determine if point is in a possibly non-convex polygon (by William
// Randolph Franklin); returns 1 for strictly interior points, 0 for
// strictly exterior points, and 0 or 1 for the remaining points.
// Note that it is possible to convert this into an *exact* test using
// integer arithmetic by taking care of the division appropriately
// (making sure to deal with signs properly) and then by writing exact
// tests for checking point on polygon boundary
bool PointInPolygon(const vector<PT> &p, PT q) {
	bool c = false;
	for (int i = 0; i < p.size(); i++){
	int j = (i+1)%p.size();
	bool test1 = (p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y);
	bool test2 = q.x < (p[i].x + (p[j].x - p[i].x)*((q.y - p[i].y)/(p[j].y - p[i].y)));
	if(test1 && test2) c = !c;
	return c;
}
// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p, PT q) {
	for (int i = 0; i < p.size(); i++)
		if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
			return true;
	return false;
}
struct Line{
	ld a,b,c;
	Line(ld a=0,ld b=0,ld c=0): a(a),b(b),c(c){}
};
pdd LineIntersection(const Line &l1,const Line &l2){
	ld a1 = l1.a; ld b1 = l1.b; ld c1 = l1.c;
	ld a2 = l2.a; ld b2 = l2.b; ld c2 = l2.c;
	ld det = (a1*b2 - a2*b1);
	assert(abs(det)>eps);
	ld x = (b1*c2 - b2*c1)/det; 
	ld y = (c1*a2 - c2*a1)/det;
	return mp(x,y);
}