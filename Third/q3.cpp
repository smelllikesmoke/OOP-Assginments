#include "Fraction.cpp"

int main()
{
    Fraction f1(2, 3);
    Fraction f2(3, 7);
    Fraction f3(3, 7);
    Fraction f5(2, 3);
    Fraction f6(4, 10);

    Fraction f4;
    f4 = f1 - f2; // should print 5/21
    cout << endl;
    f4.display();
    cout << endl << endl;
    f4 = f3 + f2; // should print 6/7
    f4.display();
    cout << endl << endl;
    f4 = f1 * f2; // should print 2/7 cuz original would be 6/21
    f4.display();
    cout << endl << endl;
    f4 = f1 / f2;
    f4.display(); // should print 14/9
    cout << endl << endl;
    f1 += f2;
    f1.display(); // should print 23/21
    cout << endl << endl;
    f1 -= f2;
    f1.display(); // should print 2/3 which's original is: 14/21
    cout << endl << endl;
    if (f1 < f2)
        cout << "True";
    else 
        cout << "False"; // should print false
    cout << endl << endl;

    if (f1 > f2)
        cout << "True";
    else 
        cout << "False"; // should print True
    cout << endl << endl;

    if (f1 <= f6)
        cout << "True";
    else 
        cout << "False"; // should print False
    cout << endl << endl;

    if (f1 >= f6)
        cout << "True";
    else 
        cout << "False"; // should print True
    cout << endl << endl;
    
    ++f1;
    f1.display(); // should print 5/3
    cout << endl << endl;
    f1++;
    f1.display(); // should print 8/3
    cout << endl << endl;
    --f1;
    f1.display(); // should print 5/3
    cout << endl << endl;
    f1--;
    f1.display(); // should print 2/3
    cout << endl << endl;

    cout << f1; // should print 2/3
    //cin >> f1;



    return 0;
}