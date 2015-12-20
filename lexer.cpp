#include "lexer.h"

inline void clear(string &s) { s = ""; }
inline void clear(int &a) { a = 0; }

vector<AQLToken>
getAQLTokens(string AQLText) {
	vector<AQLToken> tokens;

	string &s = AQLText;

    string tmp_str = "";
    int tmp_num;

    int len = AQLText.length(), i;
    for (i = 0; i < len; i++) {
    	// 忽略空白符 
    	if (isWhite(s[i])) continue;
    	// 正则表达式 
    	else if (s[i] == '/') {
    		for (i++; s[i] != '/' || s[i-1] == '\\'; i++) {
    			tmp_str += s[i];
    		}

    		tokens.push_back( AQLToken(REG, tmp_str) );
    		clear(tmp_str);
    	}
    	// string without '_'
    	else if (isalpha(s[i])) {
    		for (; isalnum(s[i]); i++) {
    			tmp_str += s[i];
    		}

    		if 		(tmp_str == "create")  tokens.push_back( AQLToken(CREATE) );
    		else if (tmp_str == "view")    tokens.push_back( AQLToken(VIEW) );
    		else if (tmp_str == "as")      tokens.push_back( AQLToken(AS) );
    		else if (tmp_str == "output")  tokens.push_back( AQLToken(OUTPUT) );
    		else if (tmp_str == "select")  tokens.push_back( AQLToken(SELECT) );
    		else if (tmp_str == "from")    tokens.push_back( AQLToken(FROM) );
    		else if (tmp_str == "extract") tokens.push_back( AQLToken(EXTRACT) );
    		else if (tmp_str == "regex")   tokens.push_back( AQLToken(REGEX) );
    		else if (tmp_str == "on") 	   tokens.push_back( AQLToken(ON) );
    		else if (tmp_str == "return")  tokens.push_back( AQLToken(RETURN) );
    		else if (tmp_str == "group")   tokens.push_back( AQLToken(GROUP) );
    		else if (tmp_str == "and") 	   tokens.push_back( AQLToken(AND) );
    		else if (tmp_str == "Token")   tokens.push_back( AQLToken(TOKEN) );
    		else if (tmp_str == "pattern") tokens.push_back( AQLToken(PATTERN) );

    		else /* [a-zA-Z][a-zA-Z0-9]* */tokens.push_back( AQLToken(ID, tmp_str) );

    		clear(tmp_str);
    	}
    	// digits
    	else if (isdigit(s[i])) {
    		for (; isdigit(s[i]); i++) {
    			tmp_num = tmp_num*10 + s[i]-'0';
    		}

    		tokens.push_back( AQLToken(NUM, tmp_num) );
    		clear(tmp_num);
    	}
    	else /* [.,;()<>{}] */ {
    		if 		(s[i] == '.') tokens.push_back( AQLToken(DOT) );
    		else if (s[i] == ',') tokens.push_back( AQLToken(COMMA) );
    		else if (s[i] == ';') tokens.push_back( AQLToken(SEMICOLON) );
    		else if (s[i] == '(') tokens.push_back( AQLToken(LEFT_ROUND_BRACKET) );
    		else if (s[i] == ')') tokens.push_back( AQLToken(RIGHT_ROUND_BRACKET) );
    		else if (s[i] == '<') tokens.push_back( AQLToken(LEFT_ANGLE_BRACKET) );
    		else if (s[i] == '>') tokens.push_back( AQLToken(RIGHT_ANGLE_BRACKET) );
    		else if (s[i] == '}') tokens.push_back( AQLToken(LEFT_CURLY_BRACKET) );
    		else if (s[i] == '}') tokens.push_back( AQLToken(RIGHT_CURLY_BRACKET) );

    		else /* unable recognized charactor */ error();
    	}
    }

    return tokens;
}
