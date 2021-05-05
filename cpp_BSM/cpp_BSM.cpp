// cpp_BSM.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <random>

using namespace std;

class BSM;

static mt19937 meisenTwice;

class pathIndependentOption {
public:
    void setMaturity(double);
    double getMaturity()const;
    void setStrike(double);
    double getStrike()const;
    virtual double payoff(double stock_at_maturity)const = 0;
    virtual double price(const BSM& bsm)const = 0;
    virtual ~pathIndependentOption() {}
protected:
    double maturity;
    double strike;

};

class callOption :public pathIndependentOption
{
public:
    double payoff(double x) const{
    
    }
    double price(const BSM& bsm)const {
        double S = bsm.stock_price;
        double K = getStrike();
        double sigma = bsm.volatility;
        double r = bsm.risk_free_rate;
        double T = maturity - bsm.date;
        double numerator = log(S / K) + (r + sigma * sigma * 0.5) * T;
        double denominator = sigma * sqrt(T);
        double d1 = numerator / denominator;
        double d2 = d1 - denominator;
        return S * normcdf(d1) - exp(-r * T) * K * normcdf(d2);

    }
    ~callOption() {}

};

class putOption:public pathIndependentOption {
public:
    double price(const BSM& bsm)const {}
    double payoff(double x)const {}

    ~putOption() {
    
    }

};
class BSM {
public:
    double stock_price;
    double volatility;
    double drift;
    double risk_free_rate;
    double date;
};

int main()
{
    std::cout << "Hello World!\n";
}

