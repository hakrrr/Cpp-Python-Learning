#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

//int main() 
//{
//
//	int n, q;
//	scanf_s("%d", &n);
//
//	//Init Vector
//	vector<int> v(n, 0);
//	vector<int> numbers;
//
//	for (size_t i = 0; i < n; i++) {
//		int x;
//		scanf_s("%d", &x);
//		v[i] = x;
//	}
//	
//	//Get Query number
//	scanf_s("%d", &q);
//	numbers = vector<int>(q, 0);
//
//	//Get numtosearch input (numbers[0] = first element)
//	for (size_t i = 0; i < q; i++)
//	{
//		int number;
//		scanf_s("%d", &number);
//		numbers[i] = number;
//	}
//
//	auto start = high_resolution_clock::now();
//
//	//Find the numbers
//		for (auto i = numbers.begin(); i != numbers.end(); i++)
//		{
//			vector<int>::iterator x = lower_bound(v.begin(), v.end(), *i);
//			int index = (int)(x - v.begin());
//			if (v[index] == *i)
//				printf("Yes %d\n", index + 1);
//			else printf("No %d\n", index + 1);
//		}
//
//	auto end = high_resolution_clock::now();
//	auto duration = duration_cast<microseconds>((end - start)/10000l);
//
//	//cout << duration.count() << endl;
//	printf("This Program took: %lld microseconds!\n", duration.count());
//
//	return 0;
//}