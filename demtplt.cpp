#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u)
{
    cout << u << " ";
    // Danh dau la u da duoc tham
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u])
    {
        // Neu dinh v chua duoc tham
        if (!visited[v])
            dfs(v);
    }
}

void cnt()
{
    int ans = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ++ans;
            cout << "Cac dinh thuoc thanh phan lien thogn thu " << ans << "\n";
            dfs(i);
            cout << endl;
        }
    }
    cout << "So thanh phan lien thong cua do thi : " << ans << endl;
}