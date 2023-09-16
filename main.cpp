/**
 * @file main.cpp
 * @author Jesse Warren
 * @date 2023-09-16
 * @brief The main function.
 * 
 * Calls both Vector.h and Vector.cpp and executes the code both hold.
 */

#include "Vector.h"
#include <iostream>

using namespace std;

int main() {

  Vector myV;

  cout << "Do you wish to do the automated 1000 integer test? (y or n): ";
  char answer; cin >> answer; cout << endl;

  /*If the response is yes, 1000 integers are placed within the 'vector' via push_back, then copied over via myV2 and displayed to the user.
  Test 1.*/
  if(answer == 'y'){
     
    for(int i = 1; i <= 1000; i++){
      myV.push_back(i);
    }

    //Test 4 and use of copy constructor, test 5.
    Vector myV2 = myV;

    cout << "Displaying Vector: " << endl;
    for(int x = 0; x <= 1000; x++){
      cout << "Vector[" << x << "] = " << myV2[x] << endl;
    }
    return 0;
  }

  //If the respond is no, it will let the user make and test the vector.
  else if(answer == 'n'){
    cout << "How many numbers do you wish to use in this vector? ";
    int size; cin >> size; cout << endl;

    int numbers[size];

    if(size <= 0){
      cout << "You must pick a number greater than 0." << endl;
      return 0;
    }

    //Uses a basic array that will hold the user's inputs.
    for(int x = 0; x < size; x++){
      cout << "Enter a number: ";
      cin >> numbers[x]; cout << endl;
    }

    //Pushes the user's inputs into the dynamic 'vector' array.
    for(int y = 0; y < size; y++){
      myV.push_back(numbers[y]);
    }

    cout << "What position do you wish to replace? ";
    int replacement; cin >> replacement; cout << endl;

    if(replacement >= size){
      cout << "The position cannot be the same or larger than size." << endl;
      return 0;
    }

    cout << "What do you wish to replace it with? ";
    int replacenum; cin >> replacenum; cout << endl;

    //Testing copy constructor. Test 5 and the use of the '=' operator function, test 4.
    Vector myV2 = myV;

    //Replaces the selected position with a user-inputted one.
    //Using brackets to modify. Test 2.
    myV2[replacement] = replacenum;

    cout << "Size: " << myV2.size() << endl;
    cout << "Capacity: " << myV2.capacity() << endl;

    
    int vectorsize = myV2.size();

    //Testing size based bounds. Test 3, and using brackets to access, Test 2.
    for (int z = 0; z < vectorsize; z++){
      cout << endl << "Vector[" << z << "] = " << myV2[z] << endl;
    }
  }
  return 0;
}
