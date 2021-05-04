// cpp_test_1_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>

using namespace std;

int* getValues(bool b)
{
    if (b) {
        static int ret[] = { -1,-2,-3,-4,-5 };
        return ret;
    } 
    static int ret[] = { 1,2,3,4,5 };
    return ret;
}

int main()
{
    auto arr1 = getValues(true);
    for (int i = 0; i != 5; ++i)
        cout << arr1[i] << ",";
    auto arr2 = getValues(false);
    for (int i = 0; i != 5; ++i)
        cout << arr2[i] << ",";
    return 0;
}


