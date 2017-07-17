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

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
vector<string> Maze;
bool vis[1000][1000];

bool valid(int i, int j)
{
	int size = Maze.size();

	if (i < 0 || i >= size)
		return false;

	int len = Maze[i].size();

	return j >= 0 && j < len;
}

void dfs(int i, int j)
{
	if (!valid(i, j) || vis[i][j] || Maze[i][j] != ' ')  // invalid cell
		return;

	Maze[i][j] = '#';
	vis[i][j] = true;

	for (int T = 0; T < 4; T++)
		dfs(i + dx[T], j + dy[T]);
}
void Clear()
{
	Maze.clear();
	memset(vis, false, sizeof vis);
}
int main()
{

	string s;
	int T;
	cin >> T;

	cin.ignore();

	while (getline(cin, s))
	{
		if (s[0] == '_') // run Floodfill 
		{
			int startX;
			int startY;
			bool ok = 1;
			for (int i = 0; i < Maze.size() && ok; i++)
			for (int j = 0; j < Maze[i].size() && ok; j++)
			{
				if (Maze[i][j] == '*')
				{
					startX = i;
					startY = j;
					ok = 0;
				}
			}

			// make * = 0 
			Maze[startX][startY] =  ' ';

			// run flood fill
			dfs(startX, startY);

			// print the answer
			for (int i = 0; i < Maze.size(); i++)
			{
				cout << Maze[i] << endl;
			}
			cout << s << endl;

			Clear();
		}
		else
			Maze.push_back(s);
	}
}
