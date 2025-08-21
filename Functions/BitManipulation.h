#ifndef BIT_FUNCTIONS
#define BIT_FUNCTIONS


template<class IntegerType> inline IntegerType IntWithSetBit(const int x)
{ return IntegerType(1) << x; }

template<class IntegerType> inline bool IsBitSet(const IntegerType & x, const int y)
{ return x & IntWithSetBit<IntegerType>(y); }

template<class IntegerType> inline bool SetBit(IntegerType & x, const int y)
{ return x |= IntWithSetBit<IntegerType>(y); }



#endif