#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <unordered_map>
#include <set>
#include <limits.h>
#include <float.h>
#include <string.h>

#define Endl << "\n"
#define endL << "\n" <<
#define Cout cout <<
#define	COUT cout << "OUT: " <<
#define Cin cin >>
#define fspc << " "
#define spc << " " <<
#define Enter cout << "\n"
#define if if
#define elif else if
#define else else
#define For(n) for(int i = 0; i < n; i++)
#define Forj(n) for(int j = 0; j < n; j++)
#define Foro(n) for(int i = 1; i <= n; i++)
#define Forjo(n) for(int j = 1; j <= n; j++)
#define between(small, middle, big) (small < middle && middle < big)
#define among(small, middle, big) (small <= middle && middle <= big)
#define stoe(container) container.begin(), container.end()
#define lf(d) Cout fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PI 3.14159265359

typedef long long LLONG;
typedef unsigned long long ULLONG;
typedef unsigned int UINT;

using namespace std;

template <typename T>
class heap : public priority_queue<T, vector<T>, greater<T>>
{
};

void MakeTree(int cur, vector<bool>& isUsed, vector<vector<int>>& graph, vector<vector<int>>& tree)
{
	isUsed[cur] = true;

	for (auto nxt : graph[cur])
	{
		if (isUsed[nxt])
			continue;

		tree[cur].push_back(nxt);
		MakeTree(nxt, isUsed, graph, tree);
	}
}

int SNS(int cur, bool ep, vector<array<int, 2>>& dp, vector<vector<int>>& tree)
{
	int& result = dp[cur][ep];
	if (result != -1)
		return result;

	int isPick = 1;
	for (auto nxt : tree[cur])
		isPick += SNS(nxt, true, dp, tree);

	int noPick = INT_MAX * !ep;
	if (ep)
	{
		for (auto nxt : tree[cur])
			noPick += SNS(nxt, false, dp, tree);
	}
	return result = min(isPick, noPick);
}

int main()
{
	FastIO;

	int n;
	Cin n;

	vector<vector<int>> graph(n + 1), tree(n + 1);
	vector<bool> isUsed(n + 1, false);
	For(n - 1)
	{
		int u, v;
		Cin u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	MakeTree(1, isUsed, graph, tree);

	vector<array<int, 2>> dp(n + 1, { -1,-1 });
	Cout SNS(1, true, dp, tree);
}