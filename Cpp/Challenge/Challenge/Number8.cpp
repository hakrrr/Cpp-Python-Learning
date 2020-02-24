#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <list>
#include <set>

using namespace std;

class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if (A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if (B == 0) throw 0;
		real = (A / B)*real;
		int ans = v.at(B);
		return real + A - B * ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int getTotalX(vector<int> a, vector<int> b) {
	vector<int>::iterator maxAi, minBi;
	maxAi = max_element(a.begin(), a.end());
	minBi = min_element(b.begin(), b.end());
	int counter = 0;
	bool forAll = true;

	for (int i = *maxAi; i <= *minBi; i++) {
		for (int ai : a) {
			if (i%ai != 0)
				forAll = false;
		}

		if (forAll)
			counter++;

		forAll = true;
		for (int bi : b) {
			if (bi%i != 0)
				forAll = false;
		}

		if (forAll)
			counter++;
	}

	return counter;
}


int nonDivisibleSubset(int k, vector<int> s) {
	unique(s.begin(), s.end());
	unsigned int * ar = new unsigned int[k]();
	unsigned int result = 0;

	//Go through s and store into [%n] array per index
	for (int& i : s)
		ar[i%k]++;
	
	if (ar[0] > 1)
		result++;

	//Iterate over [%n] array and add up to 
	for (size_t i = 1; i <= (unsigned) k/2; i++)
		result += ar[i] > ar[k - i] ? ar[i] : ar[k - i];

	return result;
}

//int main() {
//	int T; cin >> T;
//
//
//	while (T--) {
//		long long A, B;
//		cin >> A >> B;
//
//		/* Enter your code here. */
//		try {
//			Server::compute(A, B);
//		}
//		catch (const bad_alloc& ba) {
//			printf("%s\n", "Not enough Memory");
//		}
//		catch (const exception& e) {
//			printf("Exception: %s\n", e.what());
//		}
//		catch (...) {
//			printf("Other Exception\n");
//		}
//
//	}
//	cout << Server::getLoad() << endl;
//	return 0;
//}