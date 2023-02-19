#include <bits/stdc++.h>
using namespace std;


int N;
string breed;
vector<int> E(100001);
int g1 = -1; // first g
int h1 = -1;

//vector<bool> isChecked(100001);
//vector<bool> isLeader(100001);


bool isContainLeader(int index)
{
	if (breed[index] == 'G' && index > g1)
		return false;
	if (breed[index] == 'H' && index > h1)
		return false;

	for (int i = E[index]; i < N; i++)
	{
		if (breed[index] == breed[i])
			return false;
	}
	return true;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cin >> breed;
	for (int i = 0; i < N; i++)
		cin >> E[i];


	for (int i = 0; i < N; i++)
	{
		if (breed[i] == 'G' && g1 == -1)
			g1 = i;

		if (breed[i] == 'H' && h1 == -1)
			h1 = i;

		if (g1 >= 0 && h1 >= 0)
			break;
	}

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		int end = N;

		if (i > g1 && i> h1)
			break;

		if (breed[i] == 'G' && i > h1)
		{
			continue;
		}
		if (breed[i] == 'H' && i > g1)
		{
			continue;
		}

		if(isContainLeader(i) == false)
		{			
			end = E[i];
		}

		
		if (breed[i] == 'G' && h1 > i && h1 < end)
		{
			if (isContainLeader(h1))
			{
				count++;
			}

		}
		else if (breed[i] == 'H' && g1 > i && g1 < end)
		{
			if (isContainLeader(g1))
			{
				count++;
			}
		}

	}

	cout << count;

}
