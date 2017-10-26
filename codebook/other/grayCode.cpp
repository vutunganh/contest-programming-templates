#include "../template.cpp"

// Gray code 
// = numeral system where two successive values differ in only one bit

ll g(ll n) { 
  return n ^ (n >> 1); 
}

ll gInv(ll g) {
	ll n=0;
	for (; g; g >>= 1)
	  n ^= g;
	return n;
}