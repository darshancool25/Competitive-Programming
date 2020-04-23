Decimal to Any Base :

char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

string fromDeci(long long int inputNum, int base)
{
	string res = "";
	while (inputNum > 0)
	{
		res += reVal(inputNum % base);
		inputNum /= base;
	}
	reverse(res.begin(), res.end());

	return res;
}

----------------------------------------------------------------------------------
Any Base to Decimal :

int val(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}
int toDeci(string str, int base)
{
	long long int len = str.length(), power = 1, num = 0, i;
	for (i = len - 1; i >= 0; i--)
	{
		if (val(str[i]) >= base)
		{
			cout << "INVALID NUMBER!";
			return -1;
		}
		num += val(str[i]) * power;
		power = power * base;
	}
	return num;
}

--------------------------------------------------------------------------------
Convert decimal to Binary String of same lengths :

string decToBinary(int n)
{
	// Size of an integer is assumed to be 32 bits
	string s;
	for (int i = 31; i >= 0; i--) {
		long long int k = n >> i;
		if (k & 1)	s += '1';
		else	s += '0';
	}
	return s;
}


[VERY EASY]
https://codeforces.com/contest/1312/problem/C
soln - https://codeforces.com/contest/1312/submission/74190710