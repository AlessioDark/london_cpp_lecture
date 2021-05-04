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
        capacity = s * 2;
        data = new int[capacity];
        memset(data, 0, sizeof(int) * s);
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
        assert(i >= 0 && i < _size);
        return data[i];
    }

    myVector& operator+(const myVector& v) {
        assert(_size == v._size);
        myVector* ret = new myVector(_size);
        for (int i = 0; i != _size; ++i)
            ret->data[i] = data[i] + v.data[i];
        return *ret;
    }

    bool pushBack(int val) {
        if (capacity <= _size)
            resize();
        data[_size] = val;
        ++_size;
        return true;
    }

    bool resize() {
        int* temp_data = new int[2 * _size];
        capacity = 2 * _size;
        for (int i = 0; i != _size; ++i)
            temp_data[i] = data[i];
        delete[] data;
        data = temp_data;
        return true;
    }
private:
    int* data;
    int _size;
    int capacity;
};

int main()
{
    myVector vec(5);
    for (int i = 0; i != vec.size(); ++i)
        cout << vec[i] << endl;
    vec.pushBack(100);
    vec.pushBack(100);
    vec.pushBack(100);
    vec.pushBack(100);
    vec.pushBack(100);
    vec.pushBack(100);
    vec.pushBack(100);
    vec.pushBack(100);
    for (int i = 0; i != vec.size(); ++i)
        cout << vec[i] << endl;

}

