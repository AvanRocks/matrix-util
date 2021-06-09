#include "Fraction.h"
#include <cmath>

Fraction::Fraction(int numerator, int denominator) {
  if (denominator == 0) 
    throw DivideByZero();
  else if (denominator < 0) {
    numerator *= -1;
    denominator *= -1;
  }

  this->numerator = numerator;
  this->denominator = denominator;
}

Fraction::Fraction(int integer) : numerator(integer), denominator(1) {}

Fraction::Fraction() : numerator(0), denominator(1) {}

int Fraction::getGCD(int a, int b) {
	if (a == 0) return a;
	if (b == 0) return b;

	if (a == b) return a;

  if (a > b) 
		return getGCD(a-b, b);
	else
		return getGCD(a, b-a);
}

void Fraction::simplify() {
  if (this->numerator == 0) {
    this->denominator = 1;
  } else {
    int gcd = getGCD(abs(this->numerator), this->denominator);
    this->numerator /= gcd;
    this->denominator /= gcd;
  }
}

Fraction Fraction::operator+(const Fraction& rhs) const {
  int resultNumerator = this->numerator * rhs.denominator + this->denominator * rhs.numerator;
  int resultDenominator = this->denominator * rhs.denominator;
  Fraction result(resultNumerator, resultDenominator);
  result.simplify();
  return result;
}

Fraction Fraction::operator*(const Fraction& rhs) const {
  int resultNumerator = this->numerator * rhs.numerator;
  int resultDenominator = this->denominator * rhs.denominator;
  Fraction result(resultNumerator, resultDenominator);
  result.simplify();
  return result;
}

Fraction Fraction::operator-(const Fraction& rhs) const {
  Fraction rhsNoConst = rhs;
  return (*this + (rhsNoConst * -1));
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
  if (rhs == 0) throw DivideByZero();
  Fraction rhsReciprocal(rhs.denominator, rhs.numerator);
  Fraction result = lhs * rhsReciprocal;
  return result;
}

bool Fraction::operator==(const Fraction& rhs) const {
  return (this->numerator == rhs.numerator) && (this->denominator == rhs.denominator);
}

bool Fraction::operator!=(const Fraction& rhs) const {
  return !(*this == rhs);
}

std::ostream& operator<<(std::ostream& os, const Fraction& rhs) {
  os << rhs.numerator;
  if (rhs.denominator != 1) os << '/' << rhs.denominator;
  return os;
}