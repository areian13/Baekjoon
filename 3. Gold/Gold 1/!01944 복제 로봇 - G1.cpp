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

int Find(int a, vector<int>& p)
{
	if (p[a] == -1)
		return a;
	return p[a] = Find(p[a], p);
}

void Union(int a, int b, vector<int>& p)
{
	a = Find(a, p);
	b = Find(b, p);

	p[b] = a;
}

struct Edge {
	int u = -1;
	int v = -1;
	int w = 0;
	bool operator<(const Edge& a) const
	{
		return w < a.w;
	}
};

struct Info {
	int y, x, p;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,-1,0,1 };

int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<vector<char>> map(n, vector<char>(n));
	vector<Edge> key(m + 1);
	Info start;
	For(n)
	{
		Forj(n)
		{
			Cin map[i][j];
			if (map[i][j] == 'S')
				start = { i,j, 0 };
		}
	}

	vector<vector<int>> dist(n, vector<int>(n, -1));
	queue<Info> Q;

	dist[start.y][start.x] = 0;
	Q.push(start);

	int keyIDX = 0;
	while (!Q.empty())
	{
		int y = Q.front().y;
		int x = Q.front().x;
		int p = Q.front().p;
		Q.pop();

		For(4)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || ny >= n)
				continue;
			if (map[ny][nx] == '1' || dist[ny][nx] != -1)
				continue;

			dist[ny][nx] = dist[y][x] + 1;
			if (map[ny][nx] == 'K')
			{
				key[keyIDX++] = { p,p + 1,dist[ny][nx] };
				p++;

				dist[ny][nx] = 0;
			}
			Q.push({ ny,nx,p });
		}
	}
	For(n)
	{
		Forj(n)
			printf("%2d ", dist[i][j]);
		Enter;
	}
	//sort(stoe(key));
	For(key.size())
	{
		Cout key[i].u spc key[i].v spc key[i].w Endl;
	}
	/*vector<int> p(m + 1);
	int result = 0;
	for (int i = 0, cnt = 0; ; i++)
	{
		if (Find(key[i].u, p) != Find(key[i].v, p))
		{
			Union(key[i].u, key[i].v, p);
			result += key[i].w;
			cnt++;
			if (cnt == m)
				break;
		}
	}
	Cout result;*/
}