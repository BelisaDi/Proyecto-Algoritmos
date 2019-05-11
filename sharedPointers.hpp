#ifndef _sharedPointers_hpp_
#define _sharedPointers_hpp_

#include <iostream>
using namespace std;

template <typename dataType>
class sharedPointer{
private:
  dataType *pointer;
  unsigned int ref_count;

public:
  sharedPointer();
  sharedPointer(dataType *value);
  sharedPointer(const sharedPointer<dataType> & src);
  ~sharedPointer();

  dataType * get() const;
  void reset();
  void swap(sharedPointer<dataType> & other);

  dataType & operator*();
  dataType * operator->();
  sharedPointer<dataType> & operator=(const sharedPointer<dataType> & src);
};

#include "sharedPointers.cpp"
#endif //_sharedPointers_hpp_s
