#include <iostream>
using namespace std;

int lengthOfLastWord(string s) {
    if (s.empty() || s.size() == 0){
        return 0;
    }
    int l = s.size() - 1;
    while(l >= 0 && s[l] == ' '){
        l--;
    }
    for (int i = l; i >= 0; i--){
        if (s[i] == ' '){
            return l-i;
        }
    }
    return l+1;
}

int hammingWeight(uint32_t n) {
    int count = 0;
    for (int i=0; i<32; i++){
        cout << "n=" << n << ",n&1=" << (n&1) << endl;
        count += (n & 1);
        n = n >> 1;
    }
    return count;
}

int hammingWeight2(uint32_t n) {
    int count = 0;
    unsigned int bit = 1;
    for (int i=0; i<32; i++){
        cout << "bit=" << bit<< endl;
        if (n & bit) {
            count ++;
        }
        bit *= 2;
    }
    return count;
}

uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; i++){
        res = (res << 1);
        res += (n & 1);
        n = (n >> 1);
        cout << "res: " << res << endl;
    }
    return res;
}
/*
int main (int argc, char* argv[]){
    //cout << lengthOfLastWord("  ");
    //cout << hammingWeight2(1);
    cout << reverseBits(1);
}
*/
