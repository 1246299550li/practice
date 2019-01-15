﻿//
// Created by xunmi on 2019/1/12.
//

#include "RegularEmployee.h"

void RegularEmployee::calculateRealWage() {
    realWage = baseWage + allowance - pension - providentFund - tax - insurance;
}

//��ʾ��Ϣ
void RegularEmployee::displayInfo() {
    cout.precision(2);
    cout.setf(ios_base::fixed);
    cout << "--��ʽְ��--\n"
         << "\n��ţ�" << id
         << "\n������" << name
         << "\n�Ա�" << sex
         << "\n���䣺" << age
         << "\n��ͥסַ��" << address
         << "\n����ְ���ʣ�" << baseWage
         << "\n��λ������" << allowance
         << "\nס��������" << providentFund
         << "\n���Ͻ�" << pension
         << "\n����˰��" << tax
         << "\nҽ�Ʊ��գ�" << insurance
         << "\nʵ�����ʣ�" << realWage;
}

//����Ļ������Ϣ
void RegularEmployee::readInfo() {
    cout << "\n��������(������)��";
    checkInput(id);

    cout << "\n������������";
    checkInput(name);

    cout << "\n�������ձ�(1��ʾ��, 0��ʾŮ)��";
    checkInput(sex);

    cout << "\n����������(������)��";
    checkInput(age);

    cout << "\n�������ͥסַ��";
    checkInput(address);

    cout << "\n���������ְ���ʣ�";
    checkInput(baseWage);

    cout << "\n�������λ������";
    checkInput(allowance);

    cout << "\n������ס��������";
    checkInput(providentFund);

    cout << "\n���������Ͻ�";
    checkInput(pension);

    cout << "\n����������˰��";
    checkInput(tax);

    cout << "\n������ҽ�Ʊ��գ�";
    checkInput(insurance);


}

//д����Ϣ���ļ�
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

