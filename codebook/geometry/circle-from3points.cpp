#include "../template.cpp"
using pt = pair<double,double>;

pair<pt,double> circle(pt a, pt b, pt c)
{
    pt center;
    double bx = a.x; double by = a.y;
    double cx = b.x; double cy = b.y;
    double dx = c.x; double dy = c.y;
    double temp = cx*cx+cy*cy;
    double bc = (bx*bx + by*by - temp)/2.0;
    double cd = (temp - dx*dx - dy*dy)/2.0;
    double det = (bx-cx)*(cy-dy)-(cx-dx)*(by-cy);
    if (fabs(det) < 1e-6) { 
        // TODO: points are in line, return middle point of most distant
        return {center,-1};
    }
    det = 1/det;
    center.x = (bc*(cy-dy)-cd*(by-cy))*det;
    center.y = ((bx-cx)*cd-(cx-dx)*bc)*det;
    cx = center.x; cy = center.y;
    double radius = sqrt((cx-bx)*(cx-bx)+(cy-by)*(cy-by));
    return {center,radius};
}

int main() {
    pt a={5,-2}, b={-4,2}, c={0,-5};
    auto ret=circle(a,b,c);
    dbg(ret.x.x, ret.x.y, ret.y);
    
    a={-1,0}, b={0,0}, c={1,0};
    ret=circle(a,b,c);
    dbg(ret.x.x, ret.x.y, ret.y);
    return 0;
}
