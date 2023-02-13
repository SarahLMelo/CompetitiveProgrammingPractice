#include <bits/stdc++.h>

using namespace std;
const double eps = 1e-7;

struct pt{
    double x, y;

    pt(){
        x = 0;
        y = 0;
    }

    pt(int x, int y){
        this->x = x;
        this->y = y;
    }
};

bool cmp(pt a, pt b){
    if(a.x != b.x) return a.x < b.x;
    return a.y >= b.y;
}

int cmpD(double a, double b){
    if(abs(a - b) < eps) return 0;
    return (a < b) ? -1:1;
}

double dist(pt a, pt b){
    return hypot(abs(1.0*a.x - b.x), abs(1.0*a.y - b.y));
}

pt get_radar(pt a, int d){
    pt radar;

    radar.y = 0;

    radar.x = sqrt(d*d - a.y*a.y);
    radar.x += a.x;

    return radar;
}

int main(){
    int n, d, cnt = 0;
    cin >> n >> d;

    while(n || d){
        // if(cnt) cout << "\n";
        cnt++;

        vector <pt> p(n);

        for(int i = 0; i < n; i++){
            cin >> p[i].x >> p[i].y;
        }

        sort(p.begin(), p.end(), cmp);

        int ans = 0;
        bool impossible = false;
        pt radar;

        for(int i = 0; i < n && !impossible; i++){
            if(!ans){
                if(p[i].y > d) impossible = true;
                else{
                    radar = get_radar(p[i], d);
                    // cout << radar.x << " " << radar.y << "\n";
                    ans++;
                }
            }

            else{
                if(cmpD(dist(p[i], radar), d) < 0) continue;
                else{
                    radar = get_radar(p[i], d);
                    // cout << radar.x << " " << radar.y << "\n";
                    ans++;
                }
            }
        }

        cout << "Case " << cnt << ": ";
        if(impossible) cout << "-1\n";
        else cout << ans << "\n";

        cin >> n >> d;
    }

    return 0;
}