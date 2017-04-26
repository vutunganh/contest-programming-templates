#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

const int MAX_ARR = 1e6 + 7;  // limit for array size
int n;  // array size
int t[2 * MAX_ARR];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify( int l, int r, int value )
{
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
  {
    if (l&1) t[l++] += value;
    if (r&1) t[--r] += value;
  }
}

int query( int p )
{
  int res = 0;
  for (p += n; p > 0; p >>= 1) res += t[p];
  return res;
}

int main( )
{
  int N, M;
  scanf( " %d %d %d", &N, &M, &n );
  build( );

  for( int i = 0; i < N; ++i )
  {
    int L, R;
    scanf( " %d %d", &L, &R );

    modify( L, R + 1, 1 );
  }

  for( int i = 0; i < M; ++i )
  {
    int Q;
    scanf( " %d", &Q );

    printf( "%d\n", query( Q ) );
  }
  return 0;
}
