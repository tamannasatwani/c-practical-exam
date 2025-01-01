#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual void makeSound() const = 0;
    virtual void move() const = 0;

    virtual ~Animal() {}
};

class Lion : public Animal {
public:
    void makeSound() const override {
        cout << "Lion says: Roar!" << endl;
    }

    void move() const override {
        cout << "Lion is running!" << endl;
    }
};

class Fish : public Animal {
public:
    void makeSound() const override {
        cout << "Fish makes no sound!" << endl;
    }

    void move() const override {
        cout << "Fish is swimming!" << endl;
    }
};

int main() {
    Animal* animals[2];

    animals[0] = new Lion();
    animals[1] = new Fish();

    for (int i = 0; i < 2; ++i) {
        animals[i]->makeSound();
        animals[i]->move();
        cout << endl;
    }

   
    delete animals[0];
    delete animals[1];

    return 0;
}

