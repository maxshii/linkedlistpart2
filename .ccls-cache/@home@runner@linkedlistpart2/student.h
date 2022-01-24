#ifndef STUDENT_H
#define STUDENT_H

class Student {
  public:
    Student(char newfirst[80], char newlast[80], int newid, float newgpa);

    char first[80];
    char last[80];
    int id;
    float gpa;
};

#endif