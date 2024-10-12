#include <iostream>
#include "StudentManagement.h"
using namespace std;
class Student
{
    string id;
    string name;
    string className;
    string facultyName;
    string sex;
    float mathScore;
    float englishScore;
    float literatureScore;
    float averageScore;
    string academicPerformance;

public:
    Student(string id = "", string name = "", string className = "", 
    string facultyName = "", string sex ="", float mathScore = 0, float englishScore = 0, 
    float literatureScore = 0);
    string getAcademicPerformance(float averageScore);
    Student(const Student &student);
    ~Student();
    friend istream &operator >> (istream &in, Student &student);
    friend ostream &operator << (ostream &out, Student &student);
    friend bool studentManagement::indexOf(string id);
    friend void studentManagement::removeStudent(string id);
    friend void studentManagement::updateStudent(string id);
    friend int studentManagement::searchStudent(string id);
};