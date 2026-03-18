#ifndef FRACTION_H
#define FRACTION_H

class Fraction {
public:
    Fraction();
    Fraction(int numerator, int denominator);
    int getNumerator();
    int getDenominator();
    int setNumerator(int numerator);
    int setDenominator(int denominator);
    void display();
    void addingFractions(Fraction otherFraction);
    void operator+=(Fraction otherFraction);
    void subtractFractions(Fraction otherFraction);
    void operator-=(Fraction otherFraction);
    void multiplyFractions(Fraction otherFraction);
    void operator*=(Fraction otherFraction);
    void divideFractions(Fraction otherFraction);
    void operator/=(Fraction otherFraction);
    void reduceFraction();
    ~Fraction();

private:
    int numerator;
    int denominator;
};

#endif