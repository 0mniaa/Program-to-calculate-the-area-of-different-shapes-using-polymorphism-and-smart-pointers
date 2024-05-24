
#include <iostream>
#include <memory>

using namespace std;

const double pi = 3.1415;

// Base class Shape
class Shape {
public:
    // Virtual function to calculate the area
    virtual double area() const {
        return 0;
    }

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class Circle
class Circle final : public Shape {
private:
    double radius;

public:
    // Constructor
    Circle(double r) : radius(r) {}

    // Destructor
    ~Circle() {
        cout << "Circle deleted" << endl;
    }

    // Override area function
    double area() const override {
        return radius * radius * pi;
    }
};

// Derived class Rectangle
class Rectangle final : public Shape {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l, double w) : length(l), width(w) {}

    // Destructor
    ~Rectangle() {
        cout << "Rectangle deleted" << endl;
    }

    // Override area function
    double area() const override {
        return length * width;
    }
};

// Derived class Triangle
class Triangle final : public Shape {
private:
    double base;
    double height;

public:
    // Constructor
    Triangle(double b, double h) : base(b), height(h) {}

    // Destructor
    ~Triangle() {
        cout << "Triangle deleted" << endl;
    }

    // Override area function
    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    unique_ptr<Shape> shapePtr;

    {
        shapePtr = make_unique<Circle>(5);
        cout << "The area of the circle: " << shapePtr->area() << endl;
    }

    {
        shapePtr = make_unique<Triangle>(10, 20);
        cout << "The area of the triangle: " << shapePtr->area() << endl;
    }

    {
        shapePtr = make_unique<Rectangle>(10, 5);
        cout << "The area of the rectangle: " << shapePtr->area() << endl;
    }

    return 0;
}
