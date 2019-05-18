#ifdef _uniquePointers_hpp

template <typename dataType>
uniquePointer<dataType>::uniquePointer(){
  pointer = nullptr;
}

template <typename dataType>
uniquePointer<dataType>::uniquePointer(dataType* value){
  pointer = value;
}

template <typename dataType>
uniquePointer<dataType>::uniquePointer(uniquePointer<dataType> && src){
  if(this != &src){
    pointer = src.pointer;
    delete src.pointer;
  }
}

template <typename dataType>
uniquePointer<dataType>::~uniquePointer(){
  if(pointer != nullptr){
    delete pointer;
  }
}

template <typename dataType>
dataType & uniquePointer<dataType>::operator*(){
  return *pointer;
}

template <typename dataType>
dataType * uniquePointer<dataType>::operator->(){
  return pointer;
}

template <typename dataType>
dataType * uniquePointer<dataType>::get() const{
  if(pointer != nullptr){
    return pointer;
  }
  else{
    return nullptr;
  }
}

template <typename dataType>
dataType * uniquePointer<dataType>::release(){
  if(pointer != nullptr){
    dataType * nPointer = pointer;
    pointer = nullptr;
    return nPointer;
  }
  else{
    return nullptr;
  }
}

template <typename dataType>
void uniquePointer<dataType>::reset(){
  if(pointer != nullptr){
    delete pointer;
    pointer = nullptr;
  }
}

template <typename dataType>
void uniquePointer<dataType>::swap(uniquePointer<dataType> & other){
  dataType *tmp = pointer;
  pointer = other.pointer;
  other.pointer = tmp;
}

template <typename dataType>
uniquePointer<dataType> & uniquePointer<dataType>::operator=(uniquePointer<dataType> & src){
  if(this != &src){
    if(pointer != nullptr){
      delete pointer;
    }
    pointer = src.pointer;
    src.pointer = nullptr;
    return *this;
  }
  return *this;
}

#endif //_uniquePointers_hpp
