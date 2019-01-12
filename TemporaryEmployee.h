//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_TEMPORARYEMPLOYEE_H
#define NEW_TEMPORARYEMPLOYEE_H

#include "Employee.h"

//临时职工类
class TemporaryEmployee : public Employee {
private:
    double bonus; //奖金
    double tax; //所得税
    double realWage; //实发工资
    //计算实发工资=基本职务工资+奖金-所得税
    void calculateRealWage() override {
        realWage = baseWage + bonus - tax;
    };
public:
    TemporaryEmployee(int id, const string &name, bool sex, int age, const string &address, double baseWage,
                      double bonus, double tax) : Employee(id, name, sex, age, address, baseWage), bonus(bonus),
                                                  tax(tax) {
        calculateRealWage();
    }

    virtual ~TemporaryEmployee() {

    }

    void setBonus(double bonus) {
        TemporaryEmployee::bonus = bonus;
    }

    void setTax(double tax) {
        TemporaryEmployee::tax = tax;
    }

    double getBonus() const {
        return bonus;
    }

    double getTax() const {
        return tax;
    }

    double getRealWage() const {
        return realWage;
    }
};


#endif //NEW_TEMPORARYEMPLOYEE_H
