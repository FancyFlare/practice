#include <iostream>
#include <vector>
#include <map>
#include "utility.hpp"
using namespace std;

/*
 * 290. Given a pattern and a string str, find if str follows the same pattern.
 * Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.

Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 */

bool wordPattern(string pattern, string str) {
    map<char, int> patternMap;
    vector<int> myPattern;
    int id = 1;
    for(int i=0; i<pattern.size(); i++){
        char c = pattern[i];
        if(patternMap.find(c) != patternMap.end()){
            myPattern.push_back(patternMap[c]);
        } else{
            patternMap.insert(make_pair(c, id));
            myPattern.push_back(id);
            id ++;
        }
        cout << myPattern[i] << " ";
    }
    vector<string> tokens = splitString(str, " ");
    if(myPattern.empty() || myPattern.size() != tokens.size()){
        return false;
    }

    map<string, int> strMap;
    id = 1;
    for(int i=0; i<tokens.size(); i++){
        string t = tokens[i];
        if(strMap.find(t) != strMap.end()){
            if (strMap[t] != myPattern[i]){
                return false;
            }
        } else {
            strMap.insert(make_pair(t, id));
            //cout << myPattern.empty();
            if (id != myPattern[i]){
                return false;
            }
            id ++;
        }
    }
    return true;
}
/*
int main(int argc, char *argv[]){
    cout << wordPattern("jquery", "jquery");
}
*/
