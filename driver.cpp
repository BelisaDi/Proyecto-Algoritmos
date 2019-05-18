#include "uniquePointers.hpp"
#include "sharedPointers.hpp"
#include <iostream>
#include <string>
using namespace std;

class Human{
private:
  int age;
  string name;
public:
  Human(){
    age = 0;
    name = "No name";
  }

  Human(int edad, string nombre){
    age = edad;
    name = nombre;
  }

  ~Human(){
   cout << "Destructor invoked." << endl;
  }

  void Shout(){
    cout << "AHHHHHHHHHHHHHH" << endl;
  }

  int edad(){
    return age;
  }

  string nombre(){
    return name;
  }
};

int main(){

  //Creating some humans
  Human *h = new Human(15, "Marcos");
  Human *h2 = new Human(20, "Juan");

  //Creating some pointers
  uniquePointer<Human> myhuman(h);
  sharedPointer<Human> myotherhuman(h2);

  cout << "First Unique Pointer: " << endl;
  cout << "Memory direction: " << myhuman.get() << endl;
  myhuman->Shout();
  cout << myhuman->edad() << endl;
  cout << myhuman->nombre() << endl;
  cout << endl;

  cout << "Second Unique Pointer: " << endl;
  uniquePointer<Human> myhuman2;
  cout << "Default constructor: ";
  cout << "Memory direction: " << myhuman2.get() << endl;
  cout << "Assignation, ";
  myhuman2 = myhuman;
  cout << "Memory direction: " << myhuman2.get() << endl;
  myhuman2->Shout();
  cout << myhuman2->edad() << endl;
  cout << myhuman2->nombre() << endl;
  cout << endl;

  cout << "First Unique Pointer after assignation: " << endl;
  cout << "Memory direction: " << myhuman.get() << endl;
  cout << endl;


  cout << "Before swap: " << endl;
  cout << "First unique pointer memory direction: " << myhuman.get() << endl;
  cout << "Second unique pointer memory direction: " << myhuman2.get() << endl;
  cout << endl;
  myhuman2.swap(myhuman);
  cout << "After swap: " << endl;
  cout << "First unique pointer memory direction: " << myhuman.get() << endl;
  cout << "Second unique pointer memory direction: " << myhuman2.get() << endl;
  cout << endl;

  cout << "Reset of the First unique pointer: " << endl;
  myhuman.reset();
  cout << "Memory direction: " << myhuman.get() << endl;
  cout << endl;

  cout << "First Shared Pointer: " << endl;
  cout << "Memory direction: " << myotherhuman.get() << endl;
  myotherhuman->Shout();
  cout << myotherhuman->edad() << endl;
  cout << myotherhuman->nombre() << endl;
  cout << endl;

  cout << "Second Shared Pointer: " << endl;
  sharedPointer<Human> myotherhuman2;
  cout << "Default constructor: ";
  cout << "Memory direction: " << myotherhuman2.get() << endl;
  cout << "Assignation, ";
  myotherhuman2 = myotherhuman;
  cout << "Memory direction: " << myotherhuman2.get() << endl;
  myotherhuman2->Shout();
  cout << myotherhuman2->edad() << endl;
  cout << myotherhuman2->nombre() << endl;
  cout << endl;

  cout << "Reset of the First shared pointer: " << endl;
  myotherhuman.reset();
  cout << "Memory direction: " << myotherhuman.get() << endl;
  cout << endl;

  return 0;
}
