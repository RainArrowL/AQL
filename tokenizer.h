#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "head.h"

class TextToken {
  public:
    string token;
    int st, ed;
    set<int> group_num;
    TextToken() {}
    TextToken(string token, int st) :
        token(token), st(st) { ed = st+token.length(); }
};

// �� string text ����token������ȡ 
vector<TextToken>
getTextTokens(const string &text);

#endif
