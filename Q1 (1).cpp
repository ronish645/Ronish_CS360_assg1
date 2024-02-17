
#include <iostream>
#include <sstream>
#include <cmath>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Default constructor
    Complex() : real(0), imaginary(0) {}

    // Constructor with two arguments
    Complex(double r, double i) : real(r), imaginary(i) {}

    // Constructor from a string
    Complex(const std::string& str) {
        std::istringstream iss(str);
        char comma;
        if (!(iss >> real >> comma >> imaginary)) {
            // Handle error: Invalid string format
            real = 0;
            imaginary = 0;
        }
    }

    // Addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Multiplication
    Complex operator*(const Complex& other) const {
        double r = real * other.real - imaginary * other.imaginary;
        double i = real * other.imaginary + imaginary * other.real;
        return Complex(r, i);
    }

    // Division
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        double r = (real * other.real + imaginary * other.imaginary) / denominator;
        double i = (imaginary * other.real - real * other.imaginary) / denominator;
        return Complex(r, i);
    }

    // Magnitude
    double magnitude() const {
        return sqrt(real * real + imaginary * imaginary);
    }

    // Angle in degrees
    double angle() const {
        return atan2(imaginary, real) * (180 / M_PI);
    }

    // Complex conjugate
    Complex conjugate() const {
        return Complex(real, -imaginary);
    }

    // Print
    void Print() const {
        std::cout << "(" << real << ", " << imaginary << ")" << std::endl;
    }
};

int main() {
    Complex c1(3, 2);
    Complex c2(1, 7);

    std::cout << "Complex number c1: ";
    c1.Print();

    std::cout << "Complex number c2: ";
    c2.Print();

    // Addition
    Complex sum = c1 + c2;
    std::cout << "Sum (c1 + c2): ";
    sum.Print();

    // Subtraction
    Complex difference = c1 - c2;
    std::cout << "Difference (c1 - c2): ";
    difference.Print();

    // Multiplication
    Complex product = c1 * c2;
    std::cout << "Product (c1 * c2): ";
    product.Print();

    // Division
    Complex quotient = c1 / c2;
    std::cout << "Quotient (c1 / c2): ";
    quotient.Print();

    // Magnitude of c1
    std::cout << "Magnitude of c1: " << c1.magnitude() << std::endl;

    // Angle of c1 in degrees
    std::cout << "Angle of c1: " << c1.angle() << " degrees" << std::endl;

    // Complex conjugate of c1
    Complex conjugate = c1.conjugate();
    std::cout << "Complex conjugate of c1: ";
    conjugate.Print();


    return 0;
}

