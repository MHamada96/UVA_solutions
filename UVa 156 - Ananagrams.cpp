#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define PI		3.14159265
#define OO		1e9
#define S       	second
#define F       	first  
#define Trace(n)  	cout<< #n <<" = "<< n << endl; 


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

bool TheSame(string s1, string s2)
{
	for (int i = 0; i < s1.size(); i++)
		s1[i] = tolower(s1[i]);

	for (int i = 0; i < s2.size(); i++)
		s2[i] = tolower(s2[i]);

	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());

	if (s1 == s2)
		return true;
	else
		return false;
}

int main()
{
	fast();
	string s;
	vector<string> v, ans;
	while (cin >> s && s != "#")
		v.push_back(s);

	for (int i = 0; i < v.size(); i++)
	{
		bool ok = true;
		for (int j = 0; j < v.size(); j++)
		if (i != j && TheSame(v[i], v[j]) == true)
		{
			ok = false;
			break;
		}
		if (ok)
			ans.push_back(v[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

}