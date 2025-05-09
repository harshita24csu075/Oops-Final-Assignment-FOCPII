#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int id;

    Student(string n, int i) {
        name = n;
        id = i;
    }
};

class Professor {
public:
    string name;
    int id;

    Professor(string n, int i) {
        name = n;
        id = i;
    }
};

class Course {
public:
    string title;
    int courseId;
    string professorName;
    vector<pair<string, int>> studentList;  // Pair of student name and ID

    Course(string t, int id) {
        title = t;
        courseId = id;
        professorName = "None";
    }

    void assignProfessor(string name) {
        professorName = name;
    }

    void enrollStudent(string name, int id) {
        studentList.push_back({name, id});
    }

    void displayCourse() {
        cout << "Course ID: " << courseId << " | Title: " << title << " | Professor: " << professorName << endl;
        cout << "Enrolled Students:" << endl;
        for (auto& s : studentList) {
            cout << " - " << s.first << " (ID: " << s.second << ")" << endl;  // Display student name and ID
        }
    }
};

class UniversitySystem {
private:
    vector<Student> students;
    vector<Professor> professors;
    vector<Course> courses;

public:
    void addStudent(string name, int id) {
        students.push_back(Student(name, id));
    }

    void addProfessor(string name, int id) {
        professors.push_back(Professor(name, id));
    }

    void addCourse(string title, int id) {
        courses.push_back(Course(title, id));
    }

    void enrollStudentInCourse(int studentId, int courseId) {
        string studentName = findStudentName(studentId);
        Course* course = findCourse(courseId);

        if (!studentName.empty() && course != nullptr) {
            course->enrollStudent(studentName, studentId);  // Enroll student with ID
        } else {
            cout << "Invalid student or course ID!" << endl;
        }
    }

    void assignProfessorToCourse(int profId, int courseId) {
        string profName = findProfessorName(profId);
        Course* course = findCourse(courseId);

        if (!profName.empty() && course != nullptr) {
            course->assignProfessor(profName);
        } else {
            cout << "Invalid professor or course ID!" << endl;
        }
    }

    void generateReport() {
        cout << "=== University Report ===" << endl;
        for (Course &c : courses) {
            c.displayCourse();
        }
    }

private:
    string findStudentName(int id) {
        for (Student &s : students) {
            if (s.id == id) return s.name;
        }
        return "";
    }

    string findProfessorName(int id) {
        for (Professor &p : professors) {
            if (p.id == id) return p.name;
        }
        return "";
    }

    Course* findCourse(int id) {
        for (Course &c : courses) {
            if (c.courseId == id) return &c;
        }
        return nullptr;
    }
};

// Main function
int main() {
    UniversitySystem uni;

    uni.addStudent("Ishaan Verma", 105);
    uni.addStudent("Riya Bansal", 109);
    uni.addProfessor("Prof. Meera Nair", 207);
    uni.addCourse("Introduction to Robotics", 502);

    uni.assignProfessorToCourse(207, 502);
    uni.enrollStudentInCourse(105, 502);
    uni.enrollStudentInCourse(109, 502);

    uni.generateReport();

    return 0;
}
