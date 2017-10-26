// Bellman–Ford Algorithm
// shortest paths from src to all vertices in the given graph
// directed, weighted, allowed negative

// O(VE)

#include <limits>
#include <vector>
#define REP(i,a,b) for(int i=a;i<b;i++)
using namespace std;

struct TEdge {
	int a, b, w;
};
int d[107];
int p[107];
bool cyc[107];

int n; // num of verticles
vector<TEdge> edges;

// calculates d 	= dist from 0.th verticle
// 		  and p 	= prev - path to start
// 		  and cyc == true if one can get there from some negative cycle
void bellford() {
	REP(i,n) d[i] = numeric_limits<int>::max();
	d[0] = 0; p[0] = -1;
	CL(cyc, 0);
	REP(i,n-1) {
		for (auto e : edges) {
			if (d[e.b] > d[e.a] + e.w) {
				// d[e.b] = min(d[e.b], d[e.a] + e.w); // relax
				p[e.b] = e.a;
				d[e.b] = d[e.a] + e.w;
			}
		}
	}
	for (auto e : edges) {
		if (d[e.a] + e.w < d[e.b]) {
			cyc[e.b] = true;
			// detected negative cycle
		}
	}

	// Handy addition: propagates cycle into whole graph - answers: can i get to finish using neg cycle?
	REP(i,0,n-1) {
		for (auto e : edges) {
			if (cyc[e.a]) cyc[e.b] = 1;
		}
	}
}