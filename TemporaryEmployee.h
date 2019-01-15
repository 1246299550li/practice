//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_TEMPORARYEMPLOYEE_H
#define NEW_TEMPORARYEMPLOYEE_H

#include <fstream>
#include "Employee.h"

//临时职工类
class TemporaryEmployee : public Employee {
private:
    double bonus; //奖金
    double tax; //所得税
    double realWage; //实发工资

protected:
    //计算实发工资=基本职务工资+奖金-所得税
    void calculateRealWage() override {
        realWage = baseWage + bonus - tax;
    };
public:


    //显示信息
    void displayInfo() override;

    //从屏幕读入信息
    void readInfo() override;

    TemporaryEmployee(int id, const string &name, bool sex, int age, const string &address, double baseWage,
                      double bonus, double tax);

    TemporaryEmployee();

    //写入信息到文件
    friend ostream &operator<<(ostream &os, const TemporaryEmployee &employee);


    ~TemporaryEmployee() override;

    void setBonus(double bonus);

    void setTax(double tax);

    double getBonus() const;

    double getTax() const;

    double getRealWage() const override;
};


#endif //NEW_TEMPORARYEMPLOYEE_H
