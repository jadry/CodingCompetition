#include <bits/stdc++.h>

//  https://www.acmicpc.net/problem/10809



using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	cin >> s;
	for (int i = 0; i < alphabet.length(); i++)
		cout << (int)s.find(alphabet[i]) << " ";
	return 0;

}