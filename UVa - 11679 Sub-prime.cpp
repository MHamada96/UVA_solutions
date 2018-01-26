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
	int B, N;
	while (cin >> B >> N && B && N)
	{
		vector<int>v(B + 1);
		for (int i = 1; i <= B; i++)
			cin >> v[i];
		int D, C, Val;

		for (int i = 1; i <= N; i++)
		{
			cin >> D >> C >> Val;
			v[D] -= Val;
			v[C] += Val;
		}
		bool CanPay = true;
		for (int i = 1; i <= B; i++)
		if (v[i] < 0)
			CanPay = false;

		if (CanPay)
			cout << "S\n";
		else
			cout << "N\n";
	}

}