#include <exception>
#include <iostream>

class Fraction {
  int numerator, denominator;

private:
  void simplify();
	static int getGCD(int a, int b);
public:
  Fraction(int numerator, int denominator);
  Fraction(int integer);
  Fraction();

  Fraction operator+(const Fraction& rhs) const;
  Fraction operator-(const Fraction& rhs) const;
  Fraction operator*(const Fraction& rhs) const;
  friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

  bool operator==(const Fraction& rhs) const;
  bool operator!=(const Fraction& rhs) const;
  friend std::ostream& operator<<(std::ostream& os, const Fraction& rhs);
};

class DivideByZero : public std::exception {};