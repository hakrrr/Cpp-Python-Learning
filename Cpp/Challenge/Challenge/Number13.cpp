#include "pch.h"

#define contains(con, ele) (find(con.begin(), con.end(), ele) != con.end())
#define FOR(x) for(int i = 0; i < x; i++)
#define FORR(con) for (int i = con.size()-1; i >= 0; i--)
#define set(arr, to, d) arr[0] = to, arr[1] = d;

using namespace std;
typedef pair<int, int> iPair;

const char* alph = "abcdefg";

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
	if (next_permutation(w.begin(), w.end()))
		return w;
	else return "no answer";
}

bool* prune(int& n, int& k, int* degree, int* children, int* letters, int*** adj) {
	bool* isLetter = new bool[n](), * res = new bool[n]();
	vector<int> queue;
	FOR(k)	isLetter[letters[i]] = 1;

	//Init queue
	FOR(n)	if (degree[i] == 1 && !isLetter[i])	queue.push_back(i);

	while (!queue.empty()) {
		int leaf = queue[queue.size() - 1];
		queue.pop_back();
		res[leaf] = 1;

		FOR(degree[leaf]) {
			int parent = adj[leaf][i][0];
			if (isLetter[parent]) break;
			else if (!res[parent] && --children[parent] == 1) {
				queue.push_back(parent);
				break;
			}
		}
	}
	return res;
}

int*** adjG(int& n, int* degree, int* children, int* from, int* to, int* d) {
	int*** res = new int**[n];
	int* count = new int[n]();
	FOR(n - 1)	++count[from[i]], ++count[to[i]]; //count[i] = how many connections has node i
	
	FOR(n)	res[i] = new int* [count[i]], degree[i] = count[i], children[i] = count[i];
	FOR(n - 1) {
		res[from[i]][--count[from[i]]] = new int [2];
		set(res[from[i]][count[from[i]]], to[i], d[i]);

		res[to[i]][--count[to[i]]] = new int [2];
		set(res[to[i]][count[to[i]]], from[i], d[i]);
	}
	return res;
}

//return value is local! Don't do that!
int* bfs(int start, int& total, int* degree, bool* pruned, int*** adj) {
	bool calcT = !total;
	int max[2] = { -1, INT_MIN };
	vector<iPair> queue;	//stored as (to, dist)
	queue.push_back(iPair(start, 0));

	while (!queue.empty())
	{
		iPair curr = queue.at(queue.size() - 1);
		queue.pop_back();
		FOR(degree[curr.first]) {
			int dest = adj[curr.first][i][0];
			if (!pruned[dest]) {
				int dist = curr.second + adj[curr.first][i][1];
				if(calcT) total += adj[curr.first][i][1];
				queue.push_back(iPair(dest, dist));
				if (max[1] < dist)	max[0] = dest, max[1] = dist;
				pruned[curr.first] = 1;
			}
		}
	}

	return max;
}

int solve(int& n, int& k, int* letters, int* from, int* to, int* d) {
	int total = 0, * degree = new int[n], * children = new int[n];
	int*** G = adjG(n, degree, children, from, to, d);
	bool* pruned = prune(n, k, degree, children, letters, G), *prunedCpy = new bool[n];
	memcpy(prunedCpy, pruned, sizeof(bool) * n);
	int diameter = bfs(bfs(letters[0], total, degree, pruned, G)[0], total, degree, prunedCpy, G)[1];
	return 2*total - diameter;
}


//int main()
//{
//	int n, k;
//	scanf_s("%d%d", &n, &k);
//	int* letters = new int[k];
//	int* from = new int[n-1], * to = new int[n-1], * d = new int[n-1];
//	FOR(k) scanf_s("%d", letters+i);
//	FOR(k) --letters[i];
//	FOR(n - 1) scanf_s("%d%d%d", from + i, to + i, d + i);
//	FOR(n - 1) --from[i], --to[i];
//	cout << solve(n, k, letters, from, to, d);
//}

