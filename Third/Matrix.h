#include <iostream>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

class Matrix {
private:
	int rows;
	int cols;
	int ** ptr;

public:
	// Constructors
	Matrix();	
	Matrix(int rows, int columns);
    Matrix(Matrix & m);

	// Deconstructor
	~Matrix();

	// Getters and setters
	int getRows();
	int getCols();

	// Methods
	void init();
	void display();

	// Overloaded functions
	Matrix& operator=(const Matrix & m);
	Matrix operator+(Matrix & m1);
	Matrix operator-(Matrix & m1);
	Matrix operator*(Matrix & m1);
	Matrix operator*(int num);
	bool operator==(Matrix & m1);
	Matrix& operator++();
	Matrix& operator++(int);
};