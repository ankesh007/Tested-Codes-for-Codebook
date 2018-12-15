const ld eps = 1e-8;
struct Triple{
	ld x,y,z;
	Triple(ld x=0,ld y=0,ld z=0): x(x),y(y),z(z){}
	bool operator<(const Triple &t){ return make_tuple(x,y,z)<make_tuple(t.x,t.y,t.z); }
	bool operator==(const Triple &t){ return make_tuple(x,y,z)==make_tuple(t.x,t.y,t.z); }
	Triple operator+(const Triple &t){ return Triple(x+t.x,y+t.y,z+t.z); }
	Triple operator-(const Triple &t){ return Triple(x-t.x,y-t.y,z-t.z); }
	Triple operator*(const ld &d){ return Triple(x*d,y*d,z*d); }
	Triple operator/(const ld &d){ return Triple(x/d,y/d,z/d); }
	ld norm2(){ return (x*x + y*y + z*z); }
	ld norm(){ return sqrtl(norm2()); }
};
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
Triple cross(const Triple &p,const Triple &q){
	return Triple(p.y*q.z - p.z*q.y, p.z*q.x - p.x*q.z, p.x*q.y - p.y*q.x);
}
ld dot(const Triple &p, const Triple &q){
	return (p.x*q.x + p.y*q.y + p.z*q.z);
}