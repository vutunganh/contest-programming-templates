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

ld eps(ld x){return x*EPS;}
ld cross(Pt a,Pt b){return a.x*b.y-a.y*b.x;}
ld cross(Pt a,Pt b,Pt c){
  Pt ab=b-a;
  Pt ac=c-a;
  return ab.x*ac.y-ab.y*ac.x;
}
// zakladni operace
ld dot(Pt a,Pt b){return a.x*b.x+a.y*b.y;}
ld rdist(Pt a){return sqrt(dot(a,a));}
ld angle(Pt a,Pt b){return acos(dot(a,b)/rdist(a)/rdist(b));}
ld angle(Pt v){return atan2(v.y,v.x);} // uhel od x-ove osy
Pt normal(Pt a){ // jednotkova kolmice
  ld n=rdist(a);
  return {-a.y/n,a.x/n};
}
Pt toLen(Pt v,ld l){return v*l/rdist(v);} // natazeni vektoru na delku l
Pt fromPolar(ld len,ld ang){return {len*cos(ang),len*sin(ang)};}
Pt rotate(Pt a,ld ang){return {a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad)};}
ld toRad(ld deg){return deg/180*M_PI;}
// vzdalenosti
ld ptptd(const Pt& p,const Pt& q){return sqrt(dot(q-p));}
ld lnptd(const Ln& l,const Pt& p){return fabs(cross(l.a,l.b,p)/ptptd(p.a,p.b));}
// printeni
ostream& operator<<(ostream& os,Pt &p){
  os<<"["<<p.x<<","<<p.y<<"]";
  return os;
}
ostream& operator<<(ostream& os,Ln &l){
  os<<l.a<<","<<l.b;
  return os;
}
