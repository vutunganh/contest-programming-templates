// Fenwick tree data structure (cummulative sums)
// ====
// log(n) get and inc

// Doesn't work with index 0!!!

const int MX = >>number of elements + 1<<;
typedef int T;

T ft[MX];

T get(int en) {
	T sum = T();
	for(;en; en -= en & -en) sum += ft[en];
	return sum;
}
T get(int st, int en) {
	return get(en) - get(st-1);
}

void inc(int i,T val) {
	for(;i < MX; i += i & -i) ft[i] += val;
}
