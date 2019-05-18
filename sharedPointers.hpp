/*
Creado por Jhan Carlos Celi e Isabella Martínez
Última actualización: 17/05/2019
*/

#ifndef _sharedPointers_hpp_
#define _sharedPointers_hpp_

#include <iostream>
using namespace std;

/*
Clase que recrea el Shared Pointer.
*/
template <typename dataType>
class sharedPointer{
private:
  /*
  Puntero al tipo de dato.
  */
  dataType *pointer;
  /*
  Entero sin signo que lleva el
  conteo de referencia de la cantidad
  de punteros apuntando a un objeto.
  */
  unsigned int ref_count;

public:
  /*
  Constructor por defecto.
  */
  sharedPointer();
  /*
  Constructor parametrizado.
  Deja al puntero apuntando a value.
  */
  sharedPointer(dataType *value);
  /*
  Constructor copia.
  Deja a pointer apuntando al mismo objeto que
  maneja src, aumentando el conteo de referencia.
  */
  sharedPointer(const sharedPointer<dataType> & src);
  /*
  Destructor, borra el contenido al que apunta
  pointer si el conteo de referencia llega a 0.
  */
  ~sharedPointer();

  /*
  Función que retorna el puntero.
  */
  dataType * get() const;
  /*
  Función que deja a pointer en nullptr. Si el conteo
  de referencia llega a 0, elimina el contenido al que
  apuntaba.
  */
  void reset();
  /*
  Función que intercambia la propiedad del objeto manejado
  por pointer con el objeto manejado por other, asi como
  sus conteos de referencia.
  */
  void swap(sharedPointer<dataType> & other);

  /*
  Sobrecarga de operador * para Shared Pointer.
  */
  dataType & operator*();
  /*
  Sobrecarga de operador -> para Shared Pointer.
  */
  dataType * operator->();
  /*
  Sobrecarga de operador = para Shared Pointer.
  Deja a pointer apuntando al objeto que maneja el pointer
  de src. Aumenta el conteo de referencia.
  */
  sharedPointer<dataType> & operator=(const sharedPointer<dataType> & src);
};

#include "sharedPointers.cpp"
#endif //_sharedPointers_hpp_s
