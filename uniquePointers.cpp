#include <iostream>
using namespace std;

template <typename dataType>
class uniquePointer{
private:
  dataType *pointer;

public:
  uniquePointer(){
    pointer = nullptr;
  }

  uniquePointer(dataType* value){
    pointer = value;
  }

  uniquePointer(uniquePointer<dataType> && src){
    if(this != &src){
      pointer = src.pointer;
      delete src.pointer;
    }
  }

  ~uniquePointer(){
    if(pointer != nullptr){
      delete pointer;
    }
  }

  dataType & operator*(){
    return *pointer;
  }

  dataType * operator->(){
    return pointer;
  }

  dataType * get(){
    return pointer;
  }

  dataType * release(){
    dataType *newPointer = pointer;
    delete pointer;
    return newPointer;
  }

  void reset(){
    delete pointer;
  }

  void swap(uniquePointer<dataType> & other){
    dataType *tmp = pointer;
    pointer = other.pointer;
    other.pointer = tmp;
  }

  uniquePointer<dataType> & operator=(uniquePointer<dataType> & src){
    if(this != &src){
      pointer = src.pointer;
      src.pointer = 0;
      return *this;
    }
    return *this;
  }
};

int main(){
  uniquePointer<int> p(new int);
  uniquePointer<int> q(new int);
  *p = 14;
  cout << p.get() << endl;
  cout << *p << endl;
  cout << q.get() << endl;
  cout << *q << endl;
  q = p;
  cout << q.get() << endl;
  //cout << *p << endl;
  cout << p.get() << endl;
  cout << *q << endl;
  return 0;
}
