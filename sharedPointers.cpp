#ifdef _sharedPointers_hpp_

template <typename dataType>
sharedPointer<dataType>::sharedPointer(){
  pointer = nullptr;
  ref_count = 0;
}

template <typename dataType>
sharedPointer<dataType>::sharedPointer(dataType *value){
  pointer = value;
  ref_count = 1;
}

template <typename dataType>
sharedPointer<dataType>::sharedPointer(const sharedPointer<dataType> & src){
  pointer = src.pointer;
  ref_count = src.ref_count;
  ref_count++;
}

template <typename dataType>
sharedPointer<dataType>::~sharedPointer(){
  if(pointer != nullptr){
    --ref_count;
    if(ref_count == 0){
      delete pointer;
    }
  }
}

template <typename dataType>
dataType * sharedPointer<dataType>::get() const{
  return pointer;
}

template <typename dataType>
void sharedPointer<dataType>::reset(){
  if(pointer != nullptr){
    --ref_count;
    if(ref_count == 0){
      delete pointer;
    }
    pointer = nullptr;
  }
}

template <typename dataType>
void sharedPointer<dataType>::swap(sharedPointer<dataType> & other){
  dataType *tmp = pointer;
  unsigned int tmp_ref = ref_count;
  pointer = other.pointer;
  ref_count = other.ref_count;
  other.pointer = tmp;
  other.ref_count = tmp_ref;
}

template <typename dataType>
dataType & sharedPointer<dataType>::operator*(){
  return *pointer;
}

template <typename dataType>
dataType * sharedPointer<dataType>::operator->(){
  return pointer;
}

template <typename dataType>
sharedPointer<dataType> & sharedPointer<dataType>::operator=(const sharedPointer<dataType> & src){
  if(this != &src){
    if((--ref_count) == 0){
      delete pointer;
    }
    pointer = src.pointer;
    ref_count = src.ref_count;
    ref_count++;
  }
  return *this;
}

#endif //_sharedPointers_hpp_
