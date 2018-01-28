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
	int n;
	while (cin >> n && n)
	{
		int FirstNum;
		while (cin >> FirstNum && FirstNum)
		{
			stack<int> st;
			vector<int>v(n);
			v[0] = FirstNum;
			for (int i = 1; i < n; i++)
				cin >> v[i];
			int cnt = 0;
			for (int i = 1; i <= n; i++)
			{
				st.push(i);
				while (!st.empty())
				{
					if (st.top() == v[cnt])
						st.pop(), cnt++;
					else
						break;
				}
			}
			if (st.empty())
				cout << "Yes\n";
			else
				cout << "No\n";
		}
		cout << "\n";
	}
}