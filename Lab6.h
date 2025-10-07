

#ifndef LAB6_H
#define LAB6_H
#include <Vector>
class Person {
private:
    int nationalID;
protected:
    string name;
    int age;
public:
    Person() {
        cout<<"Default constructor of Person is called"<<endl;
    }
Person(string name, int age, int id) {
this->name = name;
        this->age = age;
        nationalID = id;
        cout<<"Person is called"<<endl;
    }
    void setName(string name) {
        this->name = name;
    }
    void setAge(int age) {
        this->age = age;
    }
    void setID(int id) {
        nationalID = id;
    }
    void displayPerson() {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"ID: "<<nationalID<<endl;
    }
    ~Person() {
        cout<<"Person destructor is called"<<endl;
    }
};
class Student : virtual public Person {
protected:
    float gpa;
    public:
    Student() {
        cout<<"Default constructor of Student is called"<<endl;
    }
    Student(string name, int age, int id, float gpa):Person(name, age, id), gpa(gpa) {
       cout<<"Student constructor is called"<<endl;
    }
void setGPA(float gpa) {
        this->gpa = gpa;
    }
void displayStudent() {
        displayPerson();
        cout<<"GPA: "<<gpa<<endl;
    }
    ~Student() {
        cout<<"Student destructor is called"<<endl;
    }
};
class Teacher :virtual public Person {
private:
    string subject;
    public:
    Teacher() {
        cout<<"Default constructor of Teacher is called"<<endl;
    }
    Teacher(string name, int age, int id, string subject):Person(name, age, id), subject(subject) {
        cout<<"Teacher constructor is called"<<endl;
    }
    void setSubject(string subject) {
        this->subject = subject;
    }
    void showRole() {
        cout<<"I am a Teacher, Subject: "<<subject<<endl;
    }
    void displayTeacher() {
        displayPerson();
    cout<<"Subject: "<<subject<<endl;
    }
    ~Teacher() {
        cout<<"Teacher destructor is called"<<endl;
    }
};
class TeachingAssistant:public Student, public Teacher {
    int hoursPerWeek;
    public:
    TeachingAssistant() {
        cout<<"Default constructor of TeachingAssistant"<<endl;
    }
    TeachingAssistant(string name, int age, int id, float gpa, string subject, int hours):Teacher(name, age, id, subject), hoursPerWeek(hours) {
        setGPA(gpa);
    };
class Course{
private:
Teacher courseTeacher;
vector<Student *> students;
public:
Course(){
cout<<"Course constructor called\n";
}
~Course(){
cout<<"Course destructor called. Note: Aggregated students are NOT automoatically deleted!\n";
}
void setCourseTeacher(string name, int age, int id, string subject){
    courseTeacher.setname(name);
    courseTeacher.setage(age);
    courseTeacher.setID(id);
    courseTeacher.setSubject(subject);
}
void addStudent(Student *student){
    students.push_back(student);
}
void displayCourse(){
courseTeacher.displayTeacher();
    for(int i=0; i<students.size();i++){
    cout<<"----------------\n;
        students[i]->displayStudent();
    }
    
}
};



#endif //LAB6_H
