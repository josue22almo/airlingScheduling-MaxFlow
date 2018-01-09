#include <iostream>
using namespace std;

int main(){
    float n, total = 0, sum = 0;;
    while(cin >> n){
        sum += n;
        ++total;
    }
    cout << sum /  total << endl;
}
