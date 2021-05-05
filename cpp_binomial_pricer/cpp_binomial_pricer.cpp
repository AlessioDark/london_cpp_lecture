// cpp_binomial_pricer.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>

using namespace std;

class Binlittice {

public:
    void setN(int N0) {
        N = N0;
        lattice.resize(N+1);
        for (int i = 0; i != N + 1; ++i) 
            lattice[i].resize(i+1);
    }
    void setNode(int n1, int i1, double node1) {
        lattice[n1][i1] = node1;
    }
    double getNode(int n, int i) const{
        return lattice[n][i];
    }
    void display() {
        for (int i = 0; i < N + 1; ++i) {
            for (int j = 0; j < i + 1; ++j)
                cout << getNode(i, j) << " ";
            cout << endl;
        }            
    }
private:
    int N;
    vector<vector<double>> lattice;


};

int main()
{
    std::cout << "Hello World!\n";
}

