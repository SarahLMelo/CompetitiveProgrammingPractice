#include <bits/stdc++.h>

using namespace std;

int main(){
    ofstream out;
    out.open("atributos.txt");

    vector <int> v = {-3,-2, -1, 0, 0, 1, 2, 3};
    vector <vector <int>> ans;
    int cnt = 1;

    do
    { 
        ans.push_back(v);
    } while (next_permutation(v.begin(), v.end()));
    
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle(ans.begin(), ans.end(), std::default_random_engine(seed));

    int x;
    cout << "Insira um numero de 1 a 20160: ";
    cin >> x;

    x--;

    out << "AGI: " << ans[x][0] << "\n";
    out << "FOR: " << ans[x][1] << "\n";
    out << "DES: " << ans[x][2] << "\n";
    out << "CLA: " << ans[x][3] << "\n";
    out << "INT: " << ans[x][4] << "\n";
    out << "RES: " << ans[x][5] << "\n";
    out << "CAR: " << ans[x][6] << "\n";
    out << "FDV: " << ans[x][7] << "\n";

    cout << "Obrigada!\n";
    
    // for(auto s:ans){
    //     out << "================ " << cnt << " ================\n";
    //     out << "AGI: " << s[0] << "\n";
    //     out << "FOR: " << s[1] << "\n";
    //     out << "DES: " << s[2] << "\n";
    //     out << "CLA: " << s[3] << "\n";
    //     out << "INT: " << s[4] << "\n";
    //     out << "RES: " << s[5] << "\n";
    //     out << "CAR: " << s[6] << "\n";
    //     out << "FDV: " << s[7] << "\n";
    //     cnt++;
    // }


    out.close();
    return 0;
}