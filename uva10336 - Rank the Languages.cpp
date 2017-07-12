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
fstream f("output.txt", ios::in | ios::out);
#define cout f

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
bool vis[1000][1000];
char grid[100][100];
int Count[26];
int n, m, T, C;

void clear()
{
	memset(vis, false, sizeof vis);
	memset(Count, 0, sizeof Count);
}
bool valid(int i, int j)
{
	return  i >= 0 && j >= 0 && i < n && j < m;
}
void DFS(int i, int j,char lang)
{
	if (!valid(i, j) || vis[i][j] || grid[i][j] != lang)
		return;

	C++;
	vis[i][j] = true;
	
	for (int I = 0; I < 4; I++)
		DFS(i + dx[I], j + dy[I], lang);
}

int main()
{
	cin >> T;
	for (int t = 1; t <= T;t++)
	{
		clear();

		cin >> n >> m;
		for (int i = 0; i < n;i++)
		for (int j = 0; j < m; j++)
			cin >> grid[i][j];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				C = 0;
				DFS(i, j, grid[i][j]);
				if (C)
					Count[grid[i][j] - 'a']++;
			}
		}

		cout << "World #" << t << endl;

		set<pair<int, char> > ans_set;
		for (int i = 0; i < 26; i++)
		if (Count[i])
			ans_set.insert(make_pair(-Count[i], char(i + 'a')));

		set<pair<int, char> >::iterator it = ans_set.begin();

		for (; it != ans_set.end(); it++)
			cout << it->second << ": " << abs(it->first) << endl;
	}

}