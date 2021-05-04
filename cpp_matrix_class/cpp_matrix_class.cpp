// cpp_matrix_class.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <vector>
#include <cassert>


using namespace std;

class myMatrix {

public:
    /*默认构造函数*/
    myMatrix() {
        row_size = 0;
        col_size = 0;
        data = NULL;
    }
    /*析构函数*/
    ~myMatrix(){
        delete[] data;
    }
    /*有参数的构造函数*/
    myMatrix(int r, int c, double d) :row_size(r), col_size(c) {
        data = new double[r * c];
        for (int i = 0; i != size(); ++i)
            data[i] = d;
    }
    /*定位到具体的位置*/
    int offset(int i, int j) {
        assert((i >= 0 && i < row_size)&& (j>=0 && j<col_size));
        return col_size*i+j;
    }
    /*获取指定位置的值*/
    double get(int i, int j) {
        return data[offset(i - 1, j - 1)];
    }
    /*设置指定位置的值*/
    bool set(int i, int j, double d) {
        data[offset((i - 1), (j - 1))] = d;
        return true;
    }
    /*获取矩阵总数*/
    int size() {
        return row_size * col_size;
    }
    /*获取行数*/
    int getRowSize() {
        return row_size;
    }
    /*获取列数*/
    int getColSize() {
        return col_size;
    }
    /*指向数据开始的指针*/
    double* begin() {
        return data;
    }
    /*指向结尾的指针*/
    double* end() {
        return data + size();    
    }
    /*运算符重载+*/   
    myMatrix operator+(myMatrix& b) {
        assert((this->row_size==b.row_size) && (this->col_size==b.col_size));
        myMatrix temp(row_size,col_size,0);
        for (int i = 0; i != size(); ++i)
            temp.data[i] = this->data[i] + b.data[i];
        return temp;
    }
    myMatrix operator-(myMatrix& b) {
        assert((this->row_size == b.row_size) && (this->col_size == b.col_size));
        myMatrix temp(row_size, col_size, 0);
        for (int i = 0; i != size(); ++i)
            temp.data[i] = this->data[i] - b.data[i];
        return temp;    
    }
    myMatrix operator*(myMatrix& b) {
        assert((this->row_size == b.row_size) && (this->col_size == b.col_size));
        myMatrix temp(row_size, col_size, 0);
        for (int i = 0; i != size(); ++i)
            temp.data[i] = this->data[i] * b.data[i];
        return temp;
    }
    /*运算符重载+=*/
    myMatrix operator+=(const myMatrix& b) {
        assert((this->row_size == b.row_size) && (this->col_size == b.col_size));
        myMatrix temp(row_size, col_size, 0);
        for (int i = 0; i != size(); ++i)
            temp.data[i] = this->data[i] + b.data[i];
        return temp;
    }
    /*运算符重载-=*/
    myMatrix operator-=(const myMatrix& b) {
        assert((this->row_size == b.row_size) && (this->col_size == b.col_size));
        myMatrix temp(row_size, col_size, 0);
        for (int i = 0; i != size(); ++i)
            temp.data[i] = this->data[i] - b.data[i];
        return temp;
    }
   
private:
    /*行数*/
  int  row_size;
  /*列数*/
  int  col_size;
  /*数据存储*/
  double* data;
  
 
};

/*输入输出运算符*/
ostream& operator<<(ostream& os, myMatrix& m) {
    for (int i = 0; i != m.getRowSize(); ++i) {
        for (int j = 0; j != m.getColSize(); ++j)
            os << m.get(i + 1, j + 1) << ",";
        os << endl;
    }
    return os;
}

int main()
{
    myMatrix m1(3, 2, 0);
    cout << m1;
    myMatrix m2(3, 3, 1);
    cout << m2;

    auto m = m1 + m2;
    cout << m;
}


