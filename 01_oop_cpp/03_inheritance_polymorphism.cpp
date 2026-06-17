#include <bits/stdc++.h>
using namespace std;

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
    virtual string name() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    explicit Circle(double circleRadius) : radius(circleRadius) {}

    double area() const override {
        return acos(-1.0) * radius * radius;
    }

    string name() const override {
        return "Circle";
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double rectangleWidth, double rectangleHeight)
        : width(rectangleWidth), height(rectangleHeight) {}

    double area() const override {
        return width * height;
    }

    string name() const override {
        return "Rectangle";
    }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Circle>(3.0));
    shapes.push_back(make_unique<Rectangle>(4.0, 5.0));

    cout << fixed << setprecision(2);
    for (const auto& shape : shapes) {
        cout << shape->name() << " area: " << shape->area() << '\n';
    }

    return 0;
}
