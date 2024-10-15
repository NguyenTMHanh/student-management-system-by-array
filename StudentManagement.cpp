#include <iostream>
#include "Student.h"
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

    // mảng addStudentArray chứa danh sách sinh viên bạn muốn thêm vào
    Student *addStudentArray = new Student[addSize];
    for (int i = 0; i < addSize; i++)
    {
        cout << "\nNHAP THONG TIN SINH VIEN THEM VAO THU " << i + 1 << ": " << endl;
        cin >> addStudentArray[i];
    }

    // mảng studentArrayTemp là mảng tạm để chứa danh sách sinh viên ban đầu
    Student *originalStudentArray = new Student[this->currentSize];
    for (int i = 0; i < this->currentSize; i++)
    {
        originalStudentArray[i] = this->studentArray[i];
    }
    delete[] this->studentArray;

    // cập nhật lại kích thước tối đa của mảng chứa danh sách sinh viên và cấp phát lại một danh sách sinh viên mới = danh sách ban đầu + danh sách thêm
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

// hàm kiểm tra xem một mã số sinh viên bất kỳ có tồn tại không
bool studentManagement::indexOf(string id)
{
    for (int i = 0; i < this->currentSize; i++)
    {
        if (this->studentArray[i].id == id)
        {
            return true;
        }
    }
    return false;
}

// hàm xóa một sinh viên theo id
void studentManagement::removeStudent(string id)
{
    if (indexOf(id))
    {
        for (int i = 0; i < this->currentSize; i++)
        {
            if (this->studentArray[i].id == id)
            {
                for (int j = i; j < this->currentSize - 1; j++)
                {
                    this->studentArray[j] = this->studentArray[j + 1];
                }
                this->currentSize--;
                break;
            }
        }
    }
    else
    {
        cout << "khong ton tai ma so sinh vien cua sinh vien ma ban muon xoa" << endl;
    }
}

// hàm tìm kiếm sinh viên theo id và trả về vị trí của sinh viên đó
int studentManagement::searchStudent(string id)
{
    if (indexOf(id))
    {
        for (int i = 0; i < this->currentSize; i++)
        {
            if (this->studentArray[i].id == id)
            {
                return i;
            }
        }
        return -1;
    }
    else
    {
        return -1;
    }
}

// hàm cập nhật thông tin sinh viên theo id
void studentManagement::updateStudent(string id)
{
    int index = searchStudent(id);
    if (index != -1)
    {
         cout << "ban muon cap nhat thong tin gi cua sinh vien co ma so " << id << "?" << endl;
        cout << "1. Ho va ten" << endl;
        cout << "2. Lop" << endl;
        cout << "3. Khoa" << endl;
        cout << "4. Gioi tinh" << endl;
        cout << "5. Diem Toan" << endl;
        cout << "6. Diem Tieng anh" << endl;
        cout << "7. Diem Van" << endl;
        cout << "8. Cap nhat tat ca thong tin cua sinh vien" << endl;
        int chose;
        cout << "Hay nhap lua chon cua ban: ";
        cin >> chose;
        switch (chose)
        {
        case 1:
            cout << "Nhap ten: ";
            getline(cin>>std::ws, this->studentArray[index].name);
            break;
        case 2:
            cout << "Nhap lop: ";
            cin >> this->studentArray[index].className;
            break;
        case 3:
            cout << "nhap khoa: ";
            cin >> this->studentArray[index].facultyName;
            break;
        case 4:
            cout << "Nhap gioi tinh:";
            cin >> this->studentArray[index].sex;
            break;
        case 5:
            cout << "Nhap diem Toan: ";
            cin >> this->studentArray[index].mathScore;
            this->studentArray[index].averageScore = (this->studentArray[index].mathScore + this->studentArray[index].englishScore + this->studentArray[index].literatureScore) / 3;
            this->studentArray[index].academicPerformance = this->studentArray[index].getAcademicPerformance(this->studentArray[index].averageScore);
            break;
        case 6:
            cout << "Nhap diem Tieng anh: ";
            cin >> this->studentArray[index].englishScore;
            this->studentArray[index].averageScore = (this->studentArray[index].mathScore + this->studentArray[index].englishScore + this->studentArray[index].literatureScore) / 3;
            this->studentArray[index].academicPerformance = this->studentArray[index].getAcademicPerformance(this->studentArray[index].averageScore);
            break;
        case 7:
            cout << "Nhap diem Van: ";
            cin >> this->studentArray[index].literatureScore;
            this->studentArray[index].averageScore = (this->studentArray[index].mathScore + this->studentArray[index].englishScore + this->studentArray[index].literatureScore) / 3;
            this->studentArray[index].academicPerformance = this->studentArray[index].getAcademicPerformance(this->studentArray[index].averageScore);
            break;
        case 8:
            cin>>this->studentArray[index];
            break;
        default:
            break;
        }
    }
    else{
        cout<<"khong tim thay sinh vien co ma so sinh vien "<<id<<" trong danh sach"<<endl;
    }
}