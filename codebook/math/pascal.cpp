#include "../template.cpp"

#define MX 1001
ll PT[MX][MX];
void pt()
{
  F(MX)
  {
    PT[i][0] = PT[i][i] = 1;
    FOR(k, 1, i) PT[i][k] = PT[i-1][k] + PT[i-1][k-1];
  }
}
