#include <bits/stdc++.h>

using namespace std;

vector<tuple<int,int,int>> ttt{{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    while(1){
        string s; cin >> s;
        if(s == "end") break;
        
        bool check = true;
        int x=0,o=0;
        for(auto c : s){
            if(c == 'X'){
                x++;
            }
            else if(c == 'O'){
                o++;
            }
        }

        if(!(x == o+1 || x==o)){
            check = false;
        }

        bool binggo=false;
        int cntx =0, cnto=0;
        for(auto [a,b,c] : ttt){
            if(s[a] == s[b] && s[b] == s[c]){   //���� �ִٸ�
                if(s[a]=='O'){
                    if(x!=o) check = false;
                    binggo = true;
                    cntx++;
                                // cout << "check" << endl;

                }
                else if(s[a]=='X'){
                    if(x != o+1) check = false;
                    binggo = true;
                    cnto++;
                            // cout << "1check" << endl;
                }
            }
        }

        if(cntx>0 && cnto>0) check = false;

        if(check&& !binggo) if( s.size()-x-o > 0) check = false;

        if(check){
            cout << "valid" << "\n";
        }
        else{
            cout << "invalid" << "\n";
        }
    }
}
/*
012
345
678

����Ƿ��� 012 345 678 036 147 258 048 246
8��

�׸��� x�� o ���� �׻� ���ų� 1���ƾ���

x�� ���� �ƴٸ� 1���ƾ���
o�� ���� �ƴٸ� x�� ������ ���ƾ���


*/