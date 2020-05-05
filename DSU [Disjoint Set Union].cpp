Without Struct -

const int N = 1e4 + 5;
int par[N], sz[N], connected;

//sets parent of each node as itself
void init(ll n)
{
	ll i;
	for (int i = 1; i <= n; i++)
	{
		par[i] = i;
		sz[i] = 1;
	}
	connected = n;
}

//Finds and returns the root of the set containing x
int find(ll x)
{
	if (x == par[x]) return x;
	return par[x] = find(par[x]);  //optimization so that next time anyone queries we get answer in O(1).
}

int getSize(int k)
{
	return sz[find(k)];
}

//Performs set union operation of x,y
void union_set(ll x, ll y)
{
	int rt1 = find(x);
	int rt2 = find(y);
	if (rt1 == rt2) return;

	connected--;

	if (sz[rt1] > sz[rt2])
		swap(rt1, rt2);

	sz[rt2] += sz[rt1];
	sz[rt1] = 0;
	par[rt1] = par[rt2];
}

------------------------------------------------------------------------

Struct Implementation :
const int N = 1e4 + 5;
struct DSU
{
	int connected;
	int par[N], sz[N];

	DSU() {}

	DSU(int n)
	{
		for (int i = 1; i <= n; i++)
		{
			par[i] = i;
			sz[i] = 1;
		}
		connected = n;
	}

	int getPar(int x)
	{
		if (x == par[x]) return x;
		return par[x] = find(par[x]);
	}

	int getSize(int k)
	{
		return sz[getPar(k)];
	}

	void unite(int u, int v)
	{
		int par1 = getPar(u), par2 = getPar(v);

		if (par1 == par2)	return;

		connected--;

		if (sz[par1] > sz[par2])
			swap(par1, par2);

		sz[par2] += sz[par1];
		sz[par1] = 0;
		par[par1] = par[par2];
	}
};

[Very easy]
https://www.codechef.com/PRACTICE/problems/DISHOWN
soln - https://www.codechef.com/viewsolution/25358145



