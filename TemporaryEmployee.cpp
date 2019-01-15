﻿//
// Created by xunmi on 2019/1/12.
//

#include "TemporaryEmployee.h"

//��ʾ��Ϣ
void TemporaryEmployee::displayInfo() {
    cout.precision(2);
    cout.
            setf(ios_base::fixed);
    cout << "--��ʱְ��--\n"
         << "\n��ţ�" << id
         << "\n������" << name
         << "\n�Ա�" << sex
         << "\n���䣺" << age
         << "\n��ͥסַ��" << address
         << "\n����ְ���ʣ�" << baseWage
         << "\n����" << bonus
         << "\n����˰��" << tax
         << "\nʵ�����ʣ�" <<
         realWage;
}

//����Ļ������Ϣ
void TemporaryEmployee::readInfo() {
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

    cout << "\n�����뽱��";
    checkInput(bonus);

    cout << "\n����������˰��";
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

//д����Ϣ���ļ�
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