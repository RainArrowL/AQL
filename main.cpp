#include "head.h"

int main() {    
    vector<TextToken> tokens = getTextTokens(textToString("test.txt"));
    
    int size = tokens.size(), i;
    for (i = 0; i < size; i++) {
        printf("tokens[%3d]: %s\n", i, tokens[i].token.c_str());
    }
    
    return 0;
}
