/**
 * @file Vector.h
 * @author Jesse Warren
 * @date 2023-09-16
 * @brief This file holds the 'Vector' class.
 * 
 * Holds every function that is used and called within Vector.cpp, along with every main variable.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
private:
  int *vec_ptr; //Pointer for the vector's dynamic array.
  int vec_size, vec_capacity; //The current size of the dynamic array, and the capacity it has. 

public:

  Vector();
  /* Description: 
   *    Default constructor that initializes an empty vector,
   *    and sets both size and capacity to zero.
   */

  Vector(const Vector &other);
  /* Description:
   *    Copy constructor that initializes a dynamic array of size
   *    and capacity, and copies data from the array within
   *	the default constructor onto the new array.
   */

  ~Vector();
  /* Description:
   *    Destructor that deallocates vec_ptr.
   */

  Vector& operator=(const Vector &other);
  /* Description:
   *    Assignment operator that initializes a dynamic array
   *    of size and capacity, and copies data from other's array
   *    to the new array.
   */
  
  int size();
  /* Description:
   *    Returns the current numbers of elements within the vector.
   */
 
  int capacity();
  /* Description:
   *    Returns currently allocated storage capacity of the vector.
   */

  void push_back(int element);
  /* Description:
   *    Stores elements at the end of the vector, similar to the way 
   *    pushback functions within the vector library. Will multiply the capacity 
   *    by two if conditions are met
   */
  
  void reserve(int n);
  /* Description:
   *    Requests that the capacity be resized enough to contain 'n' elements.
   *    Dependent on the size of the 'n' integer. 
   */

  int& operator[](unsigned int index);
  /* Description:
   *    Returns a reference to the element at position index.
   */



};

#endif 
