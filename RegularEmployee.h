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
    // 计算实发工资=基本职务工资+岗位津贴-养老金-住房公积金-所得税-医疗保险
    void calculateRealWage() override {
        realWage = baseWage + allowance - pension - providentFund - tax - insurance;
    };
public:
    void displayInfo() override {
        cout << "编号：" << id
             << "姓名：" << name
             << "性别：" << sex
             << "年龄：" << age
             << "家庭住址：" << address
             << "基本职务工资：" << baseWage
             << "岗位津贴：" << allowance
             << "住房公积金：" << providentFund
             << "养老金：" << pension
             << "所得税：" << tax
             << "医疗保险：" << insurance
             << "实发工资：" << realWage;
    }

    RegularEmployee(int id, const string &name, bool sex, int age, const string &address, double baseWage,
                    double allowance, double providentFund, double pension, double tax, double insurance) :
            Employee(id, name, sex, age, address, baseWage),
            allowance(allowance), providentFund(providentFund), pension(pension), tax(tax), insurance(insurance) {
        calculateRealWage();
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
