// cpp_account.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>

using namespace std;

class account {
protected:
    double banlance;

public:
    /*默认构造函数*/
    account() :banlance(0.0) {
    
    }
    /*含有参数的默认构造函数*/
    account(double d) :banlance(d) {
    
    }

    /*存钱函数*/
    bool deposit(double amt) {
        banlance += amt;
        return true;
    }
    /*获取当前现金*/
    double getBanlance() {
        return banlance;
    }
    /*析构函数*/
    ~account() {}
};

class saveingAccount :public account {
protected:
    /*利率*/
    double rate;
public:
    /*默认构造函数*/
    saveingAccount() :account(), rate(0.0) {
    }
    /*含有参数的构造函数*/
    saveingAccount(double bal,double r) :account(bal), rate(r) {
    
    }
    /*返回本金加利息*/
    double compound() {
        double interest = banlance * rate;
        banlance += interest;
        return banlance;
    }
    /*取钱*/
    double withdraw(double amt) {
        if (amt > banlance)
            return 0.0;
        banlance -= amt;
        return amt;
    }
};

class checkingAccount :public account
{
protected:
    double limit;
    double charge;
public:
    /*默认构造函数*/
    checkingAccount() :account(), limit(0.0), charge(0.0) {}
    checkingAccount(double bal, double lim, double ch) :account(bal), limit(lim), charge(ch) {}
    



};

int main()
{
    std::cout << "Hello World!\n";
}

