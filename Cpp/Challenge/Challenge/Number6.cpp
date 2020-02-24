#include "pch.h"
#include <string>
#include <exception>
#include <iostream>
#include <vector>
#include <sstream>


using namespace std;

struct BadLengthException : public exception {
	
	int message;
	string str;

	BadLengthException(int& n) : message(n) {
		str = to_string(message);
	}
	
	const char* what() const throw() {
		return str.c_str();
	}
};

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if (n < 5) {
		throw BadLengthException(n);
	}
	for (int i = 0; i < n - 1; i++) {
		if (username[i] == 'w' && username[i + 1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

struct Matrix {

	vector<vector<int>> a;

	Matrix operator + (Matrix& b) {
		for (size_t i = 0; i < b.a.size(); i++)
		{
			for (size_t j = 0; j < b.a[i].size(); j++)
			{
				a[i][j] += b.a[i][j];
			}
		}
		return *this;
	}

};

ostream& operator << (ostream& os, Matrix& a) {
	return os;
}

vector<int> parseInts(string str) {
	vector<int> result;
	stringstream ss(str);
	string x;
	int i;

	while (getline(ss, x, ',')) {
		i = stoi(x, nullptr, 10);
		result.push_back(i);
	}

	return result;
}


class Student {

	public:
		string name;

		void setName(string name) {
			this->name = name;
		}
};

class Box {
private:
	int l, b, h;

public:
	Box() {
		l = 0;
		b = 0;
		h = 0;
	}
	Box(const int& a, const int& b, const int& c) {
		l = a;
		this->b = b;
		h = c;
	}
	Box(const Box& a) {
		l = a.l;
		b = a.b;
		h = a.h;
	}

	int getLength() const{ return l; }
	int getBreadth() const{ return b; }
	int getHeight() const{ return h; }

	long long CalculateVolume() {
		return l * b * h;
	}

	bool operator < (const Box&b) {
		if (l < b.l || (l == b.l && this->b < b.b) || (l == b.l && this->b == b.b && h < b.h))
			return true;
		else return false;
	}

};

ostream& operator<<(ostream& os, const Box& box) {
	os << to_string(box.getLength()) << " " << to_string(box.getBreadth()) << " "
		<< to_string(box.getHeight());
	return os;
}

//int main() {
//	string str;
//
//	const char* s;
//	int T; cin >> T;
//	
//	while (T--) {
//		string username;
//		cin >> username;
//		try {
//			bool isValid = checkUsername(username);
//			if (isValid) {
//				cout << "Valid" << '\n';
//			}
//			else {
//				cout << "Invalid" << '\n';
//			}
//		}
//		catch (BadLengthException e) {
//			cout << "Too short: " << e.what() << '\n';
//		}
//	}
//	return 0;
//}