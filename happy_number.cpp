#include <iostream>
#include <map>
#include <set>
using namespace std;
bool isHappy(int n) {
    //use map to store square of digits
    map<int, int> squareMap;
    for (int i = 0; i <=9; i++){
        squareMap[i] = i*i;
    }
    set<int> seen;
    while(n != 1){
        int t = n;
        int s = 0;
        while(t > 0){
           s += squareMap[t%10];
           t /= 10;
        }
        n = s;
        if (seen.find(n) != seen.end()){
            break;
        } else {
            seen.insert(n);
        }
    }
    if (n == 1)
        return true;

    return false;
}
/*
int main(int argc, char* argv[]){
    cout << isHappy(7);
}
*/
