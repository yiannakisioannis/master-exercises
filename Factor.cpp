#include <iostream>

using namespace std;

int main(){
    int a, i, r;
    cin >> a >> i;
    r = a * i;
    while ((double)r/(double)a > i-1){
        r--;
    }
    cout << r+1;

}