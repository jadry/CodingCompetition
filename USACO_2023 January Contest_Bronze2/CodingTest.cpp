﻿#include <bits/stdc++.h>


using namespace std;






int N, M;
vector<int> stalls(100);
vector<int> a(10);
vector<int> b(10);
vector<int> p(10);
vector<int> m(10);


int GetCost(int mask)
{
	vector<int> cool = stalls;

	int cost = 0;
	int index = 1;
	for (int i = 0; i < M; i++)
	{
		if ((mask & index) == 0) // not used aircon
		{
			index <<= 1;
			continue;
		}

		for (int j = a[i]; j <= b[i]; j++)
		{
			cool[j-1] -= p[i];
		}
		cost += m[i];

		index <<= 1;
	}

	for (int i = 0; i < 100; i++)
	{
		if (cool[i] > 0) // cooling failed
			return -1;
	}

	return cost;
}


int main()
{
	

	//vector<int> v = {1,2,3,4,5};
	//vector<int> out;

	//P(v, out, 3, 0);



	cin >> N >> M;
		
	int s, t, c;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> t >> c;

		for (int j = s-1; j < t; j++)
		{
			stalls[j] = c;
		}
	}

	for (int i = 0; i < M; i++)
	{
		cin >> a[i] >> b[i] >> p[i] >> m[i];
	}

	int min = -1;
	int last = (1 << M) - 1;
	for (int i = 1; i <= last; i++)
	{
		int cost = GetCost(i); // -1 if no cooling

		if (cost == -1)
			continue;

		if (min == -1)
			min = cost;
		else if (cost < min)
			min = cost;
	}


	cout << min;
}