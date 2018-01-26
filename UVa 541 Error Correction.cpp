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
		vector<vector<int> >v(n, vector<int>(n));
		vector<int> Rsum(n, 0);
		vector<int> Csum(n, 0);
		int OddRows = 0, OddCols = 0, x, y;
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				Rsum[i] += v[i][j];
				Csum[i] += v[j][i];
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (Rsum[i] % 2 == 1)
				OddRows++, x = i;
			if (Csum[i] % 2 == 1)
				OddCols++, y = i;
		}
			
		if (OddRows == 0 && OddCols == 0)
			cout << "OK\n";
		else if (OddRows == 1 && OddCols == 1 )
			cout << "Change bit (" << x + 1 << "," << y + 1 << ")\n";
		else
			cout << "Corrupt\n";
	}
}