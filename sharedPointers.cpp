#include <iostream>
using namespace std;

//CONTEO DE REFERENCIA
class counting{
private:
  size_t count;

public:
  counting(){
    count = 0;
  }

  void add(){
    count++;
  }
  size_t release(){
    return count--;
  }
};

//SHARED POINTERS
template <typename dataType>
class sharedPointer{
private:
  dataType *pointer;
  counting *reference;

public:
  sharedPointer(){
    pointer = nullptr;
    reference = new counting();
  }

  sharedPointer(dataType & value){
    pointer = &value;
    reference = new counting();
    reference->add();
  }

  sharedPointer(const sharedPointer<dataType> & src){
    pointer = src.pointer;
    reference = src.reference;
    reference->add();
  }

  ~sharedPointer(){
    if(reference->release() == 0){
      delete pointer;
      delete reference;
    }
  }

  dataType get(){
    return *pointer;
  }

  dataType & operator*(){
    return *pointer;
  }

  dataType * operator->(){
    return pointer;
  }

  sharedPointer<dataType> & operator=(const sharedPointer<dataType> & src){
    if(this != &src){
      if(reference->release() == 0){
        delete pointer;
        delete reference;
      }
      pointer = src.pointer;
      reference = src.reference;
      reference->add();
    }
    return *this;
  }
};

int main(){
  int x = 15;
  int y = 30;
  sharedPointer<int> entero(x);
  sharedPointer<int> entero2;
  entero2 = entero;
  cout << entero.get() << endl;
  cout << entero2.get() << endl;
  return 0;
}
