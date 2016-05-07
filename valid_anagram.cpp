#include <iostream>
#include <map>
using namespace std;

bool isAnagram1(string s, string t) {
    if(t.size()!=s.size()){
        return false;
    }
    map<char, int> charSet;
    for(int i=0; i< s.size(); i++){
        char c = s[i];
        if(charSet.find(c) != charSet.end()){
            charSet[c] += 1;
        }else{
            charSet.insert(make_pair(c, 1));
        }
    }
    for(int i=0; i< t.size(); i++){
        char c = t[i];
        if(charSet.find(c) == charSet.end()){
            return false;
        }else{
            if(charSet[c]<=0){
                return false;
            }
            charSet[c] -= 1;
        }
    }
    return true;
}

bool isAnagram(string s, string t) {
    if(t.size()!=s.size()){
        return false;
    }
    int table[26];
    for(int i=0; i< 26; i++){
        table[i] = 0;
    }
    for(int i=0; i< s.size(); i++){
        char c = s[i];
        table[c-'a'] += 1;
    }
    for(int i=0; i< t.size(); i++){
        if(table[t[i]-'a'] <= 0){
            return false;
        } else{
            table[t[i]-'a'] -= 1;
        }
    }
    return true;
}
/*
int main(int argc, char* argv[]){
    cout << isAnagram("anagram", "nagaram");
}
*/
