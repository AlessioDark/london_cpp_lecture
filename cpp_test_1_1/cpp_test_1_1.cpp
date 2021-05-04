// cpp_test_1_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

int foo(int& a) {
    a--;
    return 10;
}
int main()
{
    int val = 7;
    foo(val);
    cout << val;
}


