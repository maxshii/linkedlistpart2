/*
This is the .h file for node.cpp

By: Kushal Rao

Last Modified: 1/11/22
*/

//Imports
#include <iostream>
#include "student.h"

using namespace std;

class Node{
 public:
  //define all methods
  Node(Student* student);
  ~Node();
  Student* getStudent();
  void setNext(Node* newNext);
  Node* getNext();
  //Intialize the student and next node pointers
  Student* s;
  Node* next;
};