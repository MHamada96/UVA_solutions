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
//#define cout f

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
bool vis[1000][1000];
char grid[100][100];
multiset<pair<int, char> > ans_set;

int n, m, T, C;

void clear()
{
	memset(vis, false, sizeof vis);
	ans_set.clear();
}
bool valid(int i, int j)
{
	return  i >= 0 && j >= 0 && i < n && j < m;
}
void DFS(int i, int j,char land)
{
	if (!valid(i, j) || vis[i][j] || grid[i][j] != land)
		return;

	C++;
	vis[i][j] = true;
	
	for (int I = 0; I < 4; I++)
		DFS(i + dx[I], j + dy[I], land);
}

int main()
{
	int Test = 1;
	while (cin>>n>>m)
	{
		if (n == 0 && m == 0)
			return 0;

		clear();

		for (int i = 0; i < n;i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				C = 0;

				if (grid[i][j] != '.')
					DFS(i, j, grid[i][j]);

				if (C)
					ans_set.insert(make_pair(-C, grid[i][j]));
			}
		}

		cout << "Problem " << Test++ << ":" << endl;

		set<pair<int, char> >::iterator it = ans_set.begin();

		for (; it != ans_set.end(); it++)
			cout << it->second << " " << abs(it->first) << endl;
	}

}
