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
#define COUT cout << "OUT: " <<
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

enum eState {
	None = 0,
	Home,
	Chicken
};

struct Pos {
	int y, x;
};

int Dist(Pos a, Pos b)
{
	return abs(a.y - b.y) + abs(a.x - b.x);
}

int ChickenStreet(int idx, int cnt, int m, vector<Pos>& home, vector<Pos>& chicken, vector<bool>& isAvaliable)
{
	if (idx == chicken.size())
		return INT_MAX;

	if (cnt == m)
	{
		
	}
}
int main()
{
	FastIO;

	int n, m;
	Cin n >> m;

	vector<Pos> home, chicken;
	For(n)
	{
		Forj(n)
		{
			int state;
			Cin state;

			if (state == Home)
				home.push_back({ i,j });
			elif(state == Chicken)
				chicken.push_back({ i,j });
		}
	}
	vector<bool> isAvaliable(chicken.size(), false);

}