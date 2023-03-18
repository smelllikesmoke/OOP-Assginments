#include "ques10.cpp"
#include <gtest/gtest.h>
using namespace std;


//Test cases for class Array


TEST(Array, DefaultConstructor) {
    Array a;
    EXPECT_EQ(a.length(), 0);
    EXPECT_TRUE(a.isEmpty());
}

TEST(Array, SizeConstructor) {
    Array a(10);
    EXPECT_EQ(a.length(), 10);
    EXPECT_FALSE(a.isEmpty());
}

TEST(Array, ArrayConstructor) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    EXPECT_EQ(a.length(), 5);
    EXPECT_EQ(a.getAt(0), 1);
    EXPECT_EQ(a.getAt(4), 5);
    EXPECT_FALSE(a.isEmpty());
}

TEST(Array, CopyConstructor) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    Array b(a);
    EXPECT_EQ(b.length(), 5);
    EXPECT_EQ(b.getAt(0), 1);
    EXPECT_EQ(b.getAt(4), 5);
    EXPECT_FALSE(b.isEmpty());
}

TEST(Array, GetAt) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    EXPECT_EQ(a.getAt(0), 1);
    EXPECT_EQ(a.getAt(4), 5);
}

TEST(Array, SetAt) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    a.setAt(2, 10);
    EXPECT_EQ(a.getAt(2), 10);
}

TEST(Array, SubArr) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    Array b = a.subArr(2, 3);
    EXPECT_EQ(b.length(), 3);
    EXPECT_EQ(b.getAt(0), 3);
    EXPECT_EQ(b.getAt(2), 5);
}

TEST(Array, SubArrPointer) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    int* p = a.subArrPointer(2, 3);
    EXPECT_EQ(p[0], 3);
    EXPECT_EQ(p[2], 5);
}

TEST(Array, PushBack) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    a.push_back(10);
    EXPECT_EQ(a.length(), 6);
    EXPECT_EQ(a.getAt(5), 10);
}

TEST(Array, PopBack) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    int val = a.pop_back();
    EXPECT_EQ(val, 5);
    EXPECT_EQ(a.length(), 4);
    EXPECT_EQ(a.getAt(3), 4);
}

TEST(Array, Insert) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    a.insert(2, 10);
    EXPECT_EQ(a.length(), 6);
    EXPECT_EQ(a.getAt(2), 10);
    EXPECT_EQ(a.getAt(3), 3);
    EXPECT_EQ(a.getAt(5), 5);
}

TEST(Array, Erase) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    a.erase(2, 3);
    EXPECT_EQ(a.length(), 4);
    EXPECT_EQ(a.getAt(2), 4);
    EXPECT_EQ(a.getAt(3), 5);
}

TEST(Array, getSize) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    EXPECT_EQ(a.getsize(), 5);
}

TEST(Array, Length) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    EXPECT_EQ(a.length(), 5);
}

TEST(Array, Clear) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    a.clear();
    EXPECT_EQ(a.length(), 0);
    EXPECT_TRUE(a.isEmpty());
}

TEST(Array, Value) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    EXPECT_EQ(a.value(2), 3);
}

TEST(Array, Assign) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    a.assign(2, 10);
    EXPECT_EQ(a.length(), 5);
    EXPECT_EQ(a.getAt(2), 10);
}

TEST(Array, Copy) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    int arr2[] = {10,20,30,40,50};
    Array b;
    b.copy(arr2, 5);
    EXPECT_EQ(b.length(), 5);
    EXPECT_EQ(b.getAt(2), 30);
}

TEST(Array, Equal) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    Array b(arr, 5);
    EXPECT_TRUE(a.equal(b));
}

TEST(Array, Sort) {
    int arr[] = {5,4,3,2,1};
    Array a(arr, 5);
    a.sort();
    EXPECT_EQ(a.getAt(0), 1);
    EXPECT_EQ(a.getAt(4), 5);
}

TEST(Array, Reverse) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    a.reverse();
    EXPECT_EQ(a.getAt(0), 5);
    EXPECT_EQ(a.getAt(4), 1);
}

TEST(Array, Find) {
    int arr[] = {1,2,3,4,5};
    Array a(arr, 5);
    Array b = a.find(3);
    EXPECT_EQ(b.length(), 1);
    EXPECT_EQ(b.getAt(0), 2);
}

TEST(ArrayTest, Destructor) {
    Array* arr1 = new Array(5);
    EXPECT_EQ(arr1->length(), 5);
    delete arr1;
    //No easy way to test this without actually looking at the output
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
