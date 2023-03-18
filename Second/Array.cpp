#include "Array.h"

int Array::getsize()
{
	return this->size;
}
void Array::display()	
{	
	cout << "[";
	for (int i = 0; i < this->size; i++)
	{
		cout << this->ptr[i] << " ";
	}
	cout << "]";
}

Array::Array() : ptr(NULL), size(0) {}

Array::Array(int size)
{
	this->ptr = new int [size];
	this->size = size;
}

Array::Array(int * arr, int size)
{
	this->ptr = new int [size];
	this->size = size;

	for (int i = 0; i < size; i++)
		this->ptr[i] = arr[i];
}

Array::Array(const Array & a)
{
	this->size = a.size;
	this->ptr = new int[this->size];

	for (int i = 0; i < this->size; i++)
	{
		this->ptr[i] = a.ptr[i];
	}
}

int Array::getAt(int i) { return this->ptr[i]; }

void Array::setAt(int i, int val)
{
	if (i >= this->size)
	{
		cout << "Invalid index.";
		return;
	}
	this->ptr[i] = val;
}

Array Array::subArr(int pos, int siz)
{
	if (pos >= this->size)
	{
		cout << "Invalid position.";
		return *this;
	}

	if (siz + pos > this->size)
	{
		cout << "Invalid size.";
		return *this;
	}

	int * temp = new int [siz];
	for (int i = 0, j = pos; i < siz; i++, j++)
	{
		temp[i] = this->ptr[j];
	}

	this->size = siz;
	delete [] this->ptr;
	this->ptr = new int [siz];
	for (int i = 0; i < this->size; i++)
	{
		this->ptr[i] = temp[i];
	}

	delete [] temp;
	temp = NULL;
	return *this;	
}

Array Array::subArr(int pos)
{
	if (pos > this->size)
	{
		cout << "Invalid position.";
	}

	int len = this->size - pos;

	int * temp = new int [len];
	for (int i = 0, j = pos; i < len; i++, j++)
	{
		temp[i] = this->ptr[j];
	}

	for (int i = 0; i < len; ++i)
	{
		this->ptr[i] = temp[i];
	}

	delete [] temp;
	temp = NULL;
	this->size -= pos;
	return *this;
}

int * Array::subArrPointer(int pos, int siz)
{
	//pos--;
	if (pos >= this->size)
	{
		cout << "Invalid position.";
		return NULL;
	}

	if (siz + pos > this->size)
	{
		cout << "Invalid size.";
		return NULL;
	}

	int * temp = new int [siz];
	for (int i = 0, j = pos; i < siz; i++, j++)
	{
		temp[i] = this->ptr[j];
	}

	return temp;
}

int * Array::subArrPointer(int pos)
{
	--pos;
	if (pos > this->size)
	{
		cout << "Invalid position.";
	}

	int len = this->size - pos;

	int * temp = new int [len];
	for (int i = 0, j = pos; i < len; i++, j++)
	{
		temp[i] = this->ptr[j];
	}
	return temp;
}

void Array::push_back(int a)
{

	int * temp = new int [this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->ptr[i];
	}
	temp[this->size] = a;
	this->size += 1;
	delete [] this->ptr;
	this->ptr = new int [this->size];

	for (int i = 0; i < this->size ; i++)
	{
		this->ptr[i] = temp[i];
	}

	delete [] temp;
	temp = NULL;
}

int Array::pop_back()
{
	int * temp = new int[this->size - 1];
	for (int i = 0; i < this->size - 1; i++)
	{
		temp[i] = this->ptr[i];
	}
	delete [] this->ptr;
	this->ptr = new int [this->size - 1];
	this->size -= 1;
	for (int i = 0; i < this->size; i++)
	{
		this->ptr[i] = temp[i];
	}
	delete [] temp;
	temp = nullptr;

	return this->ptr[this->size];
}

int Array::insert(int idx, int val)
{
	if (idx >= this->size)
		return -1;

	this->size += 1;
	int * temp = new int [this->size];
	for (int i = 0; i < this->size; i++)
	{
		if (i == idx)
		{
			temp[i] = val;
			break;
		}
		temp[i] = this->ptr[i];

	}
	int len = idx;

	for (int i = idx + 1; i < this->size;i++, len++)
	{
		temp[i] = this->ptr[len];
	}

	delete [] this->ptr;
	this->ptr = new int [this->size];
	for (int i = 0; i < this->size; i++)
	{
		this->ptr[i] = temp[i];
	}
	delete [] temp;
	temp = NULL;

	return 1;
}

int Array::erase(int idx, int val)
{
	if (idx >= this->size)
		return -1;

	if (this->ptr[idx] != val)
		return -1;

	int * temp = new int [this->size - 1];
	for (int i = 0; i < this->size; i++)
	{
		if (i >= idx)
		{
			for (int j = idx; j < this->size - idx + 1; j++)
			{
				temp[j] = this->ptr[j + 1];
			}
		}
		else
			temp[i] = this->ptr[i];
	}

	this->size -= 1;
	delete [] this->ptr;
	this->ptr = new int [this->size];


	for (int i = 0; i < this->size; i++)
	{	
		this->ptr[i] = temp[i];
	}

	delete [] temp;
	temp = NULL;	
	return 1;
}

int Array::length() {return this->size;}

void Array::clear()
{
	delete [] this->ptr;
	this->ptr = new int[1];
	this->ptr[0] = 0;
	this->size = 0;
}

int Array::value(int idx)
{
	if (idx >= this->size)
	{
		cout << "Invalid index;";
		return -1;
	}

	return this->ptr[idx];
}	

void Array::assign(int idx, int val)
{
	if (idx >= this->size)
	{
		cout << "Invalid index.";
		return;
	}

	this->ptr[idx] = val;
}

void Array::copy(const Array & Arr)
{
	delete [] this->ptr;
	this->ptr = new int [Arr.size];
	this->size = Arr.size;
	for (int i = 0; i < this->size; i++)
	{
		this->ptr[i] = Arr.ptr[i];
	}
}

void Array::copy(const int * arr, int siz)
{
	delete [] this->ptr;
	this->size = siz;
	this->ptr = new int [this->size];

	for (int i = 0; i < this->size; i++)
	{
		this->ptr[i] = arr[i];
	}
}

bool Array::isEmpty()
{
	if (this->size == 0)
		return true;
	else 
		return false;
}

Array Array::find(int num)
{
	Array final;
	int counter = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (this->ptr[i] == num)
			counter++;
	}
	if (counter == 0)
	{
		return *this;
	}

	final.ptr = new int [counter];
	int i = 0;
	for (int j = 0; j < this->size; j++)	
	{
		if (this->ptr[j] == num)
		{
			final.ptr[i] = j;
			i++;
		}
	}
	final.size = counter;
	return final;
}

bool Array::equal(const Array & arr)
{
	if (this->size != arr.size)
		return 0;

	for (int i = 0; i < this->size; i++)
	{
		if (this->ptr[i] != arr.ptr[i])
			return 0;
	}
	return 1;
}

int Array::sort()
{
	bool sorted = true;
	for (int i = 0; i < this->size; ++i) 
	{
    	for (int j = 0; j < this->size - i; ++j) 
    	{
    		if (this->ptr[j] > this->ptr[j + 1])
    		{
    			sorted = false;
        		int temp = this->ptr[j];
        		this->ptr[j] = this->ptr[j + 1];
        		this->ptr[j + 1] = temp;
    		}
    	}
  	}
  	return sorted;
}

void Array::reverse()
{
	int j = this->size - 1;
    for(int i = 0; i < j; i++ , j--)
    {
        int temp = this->ptr[i];
        this->ptr[i] = this->ptr[j];
        this->ptr[j] = temp;
    }
}

Array::~Array()
{	
	delete [] this->ptr;
	this->size = 0;
}
