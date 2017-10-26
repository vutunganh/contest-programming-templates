#include "../template.cpp"

#define MM 2
void mul(ll A[MM][MM], ll B[MM][MM], ll R[MM][MM], ll W, ll MD)
{
  F(W) FF(W) R[i][j] = 0;
  F(W) FF(W) FFF(W) R[i][j] += A[i][k]*B[k][j],R[i][j]%=MD;
}

void pw(ll M[MM][MM], ll R[MM][MM], ll W, ll k, ll MD)
{
  static ll E[MM][MM], H[MM][MM];
  F(W) FF(W) R[i][j] = E[i][j] = i == j;
  while (k)
  {
    if (k & 1)mul(E,M,R,W,MD), memcpy(E,R,sizeof(E));
    mul(M,M,H,W,MD);
    memcpy(M, H, sizeof(H));
    k >>= 1;
  }
}

// T(n) = a * T(n - 1)+ b * T(n - 2) + T(0) = Z, T(1) = C
ll MA[2][2], MR[2][2];
ll bar(ll a, ll b, ll Z, ll C, ll n, ll MD = 1)
{
  if (n < 2) return n ? C : Z;
  MA[0][0] = a;
  MA[0][1] = b;
  MA[1][0] = 1;
  MA[1][1] = 0;
  pw(MA, MR, 2, n-1, MD);
  return MR[0][0] * C + MR[0][1] * Z;
}
