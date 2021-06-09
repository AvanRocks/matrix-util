#include <vector>
#include <exception>
#include "Fraction.h"

class Matrix {
private:
	std::vector<std::vector<Fraction>> mat;

	int numColumns();
	int numRows();
	std::vector<Fraction> getRow(int rowNum);
	void fixRows(int col);
	void swapRows(int row1, int row2);
	void zeroUnder(int col);
	void zeroAbove(int col);
	std::vector<Fraction> scale(std::vector<Fraction> &row, Fraction scaleBy);
	std::vector<Fraction> add(std::vector<Fraction> row1, std::vector<Fraction> row2);
	std::vector<Fraction> subtract(std::vector<Fraction> row1, std::vector<Fraction> row2);
	void replaceRow(int rowNum, std::vector<Fraction> newRow);
	void scaleRows();

public:
	Matrix(const std::vector<std::vector<int>> &data);

	void output();
	void ref();
	void rref();
};

class ImpossibleToBalance : public std::exception {};
class TooManyVariables : public std::exception {};