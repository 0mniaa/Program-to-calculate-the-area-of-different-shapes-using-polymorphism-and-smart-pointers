/*
 * Program to Calculate the Area of Different Shapes using Polymorphism and Smart Pointers
 *
 * This program defines a base class `Shape` with a virtual function `area()` to calculate the area.
 * Three derived classes (`Circle`, `Rectangle`, and `Triangle`) override the `area()` function to provide
 * their specific implementations. The program utilizes smart pointers (`unique_ptr`) to manage memory
 * automatically and ensure proper resource cleanup.
 *
 * The program demonstrates polymorphism by calculating the area of different shapes through base class pointers.
 */

#include <iostream>
#include <memory>
using namespace std;
const double pi = 3.1415;
class shape {
public:
    virtual double area() const {
        return 0;
    }

    virtual ~shape() {}
};

class circle final : public shape {
private:
    double radius;

public:
    circle(double r) : radius(r) {}
    ~circle() {
        cout << "Circle deleted" << endl;
    }

    double area() const override {
        return radius * radius * pi;
    }
};

class rectangle final : public shape {
private:
    double length;
    double width;
public:
    rectangle(double l, double w) : length(l), width(w) {}
    ~rectangle() {
        cout << "Rectangle deleted" << endl;
    }
    double area() const override {
        return length * width;
    }
};

class triangle final : public shape {
private:
    double base;
    double height;

public:
    triangle(double b, double h) : base(b), height(h) {}
    ~triangle() {
        cout << "Triangle deleted" << endl;
    }
    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    unique_ptr<shape> shapePtr;

    {
        shapePtr = make_unique<circle>(5);
        cout << "the area of the circle: " << shapePtr->area() << endl;
    }

    {
        shapePtr = make_unique<triangle>(10, 20);
        cout << "the area of the triangle: " << shapePtr->area() << endl;
    }

    {
        shapePtr = make_unique<rectangle>(10, 5);
        cout << "the area of the rectangle: " << shapePtr->area() << endl;
    }

    return 0;
}
