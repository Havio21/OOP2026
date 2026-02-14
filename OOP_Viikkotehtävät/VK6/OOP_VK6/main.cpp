#include <iostream>
#include "student.h"
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int selection =0;
    vector<Student>studentList;

    string name;
    int age;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            // Lisää uusi student StudentList vektoriin.
            cout << "Enter new student's name: ";
            cin >> name;

            cout << "Enter new student's age: ";
            cin >> age;

            studentList.push_back(Student(name, age));
            cout << "New student added: Name " << name << " Age: " << age << endl;
            break;
        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden
            // nimet.
            cout << "All registered students: " << endl;
            for (Student &s : studentList)
            {
                s.printStudentInfo();
            }
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            cout << "Sorting students by name: " << endl;

            std::sort(studentList.begin(), studentList.end(), [](Student &a, Student &b)
            {
                return a.getName() < b.getName();
            });

            for (Student &s : studentList)
            {
                s.printStudentInfo();
            }
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            cout << "Sorting students by age: " << endl;

            std::sort(studentList.begin(), studentList.end(), [](Student &a, Student &b)
                      {
                          return a.getAge() < b.getAge();
                      });

            for (Student &s : studentList)
            {
                s.printStudentInfo();
            }
            break;
        case 4:
        {
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            cout << "Input a student's name: ";
            cin >> name;

            auto it = find_if(studentList.begin(), studentList.end(), [name](Student &s)
            {
                return s.getName() == name;
            });

            if (it != studentList.end())
            {
                cout << "Student's information: " << endl;
                it->printStudentInfo();
            }
            else
            {
                cout << "Error! Student by the name" << name << " not found!" << endl;
            }
            break;  }

        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    }

    while(selection < 5);

    return 0;
}


