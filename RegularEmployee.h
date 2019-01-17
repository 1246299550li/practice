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
    double tax; //所得税
    double insurance; //医疗保险
    double realWage; //实发工资

public:
    RegularEmployee(int id, const string &name, bool sex, int age, const string &address, double baseWage,
                    double allowance, double providentFund, double pension, double tax, double insurance);

    RegularEmployee();

    // 计算实发工资=基本职务工资+岗位津贴-养老金-住房公积金-所得税-医疗保险
    void calculateRealWage() override;

    //显示职工信息
    void displayInfo() override;

    //从屏幕读入职工信息
    void readInfo() override;

    //重载输出方法
    friend ostream &operator<<(ostream &os, const RegularEmployee &employee);

    void setAllowance(double allowance);

    void setProvidentFund(double providentFund);

    void setPension(double pension);

    void setTax(double tax);

    double getProvidentFund() const;

    double getPension() const;

    void setInsurance(double insurance);

    double getAllowance() const;

    double getTax() const;

    double getInsurance() const;

    double getRealWage() const override;

    ~RegularEmployee() override;

};


#endif //NEW_REGULAREMPLOYEE_H
