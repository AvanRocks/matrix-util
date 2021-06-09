#include "Matrix.h"
#include <iostream>
#include <math.h>
using namespace std;

Matrix::Matrix(const vector<vector<int>> &data) {
	for (auto row : data) {
		int size = row.size();
		mat.push_back(vector<Fraction>(size));
		for (int i=0; i < size; ++i) {
			mat.back()[i] = row[i];
		}
	}
}

int Matrix::numColumns() {
	if (mat.size() == 0) {
		return 0;
	} else {
		return mat.back().size();
	}
}

int Matrix::numRows() {
	return mat.size();
}

void Matrix::output() {
	for (int row = 0; row < numRows(); ++row) {
		for (int col = 0; col < numColumns(); ++col) {
			cout<<mat[row][col]<<' ';
		}
		cout<<'\n';
	}
}

void Matrix::swapRows(int row1, int row2) {
	if (row1 == row2) {
		return;
	} else {
		mat[row1].swap(mat[row2]);
	}
}

void Matrix::fixRows(int col) {
	int pivotRow = col;

	for (int row = pivotRow; row < numRows(); ++row) {
		if (mat[row][col] != 0) {
			swapRows(row, pivotRow);
			return;
		}
	}
}

vector<Fraction> Matrix::getRow(int rowNum) {
	return mat[rowNum];
}

vector<Fraction> Matrix::scale(vector<Fraction> &row, Fraction scaleBy) {
	vector<Fraction> ret;

	for (unsigned int i=0; i<row.size(); ++i) {
		ret.push_back(row[i]*scaleBy);
	}

	return ret;
}

vector<Fraction> Matrix::add(vector<Fraction> row1, vector<Fraction> row2) {
	vector<Fraction> ret;

	for (int col = 0; col < numColumns(); ++col) {
		ret.push_back(row1[col] + row2[col]);
	}

	return ret;
}

vector<Fraction> Matrix::subtract(vector<Fraction> row1, vector<Fraction> row2) {
	return add(row1, scale(row2, -1));
}

void Matrix::replaceRow(int rowNum, vector<Fraction> newRow) {
	mat[rowNum] = newRow;
}

void Matrix::zeroUnder(int col) {
	int pivotRowNum = col;

	for (int row = pivotRowNum+1; row < numRows(); ++row) {
			Fraction pivot = mat[pivotRowNum][col];
			Fraction curr = mat[row][col];
		if (curr != 0) {
			vector<Fraction> currRow = getRow(row);
			vector<Fraction> pivotRow = getRow(pivotRowNum);
			replaceRow(row, subtract(currRow, scale( pivotRow, curr/pivot )) );
		}
	}
}

void Matrix::scaleRows() {
	for (int row = 0; row < numRows(); ++row) {
		int pivotColumn = row;

		if (pivotColumn < numColumns()) {
			Fraction pivot = mat[row][pivotColumn];
			if (pivot != 0) {
				vector<Fraction> currRow = getRow(row);
				replaceRow(row, scale(currRow, 1/pivot) );
			}
		}
	}
}

void Matrix::zeroAbove(int col) {
	int pivotRowNum = col;

	if (pivotRowNum >= numRows()) {
		return;
	}

	for (int row = pivotRowNum - 1; row >= 0; --row) {
		Fraction pivot = mat[pivotRowNum][col];
		Fraction curr = mat[row][col];
		if (pivot != 0 && curr != 0) {
			vector<Fraction> currRow = getRow(row);
			vector<Fraction> pivotRow = getRow(pivotRowNum);
			replaceRow(row, subtract(currRow, scale( pivotRow, curr/pivot )) );
		}
	}
}

void Matrix::ref() {
	for (int col = 0; col < numColumns(); ++col) {
		fixRows(col);
		zeroUnder(col);
	}

	scaleRows();
}

void Matrix::rref() {
	ref();

	// zeros above the leading ones
	for (int col = numColumns() - 1; col >= 0; --col) {
		zeroAbove(col);
	}
}