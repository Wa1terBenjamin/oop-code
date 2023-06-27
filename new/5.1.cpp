#include <cstring>
#include <iostream>

using namespace std;

class String {
   private:
    char* array;

   public:
    String(const char* p) {
        array = new char[strlen(p) + 1];
        strcpy(array, p);
    }
    ~String() { delete[] array; }
    friend ostream& operator<<(ostream& os, const String& str) {
        os << str.array;
        return os;
    }
    char& operator[](int index) { return array[index]; }
    String& operator+(String& str) {
        char* tmp = new char[strlen(array) + strlen(str.array) + 1];
        strcpy(tmp, array);
        strcat(tmp, str.array);
        delete[] array;
        array = tmp;
        return *this;
    }
    String operator+(const char* cstr) {
        char* tmp = new char[strlen(array) + strlen(cstr) + 1];
        strcpy(tmp, array);
        strcat(tmp, cstr);
        return tmp;
    }
    const int operator+(int n) { return strlen(array) + n; }
};

int main() {
    String string1("mystring"), string2("yourstring"), string3("herstring");
    cout << string1 << endl;
    string1[7] = 'n';
    cout << string1 << endl;
    string1[8] = 'n';
    cout << string1 + string2 + string3 << endl;
    cout << string1 << endl;
    cout << string2 + "ab" << endl;
    cout << string2 << endl;
    cout << string3 + 3 << endl;
    cout << string3 << endl;
    return 0;
}