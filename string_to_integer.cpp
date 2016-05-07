#include <iostream>
using namespace std;

int myAtoi(string str) {
    if(str.empty()){
        return 0;
    }
    int i = 0;
    while(i < str.size() && str[i] == ' '){
        i ++;
    }
    int signal = 1;
    if(str[i] == '-'){
        signal = -1;
        i ++;
    }else if(str[i] == '+'){
        signal = 1;
        i ++;
    }

    while(i < str.size() && str[i] == '0'){
        i ++;
    }
    cout << "signal: "<< signal << ", i: "<< i << endl;
    int result = 0;
    for(; i < str.size(); i++){
        if(str[i] < '0' || str[i] > '9'){
            return result * signal;
        }
        double tmp = double(result) * 10 + (str[i]-'0');

        if(signal == 1 && tmp > INT_MAX){
            return INT_MAX;
        }
        if(signal == -1 && tmp > 0-double(INT_MIN)){
            return INT_MIN;
        }
        result = result * 10 + (str[i]-'0');
    }
    return result * signal;
}
/*
int main(int argc, char *argv[])
{
    cout << myAtoi("  -0012a42");
}
*/
