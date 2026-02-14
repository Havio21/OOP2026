#include <iostream>
#include "student.h"

Student::Student(string n, int a)
{
    Name = n;
    Age = a;
}

void Student::setAge(int na)
{
    Age = na;
}

void Student::setName(int nn)
{
    Name = nn;
}

string Student::getName()
{
    return Name;
}

int Student::getAge()
{
    return Age;
}

void Student::printStudentInfo()
{
    cout << "Students name: " << Name << " " << "Students age: " << Age << endl;
}
