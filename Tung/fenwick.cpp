#define MAX 1000001
int T[1000001]; // T[0] se nepouziva!!!

void add( int i, int delta )
{
  while( i < MAX ) T[ i ] += delta, i += ( i & -i );
}

int pref_sum( int i )
{
  int res = 0;
  while( i > 0 ) s += T[ i ], i = i & ( i - 1 );
  return res;
}
