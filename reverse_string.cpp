#include <iostream>
#include <set>
using namespace std;
/*
 * 344. Reverse String
 */

    string reverseString(string s) {
        if (s.empty() || s.size() <= 1 ){
            return s;
        }
        int length = s.size() - 1;
        int mid = s.size()/2;

        string ans = s;
        for (int i = 0; i < mid; i ++) {
            char c = ans[length-i];
            ans[length-i] = ans[i];
            ans[i] = c;
        }
        return ans;
    }

    string reverseVowels(string s) {
        if (s.empty() || s.size() <= 1 ){
            return s;
        }
        char vowels[] = {'a','e','i','o','u'};
        set<char> vowelSet(vowels, vowels+5);
        string ans = s;
        int backIndex = ans.size()-1;
        int frontIndex = 0;
        while (frontIndex < backIndex) {
            if (vowelSet.find(tolower(ans[frontIndex])) != vowelSet.end()){
                if (vowelSet.find(tolower(ans[backIndex])) != vowelSet.end()) {
                    char c = ans[backIndex];
                    ans[backIndex] = ans[frontIndex];
                    ans[frontIndex] = c;
                    frontIndex ++;
                    backIndex --;
                } else {
                    backIndex --;
                }
            } else {
                frontIndex ++;
            }
        }
        return ans;
    }
/*
    int main(int argc, char* argv[]){
        cout << reverseString("a.");
    }
*/
