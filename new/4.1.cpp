#include <iostream>
using namespace std;

class Base {
   private:
    int x;

   public:
    Base(int _x) : x(_x) {}
    ~Base() {}
    void show() { cout << "x=" << x << endl; }
};

class Derived : public Base {
   private:
    int y;

   public:
    Derived(int _x, int _y) : Base(_x), y(_y) {}
    ~Derived() {}
    void show() {
        Base::show();
        cout << "y=" << y << endl;
    }
};

void func1(Base b) {
    b.show();
}

void func2(Derived d) {
    d.show();
}

int main() {
    Derived a(10, 20);
    a.show();
    Base* pB = &a;
    Derived* pD = &a;
    pB->show();
    pD->show();
    func1(*pB);
    func2(*pD);
}