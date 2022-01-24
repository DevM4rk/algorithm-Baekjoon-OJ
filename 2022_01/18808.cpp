/*
ȸ�� 0 �� ��
���������� 0�̸� ��ƼĿ������� ���� �� Ʋ �ȳѾ�� ����غ���
����ϴٰ� 1 ��ġ�� �н�
�Ȱ�ġ�� ��ƼĿ ���̱�
�� �۾� ��� �ȵǸ� �ð����90�� ȸ�� x 3
*/
#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef unordered_map<int, int> mpii;

int n,m,k;
int ans,cnt;          //ans ��ƼĿ ĭ, cnt ��ƼĿ ���� ��
int note[41][41];     //��Ʈ�� ũ��
int st[11][11];       //��ƼĿ ��ġ
int x,y;              //��ƼĿ ũ��

void DebugNote(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << note[i][j] << " ";
        }
        cout << endl;
    }
}

void DebugSt(){
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cout << st[i][j] << " ";
        }
        cout << endl;
    }
}

void rotate(){
    int t[11][11];
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            t[i][j] = st[i][j];

    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            st[j][i] = t[x-1-i][j];

    swap(x,y);

    //DebugSt();
}

bool attach(int a, int b){
    
    //��ƼĿ ���� �� �ִ��� Ȯ��
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(st[i][j] && note[a+i][b+j]) return false;    //���� ���� �̹� ��ƼĿ �ٿ��� �ִٸ� ��
        }
    }

    //Ȯ���� �������� ���̱�    
    for(int i=0; i<x; i++)
        for(int j=0; j<y; j++)
            if(st[i][j])
                note[a+i][b+j] = 1;
    
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k;

    for(int idx=0; idx<k; idx++){
        int stcnt=0;    
        cin >> x >> y;

        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                cin >> st[i][j];
                if(st[i][j]) stcnt++;        //��ƼĿ ũ��, 1�� ����
            }
        }

        for(int r=0; r<4; r++){             //4ȸ��
            bool paste = false;
            for(int i=0; i<=n-x; i++){       //��ƼĿ�� Ʋ �ȳѾ���� x, y���ֱ�
                if(paste) break;
                for(int j=0; j<=m-y; j++){
                    if(attach(i,j)){
                        paste = true;
                        ans += stcnt;
                        break;
                    }
                }
            }
            //DebugNote();
            //cout << r << " " << paste << " " << ans << endl;

            if(paste) break;
            rotate();
        }
    }

    cout << ans;
}