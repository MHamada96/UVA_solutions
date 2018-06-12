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
const int mx = 1000 + 5;
int a, b;
int A, B, N;
int vis[mx][mx];
map<pair<int, int>, pair<pair<int, int>, string> > parent_of;

void pour(int &n1, int &n2, int c2)
{
	int mn = min(n1, c2 - n2);
	n1 -= mn;
	n2 += mn;
}


int main()
{
	fast();
	while (cin >> A >> B >> N)
	{
		a = 0;
		b = 0;
		memset(vis, false, sizeof vis);
		parent_of.clear();
		queue<pair<int, int> >q;

		q.push({ a, b }); // {0,0} => both jugs are empty 
		vis[a][b] = true;
		parent_of[{a, b}] = { { -1, -1 }, "root" };

		while (!q.empty())
		{
			int Front_a = q.front().FF;
			int Front_b = q.front().SS;

			if (Front_b == N)
			{
				// print the solution 
				vector<string> ans;
				ans.push_back("success");
				a = Front_a;
				b = Front_b;
				int tempA, tempB;
				while (parent_of[{a, b}].SS != "root")
				{
					ans.push_back(parent_of[{a, b}].SS);

					tempA = parent_of[{a, b}].FF.FF;
					tempB = parent_of[{a, b}].FF.SS;

					a = tempA;
					b = tempB;
				}
				reverse(ans.begin(), ans.end());

				for (int i = 0; i < ans.size(); i++)
					cout << ans[i] << endl;

				break;
			}
			q.pop();

			/*   6 steps */

			// 1 => empty a
			a = 0;
			b = Front_b;
			if (vis[a][b] == false)
			{
				q.push({ a, b });
				vis[a][b] = true;
				parent_of[{a, b}] = { { Front_a, Front_b }, "empty A" };
			}

			// 2 => empty b
			a = Front_a;
			b = 0;
			if (vis[a][b] == false)
			{
				q.push({ a, b });
				vis[a][b] = true;
				parent_of[{a, b}] = { { Front_a, Front_b }, "empty B" };
			}

			// 3 => fill a
			a = A;
			b = Front_b;
			if (vis[a][b] == false)
			{
				q.push({ a, b });
				vis[a][b] = true;
				parent_of[{a, b}] = { { Front_a, Front_b }, "fill A" };
			}

			// 4 => fill b
			a = Front_a;
			b = B;
			if (vis[a][b] == false)
			{
				q.push({ a, b });
				vis[a][b] = true;
				parent_of[{a, b}] = { { Front_a, Front_b }, "fill B" };
			}

			// 5 => puor A B
			a = Front_a;
			b = Front_b;
			pour(a, b, B);
			if (vis[a][b] == false)
			{
				q.push({ a, b });
				vis[a][b] = true;
				parent_of[{a, b}] = { { Front_a, Front_b }, "pour A B" };
			}

			// 6 => puor B A
			a = Front_a;
			b = Front_b;
			pour(b, a, A);
			if (vis[a][b] == false)
			{
				q.push({ a, b });
				vis[a][b] = true;
				parent_of[{a, b}] = { { Front_a, Front_b }, "pour B A" };
			}
		}
	}
}