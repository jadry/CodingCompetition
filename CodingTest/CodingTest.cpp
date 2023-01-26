#include <bits/stdc++.h>
using namespace std;


int h[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	deque<int> dq;


	dq.push_front(1);
	dq.push_front(2);
	dq.push_front(3);
	dq.push_front(4);


	while (!dq.empty())
	{
		cout << dq.front() << "\n";
		dq.pop_front();
	}






}
