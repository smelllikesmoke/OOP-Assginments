#include "Matrix.h"

int Matrix::getRows() {return this->rows;}
int Matrix::getCols() {return this->cols;}

void Matrix::init()
{
    string input;
	int size = rows * cols;
	cout << "Let's put values in our matrix." << endl << "Please enter the elements seperated by a comma: ";
	getline(cin, input);

  	int i = 0; int k = 0;
	int check = 0;

  	for (int j = 0; j < input.length(); j++)
  	{
		if (check > size)
		{
			cout << "Invalid input, try again.";
			__throw_invalid_argument("lmao");
		}

    	char c = input[j];
    	if (c == ',')
    	{
      		i++;
      		continue;
    	}
    	if (i == cols)
    	{
    		k++;
    		i = 0;
    	}
    	//ptr[k][i] = ptr[k][i] * 10 + (c - 48); // ading the element of each index
        ptr[k][i] = int(c) - 48;
		check++;
  	}

}

void Matrix::display()
{
	cout << endl;
	for (int i = 0; i < rows; i ++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

Matrix::Matrix() : rows(0) , cols(0) {};
Matrix::Matrix(Matrix & m)
{
    this->rows = m.getRows();
    this->cols = m.getCols();
    this->ptr = new int * [m.getRows()];
    for (int i = 0; i < m.getRows(); i++)
    {
        this->ptr[i] = new int [m.getCols()];
    }

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			ptr[i][j] = m.ptr[i][j];
}

Matrix::Matrix(int rows, int cols) : rows(rows) , cols(cols)
{
	ptr = new int * [rows];
	for (int i = 0; i < rows; i++)
	{
		ptr[i] = new int [cols];
	}
}

Matrix::~Matrix()
{
	for (int i = 0; i < rows; i++)
		delete [] ptr[i];

	delete[] ptr;
}

Matrix& Matrix::operator=(const Matrix & m)
{

	for (int i = 0; i < this->rows; i++)
		delete [] this->ptr[i];
	delete [] this->ptr;

	this->rows = m.rows;
	this->cols = m.cols;

	this->ptr = new int * [this->rows];
	for (int i = 0; i < this->rows; i++)
	{
		this->ptr[i] = new int [this->cols];
	}

	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			this->ptr[i][j] = m.ptr[i][j];
		}
	}
	return *this;
}


Matrix Matrix::operator+(Matrix & m1)
{
	if ((m1.getRows() != this->getRows()) || (m1.getCols() != this->getCols()))
	{
		cout << "Invalid operands." << endl;
		__throw_invalid_argument("bruh");
	}

	Matrix temp(m1.getRows(), m1.getCols());
	for (int i = 0; i < m1.getRows(); i++)
	{
		for (int  j = 0; j < m1.getCols(); j++)
		{
			temp.ptr[i][j] = m1.ptr[i][j] + this->ptr[i][j];
		}
	}
	return temp;
}

Matrix Matrix::operator-(Matrix & m1)
{
	if ((m1.getRows() != this->getRows()) || (m1.getCols() != this->getCols()))
	{
		cout << "Invalid operands." << endl;
		__throw_invalid_argument("bruh");
	}

	Matrix temp(m1.getRows(), m1.getCols());
	for (int i = 0; i < m1.getRows(); i++)
	{
		for (int  j = 0; j < m1.getCols(); j++)
		{
			temp.ptr[i][j] = this->ptr[i][j] - m1.ptr[i][j];
		}
	}
	return temp;
}

Matrix Matrix::operator*(Matrix & m1)
{
	if (this->getCols() != m1.getRows())
	{
		cout << "Invalid matrices.";
		__throw_invalid_argument("haha");
	}

	Matrix temp(this->getRows(), m1.getCols());

	for (int i = 0; i < this->getRows(); i++)
	{
  		for (int j = 0; j < m1.getCols(); j++)
		{
			temp.ptr[i][j] = 0;
    		for (int k = 0; k < this->getCols(); k++)
			{
      			temp.ptr[i][j] += this->ptr[i][k] * m1.ptr[k][j];
    		}
  		}
	}
	return temp;
}

Matrix Matrix::operator*(int num)
{
	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getCols(); j++)
		{
			this->ptr[i][j] *= num;
		}
	}
	return *this;
}

bool Matrix::operator==(Matrix & m1)
{
	if ((this->getRows() != m1.getRows()) && (this->getCols() != m1.getCols()))
		return 0;

	for (int i = 0; i < this->getRows(); i++)
	{
		for (int j = 0; j < this->getCols(); j++)
		{
			if (this->ptr[i][j] != m1.ptr[i][j])
				return 0;
		}
	}
	return 1;
}

Matrix& Matrix::operator++()
{
	for (int i = 0; i < getRows(); i++)
	{
		for (int j = 0; j < getCols(); j++)
		{
			++this->ptr[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator++(int)
{
	Matrix temp(*this);
	++(*this);
	return temp;
}



























