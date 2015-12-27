#ifndef GLOBAL_H
#define GLOBAL_H

#include "head.h"

// 将目标文件 file 打开，读取其中内容转换成string类型 
string
textToString(string file);

bool
isWhite(const char &c);

void error(string msg);

void clear(string &s);
void clear(int &a);

int
lengthOfNum(int a);

string
intToString(int a);

#endif
