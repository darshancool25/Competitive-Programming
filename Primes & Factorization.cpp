Sieve :

const int MAX = 1e6 + 5;
bool prime[MAX];
int spf[MAX];

void sieve()
{
    memset(prime, true, sizeof(prime));
    for (int i = 1; i < MAX; i++)spf[i] = i;
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                if (prime[j]) spf[j] = i;
                prime[j] = false;
            }
        }
    }
}

--------------------------------------------------------------

Prime Factorization [Single Query] :

vector<int> primeFactors(long long int n)
{
    vector<int> pfact;
    while (n % 2 == 0) {
        pfact.push_back(2);
        n = n / 2;
    }
    long long int i;
    for ( i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            pfact.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)pfact.push_back(n);
    return pfact;
}

--------------------------------------------------------------

Prime Factorization [Multiple Query] :

vector<int> getFactorization(long long int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}


[Div2 - D]
https://codeforces.com/contest/959/problem/D
soln - https://codeforces.com/contest/959/submission/83329289



