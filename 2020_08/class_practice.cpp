#include <iostream>

using namespace std;

class air {

private:
    int temper;
    bool power;

public:
    void turn(string a);
    void temper_insert(int a);
    void temper_up_down(string a);
    void temper_print();
};

void air::turn(string a) {
    if (a=="on") power = true;
    else if (a =="off") power = false;
    cout << "power : " << power << endl;
}

void air::temper_insert(int a) {
    temper = a;
    cout << "temper : " << temper<< endl;
}

void air::temper_up_down(string a) {
    if (a=="up") temper++;
    else if (a=="down") temper--;
    cout << "temper : " << temper<< endl;
}

void air::temper_print() {
    cout << "temper : " << temper<< endl;
}

int main() {
    air con;
    con.turn("on");
    con.temper_insert(20);
    con.temper_up_down("up");
    con.temper_up_down("down");
    con.temper_print();
    con.turn("off");
}