#include <iostream>
#include <deque>

int main( void )
{
  int Q;
  std::cin >> Q;
  std::string query;
  std::deque< int > d;
  bool frontIsFront = true;

  for( int i = 0; i < Q; ++i )
  {
    std::cin >> query;
    if( query == "back" )
    {
      if( d.empty( ) )
        std::cout << "No job for Ada?" << std::endl;
      else
      {
        if( frontIsFront )
        {
          std::cout << d.back( ) << std::endl;
          d.pop_back( );
        }
        else
        {
          std::cout << d.front( ) << std::endl;
          d.pop_front( );
        }
      }
    }

    if( query == "front" )
    {
      if( d.empty( ) )
        std::cout << "No job for Ada?" << std::endl;
      else
      {
        if( frontIsFront )
        {
          std::cout << d.front( ) << std::endl;
          d.pop_front( );
        }
        else
        {
          std::cout << d.back( ) << std::endl;
          d.pop_back( );
        }
      }
    }

    if( query == "reverse" )
    {
      frontIsFront = !frontIsFront;
    }

    if( query == "push_back" )
    {
      int n;
      std::cin >> n;

      if( frontIsFront )
        d.push_back( n );
      else
        d.push_front( n );
    }

    if( query == "toFront" )
    {
      int n;
      std::cin >> n;

      if( frontIsFront )
        d.push_front( n );
      else
        d.push_back( n );
    }
  }
}
