/**
 * @file Vector.cpp
 * @author Jesse Warren
 * @date 2023-09-16
 * @brief Holds the code for the functions in Vector.h.
 * 
 * Using the function definitions within the 'Vector' class within Vector.h, this file holds the full operating functions.
 */

#include "Vector.h"
#include <iostream>
#include <fstream>

using namespace std;

Vector::Vector(){
  vec_ptr = NULL;
  vec_size = 0, vec_capacity = 0; 
}
  
Vector::Vector(const Vector &other){
  //Sets the variables equal to the ones in the default constructor, practically 'copying' it over using 'other'.
  vec_size = other.vec_size;
  vec_capacity = other.vec_capacity;
  vec_ptr = new int[vec_capacity];

  //Copies over the elements within the default constructor onto the new dynamic array that is based off capacity.
  for (int i = 0; i < vec_size; i++){ 
    vec_ptr[i] = other.vec_ptr[i];
  }
  
}

Vector::~Vector(){
  delete[] vec_ptr;
}

Vector& Vector::operator=(const Vector &other){
  if(this != &other) {
    //Similar to the copy constructor. Simply copies over data once more.
    vec_capacity = other.vec_capacity;
    vec_size = other.vec_size;
    vec_ptr = new int[vec_capacity]; 

    for (int i = 0; i < vec_size; i++){
      vec_ptr[i] = other.vec_ptr[i];
    }
  }
  
  return *this;
}

int Vector::size(){
  return vec_size;
}

int Vector::capacity(){
  return vec_capacity;
}

void Vector::push_back(int element){
  //Sets capacity to 1 in the beginning to avoid conflicts with multiplying 0 by 2.
  if(vec_capacity == 0){
    reserve(1);
  }
  //If size equals capacity, capacity is multiplied by two to accommodate new data. 
  else if(vec_size == vec_capacity){
    reserve(vec_capacity * 2);
  }

  //If the size hasn't yet reached the capacity, it will add the element to the array.
  vec_ptr[vec_size++] = element;
}

void Vector::reserve(int n){
  int* temp_ptr;
  if(n > vec_capacity){
    //if 'n' is larger than capacity, a temporary pointer is created that sets its capacity to that of n. Then, the size and data within it is copied over to the main array.
    temp_ptr = new int[n];  
    
    for(int i = 0; i < vec_size; i++){
      temp_ptr[i] = vec_ptr[i];
    }
      delete[] vec_ptr;
  }
  else if(n <= vec_capacity){
    //if n has not yet reached capacity, it will cease the function.
    throw;
  }

  vec_ptr = temp_ptr;
  vec_capacity = n;
}

int& Vector::operator[](unsigned int index){
  unsigned int size = vec_size;
  if (index >= size){
    //if index does not equal size, the function will cease.
    throw;
  }
  return vec_ptr[index];

}
