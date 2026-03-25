#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for(int i = 0; i < n; i++){
        float x, y;
        cin >> x >> y;
        double lenth = x*x + y*y;
        if(lenth <= m*m) ans++;
    }
    cout << fixed << setprecision(6) << 4.0*ans/n << endl;
    return 0;
}