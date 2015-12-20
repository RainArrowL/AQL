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

// �� string text ����token������ȡ 
vector<TextToken>
getTextTokens(const string &text);

#endif
