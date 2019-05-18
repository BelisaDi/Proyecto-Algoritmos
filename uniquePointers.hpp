/*
Creado por Jhan Carlos Celi e Isabella Martínez
Última actualización: 17/05/2019
*/

#ifndef _uniquePointers_hpp
#define _uniquePointers_hpp

#include <iostream>
using namespace std;

/*
Clase que recrea el Unique Pointer.
*/
template <typename dataType>
class uniquePointer{
private:
  /*
  Puntero al tipo de dato.
  */
  dataType *pointer;

public:
  /*
  Constructor por defecto.
  */
  uniquePointer();
  /*
  Constructor parametrizado.
  Deja al puntero apuntando a value.
  */
  uniquePointer(dataType *value);
  /*
  Constructor move.
  Arrebata la propiedad del elemento al que apuntaba
  src, dejando a src en nullptr.
  */
  uniquePointer(uniquePointer<dataType> && src);
  /*
  Destructor, borra el contenido al que apunta
  pointer.
  */
  ~uniquePointer();

  /*
  Función que retorna el puntero.
  */
  dataType * get() const;
  /*
  Función que libera la propiedad del objeto administrado
  por pointer, retornando un puntero al objeto o nullptr
  si no hay objeto.
  */
  dataType * release();
  /*
  Función que resetea a pointer, borrando el objeto que
  manejaba y reemplazándolo con nullptr.
  */
  void reset();
  /*
  Función que intercambia la propiedad del objeto manejado
  por pointer con el objeto manejado por other.
  */
  void swap(uniquePointer<dataType> & other);
  /*
  Sobrecarga de operador * para Unique Pointer.
  */
  dataType & operator*();
  /*
  Sobrecarga de operador -> para Unique Pointer.
  */
  dataType * operator->();
  /*
  Sobrecarga de operador = para Unique Pointer.
  Arrebata la posesión del objeto manejado por
  src, dejando al pointer de src en nullptr.
  */
  uniquePointer<dataType> & operator=(uniquePointer<dataType> & src);
};

#include "uniquePointers.cpp"
#endif //_uniquePointers_hpp
