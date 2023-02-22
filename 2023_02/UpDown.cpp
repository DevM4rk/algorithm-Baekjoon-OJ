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
        // cout << "다운 1번, 업 2번, 그만두고 상금받기 3번" << endl;
    while(1){

        //게임시작
        money -= 3;
        int cnt=5, randNum=0, reward=3, input;
        
        srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여 

        // 난수 %10 = 난수의 범위 0~9까지 한정
        while(1){
            randNum = rand() % 10;
            if( 0 < randNum && randNum < 10 ) break;
        }
        countNum[randNum]++;
        
        while(cnt--){
            
            int nextNum;
            srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여 
        
            // 난수 %10 = 난수의 범위 0~9까지 한정
            while(1){
                nextNum = rand() % 10;
                if( 0 < nextNum && nextNum != randNum ) break;
            }
            countNum[nextNum]++;
            
            //업다운 상금 계산 필요
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
            cout << "------" << setw(3) << setfill('-') << reward << "--------   소지금 [" << money << "]" << endl 
                << showNum << "   기회 [" << cnt+1 << "]" << endl 
                << showPattern << endl;

            // cout << "숫자는 " << randNum << "  /  현재 상금 " << reward << endl << 
            cout << "다운 성공 시 " << downReward <<
                    " / 업 성공 시 " << upReward << endl;
                    

            cin >> input;
            if(input == 1){
                if(nextNum < randNum){
                    reward = downReward;
                    cout << "맞았습니다." << endl;
                }
                else{
                    cout << "틀렸습니다. 숫자는 " << nextNum << "이었습니다." << endl;
                    system("cls");
                    break;
                }
            }
            else if(input == 2){
                if(nextNum > randNum){
                    reward = upReward;
                }
                else{
                    cout << "틀렸습니다. 숫자는 " << nextNum << "이었습니다." << endl;
                    system("cls");
                    break;
                }
            }
            else if(input == 3){
                money += reward;
                cout << "그만두고 누적된 상금 " << reward << "을 받습니다." << endl;
                system("cls");
                break;
            }
            else {
                //다시 제대로 입력

                //확률 체크
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
            //cout << "축하드립니다. 총 " << reward << "를 획득하셨습니다!!" << endl;
        }
    }
}

/*
소지금 100
판당 3

기회5번
랜덤숫자 주어짐
업 , 다운 , 그만두기  3가지 선택지


-5
	정 2배	역 2배

-6, 4
	정 1.5배	역 2.5배
3	정 4	역 8
8	정 12	역 20
66	정 100	역 168

-7, 3
	정 1.25배	역 4배
3 	정 4 	역 12
8 	정 10	역 31
12	정 15	역 46

-8, 2
	정 1.1배	역 7.6배
3	정 3	역 23
4 	정 4 	역 31
8	정 9	역 61
12 	정 13 	역 92
61	정 66	역 464
*/