//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_REGULAREMPLOYEE_H
#define NEW_REGULAREMPLOYEE_H

#include "Employee.h"

using namespace std;

//正式职工类
class RegularEmployee : public Employee {
private:
    double allowance; //岗位津贴
    double providentFund; //住房公积金
    double pension; //养老金
    double tax; //所得税
    double insurance; //医疗保险
    double realWage; //实发工资

protected:
    // 计算实发工资=基本职务工资+岗位津贴-养老金-住房公积金-所得税-医疗保险
    void calculateRealWage() override {
        realWage = baseWage + allowance - pension - providentFund - tax - insurance;
    };

public:
    template<typename T>
    void checkInput(T &target) {
        while (!(cin >> target)) {
            cout << "\n输入错误！请重新输入";
            cin.clear();
            while (cin.get() != '\n') {
            }
        }
        cout << "\n输入成功";
        while (cin.get() != '\n') {
        }
    }

    //显示信息
    void displayInfo() override {
        cout.precision(2);
        cout.setf(ios_base::fixed);
        cout << "--正式职工--\n"
             << "\n编号：" << id
             << "\n姓名：" << name
             << "\n性别：" << sex
             << "\n年龄：" << age
             << "\n家庭住址：" << address
             << "\n基本职务工资：" << baseWage
             << "\n岗位津贴：" << allowance
             << "\n住房公积金：" << providentFund
             << "\n养老金：" << pension
             << "\n所得税：" << tax
             << "\n医疗保险：" << insurance
             << "\n实发工资：" << realWage;
    }

    //从屏幕读入信息
    void readInfo() override {
        cout << "\n请输入编号(正整数)：";
        checkInput(id);

        cout << "\n请输入姓名：";
        checkInput(name);

        cout << "\n请输入姓别(1表示男, 0表示女)：";
        checkInput(sex);

        cout << "\n请输入年龄(正整数)：";
        checkInput(age);

        cout << "\n请输入家庭住址：";
        checkInput(address);

        cout << "\n请输入基本职务工资：";
        checkInput(baseWage);

        cout << "\n请输入岗位津贴：";
        checkInput(allowance);

        cout << "\n请输入住房公积金：";
        checkInput(providentFund);

        cout << "\n请输入养老金：";
        checkInput(pension);

        cout << "\n请输入所得税：";
        checkInput(tax);

        cout << "\n请输入医疗保险：";
        checkInput(insurance);


    }

    RegularEmployee(int id, const string &name, bool sex, int age, const string &address, double baseWage,
                    double allowance, double providentFund, double pension, double tax, double insurance) :
            Employee(id, name, sex, age, address, baseWage),
            allowance(allowance), providentFund(providentFund), pension(pension), tax(tax), insurance(insurance) {
        calculateRealWage();
        type = true;
    }

    RegularEmployee() {

    }

    virtual ~RegularEmployee() {

    }

    double getAllowance() const {
        return allowance;
    }

    double getProvidentFund() const {
        return providentFund;
    }

    double getPension() const {
        return pension;
    }

    double getTax() const {
        return tax;
    }

    double getInsurance() const {
        return insurance;
    }

    double getRealWage() const {
        return realWage;
    }
};


#endif //NEW_REGULAREMPLOYEE_H
