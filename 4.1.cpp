// 1、定义基类Base，有私有数据成员x，int类型。有带一个参数的构造函数为其初始化。有show函数，显示x的值。
// 2、定义公有派生类derived，增加私有数据成员y，int类型，有带两个参数的构造函数，为其数据成员初始化。有show函数，显示x、y的值。
// 3、定义外部函数func1、func2，形参分别是Base、derived类对象，函数只有一句，调用形参对象的show函数。
// 4、在main函数中静态定义derived类对象a，实参为10、20，并调用其show函数。然后分别定义Base指针、derived指针，都指向a，分别用指针调用其show函数。
// 最后以a为实参，调用函数func1、func2。
// 5、程序无输入，输出为：
// x=10
// y=20
// x=10
// x=10
// y=20
// x=10
// x=10
// y=20
// 6、对上述输出应能够正确解释。

#include <iostream>
using namespace std;
class Base {
   private:
    int x;

   public:
    Base();
    Base(int x) { this->x = x; }
    void show() { cout <<"x="<< x << endl; }
};

class Derived : public Base {
   private:
    int y;

   public:
    Derived(int x, int y) : Base(x) { this->y = y; }
    void show() {
        Base::show();
        cout<<"y=" << y << endl;
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
    Base* b = &a;
    Derived* d = &a;
    b->show();
    d->show();
    func1(a);
    func2(a);
    return 0;
}


// 对上述输出的解释：

// 1、a.show()输出x=10，因为Derived类的show函数中调用了Base类的show函数，所以先输出x=10，然后再输出y=20。
// 2、b->show()输出x=10，因为b是Base类指针，所以调用的是Base类的show函数，输出x=10。
// 3、d->show()输出x=10，因为d是Derived类指针，所以调用的是Derived类的show函数，Derived类的show函数中调用了Base类的show函数，所以先输出x=10，然后再输出y=20。
// 4、func1(a)输出x=10，因为func1的形参是Base类对象，所以调用的是Base类的show函数，输出x=10。
// 5、func2(a)输出x=10，因为func2的形参是Derived类对象，所以调用的是Derived类的show函数，Derived类的show函数中调用了Base类的show函数，所以先输出x=10，然后再输出y=20。

// 说明：在派生类中，如果派生类的成员函数与基类的成员函数同名，那么在派生类中，基类的成员函数将被隐藏，即使是基类的指针指向派生类对象，也只能调用派生类的成员函数，不能调用基类的成员函数。


