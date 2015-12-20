#include "global.h"

string
textToString(const char *file) {
    ifstream in(file);
    
    string str = "", s;
    while (!in.eof()) {
        getline(in, s);
        str += s+"\n"; // һ��Ҫ����'\n",����ǰ�����л������!!!!! 
    }
    
    return str;
}

bool isWhite(const char &c) {
    return c == ' '
        || c == '\n'
        || c == '\t'
        || c == '\r';
}

void error() {
    puts("ERROR !!!");
}
