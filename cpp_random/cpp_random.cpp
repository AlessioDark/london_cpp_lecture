// cpp_random.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <random>

using namespace std;


int main()
{
    mt19937 rnd;
    for (int i = 0; i != 10; ++i)
        cout << (rnd() + 0.5) / (rnd.max() + 1.0) << endl;
}

