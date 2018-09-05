/*
http://vnoi.info/problems/VBLOCKS/
    Algorithm: DP + BIT/IT
    Solution:
        - Determine F[i].first and F[i].second is the largest number of segments
                as possible and number of cells that have been covered.
        - Count number of cells type 1 and 2 using suffix array
        - Use Fenwick Tree to calculate Max(F[i-s-d]) (prioritize covered cells)
        - Formula: F[i] = F[i-1] if there are some must-uncovered cells
                        = Max(F[i-s-d]) + pair(1, <number of must-covered cells in i-s+1..i>)
    Time Complexity: O(L * log(L))
*/

#include <bits/stdc++.h>
#define nmax 100005
#define f first
#define s second
using namespace std;
int l, s, d, k, x, id, p, q, cnt, ans, a[nmax], blocks[nmax], must[nmax];
pair<int, int> f[nmax], t[nmax];
void update(int x, pair<int, int> val)
{
    for (; x < nmax; x += x&(-x))
        if (t[x].s < val.s || (t[x].s == val.s && t[x].f < val.f))
            t[x] = val;
}
pair<int, int> get(int x)
{
    pair<int, int> res = make_pair(0, 0);
    for (; x > 0; x -= x&(-x))
         if (t[x].s > res.s || (t[x].s == res.s && t[x].f > res.f))
            res = t[x];
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> l >> s >> d >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> x >> id;
        if (id == 1) must[x] = 1, cnt++;
        if (id == 2) blocks[x] = 1;
    }
    for (int i = 1; i < nmax; i++)
    {
        must[i] += must[i-1];
        blocks[i] += blocks[i-1];
    }
    for (int i = s; i <= l; i++)
    {
        if (blocks[i] - blocks[i-s] == 0)
        {
            if (i - s - d < 0)
            {
                f[i].f = 1;
                f[i].s = must[i] - must[i-s];
            }
            else
            {
                pair<int,int> p = get(i - s - d);
                f[i].f = p.f + 1;
                f[i].s = p.s + must[i] - must[i-s];
            }
        }
        else
            f[i] = f[i-1];
        update(i, f[i]);
    }
    ans = -1;
    for (int i = s; i <= l; i++)
        if (f[i].s == cnt) ans = max(ans, f[i].f);
    cout << ans << endl;
}
