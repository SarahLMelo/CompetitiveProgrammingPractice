#include <bits/stdc++.h>

using namespace std;
#define int long long
#define double long double

int32_t main(){
    cout << setprecision(16);

    int n, q;
    cin >> n >> q;

    double conv[2*n + 1][2*n + 1];
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++)
            conv[i][j] = -1;
    }

    vector <string> m2;
    map<string, int> m1;

    for(int i = 0; i < n; i++){
        int t;
        string a, b;
        double v;

        cin >> t >> a >> b >> v >> b;
        if(m1.find(a) == m1.end()){
            m1[a] = m2.size();
            m2.push_back(a);
        }

        if(m1.find(b) == m1.end()){
            m1[b] = m2.size();
            m2.push_back(b);
        }

        // cout << a << " " << b << endl;

        conv[m1[a]][m1[b]] = v;
        conv[m1[b]][m1[a]] = 1/v;
    }

    for(int k = 0; k < m2.size(); k++){
        for(int i = 0; i < m2.size(); i++){
            for(int j = 0; j < m2.size(); j++){
                if(conv[i][j] < 0 && !(conv[i][k] < 0) && !(conv[k][j] < 0)) conv[i][j] =  conv[i][k] * conv[k][j];
            }
        }
    }

    while(q--){
        double v;
        string a, b;

        cin >> v >> a >> b >> b;
        // cout << a << " " << b << "\n";

        if(conv[m1[a]][m1[b]] < 0) cout << "impossible\n";
        else{
            cout << conv[m1[a]][m1[b]] * v << "\n";
        }
    }

    return 0;
} 