//http://vnoi.info/problems/FP/
#include <bits/stdc++.h>
#define nmax 105
using namespace std;
pair<string, int> a[nmax];
string f[nmax][nmax][nmax];
int n, k, test;
int sum(string s)
{
    int res = 0;
    for (int i = 0; i < s.length(); i++) res += s[i] - '0';
    return res;
}

string MAX(string a, string b)
{
    if (a.length() > b.length()) return a;
    if (b.length() > a.length()) return b;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] > b[i]) return a;
        if (a[i] < b[i]) return b;
    }
    return a;
}

bool cmp(pair<string, int> a, pair<string, int> b)
{
    return a.first + b.first > b.first + a.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> test;
    while (test-- > 0)
    {
        for (int i = 1; i < nmax; i++) a[i].first = "", a[i].second = 0;
        for (int i = 0; i < nmax; i++)
            for (int j = 0; j < nmax; j++)
                for (int kk = 0; kk < nmax; kk++)
                    f[i][j][kk] = "";
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i].first, a[i].second = sum(a[i].first) % 9;
        sort(a + 1, a + 1 + n, cmp);
        f[1][1][a[1].second] = a[1].first;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
                for (int kk = 0; kk < 9; kk++)
                {
                    f[i][j][kk] = MAX(f[i][j][kk], f[i-1][j][kk]);
                    if (f[i-1][j-1][(kk - a[i].second + 9) % 9] != "" ||
                        (f[i-1][j-1][(kk - a[i].second + 9) % 9] == "" && kk == a[i].second && j == 1))
                    f[i][j][kk] =  MAX(f[i-1][j-1][(kk - a[i].second + 9) % 9] + a[i].first, f[i][j][kk]);
                }
        }
        if (f[n][k][0] == "") cout << -1 << endl;
            else cout << f[n][k][0] << endl;
    }
}
