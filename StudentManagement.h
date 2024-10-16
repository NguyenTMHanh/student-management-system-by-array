#ifndef STUDENTMANAGEMENT_H 
#define STUDENTMANAGEMENT_H 

#include <iostream>
using namespace std;

class Student; 

class studentManagement {
    int maxSize;
    int currentSize;
    Student *studentArray;

public:
    studentManagement(int maxSize = 10, int currentSize = 0);
    studentManagement(const Student studentArray[], int size);
    ~studentManagement();
    void setMaxSize(int maxSize);
    void setStudentArray(int maxSize);
    friend istream &operator>>(istream &in, studentManagement &studentManagement);
    void readFile(ifstream &input);
    friend ostream &operator<<(ostream &out, const studentManagement &studentManagement);
    void writeFile(ofstream &output);
    void addStudentArray();
    bool indexOf(string id);
    void removeStudent(string id);
    void updateStudent(string id);
    int searchStudent(string id);
    void searchAndShowStudent();
    void sortStudentByGPA();
    void addStudent(Student &student);
};
void formatHeaderPrint();
#endif 
