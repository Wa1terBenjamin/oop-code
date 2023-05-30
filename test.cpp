#include <iostream>

class CFather {
   public:
    virtual void Fun() { std::cout << "f" << std::endl; }  // 虚函数
};

// 派生类
class CSon : public CFather {
   public:
    virtual void Fun() { std::cout << "s" << std::endl; }
};

int main() {
    CSon son;
    CFather* p = &son;
    p->Fun();  // 调用哪个虚函数取决于 p 指向哪种类型的对象
    return 0;
}