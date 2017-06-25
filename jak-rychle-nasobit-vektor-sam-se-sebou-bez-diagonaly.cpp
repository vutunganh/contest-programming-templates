/**
 * Dejte tomu, ze mame ( a0,..., an ) a chceme 
 * sum( a0 * a1 + ... + a0 * an + a1 * a2 + ... ).
 * Ozn. S = a0 + ... + an.
 * Pak si = ai * S - ai * ai.
 * Ozn. vysledek V = sum( i = 0 -> n, si ) / 2. 
 * ctverecek
 */

int main( void )
{
  vector< int > V;

  int S = 0;
  for( size_t i = 0; i < V.size( ); ++i )
    S += V[ i ];

  int sum = 0;
  for( size_t i = 0; i < V.size( ); ++i )
    sum += S - V[ i ] * V[ i ];

  sum >>= 1;
  return 0;
}
