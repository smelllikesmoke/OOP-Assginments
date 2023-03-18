#include <iostream>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

class Array {
private:
	int * ptr;
	int size;

public:
	// Constructor
	Array();
	Array(int size);
	Array(int * arr, int size);
	Array(const Array &);

	// Getters and setters
	int getAt(int i);
	void setAt(int i, int val);
	int getsize();

	// Methods
	Array subArr(int pos, int siz);
	Array subArr(int pos);

	int * subArrPointer(int pos, int siz);
	int * subArrPointer(int pos);

	void push_back(int a);
	int pop_back();
	int insert(int idx, int val);
	int erase(int idx, int val);
	int length();
	void clear();
	int value(int idx);
	void assign(int idx, int val);
	void copy(const Array & Arr);
	void copy(const int * arr, int siz);
	bool isEmpty();
	Array find(int num);
	bool equal(const Array & arr);
	int sort();
	void reverse();




	~Array(); // Deconstructor
	void display();

};
