#include "../template.h"

// Computes distance between 2 points on sphere
// Each point: pair{lat,lon} in RADIANS

double dist(pair<double,double> a, pair<double,double> b, double r) {
    long double d_lat=fabs(a.x-b.x),
        d_lon=fabs(a.y-b.y),
        d_ang=2*asin(sqrt(sin(d_lat/2)*sin(d_lat/2)+cos(a.x)*cos(b.x)*sin(d_lon/2)*sin(d_lon/    2)));
    return r*d_ang;
}