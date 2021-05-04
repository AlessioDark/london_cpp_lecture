// cpp_poly.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>

using namespace std;

class musician 
{
public:
    virtual void greet() {
        cout << "musician say hello\n";
    }
};
class trumpeter :public musician
{
public:void greet() {
    cout << "trumpeter say hello\n";
}
};
class pianist :public musician
{
public :
    void greet() {
        cout << "pianist say hello\n";
    }
};

bool musicianGreet(musician* m)
{
    m->greet();
    return true;
}

//bool musicianGreet(musician& m)
//{
//    m.greet();
//    return true;
//}

bool musicianGreet(musician m)
{
    m.greet();
    return true;
}


int main()
{
    trumpeter t;
    pianist p;
    musician m;
    musician* pm;
    t.greet();
    p.greet();
    m.greet();
    cout << endl << endl;
    pm = &m;
    pm->greet();
    pm = &p;
    pm->greet();
    pm = &t;
    pm->greet();
    cout << endl;
    vector<musician*> v;
    v.push_back(new musician());
    v.push_back(new pianist());
    v.push_back(new trumpeter());
    cout << "1111...." << endl;
    for (int i = 0; i != v.size(); ++i)
        musicianGreet(v[i]);
    cout << "2222...." << endl;
    for (int i = 0; i != v.size(); ++i)
        musicianGreet(*(v[i]));
    for (int i = 0; i != v.size(); ++i) 
        delete v[i];

    trumpeter* pt = new trumpeter();
    cout << "3333..." << endl;
    pt->musician::greet();
    cout << "4444..." << endl;
    pt->greet();
    return 0;
}


