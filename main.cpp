#include <iostream>
#include "node.h"
#include "student.h"
#include <iomanip>

using namespace::std;

void add(Node* &head, Node* previous, Node* current, Student *student);
void print(Node* head);
void del(Node* &head, Node* previous, Node* current, int id);
float avgGpa(Node* head);

int main() {
  Node* head = NULL;
  Student* bob = new Student((char*)"Bob", (char*)"Dob", 123, 1);
  Student* joe = new Student((char*)"Joe", (char*)"Dob", 121, 2);
  Student* kanye = new Student((char*)"Kanye", (char*)"Dob", 122, 2);
  Student* rain = new Student((char*)"Rain", (char*)"Wong", 110, 0.3);

  add(head, head, head, bob);
  add(head, head, head, joe);
  add(head, head, head, kanye);
  add(head, head, head, rain);
  print (head);
}

//recursive function to add a node with a pointer to student to the linked list from lowest to highest id
void add(Node* &head, Node* previous, Node* current, Student* student)
{
  //nothing in the linked list
  if(head == NULL) //creates the new node and sets it to head
  {
    head = new Node(student);
  }
  //student's gpa is less than head
  else if (student->id < head->s->id) { //sets head to the new node sets the new node's next to the old head
    Node* temp = head;
    head = new Node(student);
    head->next = temp;
  }
  //at the end of the linked list
  else if (current == NULL) //sets the previous node's next to the new node
  { 
    previous->next = new Node(student);
  }
  //student's id is less than next node's
  else if (student->id < current->s->id)  //sets the previous node's next to the new node and sets the new node's next to current
  {
    previous->next = new Node(student);
    previous->next->next = current;
  }
  //student's id is greater than head/current's
  else 
  {
    add(head, current, current->next, student); //new previous is current, new current is current->next
  }

}

//recursive function to print linked list
void print(Node* head)
{
  if(head != NULL)
  {
    cout << head->s->first << " " << head->s->last << ", " << head->s->id << ", " << fixed << setprecision(2) << head->s->gpa << endl;
    print(head->next);
  }
  
}

void del(Node* &head, Node* previous, Node* current, int id)
{
  if(head == NULL){

  }
  else if(head->s->id == id)
  {
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  else if(current == NULL)
  {

  }
  else if(current->s->id == id)
  {
    previous->next = current->next;
    delete current;
  }
  else if(current->s->id != id)
  {
    del(head, current, current->next, id);
  }
  
}
