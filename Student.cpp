#include <iostream>
#include <iomanip>
#include "Student.h"
using namespace std;
// hàm dựng mặc định
Student::Student(string id, string name, string className,
                 string facultyName, string sex, float mathScore, float englishScore,
                 float literatureScore) : id(id), name(name), className(className),
                                          facultyName(facultyName), sex(sex), mathScore(mathScore), englishScore(englishScore),
                                          literatureScore(literatureScore)
{
    averageScore = (mathScore + englishScore + literatureScore) / 3;
    academicPerformance = getAcademicPerformance(averageScore);
}

// hàm xét học lực của 1 sinh viên
string Student::getAcademicPerformance(float averageScore)
{
    if (averageScore >= 8.5)
    {
        return "Gioi";
    }
    else if (averageScore >= 7)
    {
        return "Kha";
    }
    else if (averageScore >= 5)
    {
        return "Trung Binh";
    }
    else
    {
        return "Yeu";
    }
}

// hàm dựng sao chép
Student::Student(const Student &student)
{
    this->id = student.id;
    this->name = student.name;
    this->className = student.className;
    this->facultyName = student.facultyName;
    this->sex = student.sex;
    this->mathScore = student.mathScore;
    this->englishScore = student.englishScore;
    this->literatureScore = student.literatureScore;
    this->averageScore = student.averageScore;
    this->academicPerformance = student.academicPerformance;
}

// hàm hủy
Student::~Student()
{
}

// hàm nhập thông tin một sinh viên
istream &operator>>(istream &in, Student &student)
{
    cout << "nhap id: ";
    in >> student.id;
    cout << "nhap ten: ";
    getline(in >> std::ws, student.name);
    cout << "nhap lop: ";
    in >> student.className;
    cout << "nhap khoa: ";
    in >> student.facultyName;
    cout << "nhap gioi tinh: ";
    in >> student.sex;
    cout << "nhap diem toan: ";
    in >> student.mathScore;
    cout << "nhap diem anh: ";
    in >> student.englishScore;
    cout << "nhap diem van: ";
    in >> student.literatureScore;
    student.averageScore = student.caculateGPA();
    student.academicPerformance = student.getAcademicPerformance(student.averageScore);
    return in;
}

// hàm xuất thông tin một sinh viên
ostream &operator<<(ostream &out, Student &student)
{
    out << left << setw(15) << student.id
        << setw(30) << student.name
        << setw(10) << student.className
        << setw(10) << student.facultyName
        << setw(15) << student.sex
        << setw(10) << fixed << setprecision(2) << student.mathScore
        << setw(10) << fixed << setprecision(2) << student.englishScore
        << setw(10) << fixed << setprecision(2) << student.literatureScore
        << setw(10) << fixed << setprecision(2) << student.averageScore
        << setw(10) << student.academicPerformance
        << endl;
    return out;
}

// hàm tính điểm trung bình của một sinh viên
float Student::caculateGPA()
{
    return (this->mathScore + this->englishScore + this->literatureScore) / 3;
}

//hàm trả về mã số sinh viên của 1 sinh viên
string Student::getIdStudent(){
    return this->id;
}