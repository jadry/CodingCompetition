// CodingTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x;


	cin >> x;
	int i = 1;
	while (true)
	{
		if (x > i * (i - 1) / 2 && x <= i * (i + 1) / 2)
			break;

		i++;
	}

	x -= i * (i - 1) / 2;

	if (i % 2 == 0) // 우상단에서 좌하단 방향 
	{
		cout << x << "/" << (i + 1 - x) <<"\n";
	}
	else
	{
		cout << (i + 1 - x) << "/" << x << "\n";

	}


}