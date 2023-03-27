#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		string cows;
		int g = -1, h = -1;
		int nextG = 0, nextH = 0;

		cin >> n >> k;
		cin >> cows;
		string pat(n, '.');
		int count = 0;

		for (int i = 0; i < n; i++)
		{
			// first
			if (cows[i] == 'G' &&  g == -1 && i >= nextG)
					g = i + k; // put position
			else if( cows[i]=='H' && h == -1 &&  i >= nextH )
					h = i + k;


			if (i == g)
			{
				pat[i] = 'G';
				g = -1;
				nextG = i+k+1;
				count++;
			}
			else if ( i == h)
			{
				pat[i] = 'H';
				h = -1;
				nextH = i+k+1;
				count++;
			}
		}

		if (g != -1 )
		{
			for (int i = n - 1; i >= 0; i--)
				if (pat[i] == '.')
				{
					pat[i] = 'G';
					count++;
					break;
				}
		}

		if (h != -1 )
		{
			for( int i=n-1; i >= 0; i--)
				if (pat[i] == '.')
				{
					pat[i] = 'H';
					count++;

					break;
				}					
		}

		cout << count << "\n";
		cout << pat << "\n";

	}



}