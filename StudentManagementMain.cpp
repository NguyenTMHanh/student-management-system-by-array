#include<iostream>
#include "StudentManagement.h"
using namespace std;
int main(){
    int size;
    string studentId;
    cout<<"nhap so luong sinh vien: "; cin>>size;
    studentManagement studentManagement(size, size);
    cin>>studentManagement;
    cout<<studentManagement;
    // studentManagement.addStudent();
    // cout<<studentManagement;
    // cout<<"\nnhap ma so sinh vien cua sinh vien ma ban muon xoa: "; cin>>studentId;
    // studentManagement.removeStudent(studentId);
    // cout<<studentManagement;
    // cout<<"\nnhap ma so sinh vien cua sinh vien ma ban muon cap nhat: "; cin>>studentId;
    // studentManagement.updateStudent(studentId);
    // cout<<studentManagement;
    studentManagement.searchAndShowStudent();
    return 0;
}