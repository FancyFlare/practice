#include <iostream>
using namespace std;

int lengthOfLastWord(string s) {
    if (s.empty() || s.size() == 0){
        return 0;
    }
    int l = s.size() - 1;
    while(s[l] == ' ' && l > 0){
        l--;
    }
    if (l==0){
        return 0;
    }
    for (int i = l; i > 0; i--){
        if (s[i] == ' '){
            return l-i;
        }
    }
    return l+1;
}
/*
int main (int argc, char* argv[]){
    cout << lengthOfLastWord("word   ");
}
*/
