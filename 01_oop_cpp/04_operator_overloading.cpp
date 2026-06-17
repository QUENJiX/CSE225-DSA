#include <bits/stdc++.h>
using namespace std;

class Fraction {
private:
    long long numerator;
    long long denominator;

    void normalize() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        long long divisor = gcd(abs(numerator), abs(denominator));
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    Fraction(long long fractionNumerator, long long fractionDenominator)
        : numerator(fractionNumerator), denominator(fractionDenominator) {
        if (fractionDenominator == 0) {
            throw invalid_argument("denominator cannot be zero");
        }
        normalize();
    }

    friend Fraction operator+(const Fraction& left, const Fraction& right) {
        return Fraction(left.numerator * right.denominator + right.numerator * left.denominator,
                        left.denominator * right.denominator);
    }

    friend bool operator<(const Fraction& left, const Fraction& right) {
        return left.numerator * right.denominator < right.numerator * left.denominator;
    }

    friend ostream& operator<<(ostream& out, const Fraction& fraction) {
        out << fraction.numerator << '/' << fraction.denominator;
        return out;
    }
};

int main() {
    Fraction half(1, 2);
    Fraction third(1, 3);
    Fraction sum = half + third;

    cout << half << " + " << third << " = " << sum << '\n';
    cout << boolalpha << half << " < " << third << "? " << (half < third) << '\n';

    return 0;
}
