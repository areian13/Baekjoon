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

#define INF 1'000'000'000

struct Route
{
	int v, w;

	bool operator>(Route c) const
	{
		if (w == c.w)
			return v > c.v;
		return w > c.w;
	}
};

int main()
{
	FastIO;

	int n, m, k;
	Cin n >> m >> k;

	vector<vector<Route>> route(n + 1);
	For(m)
	{
		int u, v, w;
		Cin u >> v >> w;

		route[u].push_back({ v,w });
	}

	vector<int> dist(n + 1, INF);
	dist[k] = 0;

	heap<Route> H;
	H.push({ k,0 });

	while (!H.empty())
	{
		int cur = H.top().v;
		int curDist = H.top().w;
		H.pop();

		if (dist[cur] < curDist)
			continue;
		For(route[cur].size())
		{
			int nxt = route[cur][i].v;
			int nxtDist = curDist + route[cur][i].w;

			if (nxtDist >= dist[nxt])
				continue;

			dist[nxt] = nxtDist;
			H.push({ nxt,nxtDist });
		}
	}
	Foro(n)
	{
		if (dist[i] == INF)
			Cout "INF" Endl;
		else
			Cout dist[i] Endl;
	}
}