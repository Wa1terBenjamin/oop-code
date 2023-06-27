#include <iostream>

using namespace std;

int main() {
    int len;
    cin >> len;
    int* a[len];
    for (auto x : a) {
        int tmp;
        cin >> tmp;
        x = new int(tmp);
    }
    int sum = 0;
    for (auto x : a) {
        sum += *x;
        delete x;
    }
    cout << sum;
}