//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_TEMPORARYEMPLOYEE_H
#define NEW_TEMPORARYEMPLOYEE_H

#include "Employee.h"
//临时职工类
class TemporaryEmployee : public Employee{
private:
    double bonus; //奖金
    double tax; //所得税
    double realWage; //实发工资
};


#endif //NEW_TEMPORARYEMPLOYEE_H
