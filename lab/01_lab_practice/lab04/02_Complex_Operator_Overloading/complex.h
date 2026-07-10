#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
   private:
    double real, imaginary;

   public:
    Complex();
    Complex(double r, double i);

    Complex operator+(Complex a);
    Complex operator*(Complex a);
    bool operator!=(Complex a);

    void Print();
};

#endif  // COMPLEX_H
