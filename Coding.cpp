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

map<string, int> mp;
map<string, int> Hash;
vector<string> v;

bool Less(string s1, string s2)
{
	if (s1 == "ROOT")
		return 1;
	if (s2 == "ROOT" )
		return 0;

	if (s1.size() < s2.size())
		return 1;
	if (s1.size() > s2.size())
		return 0;

	for (int i = 0; i < min(s1.size(), s2.size()); i++)
	{
		if (s1[i] < s2[i])
			return 1;
		else if (s1[i] > s2[i])
			return 0;
	}
}
int main()
{
	//fstream f("output.txt", ios::in | ios::out);
//#define cout f


	string s;

	while (cin >> s)
	{
		if (s == "()")
		{
			if (mp["ROOT"] != 1)
				cout << "not complete" << endl;
			else
			{
				bool ok = true;
				map<string, int>::iterator it;
				for (it = mp.begin(); it != mp.end(); it++)
				{
					string parent = it->first;
					parent.pop_back();

					if (it->second != 1 || (it->first != "ROOT" && it->first.size() > 1 && mp[parent] != 1))
					{
						ok = false;
						cout << "not complete" << endl;
						break;
					}
				}

				if (ok)
				{
					for (it = mp.begin(); it != mp.end(); it++)
						v.push_back(it->first);

					for (int i = 0; i < v.size(); i++)
					for (int j = i + 1; j < v.size(); j++)
					if (Less(v[j], v[i]))
						swap(v[j], v[i]);

					for (int i = 0; i < v.size(); i++)
					{
						cout << Hash[v[i]];
						if (i != v.size() - 1)
							cout << " ";
					}
					cout << endl;
				}
			}
			mp.clear();
			v.clear();
		}

		else
		{
			string LR;
			int value;
			char c;

			stringstream ss(s);

			ss >> c >> value >> c >> LR;
			LR.pop_back(); // (11,LL) , pos = LL) , so need to erase ")" 

			if (!LR.size())
				LR = "ROOT";

			mp[LR]++;
			Hash[LR] = value;
		}
	}
}