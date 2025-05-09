#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    virtual double calculatePayment() {
        return 0.0;
    }
};

class Student : public Person {
public:
    Student(string n, int a) : Person(n, a) {}
    void displayDetails() override {
        cout << "Student - ";
        Person::displayDetails();
    }
};

class UndergraduateStudent : public Student {
    string major;
    string expectedGradDate;
public:
    UndergraduateStudent(string n, int a, string m, string d) 
        : Student(n, a), major(m), expectedGradDate(d) {}

    void displayDetails() override {
        Student::displayDetails();
        cout << "Major: " << major << endl;
        cout << "Expected Graduation Date: " << expectedGradDate << endl;
    }
};

class GraduateStudent : public Student {
    string thesisTitle;
    string researchTopic;
public:
    GraduateStudent(string n, int a, string thesis, string topic) 
        : Student(n, a), thesisTitle(thesis), researchTopic(topic) {}

    void displayDetails() override {
        Student::displayDetails();
        cout << "Thesis Title: " << thesisTitle << endl;
        cout << "Research Topic: " << researchTopic << endl;
    }

    double calculatePayment() override {
        return 1200.0; // Updated amount
    }
};

// Professor class inherits from Person
class Professor : public Person {
protected:
    double baseSalary;
public:
    Professor(string n, int a, double salary) 
        : Person(n, a), baseSalary(salary) {}

    void displayDetails() override {
        cout << "Professor - ";
        Person::displayDetails();
    }

    double calculatePayment() override {
        return baseSalary;
    }
};

class AssistantProfessor : public Professor {
public:
    AssistantProfessor(string n, int a, double salary) 
        : Professor(n, a, salary) {}

    double calculatePayment() override {
        return baseSalary + 250; // Slightly increased
    }
};

class Classroom {
public:
    string roomNumber;
    Classroom(string n) : roomNumber(n) {}

    void displayDetails() const {
        cout << "Classroom: " << roomNumber << endl;
    }
};

class Schedule {
public:
    string time;
    string day;

    Schedule(string t, string d) : time(t), day(d) {}

    void displayDetails() const {
        cout << "Time: " << time << ", Day: " << day << endl;
    }
};

class Course : public Classroom {
    string professor;
public:
    Course(string p, string n) : professor(p), Classroom(n) {}

    void displayDetails() const {
        cout << "Professor: " << professor << ", Room Number: " << roomNumber << endl;
    }
};

// Main function to test
int main() {
    UndergraduateStudent u("Nia Kapoor", 20, "Electrical Engineering", "05-15-2027");
    GraduateStudent g("Ravi Desai", 25, "Neural Networks in Robotics", "Machine Learning Applications");
    AssistantProfessor p("Dr. Meera Shah", 38, 52000);

    cout << "\n--- Undergraduate Student ---" << endl;
    u.displayDetails();

    cout << "\n--- Graduate Student ---" << endl;
    g.displayDetails();
    cout << "Payment: " << g.calculatePayment() << endl;

    cout << "\n--- Assistant Professor ---" << endl;
    p.displayDetails();
    cout << "Payment: " << p.calculatePayment() << endl;

    return 0;
}
