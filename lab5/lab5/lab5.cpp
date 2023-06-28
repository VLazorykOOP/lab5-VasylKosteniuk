#include <iostream>
#include <string>

using namespace std;

// Опція компіляції для вибору коду
#define USE_LIQUID_CODE

#ifdef USE_LIQUID_CODE

class Liquid {
protected:
    string name;
    double density;

public:
    Liquid(const string& _name, double _density) : name(_name), density(_density) {
        cout << "Liquid constructor called." << endl;
    }

    virtual ~Liquid() {
        cout << "Liquid destructor called." << endl;
    }

    void print() const {
        cout << "Name: " << name << endl;
        cout << "Density: " << density << endl;
    }

    void setDensity(double _density) {
        density = _density;
    }
};

class AlcoholicBeverage : public Liquid {
private:
    double alcoholContent;

public:
    AlcoholicBeverage(const string& _name, double _density, double _alcoholContent)
        : Liquid(_name, _density), alcoholContent(_alcoholContent) {
        cout << "AlcoholicBeverage constructor called." << endl;
    }

    AlcoholicBeverage(const string& _name, double _density)
        : Liquid(_name, _density), alcoholContent(0.0) {
        cout << "AlcoholicBeverage default constructor called." << endl;
    }

    ~AlcoholicBeverage() {
        cout << "AlcoholicBeverage destructor called." << endl;
    }

    void print() const {
        Liquid::print();
        cout << "Alcohol Content: " << alcoholContent << "%" << endl;
    }

    void setDensity(double _density) {
        Liquid::setDensity(_density);
    }

    void setAlcoholContent(double _alcoholContent) {
        alcoholContent = _alcoholContent;
    }
};

#else

class Wheel {
private:
    int diameter;

public:
    Wheel(int _diameter) : diameter(_diameter) {
        cout << "Wheel constructor called." << endl;
    }

    ~Wheel() {
        cout << "Wheel destructor called." << endl;
    }

    void print() const {
        cout << "Wheel diameter: " << diameter << " inches" << endl;
    }
};

class Bicycle {
private:
    string brand;
    Wheel frontWheel;
    Wheel rearWheel;

public:
    Bicycle(const string& _brand, int frontDiameter, int rearDiameter)
        : brand(_brand), frontWheel(frontDiameter), rearWheel(rearDiameter) {
        cout << "Bicycle constructor called." << endl;
    }

    ~Bicycle() {
        cout << "Bicycle destructor called." << endl;
    }

    void print() const {
        cout << "Brand: " << brand << endl;
        cout << "Front ";
        frontWheel.print();
        cout << "Rear ";
        rearWheel.print();
    }
};

class Car {
private:
    string make;
    Wheel wheels[4];

public:
    Car(const string& _make, int wheelDiameter)
        : make(_make), wheels{ Wheel(wheelDiameter), Wheel(wheelDiameter),
                               Wheel(wheelDiameter), Wheel(wheelDiameter) } {
        cout << "Car constructor called." << endl;
    }

    ~Car() {
        cout << "Car destructor called." << endl;
    }

    void print() const {
        cout << "Make: " << make << endl;
        for (int i = 0; i < 4; i++) {
            cout << "Wheel " << i + 1 << " ";
            wheels[i].print();
        }
    }
};

#endif

int main() {
#ifdef USE_LIQUID_CODE
    Liquid liquid("Water", 1.0);
    liquid.print();

    cout << endl;

    AlcoholicBeverage beer("Beer", 1.01, 5.0);
    beer.print();

    cout << endl;

    AlcoholicBeverage wine("Wine", 0.98);
    wine.setAlcoholContent(12.5);
    wine.setDensity(0.99);
    wine.print();
#else
    Bicycle bike("Giant", 26, 26);
    bike.print();

    cout << endl;

    Car car("Toyota", 16);
    car.print();
#endif

    return 0;
}
