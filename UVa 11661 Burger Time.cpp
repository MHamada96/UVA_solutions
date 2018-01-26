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

int main()
{
	fast();

	int Len;
	string s;
	while (cin >> Len && Len)
	{
		cin >> s;

		int LastD = -1;
		int LastR = -1;
		int ans = OO;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'R')
			{
				LastR = i;
				if (LastD != -1)
					ans = min(ans, i - LastD);
			}
			else if (s[i] == 'D')
			{
				LastD = i;
				if (LastR != -1)
					ans = min(ans, i - LastR);
			}
			else if (s[i] == 'Z')
			{
				ans = 0;
				break;
			}
		}
		cout << ans << endl;
	}
}