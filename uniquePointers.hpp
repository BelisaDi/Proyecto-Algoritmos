#ifndef _uniquePointers_hpp
#define _uniquePointers_hpp

#include <iostream>
using namespace std;

template <typename dataType>
class uniquePointer{
private:
  dataType *pointer;

public:
  uniquePointer();
  uniquePointer(dataType *value);
  uniquePointer(uniquePointer<dataType> && src);
  ~uniquePointer();

  dataType * get() const;
  dataType * release();
  void reset();
  void swap(uniquePointer<dataType> & other);

  dataType & operator*();
  dataType * operator->();
  uniquePointer<dataType> & operator=(uniquePointer<dataType> & src);
};

#include "uniquePointers.cpp"
#endif //_uniquePointers_hpp
