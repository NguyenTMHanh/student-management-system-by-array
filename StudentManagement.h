#include <iostream>
#include "Student.h"
using namespace std;

class studentManagement
{
    int maxSize;
    int currentSize;
    Student *studentArray;

public:
    studentManagement(int maxSize = 0, int currentSize = 0);
    studentManagement(const Student studentArray[], int size);
    ~studentManagement();
    friend istream &operator >> (istream &in, studentManagement &studentManagement);
    friend ostream &operator << (ostream &out, const studentManagement &studentManagement);
    void addStudent ();
};