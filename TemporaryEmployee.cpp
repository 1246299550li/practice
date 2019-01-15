//
// Created by xunmi on 2019/1/12.
//

#include "TemporaryEmployee.h"

//显示信息
void TemporaryEmployee::displayInfo() {
    cout.precision(2);
    cout.
            setf(ios_base::fixed);
    cout << "--临时职工--\n"
         << "\n编号：" << id
         << "\n姓名：" << name
         << "\n性别：" << sex
         << "\n年龄：" << age
         << "\n家庭住址：" << address
         << "\n基本职务工资：" << baseWage
         << "\n奖金：" << bonus
         << "\n所得税：" << tax
         << "\n实发工资：" <<
         realWage;
}

//从屏幕读入信息
void TemporaryEmployee::readInfo() {
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

TemporaryEmployee::TemporaryEmployee(int id, const string &name, bool sex, int age, const string &address,
                                     double baseWage,
                                     double bonus, double tax) :
        Employee(id, name, sex, age, address, baseWage), bonus(bonus), tax(tax) {
    calculateRealWage();
    type = false;
}

TemporaryEmployee::TemporaryEmployee() = default;

//写入信息到文件
ostream &operator<<(ostream &os, const TemporaryEmployee &employee) {
    os << static_cast<const Employee &>(employee) << " bonus: " << employee.bonus << " tax: " << employee.tax
       << " realWage: " << employee.realWage;
    return os;
}

TemporaryEmployee::~TemporaryEmployee() = default;

void TemporaryEmployee::setBonus(double bonus) {
    TemporaryEmployee::bonus = bonus;
}

void TemporaryEmployee::setTax(double tax) {
    TemporaryEmployee::tax = tax;
}

double TemporaryEmployee::getBonus() const {
    return bonus;
}

double TemporaryEmployee::getTax() const {
    return tax;
}

double TemporaryEmployee::getRealWage() const {
    return realWage;
}