#include "head.h"
#include "global.h"

#include "tokenizer.h"
#include "lexer.h"
#include "pattern.h"
#include "parser.h"

extern vector<vector<int> >
findall(const char *regex, const char *content);

extern vector<AQLView> views;
extern map<string, int> viewsIndex;
//extern enum AQLType;

int main() {
    string file_name;
    /////
    ///// tokenizer test
    /////
    file_name = "test_tokenizer.txt";
//    vector<TextToken> tokens = getTextTokens(textToString("test/"+file_name));
//    puts("get tokens done.");
    
//    printf("size: %d\n", tokens.size());
//    for (int i = 0; i < tokens.size(); i++) {
//        printf("%s\n", AQLTypeToString(tokens[i].type).c_str());
//    }
    
//    int size = views[0].columns.size(), i, j, k;
//    for (i = 0; i < size; i++) {
//        printf("tokens[%3d]: %s\n", i, tokens[i].token.c_str());
//    }
    
    //////
    //////  select test
    //////
    file_name = "test_select.txt";
//    vector<AQLToken> tokens = getAQLTokens(textToString("test/"+file_name));
//    puts("get tokens done.");
//    
//    printf("size: %d\n", tokens.size());
//    for (int i = 0; i < tokens.size(); i++) {
//        printf("%s\n", AQLTypeToString(tokens[i].type).c_str());
//    }
    
//    puts("Before parser");
//    parser(tokens, textToString("test/text.txt"), file_name);
//    
//    printf("views.size: %d\n", views.size());
//    
//    int size = views[0].columns.size(), i, j, k;
//    for (i = 0; i < size; i++) {
//        printf("tokens[%3d]: %s\n", i, tokens[i].token.c_str());
//    }
//    
//    printf("views[0].columns.size: %d\n", size);
//    
//    printf("View: %s\n", views[0].name.c_str());
//    for (i = 0; i < size; i++) {
//        for (j = 0; j < views[0].columns[i].items.size(); j++) {
//            for (k = 0; k < views[0].columns[i].items[j].size(); k++) {
//                printf("%s\n", views[0].columns[i].items[j][k].token.c_str());
//            }
//        }
//    }
    
    ////// 
    ////// 
    //////
//    file_name = "test_regex.txt";
//    vector<AQLToken> tokens = getAQLTokens(textToString("test/"+file_name));
//    puts("get tokens done.");
    
//    printf("size: %d\n", tokens.size());
//    for (int i = 0; i < tokens.size(); i++) {
//        if (tokens[i].type == REG) {
//            printf("REG: %s\n", tokens[i].str.c_str());
//        }
//        else printf("%s\n", AQLTypeToString(tokens[i].type).c_str());
//    }
    
//    puts("Before parser");
//    parser(tokens, textToString("test/text.txt"), file_name);
//    
//    printf("views.size: %d\n", views.size());
//    
    int i, j, k, r;
    
    for (r = 0; r < views.size(); r++) {
        int size = views[r].columns.size();
//        printf("views[%d].columns.size: %d\n", r, size);
        
//        printf("View: %s\n", views[r].name.c_str());
//        for (j = 0; j < size; j++)
//            printf("| %%ds", 10, views[r].columns[j].name.c_str());
//        puts("");
//        for (j = 0; j < size; j++)
//            printf("+-----------");
//        puts("");
//        for (j = 0; j < views[r].columns[0].items.size(); j++) {
//            for (i = 0; i < size; i++) {
//                for (k = 0; k < views[r].columns[i].items[j].size(); k++) {
//                    printf("| %-10s", views[r].columns[i].items[j][k].token.c_str());
//                }
//            }
//            puts("");
//        }
    }
    
//    file_name = "PerLoc.aql";
//    vector<AQLToken> tokens = getAQLTokens(textToString("test/"+file_name));
////    for (int i = 0; i < tokens.size(); i++) {
////        if (tokens[i].type == REG) printf("REG: %s\n", tokens[i].str.c_str());
////        else printf("%s\n", AQLTypeToString(tokens[i].type).c_str());
////    }
////    puts("getTokens done");
//    parser(tokens, textToString("test/perloc/PerLoc.input"), file_name);
    
    freopen("test/revenue/Revenue.output", "w", stdout);
    
    file_name = "Revenue.aql";
    vector<AQLToken> tokens = getAQLTokens(textToString("test/"+file_name));
//    for (int i = 0; i < tokens.size(); i++) {
//        if (tokens[i].type == REG) printf("REG: %s\n", tokens[i].str.c_str());
//        else printf("%s\n", AQLTypeToString(tokens[i].type).c_str());
//    }
//    puts("getTokens done");
    parser(tokens, textToString("test/revenue/Revenue.input"), file_name);

    
    
    
    
    
    
    
    
    
    return 0;
}
