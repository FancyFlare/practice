#include <cmatch>
#include <iostream>
using namespace std;

int reverse(int x) {
    cout << INT_MIN << endl;
    cout << INT_MAX << endl;

    int digits[10] = {0};
    int isPos = 1;
    if (x < 0){
        isPos = -1;
    }
    unsigned int absx = abs(x);
    int ndigit = 0;
    for (int i=0; i<10; i++){
        digits[i] = absx % 10;
        absx /= 10;
        if(absx == 0){
            ndigit = i+1;
            break;
        }
    }
    int result = 0;
    for (int i=0; i < ndigit; i++){
        double tmp = double(result) * 10 + double(digits[i]);
        if(tmp > INT_MAX){
            return 0;
        }
        result = result * 10 + digits[i];
    }
    result *= isPos;
    return result;
}
/*
int main(int argc, char *argv[])
{
    cout << reverse(-2147483648);
}
*/
