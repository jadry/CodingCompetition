#include <bits/stdc++.h>
#include <cstdlib>


using namespace std;
void showlist(vector<int> g)
{
	for (int i = 0; i < g.size(); i++)
	{
		cout << g[i] << "\n";
	}
}


vector<string> split(string input, char delimiter)
{
	stringstream stream;

	stream.str(input);
	vector<string> result;
	string tmp;
	while (getline(stream, tmp, delimiter))
	{
		//cout << tmp << endl;
		result.push_back(tmp);
	}

	return result;

}






int hundreds, tens, ones, cont = 0;


int trying(int a) {
	if (a <= 2) {
		return 1;
	}
	else
	{
		return trying(a - 1) + trying(a - 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout << trying(10);
}
