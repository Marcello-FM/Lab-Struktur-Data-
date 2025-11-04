#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;

void dijkstra(int V, vector<vector<iPair>> &adj, int src) {
    vector<int> dist(V, INT_MAX);
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    dist[src] = 0;
    pq.push({0, src});

    //Loop Dijkstra
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        //Jika jarak yang diambil bukan yang terkecil, skip
        if (d > dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

        //jika jarak baru lebih kecil, perbarui jarak dan masukkan ke pq
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    //Tampilkan hasil akhir
    cout << "Vertex\tDistance from X\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 6;
    vector<vector<iPair>> adj(V);

    //Menambahkan edge sesuai graf
    adj[0].push_back({1, 3});
    adj[0].push_back({4, 8});
    adj[1].push_back({2, 4});
    adj[1].push_back({3, 4});
    adj[2].push_back({5, 3});
    adj[3].push_back({5, 3});
    adj[4].push_back({5, 2});

    //Karena graf tidak berarah, tambahkan edge kebalikannya juga
    adj[1].push_back({0, 3});
    adj[4].push_back({0, 8});
    adj[2].push_back({1, 4});
    adj[3].push_back({1, 4});
    adj[5].push_back({2, 3});
    adj[5].push_back({3, 3});
    adj[5].push_back({4, 2});

    dijkstra(V, adj, 0);
    return 0;
}