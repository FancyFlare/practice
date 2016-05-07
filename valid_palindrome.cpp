#include <iostream>
using namespace std;
/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 */
bool isPalindrome1(string s) {
    int i = 0, j = s.size() - 1;
    while(i<j){
        bool cont = false;

        if((!(tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z')) && (!(s[i] >= '0' && s[i] <= '9'))) {
            i ++;
            cout << "i" << endl;
            cont = true;
        }
        if((!(tolower(s[j]) >= 'a' && tolower(s[j]) <= 'z')) && (!(s[j] >= '0' && s[j] <= '9'))) {
            j --;
            cout << "j" << endl;
            cont = true;
        }
        if(!cont){
            if(tolower(s[i]) != tolower(s[j])){
                return false;
            }
            i ++;
            j --;
        }
    }
    return true;
}

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while(i<j){
        if(!((tolower(s[i]) >= 'a' && tolower(s[i]) <= 'z') || (s[i] >= '0' && s[i] <= '9'))) {
            i ++;
            continue;
        }
        if(!((tolower(s[j]) >= 'a' && tolower(s[j]) <= 'z') || (s[j] >= '0' && s[j] <= '9'))) {
            j --;
            continue;
        }
        if(tolower(s[i]) != tolower(s[j])){
            return false;
        }
        i ++;
        j --;
    }
    return true;
}
/*
int main(int argc, char *argv[])
{
    cout << isPalindrome("a.");
}
*/

