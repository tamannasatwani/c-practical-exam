#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;

public:
    Student(string n, int r) : name(n), rollNumber(r) {}

    void display() const {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << endl;
    }
};

int main() {
    Student students[] = {
        Student("Alice", 101),
        Student("Bob", 102),
        Student("Charlie", 103)
    };


    for (int i = 0; i < 3; i++) {
        students[i].display();
    }

    return 0;
}

