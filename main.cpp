#include <iostream>
#include "node.h"
#include "student.h"
#include <iomanip>
#include <cstring>

using namespace::std;

void add(Node* &head, Node* previous, Node* current, Student *student);
void print(Node* head);
void del(Node* &head, Node* previous, Node* current, int id);
void avgGpa(Node* head);
int count(Node* head, int n);
float total(Node* head, float avg);

int main() {
  Node* head = NULL;
  Student* bob = new Student((char*)"Bob", (char*)"Dob", 123, 1);
  Student* joe = new Student((char*)"Joe", (char*)"Dob", 121, 2);
  Student* kanye = new Student((char*)"Kanye", (char*)"Dob", 122, 2);
  Student* rain = new Student((char*)"Rain", (char*)"Wong", 121, 0.3);

  add(head, head, head, bob);
  add(head, head, head, joe);
  add(head, head, head, kanye);
  add(head, head, head, rain);
  
  while(true) {
    char input[80];
    cout << "ADD, PRINT, DELETE, AVG, QUIT\n";
    cin.getline(input, 80);
    if (strcmp(input, "ADD")==0)
    {
      char first[80];
      char last[80];
      int id;
      float gpa;
      cout << "Enter first name: ";
      cin.getline(first, 80);
      cout << "Enter last name: ";
      cin.getline(last, 80);
      cout << "Enter id: ";
      cin >> id;
      cin.ignore();
      cout << "Enter gpa: ";
      cin >> gpa;
      cin.ignore();

      Student * a = new Student(first, last, id, gpa);
      add(head, head, head, a);
    }
    else if (strcmp(input, "PRINT") == 0)
    {
      print(head);
    }
    else if (strcmp(input, "DELETE") == 0)
    {
      int id = 0;
      cout << "Enter ID: ";
      cin >> id;
      cin.ignore();
      del(head, head, head, id);
    }
    else if (strcmp(input, "AVG") == 0)
    {
      avgGpa(head);
    }
    else if (strcmp(input, "QUIT") == 0)
    {
        break;   
    }
  }
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

//recursive function to delete
void del(Node* &head, Node* previous, Node* current, int id)
{
  if(head == NULL){
    cout<<"List is empty\n";
  }
  else if(head->s->id == id)
  {
    Node* temp = head;
    head = head->next;
    delete temp;
    del(head, head, head, id);
  }
  else if(current == NULL)
  {

  }
  else if(current->s->id == id)
  {
    previous->next = current->next;
    delete current;
    del(head, previous, previous->next, id);
  }
  else if(current->s->id != id)
  {
    del(head, current, current->next, id);
  }
  
}
void avgGpa(Node* head)
{
  cout << fixed << setprecision(2) << total(head, 0)/count(head,0)<<endl;
}

float total(Node* head, float avg)
{

  if(head != NULL)
  {
    avg = avg + total(head->next, head->s->gpa);
  }
  return avg;

}

int count(Node* head, int n)
{
  if(head == NULL)
  {
    return n;
  }
  else
  {
    count(head->next, n+1);
  }
}