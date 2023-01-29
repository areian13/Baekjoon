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

array<int, 3> dy = { 0,1,1 };
array<int, 3> dx = { 1,0,1 };

void DFS(int y, int x, int d, vector<vector<int>>& map, int& result)
{
	if (y == map.size() - 1 && x == map.size() - 1)
	{
		result++;
		return;
	}
	
	For(3)
	{
		if (d == 0 && i == 1 || d == 1 && i == 0)
			continue;

		int ny = y + dy[i];
		int nx = x + dx[i];
		
		if (ny >= map.size() || nx >= map.size())
			continue;
		if (map[ny][nx] == 1)
			continue;
		if (i == 2)
		{
			if (map[y + 1][x] == 1 || map[y][x + 1] == 1)
				continue;
		}

		DFS(ny, nx, i, map, result);
	}
}

int main()
{
	FastIO;

	int n;
	Cin n;

	vector<vector<int>> map(n + 1, vector<int>(n + 1));
	Foro(n)
	{
		Forjo(n)
			Cin map[i][j];
	}
	int result = 0;
	DFS(1, 2, 0, map, result);
	Cout result;
}