## Operator precedence http://en.cppreference.com/w/cpp/language/operator_precedence
## Bit operations
i & -i  // Zeroes all bits except the least significant non-zero bit
(x^y) < 0 // Numbers have different signs
i^(1<<j) // toggle jth bit
i&~(1<<j) // turn off jth bit

## Zabudované C++ operace
//Všechny funkce přijímají unsigned long/long longy se suffixem l/ll;
int __builtin_popcount (unsigned int x); //Returns the number of 1-bits in x.
uint8_t reverse_bits(uint8_t b) { return (b * 0x0202020202ULL & 0x010884422010ULL) % 1023; }
int __builtin_clz (unsigned int x); //Returns the number of leading 0-bits in x, starting at the most significant bit (MSB) position. If x is 0, the result is undefined. 
// Usage: nearest higher power of 2: 1ULL << (sizeof(x)*8-__builtin_clz(x))
int __builtin_ffs (int x)
//Returns one plus the index of the least significant 1-bit of x, or if x is zero, returns zero.
int __builtin_ctz (unsigned int x)
//Returns the number of trailing 0-bits in x, starting at the least significant bit position. If x is 0, the result is undefined.
int __builtin_clrsb (int x)
//Returns the number of leading redundant sign bits in x, i.e. the number of bits following the most significant bit that are identical to it. There are no special cases for 0 or other values.
