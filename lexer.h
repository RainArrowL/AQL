#ifndef LEXER_H
#define LEXER_H

#include "head.h"

enum AQLType {
    CREATE,             // "create"
    VIEW,               // "view"
    AS,                 // "as"
    OUTPUT,             // "output"
    SELECT,             // "select"
    FROM,               // "from"
    EXTRACT,            // "extract"
    REGEX,              // "regex"
    ON,                 // "on"
    RETURN,             // "return"
    GROUP,              // "group"
    AND,                // "and"
    TOKEN,              // "Token"
    PATTERN,            // "pattern"
    
    DOT,                // "."
    COMMA,              // ","
    SEMICOLON,          // ";"
    LEFT_ROUND_BRACKET, // "("
    RIGHT_ROUND_BRACKET,// ")"
    LEFT_ANGLE_BRACKET, // "<"
    RIGHT_ANGLE_BRACKET,// ">"
    LEFT_CURLY_BRACKET, // "{"
    RIGHT_CURLY_BRACKET, // "}"

    REG,                // "/.../"
    NUM,                // "1234567890"
    ID,                 // other string as ID
};

struct aqlToken {
    enum AQLType type;
    string str;
    int num;

    aqlToken() {}
    aqlToken(enum AQLType type) :
        type(type) {}
    aqlToken(enum AQLType type, string str) :
        type(type), str(str) {}
    aqlToken(enum AQLType type, int num) :
        type(type), num(num) {}
};

typedef struct aqlToken AQLToken;

// 提取AQL文本中的token 
vector<AQLToken>
getAQLTokens(string AQLText);

#endif

