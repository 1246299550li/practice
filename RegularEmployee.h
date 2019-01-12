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
    double incsurance; //医疗保险
    double realWage; //实发工资
    // 计算实发工资=基本职务工资+岗位津贴-养老金-住房公积金-所得税-医疗保险
    void calculateRealWage() override {
        realWage = baseWage + allowance - pension - providentFund - tax - incsurance;
    };
    bool readInfo(int id, string name, bool sex, int age, string address, double baseWage, double allowance, double providentFund, double pension, double tax, double incsurance, double realWage)
};


#endif //NEW_REGULAREMPLOYEE_H
