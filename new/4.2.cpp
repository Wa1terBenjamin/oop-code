#include <cstring>
#include <iostream>
using namespace std;

class Base {
   private:
    char* name;
    int age;

   public:
    Base(const char* _name, int _age) : age(_age) {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
        cout << "Base constructor" << endl;
    }
    ~Base() {
        delete[] name;
        name = nullptr;
        cout << "Base destructor" << endl;
    }
    virtual void show() {
        cout << name << ' ' << age;
        if (typeid(*this) == typeid(Base))
            cout << endl;
    }
};

class Leader : virtual public Base {
   private:
    char position[10];

   public:
    Leader(const char* _name, int _age, const char* _position)
        : Base(_name, _age) {
        for (int i = 0; i < 10; i++)
            position[i] = _position[i];
        cout << "Leader constructor" << endl;
    }
    ~Leader() { cout << "Leader destructor" << endl; }
    void show() {
        if (typeid(*this) == typeid(Leader))
            Base::show();
        cout << ' ' << position;
        if (typeid(*this) == typeid(Leader))
            cout << endl;
    }
};

class Engineer : virtual public Base {
   private:
    char major[10];

   public:
    Engineer(const char* _name, int _age, const char* _major)
        : Base(_name, _age) {
        for (int i = 0; i < 10; i++)
            major[i] = _major[i];
        cout << "Engineer constructor" << endl;
    }
    ~Engineer() { cout << "Engineer destructor" << endl; }
    void show() {
        if (typeid(*this) == typeid(Engineer))
            Base::show();
        cout << ' ' << major;
        if (typeid(*this) == typeid(Engineer))
            cout << endl;
    }
};

class Chairman : public Leader, public Engineer {
   private:
   public:
    Chairman(const char* _name,
             int _age,
             const char* _position,
             const char* _major)
        : Base(_name, _age),
          Engineer(_name, _age, _major),
          Leader(_name, _age, _position) {
        cout << "Chairman constructor" << endl;
    }
    ~Chairman() { cout << "Chairman destructor" << endl; }
    void show() {
        if (typeid(*this) == typeid(Chairman))
            Base::show();
        Leader::show();
        Engineer::show();
        if (typeid(*this) == typeid(Chairman))
            cout << endl;
    }
};

class Derived : public Chairman {
   private:
    int hahah;

   public:
    Derived(int _hahah,
            const char* _name,
            int _age,
            const char* _position,
            const char* _major)
        : hahah(_hahah),
          Base(_name, _age),
          Chairman(_name, _age, _major, _position) {
        cout << "Derived constructor" << endl;
    }
    ~Derived() { cout << "Derived destructor" << endl; }
    void show() {
        if (typeid(*this) == typeid(Derived))
            Base::show();
        Chairman::show();
        cout << ' ' << hahah;
        if (typeid(*this) == typeid(Derived))
            cout << endl;
    }
};

int main() {
    Chairman chair("Li", 20, "chair", "computer");
    chair.show();
    Derived d(666, "xlx", 999, "father", "king");
    d.show();
}
