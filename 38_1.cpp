#include<iostream>
#include<vector>
using namespace std;
int main(){
    int k;
    cin >> k;
    vector<vector<int>> arr(k, vector<int>(3, 0));
    for(int i = 0; i < k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        arr[i] = {a, b, c};
    }
    for(int i = 0; i < k; i++){
        float ans = (arr[i][2]-arr[i][0])/(arr[i][1]*1.0);
        int anss = (ans*1000)/1;
        int yushu = anss%10;
        if(yushu > 4){
            anss = (anss/10)+1;
        }
        else{
            anss = anss/10;
        }
        int hang = (anss/10)+1;
        int lie = (anss%10)+1;
        cout << hang << " " << lie;
        if(i != k-1)  cout << endl;
    }
    return 0;
}