#include "pch.h"

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define FOR(from, to) for(int from = 0; from < to; from++)
#define ZERO(x) memset(x, 0, sizeof(x))

#pragma warning(disable : 4996)

int lexicographic_sort(const void* a, const void* b) {
	const char* ax = (const char*)a;
	const char* bx = (const char*)b;
	return strcmp(ax, bx);
}

int lexicographic_sort_reverse(const void* a, const void* b) {
	return -lexicographic_sort(a, b);
}

int distinctChar(const char* s) {
	int alphabet[26], res = 0;
	ZERO(alphabet);
	FOR(i, strlen(s)) {
		res += !alphabet[s[i] % 97] ? 1 : 0;
		alphabet[s[i] % 97] = 1;
	}
	return res;
}

int sort_by_number_of_distinct_characters(const void* a, const void* b) {
	int A = distinctChar((const char*)a), B = distinctChar((const char*)b);
	return A == B ? lexicographic_sort((const char*)a, (const char*)b) : A < B ? -1 : 1;
}

int sort_by_length(const void* a, const void* b) {
	return strlen((const char*)a) < strlen((const char*)b) ? -1 : 1;
}

void string_sort(char** arr, const int len, int (*cmp_func)(const void* a, const void* b)) {
	qsort(arr, len, sizeof(char*), cmp_func);
}


/*
4
wkue
qoi
sbv
fekls
*/