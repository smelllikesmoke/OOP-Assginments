#include "Matrix.cpp"

int main()
{

	Matrix m1(2, 3);
    m1.init();
	m1.display();	
	Matrix m2(3, 2);
    m2.init();
	m2.display();

    // m1 = m2; // assignment operatro
    // m1.display();
	// Matrix m3 = m2; // copy constructor
	// m3.display();

	// Matrix m3(2, 2);
	// Matrix m4(2, 2);
	// m3.init();
	// m4 = m1 + m2 + m3;
	// m4.display(); // 9 9 | 99 
	// m4 = m4 - m3;
	// m4.display();

	// Matrix m5(3, 2);
	// m5 = m1 * m2;	
	// m5.display(); // should print 18 18 | 18 18
	// m5 = m5 * 2;
	// m5.display(); // should print 36 36 | 36 36

// checking ==
	// Matrix x1(2, 2);
	// x1.init();
	// Matrix x2(2, 2);
	// x2.init();
	// bool check;
	// check = x1 == x2;
	// cout << check;

// checking prefix inc
	// Matrix x3(2, 2);
	// x3.init();
	// ++x3;
	// x3.display();

// checking post-fix inc
	// Matrix x4(2, 2);
	// x4.init();
	// x4++;
	// x4.display();



}