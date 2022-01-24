/*
This is a bare bones class for a node that holds students

By: Kushal Rao

Last Modified: 1/11/22
*/

//Imports
#include <iostream>
#include "student.h"
#include "node.h"

using namespace std;

Node::Node(Student* student){//Set the node to hold a specific student
  s = student;
  next = NULL;
}

Node::~Node(){//Deletes the student
  delete s;
  next = NULL;
}

Student* Node::getStudent(){//Gets the student of this node
  return s;
}

void Node::setNext(Node* newNext){//Sets next node
  next = newNext;
}

Node* Node::getNext(){//Gets next node
  return next;
}