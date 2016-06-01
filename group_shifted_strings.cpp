
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

/*
 * 249. Group Shifted Strings
 * Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd".
 * We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
Return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
Note: For the return value, each inner list's elements must follow the lexicographic order.
 */

vector<vector<string> > groupStrings(vector<string>& strings) {
    /*
     * convert all strings to start with 'a', then use the converted string as key for the hash map
     */
    vector<vector<string> > result;
    if(strings.empty()) return result;
    map<string, multiset<string> > mymap;
    for (int i=0; i<strings.size(); i++){
        string str = strings[i];
        if(str==""){
            if(mymap.find("")==mymap.end()){
                multiset<string> s;
                s.insert("");
                mymap.insert(pair<string, multiset<string> >("",s));
            }else{
                mymap[""].insert("");
            }
        }else{
            int gap = str[0]-'a';
            string converted = str;
            for(int j=0; j<str.size(); j++){
                char c = (str[j] - gap >= 'a') ? (str[j] - gap) : (str[j] - gap + 26);
                converted[j] = c;
            }
            if(mymap.find(converted)==mymap.end()){
                multiset<string> s;
                s.insert(str);
                mymap.insert(pair<string, multiset<string> >(converted,s));
            }else{
                mymap[converted].insert(str);
            }
        }
    }
    map<string, multiset<string> >::iterator it;
    for(it=mymap.begin(); it != mymap.end(); it++){
        vector<string> vec(it->second.begin(), it->second.end());
        result.push_back(vec);
    }
    return result;
}
/*
int main (int argc, char* argv[]){
    vector<string> strings;
    strings.push_back("abc");
    strings.push_back("bcd");
    vector<vector<string> > result = groupStrings(strings);

}
*/
