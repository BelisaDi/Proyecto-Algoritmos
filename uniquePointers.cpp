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

  uniquePointer(dataType & value){
    pointer = &value;
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

  dataType get(){
    return *pointer;
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
      src.pointer = nullptr;
      return *this;
    }
  }
};

int main(){
  int x = 15;
  int y = 30;
  uniquePointer<int> entero(x);
  uniquePointer<int> enteroprima(*entero);
  cout << enteroprima.get() << endl;
  cout << entero.get() << endl;
  return 0;
}
