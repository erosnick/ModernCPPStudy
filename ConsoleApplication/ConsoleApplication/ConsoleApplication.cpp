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

	float X;
	float Y;
	float Z;
};

template <class ClassType, class DataType1, class DataType2>
void AccessOrder(DataType1 ClassType::*Member1, DataType2 ClassType::*Member2)
{
	if (Member1 < Member2)
	{
		std::cout << "Member1 occurs first." << endl;
	}
	else
	{
		std::cout << "Member2 occurs first." << endl;
	}
}

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

	//AccessOrder(&Point::X, &Point::Z);

	float Point::*ZPtr = &Point::Z;
	float Point::*XPtr = &Point::X;

	printf("ZPtr=%d\n", XPtr);
	printf("ZPtr=%d\n", ZPtr);

	//Point P;

	//float* ZPtr = &P.Z;
	//float* XPtr = &P.X;

	//if (ZPtr < XPtr)
	//{
	//	std::cout << "Z occurs first." << endl;
	//}
	//else
	//{
	//	std::cout << "X occurs first." << endl;
	//}

	return 0;
}