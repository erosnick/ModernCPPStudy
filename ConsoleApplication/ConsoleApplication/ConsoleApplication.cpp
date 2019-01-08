// ConsoleApplication.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include "Utility.h"

using namespace std;

class Point
{
public:

	virtual ~Point() {}

	static Point P;
	float X;
	float Y;
	float Z;
};

class Concrate1
{
public:
	virtual void foo() { std::cout << "Concrate1" << std::endl; }

private:
	int Value;
	char A;
};

class Concrate2 : public Concrate1
{
private:
	virtual void foo() { std::cout << "Concrate2" << std::endl; }
	char B;
};

class Concrate3 : public Concrate2
{
private:
	char C;
};

struct Base1
{
	int Val1;
};

struct Base2
{
	int Val2;
};

struct Derived : Base1, Base2
{

};

class Abstract
{
public:

	virtual void Foo() const = 0
	{
	}

protected:

	int DataMember;
};

class Concrate : public Abstract
{
public:

	void Foo() const
	{
		Abstract::Foo();
	}
};

int main()
{
	std::vector<int> Array;

	for (auto i = 1; i <= 1000; i++)
	{
		Array.push_back(i);
	}

	auto Index = BinarySearch(Array, 1000);

	Stack<int> IntStack;

	IntStack.Push(10);

	std::cout << IntStack.Size() << std::endl;

	IntStack.Push(20);

	std::cout << IntStack.Size() << std::endl;

	std::cout << IntStack.Pop() << std::endl;

	std::cout << IntStack.Size() << std::endl;

	std::cout << IntStack.Pop() << std::endl;

	std::cout << IntStack.Size() << std::endl;

	//float Point::*ZPtr = &Point::Z;
	//float Point::*XPtr = &Point::X;

	//Point P;
	//printf("P=%p\n", &P);
	//printf("P.X=%p\n", &P.X);
	//printf("P.X=%p\n", &P.Z);
	//printf("ZPtr=%d\n", XPtr);
	//printf("ZPtr=%d\n", ZPtr);

	printf("&Point::X = %p\n", &Point::X);
	printf("&Point::Y = %p\n", &Point::Y);
	printf("&Point::Z = %p\n", &Point::Z);

	printf("&Base1::Val1 = %p \n", &Base1::Val1);
	printf("&Base2::Val2= %p \n", &Base2::Val2);
	printf("&Derived::Val1 = %p \n", &Derived::Val1);
	printf("&Derived::Val2 = %p \n", &Derived::Val2);

	std::cout << sizeof(Concrate1) << std::endl;
	std::cout << sizeof(Concrate2) << std::endl;
	std::cout << sizeof(Concrate3) << std::endl;

	Concrate2 C2;
	Concrate1* PC1 = &C2;
	PC1->foo();
	Point P;

	float* ZPtr = &P.Z;
	float* XPtr = &P.X;

	if (ZPtr < XPtr)
	{
		std::cout << "Z occurs first." << endl;
	}
	else
	{
		std::cout << "X occurs first." << endl;
	}

	Concrate C;
	C.Foo();

	return 0;
}