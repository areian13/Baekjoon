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

struct Point
{
	int y = 0, x = 0;
	bool operator==(const Point& p) const
	{
		return p.y == y && p.x == x;
	}
};

namespace std
{
	template<>
	struct hash<Point>
	{
		size_t operator()(const Point& pos) const
		{
			hash<int> hash_func;
			return hash_func(pos.y) ^ pos.x;
		}
	};
}

struct PlayerState
{
	Point spawnPoint;
	int maxHP = 20;
	int HP = maxHP;
	int offense = 2;
	int defense = 2;

	int level = 1;
	int exp = 0;
};
struct MonsterState
{
	int maxHP;
	int HP;
	int offense;
	int defense;
	int exp;
};
struct Equip
{
	char equipType;
	string effect;
};
struct EquipEffect
{
	int weapon = 0;
	int armor = 0;
	unordered_map<string, bool> isTaken;
};
class Player
{
private:
	Point mPos;
	PlayerState mState;
	EquipEffect mEffect;

	int nofEquip= 0;

public:

	void Position(Point pos)
	{
		mPos = pos;
	}
	Point Position()
	{
		return mPos;
	}
	void Position(int y, int x)
	{
		mPos = { y,x };
	}
	
	PlayerState State()
	{
		return mState;
	}
	EquipEffect Effect()
	{
		return mEffect;
	}
	void LevelUp()
	{
		mState.level++;
		mState.exp = 0;

		mState.maxHP += 5;
		mState.HP = mState.maxHP;
		mState.offense += 2;
		mState.defense += 2;
	}
	void GetEXP(int exp)
	{
		mState.exp += exp;
		if (mState.exp >= 5 * mState.level)
		{
			LevelUp();
		}
	}

	void TakeDamage(int damage)
	{
		mState.HP -= max(1, damage - (mState.defense + mEffect.armor));
	}
	void TakeFixedDamage(int damage)
	{
		mState.HP -= damage;
	}

	int Attack()
	{
		return mState.offense + mEffect.weapon;
	}
	void GetWeapon(int n)
	{
		mEffect.weapon = n;
	}
	void GetArmor(int n)
	{
		mEffect.armor = n;
	}

	void GetEquip(string equip)
	{
		mEffect.isTaken[equip] = true;
		nofEquip++;
	}
	void LostEquip(string equip)
	{
		mEffect.isTaken[equip] = true;
		nofEquip++;
	}

};
class Monster
{
private:
	string mName;
	MonsterState mState;

public:

	void Setting(string name, int maxHP, int offense, int defense, int exp)
	{
		mName = name;
		mState = { maxHP,maxHP,offense,defense,exp };
	}
	string Name()
	{
		return mName;
	}
	MonsterState State()
	{
		return mState;
	}

	void TakeDamage(int damage)
	{
		mState.HP -= max(1, damage - mState.defense);
	}
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0 };

int main()
{
	FastIO;

	Player player;

	int n, m;
	Cin n >> m;

	vector<vector<char>> grid(n + 1, vector<char>(m + 1));
	int nofMob = 0;
	int nofBox = 0;
	Foro(n)
	{
		Forjo(m)
		{
			Cin grid[i][j];
			
			switch (grid[i][j])
			{
			case '@':
				player.Position(i, j);
				grid[i][j] = '.';
				break;

			case 'M':
			case '&':
				nofMob++;
				break;

			case 'B':
				nofBox++;
				break;
			}
		}
	}

	string control;
	Cin control;

	unordered_map<Point, Monster> mobList;
	For(nofMob)
	{
		int r, c, w, a, h, e;
		string name;
		Cin r >> c >> name >> w >> a >> h >> e;
		mobList[Point{r, c}].Setting(name, w, a, h, e);
	}

	unordered_map<Point, Equip> boxList;
	For(nofBox)
	{
		int r, c;
		char t;
		string s;
		Cin r >> c >> t >> s;
		boxList[{r, c}] = { t,s };
	}

	int turn = 0;
	for (auto arrow : control)
	{
		turn++;

		int y = player.Position().y;
		int x = player.Position().x;

		int dir;
		switch (arrow)
		{
		case'L':
			dir = 0;
			break;

		case 'U':
			dir = 1;
			break;

		case 'R':
			dir = 2;
			break;

		case 'D':
			dir = 3;
			break;
		}

		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m || grid[ny][nx] == '#')
		{
			ny = y;
			nx = x;
		}
		player.Position(ny, nx);
		switch (grid[ny][nx])
		{
		case 'B':
		{
			Equip equip = boxList[{ny, nx}];
			switch (equip.equipType)
			{
			case 'W':
				player.GetWeapon(stoi(equip.effect));
				break;

			case 'A':
				player.GetArmor(stoi(equip.effect));
				break;

			case 'O':
				player.GetEquip(equip.effect);
				break;
			}
		}
		case '^':
		{
			int damage = 5;
			if (player.Effect().isTaken["DX"] == true)
			{
				damage = 1;
			}
			player.TakeFixedDamage(damage);
			break;
		}
		case 'M':
		case '&':
		{
			int battleTurn = 0;
			Monster mob = mobList[{ny, nx}];

			while (true)
			{
				battleTurn++;
				int attack = player.Attack();
				if (battleTurn == 1)
				{
					int attackBuf = 1;
					if (player.Effect().isTaken["DX"] == true && player.Effect().isTaken["CO"] == true)
						attackBuf = 3;
					elif(player.Effect().isTaken["CO"] == true)
						attackBuf = 2;
					attack *= attackBuf;
				}
				
				mob.TakeDamage(attack);
				if (mob.State().HP <= 0)
				{
					grid[ny][nx] = '.';
					player.GetEXP(mob.State().exp);

				}
			}
		}

		}

	}

}