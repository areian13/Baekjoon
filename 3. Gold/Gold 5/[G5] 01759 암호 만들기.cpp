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

void BT(string result, int prev, int l, int c, int mo, int ja, const vector<char>& a, const array<bool, 26>& isMo)
{

	if (result.size() == l)
	{
		if (mo >= 1 && ja >= 2)
			Cout result Endl;
		return;
	}
	
	for (int i = prev + 1; i < c; i++)
	{
		result += a[i];
		BT(result, i, l, c, mo + isMo[a[i] - 'a'], ja + !isMo[a[i] - 'a'], a, isMo);
		result.pop_back();
	}
}
int main()
{
	FastIO;

	array<bool, 26> isMo = { false, };
	isMo['a' - 'a'] = isMo['e' - 'a'] = isMo['i' - 'a'] = isMo['o' - 'a'] = isMo['u' - 'a'] = true;

	int l, c;
	Cin l >> c;
	
	vector<char> a(c);
	For(c)
		Cin a[i];
	sort(stoe(a));

	BT("", -1, l, c, 0, 0, a, isMo);
}