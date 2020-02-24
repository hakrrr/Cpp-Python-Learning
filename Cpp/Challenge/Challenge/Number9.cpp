#include "pch.h"

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;

#define FOR(x, to) for(int x = 0; x < to; x++)
#define FOREACH(x, v) for(auto x : v)
#define ITR(x, a) for(auto x = a.begin(); x != a.end(); x++)
#define ALL(a) (a.begin(), a.end());
//---------------------------------------------------

//#typedef & #define
//#Modular division #Fermat's little Theorem #Exponantiation by Squaring #Precompiling #Multiplicative Inverse
//# +true == +1
//char * = string but don't forget the \0 at the end of the char * -> size+1!
//inverse(a) = (inverse(prime % a) * (prime - prime / a)) % prime


string m_String;
ui mod = 1000000007;
static ull *inv, *fact, *factr, *alphabets[26];

void initialize(string s) {
	m_String = s;
	const size_t _size = (s.size() / 2 + 1);

	fact = new ull[_size];
	factr = new ull[_size];
	inv = new ull[_size];
	fact[0] = factr[0] = inv[1] = 1;

	for (int i = 2; i < _size; ++i) inv[i] = (ull)inv[mod%i] * (mod - mod / i) % mod;

	for (int i = 1; i < _size; ++i) factr[i] = factr[i - 1] * inv[i] % mod,
		fact[i] = fact[i - 1] * i % mod;

	for (size_t i = 1; i < _size; i++) fact[i] = fact[i - 1] * i% mod;

	FOR(i, 26)    alphabets[i] = new ull[s.size() + 1];

	FOR(i, s.size()) {
		ui index = s[i] % 26;
		FOR(j, 26)    alphabets[j][i + 1] = alphabets[j][i] + (j == index);
	}
}

int answerQuery(int l, int r) {
	if (l == r)
		return 1;

	ui evenCounter, unevenCounter, nom;
	evenCounter = unevenCounter = 0;
	ull denom = 1, result;

	FOREACH(it, alphabets) {
		ui alphCounter = it[r] - it[l - 1];
		ui evens = alphCounter - (alphCounter % 2);

		if (alphCounter > 1) {
			denom *= factr[evens / 2];
			denom %= mod;
			evenCounter += evens;
			unevenCounter += alphCounter % 2;
		}
		else if (alphCounter == 1)
			unevenCounter++;

	}

	nom = fact[evenCounter / 2];

	result = nom * denom %mod;
	result = unevenCounter > 0 ? (result*unevenCounter) % mod : result;

	return result;
}

//ui expBySqr(ui base, ui exp) {
//	if (exp == 0)
//		return 1ll;
//	else if (exp == 1)
//		return base;
//	else {
//		ull result = expBySqr(base, exp / 2);
//		result *= exp % 2 == 0 ? result : (result * base) % mod;
//		result %= mod;
//		return (ui) result;
//	}
//}
//
//ui divMod(ui& nom, ui denom) {
//	ui inverse = expBySqr(denom, mod - 2);
//	ull result = (ull)inverse*nom;
//	result %= mod;
//	return (ui)result;
//}

//int main() {
//	const int NUM_ = 200003;
//	static long long inv[NUM_ + 1];
//	long long mo = 1000000007;
//	inv[1] = 1;
//	for (int i = 2; i <= NUM_; ++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
//
//	/*ui inv_2 = expBySqr(2, mod - 2);
//	FOR(i, 13) cout << "Current number: " << i << ": " << (ull)(pow(i, 13 - 2))%13 << endl;*/
//	int *a = new int[12];
//	int b[12];
//	int *c = (int*)malloc(sizeof(int) * 12);
//	initialize("aaaaaaa");
//	cout << factr[3];
//}