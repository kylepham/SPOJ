#include <bits/stdc++.h>
using namespace std;
string s;
int check[1000];
int cnt, k, j;
int main()
{
    cin >> s;
    cout << "brute force : ";
    for (int i = 0; i < s.length() - 1; i++)
        for (int j = i; j < s.length(); j++)
        {
            memset(check, 0, sizeof check);
            for (k = i; k <= j; k++)
                if (!check[(int)s[k]] != 0)
                {
                    check[(int)s[k]] = 1;
                }
                else break;
            if (k == j + 1) cnt = max(cnt, j - i + 1);
        }
    cout << cnt << endl;
    cnt = 0;
    cout << "full : ";
    j = 0;
    for (int i = 0; i < 1000; i++) check[i] = -1;
    check[(int)s[0]] = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (check[(int)s[i]] == -1)
        {
            check[(int)s[i]] = i;
            cnt = max(cnt, i - j + 1);
        }
        else
        {
            cnt = max(cnt, i - j);
            j = max(j,check[(int)s[i]] + 1);
            check[(int)s[i]] = i;
        }
    }
    cout << cnt << endl;
}
