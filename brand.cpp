#include <iostream>
#include <string>
#include <iomanip> 
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

    virtual float calculateDiscount() const = 0; 

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

    float calculateDiscount() const override {
        return 0.1f; 
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

    float calculateDiscount() const override {
        return 0.15f; 
    }
};

int main() {
    
    Device* devices[2];

    
    Laptop* myLaptop = new Laptop();
    myLaptop->setBrand("Dell");
    myLaptop->setPowerConsumption(65);
    myLaptop->setScreenSize(15.6);

    Smartphone* myPhone = new Smartphone();
    myPhone->setBrand("Samsung");
    myPhone->setPowerConsumption(10);
    myPhone->setBatteryCapacity(5000);

    
    devices[0] = myLaptop;
    devices[1] = myPhone;

    cout << fixed << setprecision(2); 
    for (int i = 0; i < 2; ++i) {
        devices[i]->display();
        cout << "Discount: " << devices[i]->calculateDiscount() * 100 << "%\n" << endl;
    }

    delete myLaptop;
    delete myPhone;

    return 0;
}

