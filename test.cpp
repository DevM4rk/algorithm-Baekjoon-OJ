#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<string, int> ii;

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);

    v.pop_back();
    cout << v.back();
}