#include <bits/stdc++.h>

#define endl "\n"
#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> tp;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

int money = 100;
int countNum[10];

int main(){
    system("cls");
        // cout << "�ٿ� 1��, �� 2��, �׸��ΰ� ��ݹޱ� 3��" << endl;
    while(1){

        //���ӽ���
        money -= 3;
        int cnt=5, randNum=0, reward=3, input;
        
        srand((unsigned int)time(NULL)); //seed������ ����ð� �ο� 

        // ���� %10 = ������ ���� 0~9���� ����
        while(1){
            randNum = rand() % 10;
            if( 0 < randNum && randNum < 10 ) break;
        }
        countNum[randNum]++;
        
        while(cnt--){
            
            int nextNum;
            srand((unsigned int)time(NULL)); //seed������ ����ð� �ο� 
        
            // ���� %10 = ������ ���� 0~9���� ����
            while(1){
                nextNum = rand() % 10;
                if( 0 < nextNum && nextNum != randNum ) break;
            }
            countNum[nextNum]++;
            
            //���ٿ� ��� ��� �ʿ�
            int upReward, downReward;
            if(randNum == 1 || randNum == 9){
                upReward = reward;
                downReward = reward;
            }
            else if(randNum == 2){
                upReward = reward * 1.1;
                downReward = reward * 7.6;
            }
            else if(randNum == 8){
                upReward = reward * 7.6;
                downReward = reward * 1.1;
            }
            else if(randNum == 3){
                upReward = reward * 1.25;
                downReward = reward * 4;
            }
            else if(randNum == 7){
                upReward = reward * 4;
                downReward = reward * 1.25;
            }
            else if(randNum == 4){
                upReward = reward * 1.5;
                downReward = reward * 2.5;
            }
            else if(randNum == 6){
                upReward = reward * 2.5;
                downReward = reward * 1.5;
            }
            else if(randNum == 5){
                upReward = reward * 2;
                downReward = reward * 2;
            }

            string showNum = "1 2 3 4 5 6 7 8 9";
            string showPattern="";
            for(int i=1; i<=9; i++){
                if(i==randNum) showPattern += "@ ";
                else showPattern += "* ";
            }
            cout << "------" << setw(3) << setfill('-') << reward << "--------   ������ [" << money << "]" << endl 
                << showNum << "   ��ȸ [" << cnt+1 << "]" << endl 
                << showPattern << endl;

            // cout << "���ڴ� " << randNum << "  /  ���� ��� " << reward << endl << 
            cout << "�ٿ� ���� �� " << downReward <<
                    " / �� ���� �� " << upReward << endl;
                    

            cin >> input;
            if(input == 1){
                if(nextNum < randNum){
                    reward = downReward;
                    cout << "�¾ҽ��ϴ�." << endl;
                }
                else{
                    cout << "Ʋ�Ƚ��ϴ�. ���ڴ� " << nextNum << "�̾����ϴ�." << endl;
                    system("cls");
                    break;
                }
            }
            else if(input == 2){
                if(nextNum > randNum){
                    reward = upReward;
                }
                else{
                    cout << "Ʋ�Ƚ��ϴ�. ���ڴ� " << nextNum << "�̾����ϴ�." << endl;
                    system("cls");
                    break;
                }
            }
            else if(input == 3){
                money += reward;
                cout << "�׸��ΰ� ������ ��� " << reward << "�� �޽��ϴ�." << endl;
                system("cls");
                break;
            }
            else {
                //�ٽ� ����� �Է�

                //Ȯ�� üũ
                for(int i=1; i<=9; i++){
                    cout << countNum[i] << " ";
                }
                cout << endl;
                break;
            }

            randNum = nextNum;

            system("cls");
        }

        if(cnt == -1 && input != 3){
            money += reward;
            //cout << "���ϵ帳�ϴ�. �� " << reward << "�� ȹ���ϼ̽��ϴ�!!" << endl;
        }
    }
}

/*
������ 100
�Ǵ� 3

��ȸ5��
�������� �־���
�� , �ٿ� , �׸��α�  3���� ������


-5
	�� 2��	�� 2��

-6, 4
	�� 1.5��	�� 2.5��
3	�� 4	�� 8
8	�� 12	�� 20
66	�� 100	�� 168

-7, 3
	�� 1.25��	�� 4��
3 	�� 4 	�� 12
8 	�� 10	�� 31
12	�� 15	�� 46

-8, 2
	�� 1.1��	�� 7.6��
3	�� 3	�� 23
4 	�� 4 	�� 31
8	�� 9	�� 61
12 	�� 13 	�� 92
61	�� 66	�� 464
*/