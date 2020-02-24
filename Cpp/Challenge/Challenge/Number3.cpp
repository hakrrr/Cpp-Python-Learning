#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

//int main()
//{
//	int n, queries;
//	scanf_s("%d%d", &n, &queries);
//	vector<int> * array = new vector<int>[n];
//
//	//Init the 2D array
//	for (size_t i = 0; i < n; i++)
//	{
//		int size;
//		scanf_s("%d", &size);
//		array[i] = vector<int>(size, 0);
//		
//		//Init a[i]
//		for (size_t ii = 0; ii < array[i].size(); ii++)
//		{
//			scanf_s("%d", &array[i][ii]);
//		}
//	}
//
//	//Queries
//	for (size_t it = 0; it < queries; it++)
//	{
//		int i, j;
//		scanf_s("%d%d", &i, &j);
//		printf("%d\n", array[i][j]);
//	}
//}