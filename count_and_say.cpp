#include <iostream>
#include <string>
using namespace std;
/*
 * 38. Count and Say
 */

string convert (string input) {
    if (input.empty() || input.size() == 0){
        return input;
    }
    char prev = input[0];
    int cnt = 1;
    string output;
    for (int i = 1; i < input.size(); i++) {
        if (input[i] == prev) {
            cnt ++;
            continue;
        }
        char buffer[10];
        sprintf(buffer, "%d", cnt);
        output += buffer;
        output += prev;
        prev = input[i];
        cnt = 1;
    }
    if(input[input.size()-1] == prev){
        char buffer[10];
        sprintf(buffer, "%d", cnt);
        output += buffer;
        output += prev;
    }
    return output;
}
string countAndSay(int n) {
    if (n==0){
        return NULL;
    }
    string res = "1";
    for (int i=1; i<n; i++) {
        res = convert(res);
    }
    return res;
}
/*
int main(int argc, char* argv[]) {
    cout << countAndSay(5);
}
*/
