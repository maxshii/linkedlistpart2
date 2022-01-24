#include <cstring>
#include "student.h"

Student::Student(char newfirst[80], char newlast[80], int newid, float newgpa)
{
  strcpy(first, newfirst);
  strcpy(last, newlast);
  id = newid;
  gpa = newgpa;
}