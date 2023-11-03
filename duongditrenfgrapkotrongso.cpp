#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<int> adj[1001];
bool visited[1001];
int parent[1001];

void dfs(int u){
    cout << u << " ";
    //Danh dau la u da duoc tham
    visited[u] = true;
    for(int v : adj[u]){
        //Neu dinh v chua duoc tham
        if(!visited[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}

void path(int s, int t){
    memset(visited, false, sizeof(visited));
    memset(parent, 0, sizeof(parent));
    dfs(s);
    if(!visited[t]) cout << "Khong co duong di !\n";
    else{
        //Truy vet duong di
        vector<int> path;
        //bat dau tu dinh t
        while(t!=s){
            path.push_back(t);
            //lat nguoc lai
            t = parent[t];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for(int x : path) cout << x << " ";
    }
}

main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> s >> t;
    path(s, t);
}