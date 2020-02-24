#include "pch.h"

using namespace std;


//this is evil, since returning a reference to local/out of scope var is undefined behaviour
 int& evilfuncion(int input) {
	int result = 1230;
	return result;
}

 //it will convert is self, no run time error
 int x(int input) {
	 long long i = 10000000000000000000;
	 return i;
 }

 vector<vector<vector<int>>> AllmagicSquares = {
	{{8,1,6},{3,5,7},{4,9,2}},
	{{6,1,8},{7,5,3},{2,9,4}},
	{{4,9,2},{3,5,7},{8,1,6}},
	{{2,9,4},{7,5,3},{6,1,8}},
	{{8,3,4},{1,5,9},{6,7,2}},
	{{4,3,8},{9,5,1},{2,7,6}},
	{{6,7,2},{1,5,9},{8,3,4}},
	{{2,7,6},{9,5,1},{4,3,8}}
 };

 struct Pair
 {
	 int i, j;

	 Pair(int a, int b) : i(a), j(b) {	 }
	 
	 void set(int a, int b) {
		 i = a;
		 j = b;
	 }
 };

 void matrixRotation(vector<vector<int>> matrix, int r) {

	unsigned int m, n, newRot, leftup, leftdown, rightup, rightdown;
	unsigned int lui, luj, ldi, ldj, rui, ruj, rdi, rdj;

	m = matrix.size();
	n = matrix[0].size();
	lui = 0;
	luj = 0;
	ldi = m - 1;
	ldj = 0;
	rui = 0;
	ruj = n - 1;
	rdi = m - 1;
	rdj = n - 1;

	while (m*n > 0) {

		//for one circle
		newRot = r % (n*m);
		while (newRot--)
		{
			leftup = matrix[lui][luj];
			leftdown = matrix[ldi][ldj];
			rightup = matrix[rui][ruj];
			rightdown = matrix[rdi][rdj];

			//left line
			for (int i = (unsigned)ldi; i > (unsigned)lui; i--)
			{
				matrix[i][luj] = matrix[i - 1][luj];
			}
			//down line
			for (int i = (unsigned)rdj; i > (unsigned)ldj; i--)
			{
				matrix[ldi][i] = matrix[ldi][i - 1];
			}
			//right line
			for (int i = (unsigned)rui; i < (unsigned)rdi; i++)
			{
				matrix[i][ruj] = matrix[i + 1][rdj];
			}
			//up line
			for (int i = (unsigned)luj; i < (unsigned)ruj; i++)
			{
				matrix[lui][i] = matrix[rui][i + 1];
			}
			//corners
			matrix[lui + 1][luj] = leftup;
			matrix[ldi][ldj + 1] = leftdown;
			matrix[rdi - 1][rdj] = rightdown;
			matrix[rui][ruj - 1] = rightup;
		}

		//update new corners
		lui++;
		luj++;
		ldi--;
		ldj++;
		rdi--;
		rdj--;
		rui++;
		ruj--;
		//printf corner values
		n -= 2;
		m -= 2;
	}


	 for (size_t i = 0; i < matrix.size(); i++)
	 {
		 for (size_t j = 0; j < matrix[0].size(); j++)
		 {
			 printf("%d ", matrix[i][j]);
		 }
		 if (i + 1 != matrix.size())
			 printf("\n");
	 }
 }


 int pickingNumbers(vector<int> a) {
	 
	 sort(a.begin(), a.end());
	 int max = INT_MIN;
	 int counter = 0;
	 for (int i = 0; i < a.size(); i++) {

		 while (i + 1 < a.size() && a[i] == a[i + 1]) {
			 ++counter;
			 i++;
		 }

		 int j = i;
		 while (j + 1 < a.size() && a[i] + 1 == a[++j])
			 ++counter;

		 max = counter > max ? counter : max;
		 counter = 0;
	 }
	 return max;
 }

 vector<vector<int>> testy = {
{1,2,3,4},
{5,6,7,8},
{9,10,11,12},
{13,14,15,16}
 };

 //printf("%s", str);

// int main() {
//	 int n = 6;
//	 string str;
//	 string blancWidth = "%" + to_string(n) + "s\n";
//	 char* a = (char*) malloc(n* sizeof(char));
//
//	 for (size_t i = 0; i < (unsigned) n; i++)
//	 {
//		 str.append("#");
//		 printf(blancWidth.c_str(), str.c_str());
//	 }
//}