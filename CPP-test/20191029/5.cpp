#include<iostream>
#include<string>
using namespace std;

class Staff {
    protected:
        int code;
        string name;
        static int count;
    public:
        Staff(string str) {
            name = str;
            code = count;
            count ++;
        }
        void SetName(string str) {
            name = str;
        }
        string GetName() {
            return name;
        }
        int GetCode() {
            return code;
        }
        static int GetStaffCount() {
            return count-1;
        }
};
int Staff::count = 1;
class Teacher: virtual public Staff {
    protected:
        string subject;
    public:
        Teacher(string str1, string str2): Staff(str1), subject(str2) { }
        void SetSubject(string str) {
            subject = str;
        }
        string GetSubject() {
            return subject;
        }
};

class Officer: virtual public Staff{
    protected:
        string work;
    public:
        Officer(string str1, string str2): Staff(str1), work(str2) {    }
        void SetWork(string str) {
            work = str;
        }  
        string GetWork() {
            return work;
        }
};

class Teacher_Officer: public Teacher, public Officer {
    public:
        Teacher_Officer(string str1, string str2, string str3): Staff(str1), Teacher(str1, str2), Officer(str1, str3) { }
};

int main() {
    Teacher t1("孔子", "儒家文学"); //创建教学类员工t1
    Teacher t2 ("公输班","建筑学");
    Officer o1("端木赐","财务科长"); //创建教辅类员工o1
    Teacher_Officer to3("颜回","儒家文学","副院长");//创建教师教辅类员工to3

    cout << "共有教职工" << Staff::GetStaffCount() << "人" << endl;
    cout << t1.GetCode() << ", " << t1.GetName() << ", " << t1.GetSubject() << endl;
    cout << t2.GetCode() << ", " << t2.GetName() << ", " << t2.GetSubject() << endl;
    cout << o1.GetCode() << ", " << o1.GetName() << ", " << o1.GetWork() << endl;
    cout << to3.GetCode() << ", " << to3.GetName() << ", " << to3.GetSubject() << ", " << to3.GetWork() << endl;
    return 0;
}