#include "pattern.h"

extern string textInString;
extern vector<TextToken> textTokens;
int size_textTokens;
int cnt;

vector<vector<int> >
findall(const char *regex, const char *content);

extern vector<AQLView> views;
extern map<string, int> viewsIndex;

AQLView matchPattern(vector<AQLAtom> atoms,
                     map<int, string> group_name,
                     int tmp_cnt) {
                         
    for (int i = 0; i < atoms.size(); i++) {
        if (atoms[i].type == Reg) printf("Reg: %s\n", atoms[i].reg.c_str());
        else if (atoms[i].type == Token) puts("Token");
        else /* atoms[i].type == column) */ printf("%s.%s\n", atoms[i].viewID.c_str(), atoms[i].columnID.c_str());
    }
                         
    AQLView view;
    cnt = tmp_cnt;
    while (tmp_cnt--) view.columns.push_back(AQLColumn());

    size_textTokens = textTokens.size();
//    printf("size_textTokens: %d\n", size_textTokens);
//    for (int i = 0; i < size_textTokens; i++) {
//        printf("%s\n", textTokens[i].token.c_str());
//    }puts("");
    
    printf("atoms.size: %d\n", atoms.size());

    int size = textTokens.size(), i;
    for (i = 0; i < size; i++) {
    	vector<TextToken> tmpTokens;
    	dfs(atoms, 0, atoms.size(), group_name, tmpTokens, view, i);
    }

    AQLView view_cut;
    AQLColumn tmp_column;
    for (map<int, string>::iterator it = group_name.begin();
    	 it != group_name.end(); it++) {
    	tmp_column = AQLColumn(it->second, view.columns[it->first].items);
    	view_cut.columns.push_back(tmp_column);
    }

    return view_cut;
}

void dfs(const vector<AQLAtom> &atoms, int kk, const int &size,
		 const map<int, string> &group_name,
         vector<TextToken> &tmpTokens, AQLView &view, int pos) {
	int tmp_size = tmpTokens.size();

    printf("dfs- pos: %d - kk: %d\n", pos, kk);
    
    if (pos >= size_textTokens && kk < size) return;
    
	int i, j, k;

	if (kk == size) {
		vector<TextToken> *item;
		item = new vector<TextToken>[cnt+1];
		
		puts("create item");

		int size_tmpTokens = tmpTokens.size();
		set<int>::iterator it;
		for (i = 0; i < size_tmpTokens; i++) {
			for (it = tmpTokens[i].group_num.begin(); it != tmpTokens[i].group_num.end(); it++) {
				item[*it].push_back(tmpTokens[i]);
			}
		}

		for (i = 0; i < cnt; i++) {
			view.columns[i].items.push_back(item[i]);
		}
		
		puts("add column done");
		
		delete []item;
		
		puts("delete done");

	} else {
		// Reg
		if (atoms[kk].type == Reg) {
		    printf("atoms[%d]: Reg\n", kk);

			for (i = atoms[kk].minn; i <= atoms[kk].maxx; i++) {
				if (pos+i-1 >= size_textTokens) return;

				vector<vector<int> > tmp = findall(atoms[kk].reg.c_str(), textTokens[pos+i-1].token.c_str());
				if (tmp.empty()
				 || tmp[0][0] != 0
				 || tmp[0][1] != textTokens[pos+i-1].token.length()) return;

				for (j = 0; j < i; j++) {
					TextToken tmp_textToken = textTokens[pos+j];
					tmp_textToken.group_num = atoms[kk].group_num;

					tmpTokens.push_back(tmp_textToken);
				}

				dfs(atoms, kk+1, size, group_name, tmpTokens, view, pos+i);

				while (tmpTokens.size() > tmp_size) tmpTokens.pop_back();
			}

			while (tmpTokens.size() > tmp_size) tmpTokens.pop_back();
		}
		// Column
		else if (atoms[kk].type == Column) {
		    printf("atoms[%d]: %s.%s\n", kk, atoms[kk].viewID.c_str(), atoms[kk].columnID.c_str());
		    
			AQLView &tmp_view = views[viewsIndex[atoms[kk].viewID]];
			AQLColumn &tmp_column = tmp_view.columns[tmp_view.columnsIndex[atoms[k].columnID]];

			int tmp_pos,
				size_items = tmp_column.items.size(),
				size_item;

			for (j = 0; j < size_items; j++) {
				size_item = tmp_column.items[j].size();
				
				for (i = atoms[kk].minn; i <= atoms[kk].maxx; i++) {
					if (pos+size_item*i-1 >= size_textTokens) return;

					tmp_pos = pos;
					for (k = 0; k < size_item; k++) {
						if (tmp_column.items[j][k].st != textTokens[tmp_pos++].st) break;
					}

					if (size_item > 1) printf("k: %d\n", k);

					if (k < size_item) break;
					else {
						tmp_pos = pos;
						for (k = 0; k < i; k++) {
							for (int r = 0; r < size_item; r++) {
								TextToken tmp_textToken = textTokens[tmp_pos++];
								tmp_textToken.group_num = atoms[kk].group_num;

								tmpTokens.push_back(tmp_textToken);
							}
						}
					}

					dfs(atoms, kk+1, size, group_name, tmpTokens, view, pos+i*size_item);

					while (tmpTokens.size() > tmp_size) tmpTokens.pop_back();
				}

				while (tmpTokens.size() > tmp_size) tmpTokens.pop_back();
			}
		}
		// Token
		else {
		    printf("atoms[%d]: Token\n", kk);
		    
			if (pos+atoms[kk].minn-1 >= size_textTokens) return;

			for (i = atoms[kk].minn; i <= atoms[kk].maxx; i++) {
				if (pos+i-1 >= size_textTokens) return;

				for (j = 0; j < i; j++) {
					TextToken tmp_textToken = textTokens[pos+j];
					tmp_textToken.group_num = atoms[kk].group_num;

					tmpTokens.push_back(tmp_textToken);
				}

				dfs(atoms, kk+1, size, group_name, tmpTokens, view, pos+i);

				while (tmpTokens.size() > tmp_size) tmpTokens.pop_back();
			}

			while (tmpTokens.size() > tmp_size) tmpTokens.pop_back();
		}
	}
}

