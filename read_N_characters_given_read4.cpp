#include <iostream>
using namespace std;

/*
 * 157. Read N Characters Given Read4
 *
 * The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function will only be called once for each test case.
 */

// Forward declaration of the read4 API.


int read4(char *buf){
    static char* file = "ab";//"ThisIsAFileToBeRead";
    static char* p = file;
    int s = strlen(p) < 4 ? strlen(p) : 4;
    for(int i=0; i<s; i++){
        *(buf+i) = *(p+i);
    }
    *(buf+s) = '\0';
    p += s;
    return s;
}


/**
 * @param buf Destination buffer
 * @param n   Maximum number of characters to read
 * @return    The number of characters read
 */
int read(char *buf, int n) {
    if (buf == NULL){
        return 0;
    }
    int round = n/4;
    int numRead = 0;
    char *p = buf;
    while(1){
        if(n - numRead < 4){
            //less than 4 left to read
            int nn = read4(p);
            //if even less characters there
            int xx = nn < (n - numRead) ? nn : (n - numRead);
            *(p+xx) = '\0';
            numRead += xx;
            cout << "num read: " << numRead << " , read: " << p << endl;
            return numRead;
        }
        int nn = read4(p);
        numRead += nn;
        if(nn < 4) {//end of the file
            return numRead;
        }
        cout << "num read: " << numRead << " , read: " << p << endl;
        p += 4;
    }
    return numRead;
}
/*
int main (int argc, char* argv[]){
    char *buf = new char[100];
    read(buf, 1);
    cout << "The buf: " << buf;
}
*/
