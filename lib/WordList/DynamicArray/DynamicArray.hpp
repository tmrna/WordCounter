/*
 *
 * Rob Deans
 * Lab 2
 * 2/2/2023
 *
 * */
#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP

#define TTT template <typename T>

// current workaround, need to find out how to link properly

template <typename T>
class DynamicArray{

  private:
    T* array_;
    unsigned size_;
    unsigned upperBound_;
    
    void reAllocate();
    void cleanup();

  public:
    
    DynamicArray(unsigned size = 0): size_(size), upperBound_(2 * size_){array_ = size_ > 0 ? new T[upperBound_] : nullptr;} 
    ~DynamicArray();
    DynamicArray(const DynamicArray<T> &);

    DynamicArray<T>& operator=(const DynamicArray<T> &);

    unsigned size() const {return size_;}
    bool empty() const {return array_ == nullptr;}

    T operator[](int) const;
    T& operator[](int);

    bool operator==(const DynamicArray<T> &);


    void swap(int, int);

    void push(const T &);
    bool insert(int, const T &);
    bool remove(int);
};

//
//                      dtor
//---------------------------------------------------------------------------------
//

TTT
// dtor
DynamicArray<T>::~DynamicArray(){
  if(!empty()) delete[] array_;
}

//
//                      cpy ctor
//---------------------------------------------------------------------------------
//

TTT
// cpy ctor
DynamicArray<T>::DynamicArray(const DynamicArray<T> & rhs){
  size_ = rhs.size_;
  upperBound_ = rhs.upperBound_;
  array_ = new T[upperBound_];
  for(unsigned i = 0; i < size_; ++i){
    array_[i] = rhs[i];
  }
}

//
//                      overloaded assignment
//---------------------------------------------------------------------------------
//

TTT
// overloaded assignment
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> & rhs){
  if(&rhs == this) return *this;
  
  size_ = rhs.size_;
  upperBound_ = rhs.upperBound_;

  if(!empty()) delete[] array_;
  array_ = new T[upperBound_];

  for(unsigned i = 0; i < size_; ++i){
    array_[i] = rhs[i];
  }

  return *this;
}

//
//                          overloaded subscript operator 
//---------------------------------------------------------------------------------
//

TTT
// accessor
T DynamicArray<T>::operator[](int i) const{
  return array_[i];
}

TTT
// mutator
T& DynamicArray<T>::operator[](int i){
  return array_[i];
}


//                              equivalence
//---------------------------------------------------------------------------------
//

TTT
// checks if same size and if all elements within range are equal
bool DynamicArray<T>::operator==(const DynamicArray<T> & rhs){
  if(size_ != rhs.size_) return false;
  for(unsigned i = 0; i < size_; ++i){
    if(array_[i] != rhs[i]) return false;
  }
  return true;
}
//
//                          swap 
//---------------------------------------------------------------------------------
//

TTT
// swaps two elements at the given indicies
void DynamicArray<T>::swap(int first, int second){
  T tmp = array_[first];
  array_[first] = array_[second];
  array_[second] = tmp;
}

//                           re-allocation
//---------------------------------------------------------------------------------
//

TTT
// allocates size_ * 2 for memory. Used to extend and shrink the array
void DynamicArray<T>::reAllocate(){
  
  // check to see if the array is null
  if(empty()){
    upperBound_ = size_ * 2;
    array_ = new T[upperBound_];
  }

  // make a replacement
  else{
    upperBound_ = size_ * 2;
    T* supplement = new T[upperBound_];
    for(int i = 0; i < size_; ++i){
      supplement[i] = array_[i];
    }
    if(!empty()) delete[] array_;

    array_ = supplement;
  }
}

//                           re-allocation
//---------------------------------------------------------------------------------
//

TTT
// allocates / deallocates to save on space
void DynamicArray<T>::cleanup(){
  if(size_ == 0 && !empty()) delete[] array_;
  
  // choosing 4 here as upperBound_ is typically 2*size_ when we allocate.
  // we would have then shrunk back before the previous allocation.
  if(size_ >= upperBound_ || upperBound_ / 4 > size_) reAllocate();
}


//                          push
//---------------------------------------------------------------------------------
//

TTT
// places an element on the end of the array.
// if the array is full then extend
void DynamicArray<T>::push(const T & newElement){
  // increase size
  ++size_;
  // allocate mem if we need to
  if(size_ >= upperBound_) reAllocate();
  // place
  array_[size_ - 1] = newElement;
}

//                         insert 
//---------------------------------------------------------------------------------
//

TTT
// inserts an element at the given index, moves everything at that point and ahead forward
// returns if the operation was possible
bool DynamicArray<T>::insert(int index, const T & newElement){
  // check if we can perform the operation
  if(empty() || index < 0 || index >= size_) return false;

  // increase size to accomodate
  ++size_;
  // reallocate if need be
  cleanup();
  // shift
  for(int i = size_ - 1; i > index; --i){
    array_[i] = array_[i - 1];
  }
  // place
  array_[index] = newElement;
  return true;
}

//                         remove 
//---------------------------------------------------------------------------------
//

TTT
// removes an element at the given index, moves everything back
// returns if it was possible to perform the operation
bool DynamicArray<T>::remove(int index){
  
  // out of bounds
  if(index < 0 || index >= size_) return false;
  
  if(size_ != 0 && index < size_){
    // if we are removing our only element then just delete the array
    if(size_ == 1){
      --size_;
      reAllocate();
      return true;
    }

    // shift every point ahead of the index one step down
    else{
      --size_;
      for(int i = size_; i > index; --i){
        array_[i - 1] = array_[i];
      }
      cleanup();
      return true;
    }

  }
  return false;
}

#undef TTT
#endif
