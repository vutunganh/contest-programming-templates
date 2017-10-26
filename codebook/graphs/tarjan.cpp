#include "../template.cpp"
// Tarjan's strongly connected components algorithm
// O(|V|+|E|)

#define MX 201
ll D[MX], LO[MX], SC[MX]; // SC - ID komponent
stack<ll> ST;
bitset<MX> STA;
ll TI, SCC;
void tarjanR(vector<vll>& G, ll u)
{
  D[u] = LO[u] = TI++;
  ST.push(u);
  STA[u] = 1;
  F(G[u].size())
  {
    ll v = G[u][i];
    if (~D[v])
      tarjanR(G, v);
    if (~D[v] || STA[v])
      LO[u] = min(LO[u], LO[v]);
  }
  if (D[u] == LO[u])
  {
    ll v;
    do {
      v = ST.top();
      ST.pop();
      STA[v] = 0;
      SC[v] = SCC;
    } while (u != v);
    SCC++;
  }
}
void tarjan(vector<vll>& G, ll u)
{
  CL(D, -1);
  tarjanR(G, u);
}
