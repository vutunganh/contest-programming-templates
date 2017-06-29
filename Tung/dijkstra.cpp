struct E
{
  int to;
  int w;

  bool operator<( const E& a ) const { return w < a.w };
}

int main( void )
{
  vector< int > D( n + 1, 1000000007 ); // distances
  vector< int > P( n + 1, - ); // parents, maybe unnecessary

  D[ s ] = 0; // start distance

  priority_queue< pair< int, int > > Q; /* first is vertex,
                                           second is distance of said vertex */

  Q.push( make_pair( s, D[ s ] ) );

  while( !Q.empty( ) )
  {
    auto v = Q.top( );
    Q.pop( );

    for( const auto& w : G[ v.first ] )
      if( D[ w.to ] > D[ v.first ] + w.w )
      {
        D[ w.to ] = D[ v.first ] + w.w; 
        P[ w.to ] = v.first;
        Q.push( make_pair( w.to, D[ w.to ] ) );
      }
  }

  return 0;
}
