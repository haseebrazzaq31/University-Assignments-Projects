#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Student{
    string name;
    int id;
};
struct Course{
    string courseName;
    string courseCode;
    vector<Student> enrolledStudents;
};
int main(){
    int numCourses;
    cout<<"Enter number of courses: ";
    cin>>numCourses;
    vector<Course> courses(numCourses);
    for(int i = 0; i < numCourses; i++){
        cout<<"\nCourse " << i + 1 << ":\n";
        cout<<"Course name: ";
        cin>>ws;
        getline(cin, courses[i].courseName);
        cout<<"Course code: ";
        getline(cin, courses[i].courseCode);
        int numStudents;
        cout<<"Number of enrolled students: ";
        cin>>numStudents;
        for(int j = 0; j < numStudents; j++){
            Student newStudent;
            cout<<"\nStudent " << j + 1 << ":\n";
            cout<<"Name: ";
            cin>>ws;
            getline(cin, newStudent.name);
            cout<<"ID: ";
            cin>>newStudent.id;
            courses[i].enrolledStudents.push_back(newStudent);
        }
    }
    for(int i = 0; i < numCourses; i++){
        cout<<"\nCourse: "<<courses[i].courseName<<" ("<<courses[i].courseCode<<")\n";
        if(courses[i].enrolledStudents.size() == 0){
            cout<<"No students enrolled.\n";
        }else{
            cout<<"Enrolled students:\n";
            for(int j = 0; j < courses[i].enrolledStudents.size(); j++)
            {
                cout<<"  " << courses[i].enrolledStudents[j].name 
                    <<" (ID: " << courses[i].enrolledStudents[j].id << ")\n";
            }
        }
    }
    return 0;
}