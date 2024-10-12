#include <iostream>
#include "studentManagement.h"
#include <iomanip>
using namespace std;

// hàm dựng mặc định
studentManagement::studentManagement(int maxSize, int currentSize) : maxSize(maxSize), currentSize(currentSize)
{
    this->studentArray = new Student[maxSize];
}

// hàm dựng sao chép
studentManagement::studentManagement(const Student studentArray[], int size)
{
    this->maxSize = size;
    this->currentSize = size;
    this->studentArray = new Student[maxSize];
    for (int i = 0; i < size; i++)
    {
        this->studentArray[i] = studentArray[i];
    }
}

// hàm hủy
studentManagement::~studentManagement()
{
    delete[] this->studentArray;
}

// hàm nhập một danh sách sinh viên
istream &operator>>(istream &in, studentManagement &studentManagement)
{
    for (int i = 0; i < studentManagement.currentSize; i++)
    {
        cout << "\nNHAP THONG TIN SINH VIEN THU " << i + 1 << ": " << endl;
        in >> studentManagement.studentArray[i];
    }
    return in;
}

// hàm xuất một danh sách sinh viên
ostream &operator<<(ostream &out, const studentManagement &studentManagement)
{
    cout<<"\n                                                        DANH SACH SINH VIEN                                "<<endl;
    out << left << setw(5) << "STT" << setw(15) << "ID" << setw(30) << "Ho va ten"
        << setw(10) << "Lop" << setw(10) << "Khoa" << setw(15) << "Gioi tinh" << setw(10) << "Toan"
        << setw(10) << "Anh" << setw(10) << "Van" << setw(10) << "Diem TB"
        << setw(10) << "Hoc luc" << endl;

    for (int i = 0; i < studentManagement.currentSize; i++)
    {
        out << setw(5) << i + 1 << studentManagement.studentArray[i];
    }
    return out;
}
