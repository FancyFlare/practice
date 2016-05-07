#include <iostream>
#include <map>
#include <deque>;
using namespace std;

bool isValid(string s) {
    map<char, char> charMap;
    charMap['('] = ')';
    charMap['['] = ']';
    charMap['{'] = '}';
    map<char, char>::iterator iter;

    deque<char> charStack;
    for(int i = 0; i < s.size(); i++){
        //cout << s[i] << endl;
        if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
            if(charStack.size() == 0){
                //cout << "1\n";
                return false;
            }
            if(charMap.find(charStack.back()) != charMap.end()){
                if(s[i] == charMap[charStack.back()]){
                    //cout << "pop " << charStack.back() << endl;
                    charStack.pop_back();
                    //cout << "charStack.back(): " << charStack.back() << endl;
                }else{
                    //cout << "2\n";
                    return false;
                }
            }
        }else{
           charStack.push_back(s[i]);
           //cout << "push " << charStack.back() << endl;

        }
    }
    if(charStack.size()){
        //cout << "3\n";
        return false;
    }else{
        return true;
    }
}
/*
int main(int argc, char *argv[])
{
    cout << isValid("([])");
}
*/
