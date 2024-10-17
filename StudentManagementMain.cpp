#include <iostream>
#include <fstream>
#include "StudentManagement.h"
#include "Student.h"
using namespace std;
int main()
{
    studentManagement studentManagement;
    string id;
    int chose;
    int size;
    ifstream input;
    ofstream output;
    Student student;
    cout << "CHUONG TRINH QUAN LY SINH VIEN BANG MANG TRONG C++" << endl;
    cout << "1. Nhap danh sach sinh vien tu ban phim" << endl;
    cout << "2. Nhap danh sach sinh vien tu file input va hien thi ra console" << endl;
    cout << "3. Ghi danh sach sinh vien vao file output" << endl;
    cout << "4. Them mot mang danh sach sinh vien" << endl;
    cout << "5. Them mot sinh vien vao cuoi danh sach" << endl;
    cout << "6. Cap nhat thong tin sinh vien boi ID" << endl;
    cout << "7. Xoa sinh vien boi ID" << endl;
    cout << "8. Tim kiem sinh vien theo ID hoac theo ten" << endl;
    cout << "9. Sap xep danh sach sinh vien theo GPA" << endl;
    cout << "10. Hien thi danh sach sinh vien ra console" << endl;
    cout << "Nhap mot ky tu bat ky de thoat khoi chuong trinh" << endl;
    do
    {
        cout << "\nHay nhap lua chon cua ban: ";
        cin >> chose;
        switch (chose)
        {
        case 1:
            cout << "Nhap so luong sinh vien: ";
            cin >> size;
            studentManagement.setMaxSize(size);
            studentManagement.setStudentArray(size);
            cin >> studentManagement;
            break;
        case 2:
            studentManagement.readFile(input);
            break;
        case 3:
            studentManagement.writeFile(output);
            break;
        case 4:
            studentManagement.addStudentArray();
            break;
        case 5:
            cin >> student;
            studentManagement.addStudent(student);
            break;
        case 6:
            cout << "nhap mssv cua sinh vien muon cap nhat: ";
            cin >> id;
            studentManagement.updateStudent(id);
            break;
        case 7:
            cout << "nhap mssv cua sinh vien muon xoa: ";
            cin >> id;
            studentManagement.removeStudent(id);
            break;
        case 8:
            studentManagement.searchAndShowStudent();
            break;
        case 9:
            studentManagement.sortStudentByGPA();
            break;
        case 10:
            cout << studentManagement;
            break;
        default:
            break;
        }
    } while (chose > 0 && chose <= 10);
    return 0;
}