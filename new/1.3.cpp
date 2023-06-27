#include <cstring>
#include <iostream>
using namespace std;

int main() {
    const char* abc = "abc";
    auto p = abc;
    cout << p << endl;
    char* def = new char[sizeof("def") / sizeof(char) + 1]{'d', 'e', 'f', '\0'};
    cout << def << ' ' << sizeof("def") / sizeof(char) + 1 << endl;
    strcpy(def, p);
    char x;
    cin >> x;
    def[strlen(def)] = x;
    cout << def;
    delete[] def;
}