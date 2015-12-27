#include "global.h"
#include "tokenizer.h"

vector<TextToken>
getTextTokens(const string &text) {
    vector<TextToken> tokens;
    
    string tmp_str = "";
    
    int len = text.length(), i, st = -1;
//    printf("len: %d\n", len);
//    for (i = 0; i < len; i++)
//        printf("[%3d]: %c %d\n", i, text[i], text[i]);
        
    for (i = 0; i < len; i++) {
        // ���� �հ׷� 
        if (isWhite(text[i])) continue;
        // ���� 
        else if (isdigit(text[i])) {
            if (st == -1) st = i;
            tmp_str += text[i];
            
            if (!isdigit(text[i+1]) || isWhite(text[i+1])) {
                tokens.push_back( TextToken(tmp_str, st) );
                clear(tmp_str);
                st = -1;
            }
        }
        // Ӣ����ĸ 
        else if (isalpha(text[i])) {
            if (st == -1) st = i;
            tmp_str += text[i];
            
            if (!isalpha(text[i+1]) || isWhite(text[i+1])) {
                tokens.push_back( TextToken(tmp_str, st) );
                clear(tmp_str);
                st = -1;
            } 
        } else { // ��������Ӣ�ķ��� 
            tmp_str += text[i];
            tokens.push_back( TextToken(tmp_str, i) );
            clear(tmp_str);
        }
    }
    
    return tokens;
}

