// CodingTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>
using namespace std;


/* P1
int main()
{
	int n;

	cin >> n;
	vector<long long> c(n);
	for (int i = 0; i < n; i++)
		cin >> c[i];

	sort(c.begin(), c.end());

	long long max = 0;
	long tuition = 0;

	long long crnt = 0;

	for (int i = 0; i < n; i++)
	{
		crnt = c[i] * (n - i);
		if (crnt > max)
		{
			max = crnt;
			tuition = c[i];
		}
	}

	cout << max << " " << tuition << "\n";

}
*/



void solve()
{
	int n, k;
	string breed;
	cin >> n >> k;
	cin >> breed;

	string patch(n, '.');
	int count = 0;

	for (int i = k; i < n ; i++)
	{
		if (i < n-1 && breed[i - k] == '.')
			continue;

		for (int j = i - k; j <= i+k; j++)
		{
			if (j >= n)
				continue;

			if (patch[i] == '.' && breed[j] != '.')// i 위치에 패치 놓을 조건 
			{
				 
				patch[i] = breed[j];
				count++;
				breed[j] = '.';
			}
			else if (patch[i] != '.' && patch[i] == breed[j])// i위치의 패치와 같은 소를 feed 처리
			{
				breed[j] = '.';
			}
		}
	}

	int index = -1;
	for (int i = n - 1; i >= n - k - 1; i--)
	{
		if (index == -1 && patch[i] == '.')
			index = i;
	}

	if( index >= 0)
	{
		for (int i = n - 1; i >= n - k - 1; i--)
		{
			if (breed[i] != '.')
			{
				patch[index] = breed[i];
				breed[i] = '.';
				count++;
				break;
			}
		}

	}

	cout << count << "\n";
	for (char c : patch)
	{
		cout << c;
	}
	cout << "\n";
}


int main()
{
	// 공부하자!( 2022.12.19 )
	//int a = 3000000;
	//int n = 10000;

	//long long c = a * n;

	//c = 3000000 * 10000;

	//c = 3000000LL * 10000LL;

	//-----------------------------------------


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int t;
	
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		solve();

		//cout << n << " " << k << "\n";
		//cout << breed << "\n";
	}

}
