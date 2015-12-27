#include "global.h"

string
textToString(string file) {
    ifstream in(file.c_str());
    
    string str = "", s;
    while (!in.eof()) {
        getline(in, s);
        str += s+"\n"; // 一定要加上'\n",否则前后两行会合起来!!!!! 
    }
    
    return str;
}

bool
isWhite(const char &c) {
    return c == ' '
        || c == '\n'
        || c == '\t'
        || c == '\r';
}

void error(string msg) {
    printf("Error: %s\n", msg.c_str());
    exit(0);
}

void clear(string &s) { s = ""; }
void clear(int &a)    { a = 0; }

int lengthOfNum(int a) {
    int cnt = 0;
    while (a) {
        cnt++;
        a /= 10;
    }
    return cnt;
}

string intToString(int a) {
    if (a == 0) return string("0");
    string s = "";
    while (a) {
        s = char(a%10+'0') + s;
        a /= 10;
    }
    return s;
}
