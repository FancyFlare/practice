#include <iostream>
using namespace std;

/* 168. Excel Sheet Column Title
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 */

string convertToTitle(int n) {
    if(n <= 0)
        return "";

    string title = "";
    while(n > 0){
        char c = ((n-1)%26) + 'A';
        n = (n-1)/26;
        title = string(1, c) + title;
        cout << title << endl;
    }
    return title;
}

/*
 * 171. Excel Sheet Column Number
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 */
int titleToNumber(string s) {
    if(s.empty()){
        return 0;
    }
    int len = s.size();
    int result = 0;
    for(int i = 0; i < len; i++){
        int x = s[i] - 'A' + 1;
        result = result*26 + x;
    }
    return result;
}

int main(int argc, char* argv[]){
    //cout << convertToTitle(26);
    printf("%d",titleToNumber("AB"));
}
