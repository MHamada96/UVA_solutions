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

fstream out("output.txt", ios::in | ios::out);
//fstream in("input.txt", ios::in | ios::out);

//#define cout out
//#define cin  in 

vector<string> Grid;
bool vis[30][30];
int N, M, Counter;

bool valid(int i, int j)
{
	return i >= 0 && j >= 0 && i < N && j < M;
}

void dfs(int i, int j)
{
	vis[i][j] = true;
	Counter++;
	for (int D = 0; D < 8; D++)
	{
		int II = i + dx[D];
		int JJ = j + dy[D];

		if (valid(II, JJ) && !vis[II][JJ] && Grid[II][JJ] == '1')
			dfs(II, JJ);
	}
}
void Clear()
{
	Grid.clear();
	memset(vis, false, sizeof vis);
}
int main()
{
	int n;
	cin >> n;
	char Buffer[30];
	gets(Buffer);
	gets(Buffer);

	while (n--)
	{
		while (gets(Buffer) && strlen(Buffer) > 0)
		{
			string s(Buffer);
			Grid.push_back(s);
		}

		N = Grid.size();
		M = Grid[0].size();
		int ans = 0;
		for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			if (!vis[i][j]&&Grid[i][j]=='1')
			{
				Counter = 0;
				dfs(i, j);
				ans = max(ans, Counter);
			}
		}

		cout << ans << endl;
		if (n)
			cout << endl;
		Clear();
	}

}
