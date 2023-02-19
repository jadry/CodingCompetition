#include <bits/stdc++.h>
using namespace std;


void replace(string w, int count, set<string> dic);

int m;
int maxDepth;



bool go(string& w, int& count, set<string>& dic)
{
	if (w.length() < 3)
	{
		return false;
	}
	else if (dic.find(w) != dic.end())
		return false;
	else if (w.length() == 3)
	{
		if (w == "MOO")
		{
			if (m == -1 || m > count)
				m = count;

			if (count > maxDepth)
				maxDepth = count;
			return false;

		}
		else if (w[1] == 'M') // MMM 가운데 M이 있으면 불가능 
			return false;
	}

	// 중간에 'O'가 하나는 들어있어야 함
	bool haveO = false;
	for (int i = 1; i < w.length() - 1; i++)
	{
		if (w[i] == 'O')
		{
			haveO = true;
			break;
		}
	}
	if (haveO == false)
		return false;


	return true;
}



void del(string w, int count, set<string> dic)
{
	if (go(w, count, dic) == false)
		return;

	//-----------------------------------
	if (w.length() > 4)
	{
		int idx = w.find("MOO");
		if (idx != w.npos)
		{
			replace(w.substr(idx, 3), count + w.length() - 3, dic);
			return;
		}
		idx = w.find("MO");
		if (idx != w.npos && idx <= w.length() - 3)
		{
			replace(w.substr(idx, 3), count + w.length() - 3, dic);
			return;
		}

		if (w[1] == 'M')
		{
			string sub = w.substr(1);
			del(sub, count + 1, dic);
			return;
		}

		string sub = w.substr(0, w.length() - 1);
		del(sub, count + 1, dic);
		return;
	}
	else if (w.length() == 3)
	{
		replace(w, count, dic);
		return;
	}

	dic.insert(w);

	string sub = w.substr(1);
	replace(sub, count + 1, dic);

	sub = w.substr(0, w.length() - 1);
	replace(sub, count + 1, dic);
}



void replace(string w, int count, set<string> dic)
{
	if (go(w, count, dic) == false)
		return;

	//-----------------------------------

	if (w.length() > 3)
	{
		del(w, count, dic); // no replace
		return;
	}

	dic.insert(w);


	//-----------------------------------
	char s = w[0];
	if (w[0] == 'O')
		w[0] = 'M';
	else
		w[0] = 'O';

	del(w, count + 1, dic);

	//-----------------------------------
	if (w[w.length() - 1] == 'O')
		w[w.length() - 1] = 'M';
	else
		w[w.length() - 1] = 'O';

	del(w, count + 2, dic);


	//-----------------------------------
	w[0] = s;
	del(w, count + 1, dic);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);



	int Q;
	cin >> Q;
	set<string> dic;

	while (Q--)
	{
		m = -1;
		maxDepth = 0;
		dic.clear();

		string w;
		cin >> w;

		replace(w, 0, dic);
		cout << m << "\n";
	}


}
