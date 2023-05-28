#include <bits/stdc++.h>

using namespace std;
#define int long long

template <class T = int>
class Dinic {
public:
	struct Edge {
		Edge(int a, T b){to = a;cap = b;}
		int to;
		T cap;
	};

	Dinic(int _n) : n(_n) {
		edges.resize(n);
	}

	T maxFlow(int src, int sink) {
		T ans = 0;
		while(bfs(src, sink)) {
			// maybe random shuffle edges against bad cases?
			T flow;
			pt = std::vector<int>(n, 0);
			while((flow = dfs(src, sink))) {
				ans += flow;
			}
		}
		return ans;
	}

	void addEdge(int from, int to, T cap, T other = 0) {
		edges[from].push_back(list.size());
		list.push_back(Edge(to, cap));
		edges[to].push_back(list.size());
		list.push_back(Edge(from, other));
	}

	bool inCut(int u) const { return h[u] < n; }
	int size() const { return n; }
private:
	int n;
	std::vector<std::vector<int> > edges;
	std::vector<Edge> list;
	std::vector<int> h, pt;

	T dfs(int on, int sink, T flow = 1e9) {
		if(flow == 0) {
			return 0;
		} if(on == sink) {
			return flow;
		}
		for(; pt[on] < (int) edges[on].size(); pt[on]++) {
			int cur = edges[on][pt[on]];
			if(h[on] + 1 != h[list[cur].to]) {
				continue;
			}
			T got = dfs(list[cur].to, sink, std::min(flow, list[cur].cap));
			if(got) {
				list[cur].cap -= got;
				list[cur ^ 1].cap += got;
				return got;
			}
		}
		return 0;
	}

	bool bfs(int src, int sink) {
		h = std::vector<int>(n, n);
		h[src] = 0;
		std::queue<int> q;
		q.push(src);
		while(!q.empty()) {
			int on = q.front();
			q.pop();
			for(auto a : edges[on]) {
				if(list[a].cap == 0) {
					continue;
				}
				int to = list[a].to;
				if(h[to] > h[on] + 1) {
					h[to] = h[on] + 1;
					q.push(to);
				}
			}
		}
		return h[sink] < n;
	}
};

int32_t main(){
    int n, s, e;
    /*
        0 -> Caixa d'agua
        1 -> Pia
        2*x -> Entrada do vértice
        2*x + 1 -> Saída do vértice
    */

    cin >> n >> s >> e;
    Dinic <> d(2*n + 2);

    for(int i = 1; i <= n; i++){
        d.addEdge(2*i, 2*i + 1, 1);
    }

    for(int i = 0; i < s; i++){
        int x;
        cin >> x;

        d.addEdge(0, 2*x, 1);
    }

    for(int i = 0; i < e; i++){
        int x;
        cin >> x;

        d.addEdge(2*x + 1, 1, 1);
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        d.addEdge(2*a + 1, 2*b, 1);
    }

    cout << d.maxFlow(0, 1) << "\n";

    return 0;
}