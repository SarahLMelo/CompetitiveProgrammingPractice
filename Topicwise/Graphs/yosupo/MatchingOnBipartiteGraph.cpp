#include <bits/stdc++.h>

using namespace std;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

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
        // for(auto &i:edges){
        //     shuffle(i.begin(), i.end(), rng);
        // }

		while(bfs(src, sink)) {
			// maybe random shuffle edges against bad cases?
			T flow;
			pt = std::vector<int>(n, 0);
			while((flow = dfs(sink, src))) {
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
// private:
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
			if(h[on] - 1 != h[list[cur].to]) {
				continue;
			}
			T got = dfs(list[cur].to, sink, std::min(flow, list[cur ^ 1].cap));
			if(got) {
				list[cur].cap += got;
				list[cur ^ 1].cap -= got;
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


//complexity = O(sqrt(V) * E)
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int l, r, m;
    cin >> l >> r >> m;
    Dinic <> d(l + r + 2);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a++;
        b += l + 1;

        d.addEdge(a, b, 1);
    }
    
    for(int i = 1; i <= l; i++) d.addEdge(0, i, 1);
    for(int i = 1; i <= r; i++) d.addEdge(l + i, l + r + 1, 1);

    cout << d.maxFlow(0, l + r + 1) << "\n";

    vector <pair <int, int>> ans;
    for(int i = 1; i < 2*m; i+=2){
        if(d.list[i].cap){
            ans.emplace_back(d.list[i].to - 1, d.list[i-1].to - 1 - l);
        }
    }

    for(auto i:ans){
        cout << i.first << " " << i.second << "\n";
    }

    return 0;
}   