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

// ����ʵ������=����ְ����+��λ����-���Ͻ�-ס��������-����˰-ҽ�Ʊ���
void RegularEmployee::calculateRealWage() {
    realWage = baseWage + allowance - pension - providentFund - tax - insurance;
}

//��ʾְ����Ϣ
void RegularEmployee::displayInfo() {
    cout.precision(2);
    cout.setf(ios_base::fixed);
    cout << "--��ʽְ��--"
         << "\n��ţ�" << id
         << "   ������" << name
         << "   �Ա�" << sex
         << "   ���䣺" << age
         << "   ��ͥסַ��" << address
         << "   ����ְ���ʣ�" << baseWage
         << "\n��λ������" << allowance
         << "   ס��������" << providentFund
         << "   ���Ͻ�" << pension
         << "   ����˰��" << tax
         << "   ҽ�Ʊ��գ�" << insurance
         << "   ʵ�����ʣ�" << realWage
         << "\n\n";
}

//����Ļ����ְ����Ϣ
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

//�����������
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