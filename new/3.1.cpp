#include <iostream>

using namespace std;

class Student;

class Teacher {
   private:
    Student* pStu;

   public:
    Teacher(int size);
    ~Teacher();

    void assign(int index);
    void show(int index);
};

class Student {
    friend void Teacher::assign(int index);

   private:
    int usual_grade;
    int final_grade;
    static float proportion;

   public:
    Student() {}
    ~Student() {}
    static void setProp() { cin >> proportion; }
    void compScore() {
        cout << usual_grade * proportion + final_grade * (1 - proportion);
    }
};

float Student::proportion = 0.5;

Teacher::Teacher(int size) {
    pStu = new Student[size];
}

Teacher::~Teacher() {
    delete[] pStu;
}

void Teacher::assign(int index) {
    cin >> pStu[index].usual_grade >> pStu[index].final_grade;
}

void Teacher::show(int index) {
    pStu[index].compScore();
}

int main() {
    Student::setProp();
    int num;
    cin >> num;
    Teacher t(num);
    for (int i = 0; i < num; i++)
        t.assign(i);

    for (int i = 0; i < num; i++) {
        t.show(i);
        if (i != num - 1)
            cout << ' ';
    }
}