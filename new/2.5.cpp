#include <cstring>
#include <iostream>

using namespace std;

class Student {
   public:
    Student(const char* name, float g1, float g2) : g1(g1), g2(g2) {
        this->name = new char(strlen(name) + 1);
        strcpy(this->name, name);
        cout << "construct " << this->name << endl;
    }
    Student(const Student& stu) : g1(stu.g1 - 10), g2(stu.g2 - 10) {
        char* tmp = new char(strlen(stu.name) + sizeof('u') + 1);
        strcpy(tmp, stu.name);
        tmp[strlen(stu.name) + sizeof('u') - 1] = 'u';
        this->name = tmp;
        cout << "copy " << this->name << endl;
    }
    ~Student() {
        cout << "destruct " << this->name << endl;
        delete[] this->name;
        this->name = nullptr;
    }

    const float& getG1() { return g1; }
    const float& getG2() { return g2; }
    const Student* getLoc() { return this; }

   private:
    char* name;
    float g1;
    float g2;
};

int main() {
    Student a("li", 90.0, 80.0);
    {
        Student st[2]{Student("zhang", 80.0, 70.0),
                      Student("wang", 90.0, 80.0)};
        for (int i = 0; i < 2; i++) {
            cout << (st[i].getG1() + st[i].getG2()) / 2 << " ";
        }
        cout << endl;
    }
    Student b(a);
    cout << &b - b.getLoc() << endl;
}