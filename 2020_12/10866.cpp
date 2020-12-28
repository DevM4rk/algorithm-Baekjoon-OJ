#include <iostream>

using namespace std;

int N,x,arr[10001]={0,},arr_front=0,arr_back=0,total=0;
string str;

void push_front(){
    arr[arr_front] = x;
    arr_front--;
    if(arr_front < 0) arr_front = 10000;
    total++;
}

void push_back(){
    arr_back++;
    if(arr_back > 10000) arr_back = 0;
    arr[arr_back] = x;
    total++;
}

int pop_front(){
    if(total == 0) return -1;
    else{
        arr_front++;
        if(arr_front > 10000) arr_front = 0;
        int temp = arr[arr_front];
        total--;
        return temp;
    }
}

int pop_back(){
    if(total == 0) return -1;
    else{
        int temp = arr[arr_back];
        arr_back--;
        if(arr_back < 0) arr_back = 10000;
        total--;
        return temp;
    }
}

int size(){
    return total;
}

int empty(){
    if( total == 0 ) return 1;
    else return 0;
}

int front(){
    if( total > 0 ){
        if( arr_front == 10000) return arr[0];
        else return arr[arr_front+1];
    }
    return -1;
}

int back(){
    if( total > 0 ) return arr[arr_back];
    return -1;
}

int main(){
    cin >> N;

    while(N--){
        cin >> str;
        if( str == "push_front" ){
            cin >> x;
            push_front();
        }
        else if( str == "push_back" ){
            cin >> x;
            push_back();
        }
        else if( str == "pop_front" ){
            cout << pop_front() << endl;
        }
        else if( str == "pop_back" ){
            cout << pop_back() << endl;
        }
        else if( str == "size" ){
            cout << size() << endl;
        }
        else if( str == "empty" ){
            cout << empty() << endl;
        }
        else if( str == "front" ){
            cout << front() << endl;
        }
        else if( str == "back" ){
            cout << back() << endl;
        }
    } 
}
