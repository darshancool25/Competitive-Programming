//Create diff and cover arrays globally [preferred];
// size of diff should be slightly more than cover array
int diff[10005], cover[10003];

void update(int l, int r, int x)
{
    diff[l] += x;
    diff[r + 1] -= x;
}

void work(int l, int r)
{
    cover[l] = diff[l];
    for (int i = l + 1; i <= r; i++)
        cover[i] = diff[i] + cover[i - 1];
}

void clean(int l, int r)
{
    for (int i = l; i <= r; ++i)
        cover[i] = diff[i] = 0;
}

//Note : Dont forget to clean arrays before use;

[CF BLOG]
https://codeforces.com/blog/entry/78762

[Easy]
https://codeforces.com/contest/1343/problem/D
soln - https://codeforces.com/contest/1343/submission/77688710

[Medium]
Hackerrank - Cloudy Day Problem
https://www.hackerrank.com/challenges/cloudy-day/problem

