#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;
/*
 * 288. An abbreviation of a word follows the form <first letter><number><last letter>:
 * d|o|g --> d1g
 * Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary.
 * A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
 */

class ValidWordAbbr {
public:
    map<string, set<string> > dict;
    ValidWordAbbr(){}
    ValidWordAbbr(vector<string> &dictionary) {
        for(int i=0; i<dictionary.size(); i++){
            string abb = this->abbreviate(dictionary[i]);
            if(dict.find(abb) != dict.end()){
                dict[abb].insert(dictionary[i]);
            }else{
                set<string> new_set;
                new_set.insert(dictionary[i]);
                dict.insert(make_pair(abb, new_set));
            }
        }
    }

    string abbreviate(string s){
        if(s.empty()){
            return "";
        }
        string ret;
        ret.push_back(s[0]);
        if(s.size()==1){
            ret += "0";
            ret.push_back(s[0]);
            return ret;
        }

        int n = s.size()-2;
        ostringstream ss;
        ss << ret << n << s[s.size()-1];
        ret = ss.str();
        return ret;
    }
    bool isUnique(string word) {
        string abb = this->abbreviate(word);
        if(this->dict.find(abb) == this->dict.end()){
            return true;
        }
        set<string> tmp_set = this->dict[abb];
        if (tmp_set.find(word) == tmp_set.end()){
            return false;
        }
        if(tmp_set.size()==1){
            return true;
        }
        return false;
    }
};
/*
int main(int argc, char *argv[]){
    //ValidWordAbbr vwa;
    //cout << vwa.abbreviate("internationalization");
    vector<string> dictionary;
    dictionary.push_back("deer");
    dictionary.push_back("door");
    dictionary.push_back("cake");
    dictionary.push_back("card");
    ValidWordAbbr vwa(dictionary);
    cout << vwa.isUnique("make");
}
*/
