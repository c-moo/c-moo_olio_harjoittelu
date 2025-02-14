#include <iostream>
#include "Student.h"
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int selection = 0;
    string name = "";
    int age = 0;
    vector<Student> studentList = {
        {"Bart", 10}, {"Adam", 26 }, {"Caesar", 35}
    };

    while(selection < 5) {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection) {
        case 0:
            cout << "Please enter the students name" << endl;
            cin >> name;
            cout << "Please enter the students age" << endl;
            cin >> age;
            studentList.push_back({name, age});
            break;

        case  1:
            for (auto &s: studentList) {
                s.printStudentInfo();
            }
            break;

        case 2:
            sort(studentList.begin(), studentList.end(), [](Student&a, Student&b) {
                return a.getName() < b.getName();
            });
            for (auto &s: studentList) {
                s.printStudentInfo();
            }
            // Järjestä StudentList vektorin Student oliot nimen mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            break;

        case 3:
            sort(studentList.begin(), studentList.end(), [](Student&a, Student&b) {
                return a.getAge() < b.getAge();
            });
            for (auto &s: studentList) {
                s.printStudentInfo();
            }
            // Järjestä StudentList vektorin Student oliot iän mukaan
            // algoritmikirjaston sort funktion avulla
            // ja tulosta printStudentInfo() funktion avulla järjestetyt
            // opiskelijat
            break;
        case 4:
            cout << "Student to be found name = ?" << endl;
            cin >> name;
                auto it = find_if(studentList.begin(), studentList.end(), [name](Student&a) {
                    return (a.getName() == name);
                });

                if(it != studentList.end()) {
                    cout << "Student found:" << endl;
                    it->printStudentInfo();
                }
                else {
                    cout << "No student found" << endl;
                }
            // Kysy käyttäjältä opiskelijan nimi
            // Etsi studentListan opiskelijoista algoritmikirjaston
            // find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            break;
        }
    }

return 0;
}
