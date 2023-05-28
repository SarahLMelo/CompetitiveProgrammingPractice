#include <bits/stdc++.h>

using namespace std;
#define int long long

const double PI = acosl(-1), eps = 1e-7;

int cmp(double a, double b){
    if(abs(a - b) < eps) return 0;
    if(a < b) return -1;
    return 1;
}

int32_t main(){
    cout << setprecision(9) << fixed;

    int n;
    cin >> n;

    vector <pair <int, int>> p(n);

    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }

    double ansl = 0, ansr = 0;
    for(int i = 0; i < n; i++){
        ansl = max(ansl, atan2(p[i].second - p[0].second, p[i].first - p[0].first));
    }

    reverse(p.begin(), p.end());

    for(int i = 0; i < n; i++){
        ansr = max(ansr, atan2(p[i].second - p[0].second, p[0].first - p[i].first));
    }

    cout << max(ansl, ansr)* 360 / 2 / PI << "\n";

    return 0;
}