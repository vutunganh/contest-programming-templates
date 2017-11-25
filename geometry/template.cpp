//#define M_PI 3.14159265358979323846

struct Pt{
  ld x,y;
  Pt(){}
  Pt(ld a,ld b) :x(a),y(b){}
  bool operator<(const Pt& o) const{
    return x<o.x||(x==o.x&&y<o.y);
    // return x<o.x+EPS||EQ(x,o.x)&&y<o.y+EPS;
  }
  Pt operator+(const Pt& o) const{return {x+o.x,y+o.y};}
  Pt operator-(const Pt& o) const{return {x-o.x,y-o.y};}
  Pt operator*(ld d) const{return {x*d,y*d};}
  Pt operator/(ld d) const{return {x/d,y/d};}
  bool operator==(const Pt& o) const{return EQ(x-o.x,0)&&EQ(y-o.y,0);}
  bool operator!=(const Pt& o) const{return !(*this==b);}
};

struct Ln{
  Pt a,b;
  Ln(){}
  Ln(Pt p,Pt q) :a(p),b(q){}
  bool operator<(const Ln& l) const{ // podle uhlu
    Pt v=b-a,w=l.b-l.a;
    return atan2(v.y,v.x)<atan2(w.y,w.x); //+ EPS
  }
};
