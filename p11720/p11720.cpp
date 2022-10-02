// p11720.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//  https://www.acmicpc.net/problem/11720

#include <bits/stdc++.h>


using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count = 0;
	string bumber;
	int total = 0;
	int number;
	cin >> count;
	cin >> bumber;


	for (int i = 0; i < count; i++)
	{

		int x = ((int)bumber[i]) - 48;

		total = total + x;

	}
	cout << total;
}