// cpp_test_1_3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxElement(vector<int>& v) {
    return *(max_element(v.begin(), v.end()));
}

int main()
{
    std::cout << "Hello World!\n";
}

