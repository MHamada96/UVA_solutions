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

fstream out("output.txt", ios::in | ios::out);
fstream in("input.txt", ios::in | ios::out);

//#define cout out
//#define cin  in 

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
}
vector<string> forest;
int arr[1000][1000];
bool vis[1000][1000];
int n, m;
int Rank;

void reduce(string &s)
{
	string T;
	for (int i = 0; i < s.size(); i++)
	if (s[i] != ' ')
		T += s[i];
	s = T;
}
bool valid(int i, int j)
{
	return i >= 0 && j >= 0 && i < n && j < m;
}
void dfs(int i, int j, int R)
{
	vis[i][j] = 1;
	arr[i][j] = R;
	for (int T = 0; T < 8; T++)
	{
		int II = i + dx[T];
		int JJ = j + dy[T];
		if (valid(II, JJ) && !vis[II][JJ] && forest[i][j] == forest[II][JJ])
			dfs(II, JJ, R);
	}
}
int Max_Spaces(int col)
{
	int T = -1;

	for (int i = 0; i < n; i++)
		T = max(T, arr[i][col]);

	return  1 + log10(T*1.0);
}
void CLEAR()
{
	forest.clear();
	memset(vis, false, sizeof vis);
}

void Solve()
{
	n = forest.size();
	m = forest[0].size();
	int Rank = 1;

	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	if (!vis[i][j])
		dfs(i, j, Rank), Rank++;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(Max_Spaces(j)) << right << arr[i][j];
			if (j != m - 1)
				cout << " ";
		}
		cout << endl;
	}
	cout << "%" << endl;

	CLEAR();
}
int main()
{
	/*
		explaination on algorithmist : http://www.algorithmist.com/index.php/UVa_776

		note : "separated by as many blank spaces 
				as required to align ""columns"" to the right "
	*/
	string s;

	while (getline(cin, s))
	{
		if (s != "%")
		{
			reduce(s);
			forest.push_back(s);
		}
		else
			Solve();
	}

	Solve();
}
