#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "head.h"

struct textToken {
    string token;
    textToken() {}
    textToken(string token) :
        token(token) {}
};

typedef struct textToken TextToken;

// 将 string text 进行token划分提取 
vector<TextToken>
getTextTokens(const string &text);

#endif
