#include "include/classes.hpp"

<<<<<<< HEAD
=======

>>>>>>> 124293a3fc1897d18a2328163e4ac3108a716b4f
Student::Student(int id, std::string name, std::vector<double> grades)
{
    this->id = id;
    this->name = name;
    this->grades = grades;
    calculateAverage();
}

int Student::getId()
{
    return this->id;
}

std::string Student::getName() const
{
    return this->name;
}

 std::vector<double> Student::getGrades() const
{
    return this->grades;
}

double Student::getAverage() const
{
    return this->average;
}

bool Student::hasFailed()
{
    return this->average < 5.0;
}

std::ostream& operator<<(std::ostream& out, const Student& student)
{
    out << "ID: " << student.id << "\n" << "Name: " << student.name << "\n" << "Grades: [ ";

    for(double i : student.grades)
    {
        out << i << " ";
    }

    out << "]\n" << "Average: " << student.average << "\n";

    return out;
}

int main(void)
{
    Faculty acs("ACS", { Student(1,"John Doe", {7.0, 5.0, 9.9}), Student(2,"Jane doe", {4.5, 6.0, 1.0})});

    acs.printPassingStudents();
    acs.printFailingStudents();
    std::cout << acs;

    return 0;
}
