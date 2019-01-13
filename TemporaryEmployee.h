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

protected:
    //计算实发工资=基本职务工资+奖金-所得税
    void calculateRealWage() override {
        realWage = baseWage + bonus - tax;
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
        cout << "--临时职工--\n"
             << "\n编号：" << id
             << "\n姓名：" << name
             << "\n性别：" << sex
             << "\n年龄：" << age
             << "\n家庭住址：" << address
             << "\n基本职务工资：" << baseWage
             << "\n奖金：" << bonus
             << "\n所得税：" << tax
             << "\n实发工资：" << realWage;
    }

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

        cout << "\n请输入奖金：";
        checkInput(bonus);

        cout << "\n请输入所得税：";
        checkInput(tax);
    }

    TemporaryEmployee(int id, const string &name, bool sex, int age, const string &address, double baseWage,
                      double bonus, double tax) :
            Employee(id, name, sex, age, address, baseWage), bonus(bonus), tax(tax) {
        calculateRealWage();
        type = false;
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
