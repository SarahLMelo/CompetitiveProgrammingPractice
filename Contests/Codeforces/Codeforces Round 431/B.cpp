#include <bits/stdc++.h>

using namespace std;
#define int long long

struct PT{
    int x, y;
    PT(int x, int y) : x(x), y(y) {}

    PT operator+(const PT &p){
        return PT(x + p.x, y + p.y);
    }

    PT operator-(const PT &p){
        return PT(x - p.x, y - p.y);
    }

    bool operator==(const PT &p){
        return x == p.x && y == p.y;
    }
};

int cross (PT p, PT q) { return p.x * q.y - p.y*q.x; }

bool collinear(PT &a, PT &b, PT &c){
    if(cross(a - b, a - c) == 0) return true;
    if(cross(b - a, b - c) == 0) return true;
    if(cross(c - a, c - b) == 0) return true;

    return false; 
}

int32_t main(){
    int n;
    cin >> n;

    vector <PT> p;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;

        p.emplace_back(i, x);
    }

    bool ans = true;
    vector <PT> otherLine;
    for(int i = 2; i < n; i++){
        if(collinear(p[0], p[1], p[i])) continue;
        otherLine.push_back(p[i]);
    }

    if(otherLine.empty()) ans = false;

    for(int i = 2; i <= otherLine.size() && ans; i++){
        if(collinear(otherLine[0], otherLine[1], otherLine[i])) continue;
        ans = false;
    }
    
    if(ans){
        cout << "Yes\n";
        return 0;
    }

    otherLine = {};
    ans = true;
    for(int i = 1; i < n; i++){
        if(i == 2) continue;
        if(collinear(p[0], p[2], p[i])) continue;
        otherLine.push_back(p[i]);
    }
    if(otherLine.empty()) ans = false;
    for(int i = 2; i <= otherLine.size() && ans; i++){
        if(collinear(otherLine[0], otherLine[1], otherLine[i])) continue;
        ans = false;
    }
    
    if(ans){
        cout << "Yes\n";
        return 0;
    }

    otherLine = {};
    ans = true;
    for(int i = 0; i < n; i++){
        if(i == 1 || i == 2) continue;
        if(collinear(p[1], p[2], p[i])) continue;
        otherLine.push_back(p[i]);
    }
    for(int i = 2; i <= otherLine.size() && ans; i++){
        if(collinear(otherLine[0], otherLine[1], otherLine[i])) continue;
        ans = false;
    }
    if(otherLine.empty()) ans = false;

    if(ans){
        cout << "Yes\n";
        return 0;
    }

    cout << "No\n";
}