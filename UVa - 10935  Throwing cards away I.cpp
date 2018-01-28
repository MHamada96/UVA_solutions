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
	cin >> n;
	while (n)
	{
		vector<int> disc;
		deque<int> dq;
		for (int i = 1; i <= n; i++)
			dq.push_back(i);
		while (dq.size() >=2)
		{
			disc.push_back(dq.front());
			dq.pop_front();
			dq.push_back(dq.front());
			dq.pop_front();
		}
		cout << "Discarded cards:";
		for (int i = 0; i < disc.size(); i++)
			cout << (i ? ", " : " ") << disc[i];
		cout << endl;
		cout << "Remaining card: " << dq.front() << endl;
		
		cin >> n;
	}
}