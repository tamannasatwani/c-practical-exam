#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string model;
    int year;
    float speed;

public:
    void setModel(const string& m) { model = m; }
    void setYear(int y) { 
        if (y > 1885) 
            year = y; 
        else
            cout << "Invalid year!" << endl;
    }
    void setSpeed(float s) { 
        if (s >= 0)
            speed = s; 
        else
            cout << "Speed cannot be negative!" << endl;
    }

    string getModel() const { return model; }
    int getYear() const { return year; }
    float getSpeed() const { return speed; }

    void display() const {
        cout << "Model: " << model 
             << ", Year: " << year 
             << ", Speed: " << speed << " km/h" << endl;
    }
};

int main() {
    Car car;

    car.setModel("Tesla Model S");
    car.setYear(2022);
    car.setSpeed(250.5);

    cout << "Car details accessed through getters:" << endl;
    cout << "Model: " << car.getModel() << endl;
    cout << "Year: " << car.getYear() << endl;
    cout << "Speed: " << car.getSpeed() << " km/h" << endl;

    cout << "\nCar details accessed through the display method:" << endl;
    car.display();

    return 0;
}

