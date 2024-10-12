#include<iostream>
#include "StudentManagement.h"
using namespace std;
int main(){
    int size;
    cout<<"nhap so luong sinh vien: "; cin>>size;
    studentManagement studentManagement(size, size);
    cin>>studentManagement;
    cout<<studentManagement;
    studentManagement.addStudent();
    cout<<studentManagement;
    return 0;
}