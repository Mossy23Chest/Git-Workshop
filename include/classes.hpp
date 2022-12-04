#include "libs.hpp"

using namespace std;

class Student
{
    private:
        int id;
        std::string name;
        std::vector<double> grades;
        double average;

    public:
        Student(int id, std::string name, std::vector<double> grades);

        int getId();
<<<<<<< HEAD:include/classes.hpp
         std::string getName() const;
         std::vector<double> getGrades() const ;
        std::vector<std::string> getCourse() const;
        double getAverage() const;

        void calculateAverage()
        {

             double s = 0, k=0;

             for(double i : grades)
            {

                s = s + i;
                k++;
            }


            average = s/k;

        }
=======
        std::string getName();
        std::vector<double> getGrades();
        double getAverage();
        
        void calculateAverage(){
        
        	double s=0, k=0;
        	
        	for(double i : grades)
        	{
        		s=s+i;
        		k++;
        	}
        	
        	average = s/k;
        	
        	
        };
>>>>>>> 124293a3fc1897d18a2328163e4ac3108a716b4f:include/classes.hpp
        bool hasFailed();

        friend std::ostream& operator<<(std::ostream& out, const Student& student);
};
<<<<<<< HEAD:include/classes.hpp
=======

>>>>>>> 124293a3fc1897d18a2328163e4ac3108a716b4f:include/classes.hpp

class University
{
    protected:
        std::string name;
        std::vector<Student> students;

    public:
        University(std::string name, std::vector<Student> students);

        std::string getName()  ;
        std::vector<Student> getStudents() ;

        void addStudent(Student student);
        virtual void printPassingStudents() = 0;
        virtual void printFailingStudents() = 0;
};

University::University(std::string name, std::vector<Student> students)
{
    this->name = name;
    this->students = students;
}

 std::string University::getName()
{
    return this->name;
}

 std::vector<Student> University::getStudents()
{
    return this->students;
}

void University::addStudent(Student student)
{
    this->students.push_back(student);
}

class Faculty : public University
{
    private:
        std::vector<std::string> courses = {"PC", "SDA", "POO", "SS", "TSA"};

    public:
        Faculty(std::string name, std::vector<Student> students);

        void addStudent(Student student);
        void printPassingStudents();
        void printFailingStudents();
        std::string getCourse(int i) const;

        friend std::ostream& operator<<(std::ostream& out, const Faculty& faculty);
};


std::string Faculty::getCourse(int i) const
{
    return this->courses[i];
}

Faculty::Faculty(std::string name, std::vector<Student> students):University{name, students}{


};

void Faculty::addStudent(Student student)
{
    this->students.push_back(student);
}

void Faculty::printPassingStudents()
{
    std::cout << "Passing students: " << std::endl;
    for (Student student : this->students)
    {
        if (!student.hasFailed())
        {
            std::cout << student << std::endl;
        }
    }
}

void Faculty::printFailingStudents()
{
    std::cout << "Failing students: " << std::endl;
    for (Student student : this->students)
    {
        if (student.hasFailed())
        {
            std::cout << student << std::endl;
        }
    }
}

std::ostream& operator<<(std::ostream& out, const Faculty& faculty)
{
    out << "Name: " << faculty.name << std::endl;
    out << "Students: " << std::endl;

    for(int i = 0; i < faculty.students.size(); i++)
    {
        out << faculty.students.at(i) << "\n\t";
        int k=0;
        for(double j : faculty.students.at(i).getGrades())
        {
            string message = (j < 5) ? " a picat materia " : " a trecut materia ";
            out << "Studentul " << faculty.students.at(i).getName() << message<<faculty.getCourse(k) <<"\n";
            k++;
        }
    }

    return out;
}
