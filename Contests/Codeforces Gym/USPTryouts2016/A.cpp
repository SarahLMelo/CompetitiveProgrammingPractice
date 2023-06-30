#include <bits/stdc++.h>

using namespace std;
#define double long double

const double inf = 1e100, eps = 1e-9;
int cmp (double a, double b = 0) {
  if (abs(a-b) < eps) return 0;
  return (a < b) ? -1 : +1;
}
struct PT {
  double x, y;
  PT(double x = 0, double y = 0) : x(x), y(y) {}
  PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
  PT operator * (double c) const { return PT(x*c, y*c); }
  PT operator / (double c) const { return PT(x/c, y/c); }
  bool operator <(const PT &p) const {
    if(cmp(x, p.x) != 0) return x < p.x;
    return cmp(y, p.y) < 0;
  }
  bool operator ==(const PT &p) const {return !cmp(x, p.x) && !cmp(y, p.y);}
  bool operator != (const PT &p) const {return !(p == *this);}
};
ostream &operator<<(ostream &os, const PT &p) {
  return os << p.x << " " << p.y; 
}

double h, w;
PT f(PT p, PT u, PT v, PT st){
    double nx, ny;

    nx = st.x + p.x / w * u.x + p.y / h * v.x;
    ny = st.y + p.x / w * u.y + p.y / h * v.y;

    // st = st + (u * (p.x / w));
    // st = st + (v * (p.y / h));

    return PT(nx, ny);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> h >> w;

    vector <PT> small(4);
    for(int i = 0; i < 4; i++){
        double x, y;
        cin >> x >> y;

        small[i] = PT(x, y);
    }

    PT u, v;
    u = small[1] - small[0];
    v = small[3] - small[0];

    PT p;
    for(int i = 0; i < 1e6; i++)
        p = f(p, u, v, small[0]);
    
    cout << setprecision(11) << fixed;
    cout << p << "\n";

    return 0;
}