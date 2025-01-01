#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

class Employee {
private:
    string name;
    int age;

public:
    
    Employee(const string& name, int age) : name(name), age(age) {}

    string getName() const { return name; }

    int getAge() const { return age; }

    int operator-(const Employee& other) const {
        return abs(this->age - other.age); 
    }

    
    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Employee emp1("Alice", 45);
    Employee emp2("Bob", 30);

    cout << "Employee 1 Details:" << endl;
    emp1.display();

    cout << "Employee 2 Details:" << endl;
    emp2.display();

   
    int ageDifference = emp1 - emp2;

   
    cout << "\nThe age difference between " << emp1.getName() 
         << " and " << emp2.getName() << " is: " 
         << ageDifference << " years." << endl;

    return 0;
}

