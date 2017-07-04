#include<iostream>

#include<fstream>
#include<istream>
#include<ostream>

#include<vector>
#include<deque>
#include<set>
#include<map>
#include<queue>

#include<string>
#include<cstring>
#include<sstream>

#include<cmath>
#include <stdlib.h>
#include<iomanip>
#include<algorithm>
#include<assert.h>

using namespace std;

#define PI		3.14159265
#define OO		1e9
#define S       second
#define F       first  


int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, 1, -1, 1, -1 };
//fstream f("output.txt", ios::in | ios::out);

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
string road = "IEHOVA#";
int n, m;
char grid[10][10];

bool valid(int i, int j)
{
	return i >= 0 && j >= 0 && i < n && j < m;
}

void Track(int r, int c, int pos = 0)
{
	if (pos == road.size())
		return;

	if (pos)
		cout << " ";

	if (valid(r - 1, c) && grid[r - 1][c] == road[pos])
	{
		cout << "forth";
		Track(r - 1, c, pos + 1);
	}
	else if (valid(r, c - 1) && grid[r][c - 1] == road[pos])
	{
		cout << "left";
		Track(r, c - 1, pos + 1);
	}
	else if (valid(r, c + 1) && grid[r][c + 1] == road[pos])
	{
		cout << "right";
		Track(r, c + 1, pos + 1);
	}
}
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int r, c;
		cin >> n >> m;
		for (int i = 0; i < n;i++)
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] == '@')
				r = i, c = j;
		}
		Track(r, c);
		cout << endl;
	}
}