#include <cstring>
#include <iostream>
#include <typeinfo>

using namespace std;

class Base {
   private:
    char* name;
    int age;

   public:
    Base(const char* n, int a) : age(a) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        cout << "Base constructor" << endl;
    }
    virtual ~Base() {
        delete[] name;
        cout << "Base destructor" << endl;
    }
    virtual void show() { cout << name << " " << age << " "; }
};

class Leader : virtual public Base {
   private:
    char title[10];

   public:
    Leader(const char* n, int a, const char* t) : Base(n, a) {
        strcpy(title, t);
        cout << "Leader constructor" << endl;
    }
    ~Leader() { cout << "Leader destructor" << endl; }
    void show() {
        if (typeid(*this) == typeid(Leader)) {
            Base::show();
        }
        cout << title << " ";
    }
};

class Engineer : virtual public Base {
   private:
    char major[10];

   public:
    Engineer(const char* n, int a, const char* m) : Base(n, a) {
        strcpy(major, m);
        cout << "Engineer constructor" << endl;
    }
    ~Engineer() { cout << "Engineer destructor" << endl; }
    void show() {
        if (typeid(*this) == typeid(Engineer)) {
            Base::show();
        }
        cout << major << " ";
    }
};

class Chairman : public Leader, public Engineer {
   public:
    Chairman(const char* n, const char* t, const char* m, int a)
        : Base(n, a), Leader(n, a, t), Engineer(n, a, m) {
        cout << "Chairman constructor" << endl;
    }
    ~Chairman() { cout << "Chairman destructor" << endl; }
    void show() {
        Base::show();
        Leader::show();
        Engineer::show();
        cout << endl;
    }
};

int main() {
    Chairman a("Li", "chair", "computer", 20);
    a.show();
    return 0;
}
