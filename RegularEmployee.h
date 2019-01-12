//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_REGULAREMPLOYEE_H
#define NEW_REGULAREMPLOYEE_H

#include "Employee.h"


//正式职工类
class RegularEmployee : public Employee {
private:
    double allowance; //岗位津贴
    double providentFund; //住房公积金
    double pension; //养老金
    double tax; //所得税+
    double insurance; //医疗保险
    double realWage; //实发工资
    // 计算实发工资=基本职务工资+岗位津贴-养老金-住房公积金-所得税-医疗保险
    void calculateRealWage() override {
        realWage = baseWage + allowance - pension - providentFund - tax - insurance;
    };
public:
    RegularEmployee(double allowance, double providentFund, double pension, double tax, double insurance) : allowance(
            allowance), providentFund(providentFund), pension(pension), tax(tax), insurance(insurance) {
        calculateRealWage();
    }

    void setAllowance(double allowance) {
        RegularEmployee::allowance = allowance;
    }

    void setProvidentFund(double providentFund) {
        RegularEmployee::providentFund = providentFund;
    }

    void setPension(double pension) {
        RegularEmployee::pension = pension;
    }

    void setTax(double tax) {
        RegularEmployee::tax = tax;
    }

    void setInsurance(double insurance) {
        RegularEmployee::insurance = insurance;
    }

};


#endif //NEW_REGULAREMPLOYEE_H
