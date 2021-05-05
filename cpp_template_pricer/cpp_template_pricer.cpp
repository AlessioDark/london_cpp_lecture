// cpp_template_pricer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>

using namespace std;

template<typename type>
class binLattice {
public:
    void setN(int N0) {
        N = N0;
        lattice.resize(N+1);
        for (int i = 0; i != N + 1; ++i)
            lattice[i].resize(i+1);
    }
    setNode(int n, int i, type t) {
        lattice[n][i] = t;
    }
    type getNode(int n,int i) {
        return lattice[n][i];
    }
private:
    int N;
    vector<vector<type>> lattice;
};

int main()
{
    std::cout << "Hello World!\n";
}

