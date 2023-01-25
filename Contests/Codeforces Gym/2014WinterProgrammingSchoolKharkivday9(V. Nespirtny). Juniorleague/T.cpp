#include <bits/stdc++.h>

using namespace std;
#define int long long
const double inf = 1e100, eps = 1e-12;
const double PI = acos(-1.0L);

int cmp (double a, double b = 0) {
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}

struct pt{ //Struct de ponto/vetor com algumas operações básicas
    int x, y;

    pt (double x = 0, double y = 0) : x(x), y(y) {}
    pt operator+ (const pt &p){ return pt(x + p.x, y + p.y); }
    pt operator- (const pt &p){ return pt(x - p.x, y - p.y); }
    pt operator* (const double &c){ return pt(c*x, c*y); }
    pt operator/ (const double &c){ return pt(x/c, y/c); }

    bool operator <(const pt &p) const {
        if(cmp(x, p.x) != 0) return x < p.x;
        return cmp(y, p.y) < 0;
    }

    bool operator == (const pt &p){ return !cmp(x, p.x) && !cmp(y, p.y); }
    bool operator != (pt &p) const {return !(p == *this);}

};

double dot(pt a, pt b){
    return a.x * b.x + a.y * b.y;
}

double cross(pt a, pt b){
    return a.x * b.y - a.y * b.x;
}

double orient(pt a, pt b, pt c){
    return cross(b-a, c-a);
}

int32_t main(){
    int n;
    cin >> n;

    vector <pt> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
    }

    int m;
    cin >> m;

    for(int t = 0; t < m; t++){
        pt a, b;
        cin >> a.x >> a.y >> b.x >> b.y;

        vector <int> r, l;
        bool flag = true;

        for(int i = 0; i < n && flag; i++){
            int cmd = orient(p[i], a, b);

            if(cmd > 0) l.push_back(i+1);
            else if(cmd < 0) r.push_back(i+1);

            if(l.size() > 0 && r.size() > 0){
                cout << l[0] << " " << r[0] << "\n";
                flag = false;
            }
        }

        if(flag) cout << "0\n";

    }

    return 0;
}