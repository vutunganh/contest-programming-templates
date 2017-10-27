## Operator precedence (http://en.cppreference.com/w/cpp/language/operator_precedence)
- BITWISE operators have counter-intuitively very low priority
    - only logical &&,||, assigment and comma have lower!!!
    - relational <=,==,>= before bitwise &|^!
- arithmetical before all bitwise and logical
- ?:, &&, || are LAZY

## Bit operations
i & -i  // Least significant ONE bit
(x^y) < 0 // Numbers have different signs
i^(1<<j) // toggle jth bit
i&~(1<<j) // turn off jth bit
(v & (v - 1)) == 0; // is a power of 2


## Zabudované C++ operace
Všechny funkce přijímají unsigned long/long longy se suffixem l/ll;

// Population count: Returns the number of 1-bits in x.
int __builtin_popcount (unsigned int x); 

Parity (popcount modulo 2)
int __builtin_parity (unsigned int x)

// Returns the number of leading 0-bits in x, (from MSB position).
//  If x is 0, the result is UNDEFINED. 
int __builtin_clz (unsigned int x); 

// Returns one plus the index of the least significant 1-bit of x.
//  If x is zero, returns zero.
int __builtin_ffs (int x)

// Nearest higher power of 2: 
1ull << (sizeof(x)*8-__builtin_clz(x))

// Returns the number of trailing 0-bits in x, from LSB. 
//  If x is 0, the result is uNDEFINED.
int __builtin_ctz (unsigned int x)

// Returns the number of leading same bits
// i.e. the number of bits following the most significant bit that are identical to it.
// There are no special cases for 0 or other values.
int __builtin_clrsb (int x)

// reverse bits
uint8_t reverse_bits(uint8_t b) {
    return (b * 0x0202020202ULL & 0x010884422010ULL) % 1023; 
}

// ENDIANITY switch: Returns x with the order of the BYTES Reversed
uint64_t __builtin_bswap64 (uint64_t x)
