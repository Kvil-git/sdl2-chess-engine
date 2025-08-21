#ifndef BIT_FUNCTIONS
#define BIT_FUNCTIONS


#include <vector>


template<class IntegerType> inline IntegerType IntWithSetBit(const int x)
{ return IntegerType(1) << x; }

template<class IntegerType> inline bool IsBitSet(const IntegerType & x, const int y)
{ return x & IntWithSetBit<IntegerType>(y); }

template<class IntegerType> inline bool SetBit(IntegerType & x, const int y)
{ return x |= IntWithSetBit<IntegerType>(y); }


template<class IntegerType> inline std::vector<int> GetSetBitIndices(const IntegerType bitset) {
    std::vector<int> output;
    while (bitset != 0) {
        IntegerType t = bitset & -bitset;
        int index = __builtin_ctzl(bitset);
        
        bitset ^= t;
        output.push_back(index);
    }
}


#endif