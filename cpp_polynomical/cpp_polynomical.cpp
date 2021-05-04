// cpp_polynomical.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class polynomical {
public:
    /*默认构造函数*/
    polynomical() {
        v.push_back(0.0);
    }
    /*只有一个参数*/
    polynomical(double d) {
        v.push_back(d);
    }
    /*用数组进行初始化*/
    polynomical(vector<double>& in) {
        v = in;
    }
    /*得到在x处的y值*/
    double getY(double x) {
        double ret(0.0);
        for (int i = 0; i != v.size(); ++i)
            ret += pow(x, i) * v[i];
        return ret;
    }
    polynomical operator+(const polynomical& p) {
        assert(p.v.size()==v.size());
        polynomical ret(v);
        for (int i = 0; i != v.size(); ++i)
            ret.v[i] = p.v[i] + v[i];
        return ret;
    }
private:
    vector<double> v;
};

int main()
{
    polynomical p1(10);
    polynomical p2(20);
    auto p3 = p1 + p2;
    cout << p3.getY(5) << endl;
}


