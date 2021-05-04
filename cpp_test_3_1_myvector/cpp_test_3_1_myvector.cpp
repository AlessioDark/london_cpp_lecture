// cpp_test_3_1_myvector.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <cassert>

using namespace std;

class myVector {
public:
    /*默认的构造函数*/
    myVector(int s) {
        _size = s;
        data = new int[s];
        memset(data,0,sizeof(int)*s);
    }
    /*默认的析构函数*/
    ~myVector() {
        delete[] data;
    }
    /*获取大小*/
    int size() {
        return _size;
    }
    /*返回引用就是返回本身*/
    int& operator[](int i) {
        assert(i>=0 && i<_size);
        return data[i];
    }

    myVector& operator+(const myVector& v) {
        assert(_size == v._size);
        myVector* ret=new myVector(_size);
        for (int i = 0; i != _size; ++i)
            ret->data[i] = data[i] + v.data[i];
        return *ret;
    }
private:
    int* data;
    int _size;
};

int main()
{
    myVector v1(1);
    myVector v2(1);
    auto v3 = v1 + v2;
    cout << v3[0] << endl;
    return 0;

}
