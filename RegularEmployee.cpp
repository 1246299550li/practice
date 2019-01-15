//
// Created by xunmi on 2019/1/12.
//

#include "RegularEmployee.h"

void RegularEmployee::calculateRealWage() {
    realWage = baseWage + allowance - pension - providentFund - tax - insurance;
}

template<typename T>
void RegularEmployee::checkInput(T &target) {
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
void RegularEmployee::displayInfo() {
    cout.precision(2);
    cout.setf(ios_base::fixed);
    cout << "--正式职工--\n"
         << "\n编号：" << id
         << "\n姓名：" << name
         << "\n性别：" << sex
         << "\n年龄：" << age
         << "\n家庭住址：" << address
         << "\n基本职务工资：" << baseWage
         << "\n岗位津贴：" << allowance
         << "\n住房公积金：" << providentFund
         << "\n养老金：" << pension
         << "\n所得税：" << tax
         << "\n医疗保险：" << insurance
         << "\n实发工资：" << realWage;
}

//从屏幕读入信息
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

//写入信息到文件
ostream &operator<<(ostream &os, const RegularEmployee &employee) {
    os << static_cast<const Employee &>(employee) << " allowance: " << employee.allowance << " providentFund: "
       << employee.providentFund << " pension: " << employee.pension << " tax: " << employee.tax << " insurance: "
       << employee.insurance << " realWage: " << employee.realWage;
    return os;
}

RegularEmployee::RegularEmployee(int id, const string &name, bool sex, int age, const string &address, double baseWage,
                                 double allowance, double providentFund, double pension, double tax, double insurance) :
        Employee(id, name, sex, age, address, baseWage),
        allowance(allowance), providentFund(providentFund), pension(pension), tax(tax), insurance(insurance) {
    calculateRealWage();
    type = true;
}

RegularEmployee::RegularEmployee() = default;

RegularEmployee::~RegularEmployee() = default;

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

double RegularEmployee::getProvidentFund() const {
    return providentFund;
}

double RegularEmployee::getPension() const {
    return pension;
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

