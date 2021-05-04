// cpp_stringstream.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    stringstream ss;
    for (int i = 0; i != 100; ++i)
        ss << "Hello,World...\n";
    string str=ss.str();
    cout << str << endl;
}

