#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>

using namespace std;
#define PI			3.14159265
#define OO			1e9
#define SS       	second
#define FF       	first  
#define Trace(n)  	cout<< #n <<" = "<< n << endl; 
#define ll			long long
#define endl		"\n"


int dx[] = { 0, 0, -1, 1, 1, 1, -1, -1 };
int dy[] = { -1, 1, 0, 0, 1, -1, 1, -1 };

void fast()
{
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}

map<char, vector<char> > adj;
vector<char>ans;
bool vis[26];
bool Exist[26];

void topoSort(char c)
{
	vis[c - 'A'] = true;

	for (int i = 0; i < adj[c].size(); i++)
	if (!vis[adj[c][i] - 'A'])
		topoSort(adj[c][i]);

	ans.push_back(c);
}


int main()
{
	fast();
	string s;
	vector<string>v;

	while (cin >> s)
	{
		if (s != "#")
			v.push_back(s);
		else
		{
			memset(vis, 0, sizeof vis);
			memset(Exist, 0, sizeof Exist);

			for (int i = 0; i < v.size() - 1; i++)
			{
				string s1 = v[i];
				string s2 = v[i + 1];

				int mn = min(s1.size(), s2.size());

				for (int j = 0; j < mn; j++)
				{
					if (s1[j] != s2[j])
					{
						adj[s1[j]].push_back(s2[j]);

						Exist[s1[j] - 'A'] = true;
						break;
					}
				}
			}

			for (int i = 0; i < 26; i++)
			if (Exist[i] && !vis[i])
				topoSort('A' + i);

			reverse(ans.begin(), ans.end());

			for (int i = 0; i < ans.size(); i++)
				cout << ans[i];

			v.clear();
			adj.clear();
			ans.clear();
			cout << endl;
		}
	}
}
