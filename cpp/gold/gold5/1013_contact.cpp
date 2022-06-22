#include <iostream>
using namespace std;

bool contact(string str);

int main()
{
	int n;
	cin >> n;
	bool* results = new bool[n];
	for (int i = 0; i < n; i++)
	{
		string inp;
		cin >> inp;
		results[i] = contact(inp);
	}

	for (int i = 0; i < n; i++)
		if (results[i])
			cout << "YES\n";
		else
			cout << "NO\n";

}

bool contact(string str) 
{
	int i = 0;
	while (i < str.length()) 
	{
		if (str[i] == '1')
		{
			if (++i + 2 >= str.length() || str[i] != '0')
				return false;
			if (str[++i] != '0')
				return false;

			while (true) 
			{
				if (++i >= str.length())
					return false;

				if (str[i] == '1')
					break;

			}

			while (true)
			{
				if (++i >= str.length())
					return true;

				if (str[i] == '0')
					break;
			}

			if (++i >= str.length())
				return false;

			if (str[i] == '1') 
				i++;
			else
			{
				if (str[i - 3] != '1')
					return false;
				i -= 2;
			}
		}
		else
		{
			if (++i >= str.length() || str[i] != '1')
				return false;

			i++;
		}

	}

	return true;

}