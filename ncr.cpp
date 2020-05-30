const int MAX = 5e5 + 5;
ll fact[MAX], invf[MAX];
ll nCr(ll n, ll r) {if (n < r || n < 0 || r < 0)return 0; return mul(fact[n], mul(invf[n - r], invf[r]));}
void preprocess()
{
	fact[0] = 1;
	invf[0] = 1;
	for (ll i = 1; i < MAX; i++) {
		fact[i] = mul(fact[i - 1], i);
		invf[i] = power(fact[i], MOD - 2);
	}
}