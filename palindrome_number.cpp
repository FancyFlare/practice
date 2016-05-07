#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0){
        return false;
    }
    if (x == 0 || x/10 == 0){
        return true;
    }

    int ndigits = 0;
    int t = x;
    int first = 0;
    for(int i = 0; i < 10; i++){
        if(t/10 == 0){
           ndigits = i+1;
           break;
        }
        first = t/10;
        t /= 10;
    }
    //cout << first << endl;

    int last = x % 10;
    //cout << last << endl;
    if (first != last){
        return false;
    }
    int hi = 1;
    for (int i = 1; i < ndigits; i++){
        hi *= 10;
    }
    t = x;
    cout << "hi: "<< hi << endl;
    while(hi >= 10 && t > 10){
        t %= hi;
        t /= 10;
        hi /= 10;
        if(t > 10 && t/hi == 0 && t % 10 != 0){
            return false;
        }
        if(t/hi != 0){
            break;
        }else{
            t /= 10;
        }
    }

    return isPalindrome(t);
}
/*
int main(int argc, char *argv[])
{
    cout << isPalindrome(121);
}
*/
