//
// Created by xunmi on 2019/1/12.
//

#include "RegularEmployee.h"

RegularEmployee::RegularEmployee(int id, const string &name, bool sex, int age, const string &address, double baseWage,
                                 double allowance, double providentFund, double pension, double tax, double insurance) :
        Employee(id, name, sex, age, address, baseWage),
        allowance(allowance), providentFund(providentFund), pension(pension), tax(tax), insurance(insurance) {
    calculateRealWage();
    type = true;
}

RegularEmployee::RegularEmployee() = default;

// 计算实发工资=基本职务工资+岗位津贴-养老金-住房公积金-所得税-医疗保险
void RegularEmployee::calculateRealWage() {
    realWage = baseWage + allowance - pension - providentFund - tax - insurance;
}

//显示职工信息
void RegularEmployee::displayInfo() {
    cout.precision(2);
    cout.setf(ios_base::fixed);
    cout << "--正式职工--"
         << "\n编号：" << id
         << "   姓名：" << name
         << "   性别：" << sex
         << "   年龄：" << age
         << "   家庭住址：" << address
         << "   基本职务工资：" << baseWage
         << "\n岗位津贴：" << allowance
         << "   住房公积金：" << providentFund
         << "   养老金：" << pension
         << "   所得税：" << tax
         << "   医疗保险：" << insurance
         << "   实发工资：" << realWage
         << "\n\n";
}

//从屏幕读入职工信息
void RegularEmployee::readInfo() {
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
    cout << "\n请输入岗位津贴：";
    checkInput(allowance);
    cout << "\n请输入住房公积金：";
    checkInput(providentFund);
    cout << "\n请输入养老金：";
    checkInput(pension);
    cout << "\n请输入所得税：";
    checkInput(tax);
    cout << "\n请输入医疗保险：";
    checkInput(insurance);
}

//重载输出方法
ostream &operator<<(ostream &os, const RegularEmployee &employee) {
    os << static_cast<const Employee &>(employee) << " " << employee.allowance << " "
       << employee.providentFund << " " << employee.pension << " " << employee.tax << " "
       << employee.insurance;
    return os;
}

void RegularEmployee::setAllowance(double allowance) {
    RegularEmployee::allowance = allowance;
}

void RegularEmployee::setProvidentFund(double providentFund) {
    RegularEmployee::providentFund = providentFund;
}

void RegularEmployee::setPension(double pension) {
    RegularEmployee::pension = pension;
}

void RegularEmployee::setTax(double tax) {
    RegularEmployee::tax = tax;
}

void RegularEmployee::setInsurance(double insurance) {
    RegularEmployee::insurance = insurance;
}

double RegularEmployee::getAllowance() const {
    return allowance;
}


double RegularEmployee::getTax() const {
    return tax;
}

double RegularEmployee::getInsurance() const {
    return insurance;
}

double RegularEmployee::getRealWage() const {
    return realWage;
}

RegularEmployee::~RegularEmployee() = default;