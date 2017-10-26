// uf needs to be initialized with sequence from 0 to n !!!
ll uf[MX];
void init() { F(MX) uf[i] = i; }
int find(int e) { return uf[e] == e ? e : uf[e] = find(uf[e]); }
void mrg(int i, int j) { uf[find(i)] = find(j); }
