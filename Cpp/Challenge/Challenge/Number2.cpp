#include "pch.h"
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int max_of_four(int a, int b, int c, int d) 
{
	int max1 = max(a, b);
	int max2 = max(c, d);
	return max1 > max2? max1 : max2;
}

void update(int *a, int *b) {
	// Complete this function   
	int olda = *a, oldb = *b;
	*a = olda + oldb;
	*b = abs(olda - oldb);

}


//int main()
//{
//	int n;
//	scanf_s("%d", &n);
//	vector<int> myvector(n, 0);
//	for (size_t i = 0; i < myvector.size(); i++)
//	{
//		scanf_s("%d", &myvector[i]);
//	}
//	
//	for (vector<int>::iterator i = myvector.end() - 1; i != myvector.begin(); i--)
//	{
//		printf("%d ", *i);
//	}
//	printf("%d\n", *myvector.begin());
//
//}