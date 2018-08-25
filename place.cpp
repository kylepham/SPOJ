#include<bits/stdc++.h>
#define maxN 500000+10
using namespace std;
vector<int> a[1000000];
bool dd[1000000];
char ch;
int x, u, v, n, m, w[1000000], spv[1000000],f[1000000], idx[1000000], first[1000000], last[1000000], cnt;
void update(int x, int v)
{
    for (; x <= maxN; x += x&(-x)) f[x] += v;
}

int get(int x)
{
    int res = 0;
    for (; x > 0; x -= x&(-x)) res+=f[x];
    return res;
}

void link(int x)
{
    first[x] = cnt;
    dd[x] = true;
    for (int i = 0; i < a[x].size(); i++)
    {
        idx[++cnt] = w[a[x][i]];
        link(a[x][i]);
    }
    last[x] = cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> w[1];
    for (int i = 2; i <= n; i++)
    {
        cin >> w[i] >> spv[i];
        a[spv[i]].push_back(i);
    }
    cnt = 1;
    link(1);
    for (int q = 1; q <= m; q++)
    {
        cin >> ch;
        if (ch == 'p')
        {
            cin >> u >> v;
            update(first[u]+1, v);
            update(last[u]+1, -v);
        }
        else
        {
            cin >> u;
            if (u == 1) cout << w[1] << endl;
            else
            cout << get(first[u]) + idx[first[u]] << endl;
        }
    }
}
