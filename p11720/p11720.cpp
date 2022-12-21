// p11720.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

//  https://www.acmicpc.net/problem/11720

#include <bits/stdc++.h>


using namespace std;



int main()
{
	long long n, p, d;

	cin >> n >> p >> d;

	long long  pExp10 = pow(10, p-1);
	long long  pDigit = n/pExp10%10;

	long long  change = 0;

	if (pDigit <= 4)
	{
		change = (pDigit + d) % 10;
	}
	else 
	{
		change = abs(pDigit - d);
		while (change > 10)
			change /= 10;
	}

	long long  result = n - (n % (pExp10*10)) + change * pExp10;

	cout << result;

}