#include<bits/stdc++.h>
#define boost ios::sync_with_stdio(false); cin.tie(0)
#define ll 				long long int
#define ld 				long double
#define mk 				make_pair
#define pb 				push_back
#define f				first
#define s				second
#define fo(i,a,b) 		for(i=a;i<b;i++)
#define foe(i,a,b) 		for(i=a;i<=b;i++)
#define all(x)			x.begin(),x.end()
#define vi 				vector<int>
#define vl 				vector <long long int>
#define vpii			vector< pair<int,int> >
#define vpll 			vector < pair <long long int,long long int> >
#define MOD				1000000007
using namespace std;

ll add(ll x, ll y) {ll res=x+y; return(res>=MOD?res-MOD:res);}
ll mul(ll x, ll y) {ll res=x*y; return(res>=MOD?res%MOD:res);}
ll sub(ll x, ll y) {ll res=x-y; return(res<0?res+MOD:res);}
ll lcm(ll x, ll y) {ll res=(x*y)/__gcd(x,y); return res;}
ll power(ll x, ll y) {if(y<0) return 1; ll res=1; x%=MOD; while(y){if(y&1)res=mul(res,x); y>>=1; x=mul(x,x);} return res;}

const int MAX = 2e5 + 5;
ll fact[MAX], invf[MAX];

//This function outputs nCr % MOD
ll nCr(ll n, ll r){if(n<r||n<0||r<0)return 0; return mul(fact[n],mul(invf[n - r],invf[r]));}

void preprocess()
{
	fact[0] = 1;
	invf[0] = 1;
	for(ll i = 1; i < MAX; i++){
		fact[i] = mul(fact[i - 1], i);
		invf[i] = power(fact[i], MOD - 2);
	}
}

int main()
{
	boost;
	preprocess();
	ll n = 10,r = 2;

	cout << nCr(n,r);

	return 0;
}