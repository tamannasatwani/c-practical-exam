#include <iostream>
#include <string>
using namespace std;

class Device {
private:
    string brand;
    float powerConsumption; 

public:
    
    void setBrand(const string& b) { brand = b; }
    void setPowerConsumption(float p) { 
        if (p > 0)
            powerConsumption = p; 
        else
            cout << "Power consumption must be positive!" << endl;
    }

    
    string getBrand() const { return brand; }
    float getPowerConsumption() const { return powerConsumption; }

    virtual void display() const {
        cout << "Brand: " << brand << ", Power Consumption: " << powerConsumption << " watts" << endl;
    }

    virtual ~Device() {}
};

class Laptop : public Device {
private:
    float screenSize; 

public:
    void setScreenSize(float size) {
        if (size > 0)
            screenSize = size;
        else
            cout << "Screen size must be positive!" << endl;
    }

    float getScreenSize() const { return screenSize; }

    void display() const override {
        cout << "Laptop Details:" << endl;
        Device::display();
        cout << "Screen Size: " << screenSize << " inches" << endl;
    }
};


class Smartphone : public Device {
private:
    int batteryCapacity; 

public:
    void setBatteryCapacity(int capacity) {
        if (capacity > 0)
            batteryCapacity = capacity;
        else
            cout << "Battery capacity must be positive!" << endl;
    }

    int getBatteryCapacity() const { return batteryCapacity; }

    void display() const override {
        cout << "Smartphone Details:" << endl;
        Device::display();
        cout << "Battery Capacity: " << batteryCapacity << " mAh" << endl;
    }
};

int main() {
    
    Laptop myLaptop;
    myLaptop.setBrand("Dell");
    myLaptop.setPowerConsumption(65);
    myLaptop.setScreenSize(15.6);

    
    Smartphone myPhone;
    myPhone.setBrand("Samsung");
    myPhone.setPowerConsumption(10);
    myPhone.setBatteryCapacity(5000);

    
    cout << "Displaying device details:\n" << endl;

    myLaptop.display();
    cout << endl;

    myPhone.display();

    return 0;
}

