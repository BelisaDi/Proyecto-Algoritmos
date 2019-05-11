#include "uniquePointers.hpp"
#include "sharedPointers.hpp"
#include <iostream>
using namespace std;

class Human{
private:
  int age;
public:
  Human(){
    age = 10;
  }

  Human(int edad){
    age = edad;
  }

  void Shout(){
    cout << "AHHHHHHHHHHHHHH" << endl;
  }
};

int main(){
 uniquePointer<Human> myhuman;
 myhuman->Shout();
 return 0;
}
