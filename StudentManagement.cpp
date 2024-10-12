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
    cout << "\n                                                        DANH SACH SINH VIEN                                " << endl;
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

// hàm thêm một sinh viên
void studentManagement::addStudent()
{
    int addSize;
    cout << "\nnhap so luong sinh vien ban muon them: ";
    cin >> addSize;

    //mảng addStudentArray chứa danh sách sinh viên bạn muốn thêm vào
    Student *addStudentArray = new Student[addSize];
    for (int i = 0; i < addSize; i++)
    {
        cout << "\nNHAP THONG TIN SINH VIEN THEM VAO THU " << i + 1 << ": " << endl;
        cin >> addStudentArray[i];
    }

    //mảng studentArrayTemp là mảng tạm để chứa danh sách sinh viên ban đầu
    Student *originalStudentArray = new Student[this->currentSize];
    for (int i = 0; i < this->currentSize; i++)
    {
        originalStudentArray[i] = this->studentArray[i];
    }
    delete[] this->studentArray;

    //cập nhật lại kích thước tối đa của mảng chứa danh sách sinh viên và cấp phát lại một danh sách sinh viên mới = danh sách ban đầu + danh sách thêm
    this->maxSize += addSize;
    this->studentArray = new Student[maxSize];
    for (int i = 0; i < this->currentSize; i++)
    {
        this->studentArray[i] = originalStudentArray[i];
    }
    delete[] originalStudentArray;
    for (int i = 0; i < addSize; i++)
    {
        this->studentArray[this->currentSize] = addStudentArray[i];
        this->currentSize++;
    }
    delete[] addStudentArray;
}