#include <iostream>
#include "Fraction.h"

Fraction::Fraction(){
    numerator = 0;
    denominator = 0;
}

Fraction::Fraction(int numerator, int denominator){
    this->numerator = numerator;
    this->denominator = denominator;
}

int Fraction::getNumerator(){
    return numerator;
}

int Fraction::getDenominator(){
    return denominator;
}

int Fraction::setNumerator(int numerator){
    this->numerator = numerator;
    return 0;
}

int Fraction::setDenominator(int denominator){
    this->denominator = denominator;
    return 0;
}

void Fraction::display(){
    std::cout << numerator << " / " << denominator << std::endl;
}

void Fraction::addingFractions(Fraction otherFraction){
    int otherFractionNumerator = otherFraction.getNumerator();
    int otherFractionDenominator = otherFraction.getDenominator();

    int otherDenominatorToMain = otherFractionDenominator;
    int mainDenominator = denominator;
    int mainNumerator = numerator;
    if(mainDenominator != otherFractionDenominator){
        //sets the second fraction
        otherFractionDenominator *= mainDenominator;
        otherFractionNumerator *= mainDenominator;

        //sets the first fraction
        mainDenominator *= otherDenominatorToMain;
        mainNumerator *= otherDenominatorToMain;
    }

    denominator = mainDenominator;
    numerator = mainNumerator + otherFractionNumerator;
    // display();
    reduceFraction();
}

void Fraction::operator+=(Fraction otherFraction){
    this->addingFractions(otherFraction);
}

void Fraction::subtractFractions(Fraction otherFraction){
    int otherFractionNumerator = otherFraction.getNumerator();
    int otherFractionDenominator = otherFraction.getDenominator();

    int otherDenominatorToMain = otherFractionDenominator;
    int mainDenominator = denominator;
    int mainNumerator = numerator;
    if(mainDenominator != otherFractionDenominator){
        //sets the second fraction
        otherFractionDenominator *= mainDenominator;
        otherFractionNumerator *= mainDenominator;

        //sets the first fraction
        mainDenominator *= otherDenominatorToMain;
        mainNumerator *= otherDenominatorToMain;
    }

    denominator = mainDenominator;
    numerator = mainNumerator - otherFractionNumerator;
    // display();
    reduceFraction();
}

void Fraction::operator-=(Fraction otherFraction){
    this->subtractFractions(otherFraction);
}

void Fraction::multiplyFractions(Fraction otherFraction){
    int otherFractionNumerator = otherFraction.getNumerator();
    int otherFractionDenominator = otherFraction.getDenominator();

    denominator = denominator * otherFractionDenominator;
    numerator = numerator * otherFractionNumerator;
    // display();
    reduceFraction();
}

void Fraction::operator*=(Fraction otherFraction){
    this->multiplyFractions(otherFraction);
}

void Fraction::divideFractions(Fraction otherFraction){
    int otherFractionNumerator = otherFraction.getNumerator();
    int otherFractionDenominator = otherFraction.getDenominator();

    denominator = denominator * otherFractionNumerator;
    numerator = numerator * otherFractionDenominator;
    // display();
    reduceFraction();
}

void Fraction::operator/=(Fraction otherFraction){
    this->divideFractions(otherFraction);
}

void Fraction::reduceFraction(){
    int greatestCommonFactor = 0;

    int i = 1;
    while(i <= numerator){
        if(!(numerator % i) && !(denominator % i)){
            greatestCommonFactor = i;
        }
        i++;
    }

    numerator = numerator / greatestCommonFactor;
    denominator = denominator / greatestCommonFactor;
}

Fraction::~Fraction()
{
}
