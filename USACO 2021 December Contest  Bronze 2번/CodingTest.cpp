#include <bits/stdc++.h>
using namespace std;


//http://www.usaco.org/index.php?page=viewproblem2&cpid=1156
// Problem 2. Air Cownditioning

// Farmer John's cows N
 // are very particular about the room temperature in their barn. Some cows like the temperature to be on the cooler side, while others prefer more warmth.
// Farmer John's barn contains a sequence of N
 // stalls, numbered 1…N
// , each containing a single cow. The i
// -th cow prefers the temperature of her stall to be pi
// , and right now the temperature in her stall is ti
// . In order to make sure every cow is comfortable, Farmer John installs a new air conditioning system that is controlled in a somewhat interesting way. He can send commands to the system telling it to either raise or lower the temperature in a consecutive series of stalls by 1 unit --- for example "raise the temperature in stalls 5…8
 // by 1 unit". The series of stalls could be as short as just a single stall.

// Please help Farmer John determine the minimum number of commands he needs to send his new air conditioning system so that every cow's stall is at the ideal temperature for its resident cow.

// INPUT FORMAT (input arrives from the terminal / stdin):
// The first line of input contains N
// . The next line contains the N
 // non-negative integers p1…pN
// , separated by spaces. The final line contains the N
 // non-negative integers t1…tN
// .
// OUTPUT FORMAT (print output to the terminal / stdout):
// Please write a single integer as output containing the minimum number of commands Farmer John needs to use.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	
	cin >> N;


	vector<int> p(N);
	int t;

	for (int i = 0; i < N; i++)
		cin >> p[i];
	for (int i = 0; i < N; i++)
	{
		cin >> t;

		p[i] -= t;

	}


	int count = 0;
	int step;
	for (int i = 0; i < N; )
	{
		if (p[i] == 0)
		{
			i++;
			continue;
		}

		if (p[i] > 0)
			step = -1;
		else
			step = 1;

		for (int j = i; j < N; j++)
		{
			if (p[j] == 0)
				break;
			if (step * p[j] > 0) //0이거나 부호가 다르면 정지
				break;

			if (j == i && j < N - 1 && p[j + 1] == 0)
			{
				count += (fabs(p[i]) -1 );
				p[j] = 0;
				break;
			}

			p[j] += step;

		}
		count ++;

	}
	cout << count; 

}
