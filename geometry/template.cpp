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
void abcln(const Ln& l,ld& a,ld& b,ld& c){ // prevod parametricke primky na normalni tvar
  a=l.b.y-l.a.y;
  b=l.b.x-l.a.x;
  c=a*l.a.x+b*l.a.y;
}
// zakladni operace
ld eps(ld x){return x*EPS;}
ld cross(Pt a,Pt b){return a.x*b.y-a.y*b.x;} // vektorovy soucin
ld cross(Pt a,Pt b,Pt c){ // vektorovy soucin AB x AC
  Pt ab=b-a;
  Pt ac=c-a;
  return ab.x*ac.y-ab.y*ac.x;
}
ld dot(Pt a,Pt b){return a.x*b.x+a.y*b.y;} // skalarni soucin
ld rdist(Pt a){return sqrt(dot(a,a));} // vzdalenost od pocatku
ld angle(Pt a,Pt b){return acos(dot(a,b)/rdist(a)/rdist(b));} // uhel svirany vektory a b
ld angle(Pt v){return atan2(v.y,v.x);} // uhel od x-ove osy
Pt normal(Pt a){ // jednotkova kolmice
  ld n=rdist(a);
  return {-a.y/n,a.x/n};
}
Pt toLen(Pt v,ld l){return v*l/rdist(v);} // natazeni vektoru na delku l
Pt fromPolar(ld len,ld ang){return {len*cos(ang),len*sin(ang)};}
Pt rotate(Pt a,ld ang){return {a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad)};} // rotace vektoru
ld toRad(ld deg){return deg/180*M_PI;}
// vzdalenosti
ld ptptd(const Pt& p,const Pt& q){return sqrt(dot(q-p));}
ld lnptd(const Ln& l,const Pt& p){return fabs(cross(l.a,l.b,p)/ptptd(p.a,p.b));}
// judge
bool lnlnparallel(const Ln& k,const Ln& l){
  ld ak,bk,ck,al,bl,cl;
  abcln(k,ak,bk,ck);
  abcln(l,al,bl,cl);
  return EQ(ak*bl-al*bk,0);
}
bool lnlnparallel2(const Ln& k,const Ln& l){
  Pt v=k.b-k.a;
  Pt w=l.b-l.a;
  return EQ(cross(v,w),0);
}
// pruseciky
Pt lnlnpt(const Ln& k,const Ln& l){
  Pt v=k.b-k.a;
  Pt w=l.b-l.a;
  ld t=cross(w,k.a-l.a)/cross(v,w);
  return k.a+v*t;
}
Pt lnptvert(const Ln& l,const Pt& p){return lnlnpt(l,{p,p+normal(p.b-p.a)});} // kolmy prumet
// konvexni obalka
vector<Pt> convex_hull(vector<Pt> p){
  vector<Pt> r(2*p.size()+14);
  ll K=0;
  sort(p.begin(),p.end());
  for(Pt e:p){
    while(K>=2&&cross(r[K-1]-r[K-2],e-r[K-2])<=0)K--;
    r[K++]=e;
  }
  for(ll i=p.size()-2,T=K+1;i>=0;i--){
    while(K>=T&&cross(r[K-1]-r[K-2],p[i]-r[K-2])<=0)K--;
    r[K++]=p[i];
  }
  r.resize(K);
  r.pop_back();
  return r;
}
// plocha polygonu
ld area(vector<Pt>& p){
  ld res=0;
  F(p.size())res+=cross(p[i],p[(i+1)%p.size()]);
  return fabs(res/2);
}
// printeni
ostream& operator<<(ostream& os,Pt &p){
  os<<"["<<p.x<<","<<p.y<<"]";
  return os;
}
ostream& operator<<(ostream& os,Ln &l){
  os<<l.a<<","<<l.b;
  return os;
}
