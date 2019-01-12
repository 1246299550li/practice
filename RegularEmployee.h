//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_REGULAREMPLOYEE_H
#define NEW_REGULAREMPLOYEE_H

#include "Employee.h"
//正式职工类
class RegularEmployee : public Employee{
private:
    double allowance; //岗位津贴
    double providentFund; //住房公积金
    double pension; //养老金
    double tax; //所得税
    double incsurance; //医疗保险
    double realWage; //实发工资
};


#endif //NEW_REGULAREMPLOYEE_H
