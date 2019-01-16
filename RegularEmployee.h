//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_REGULAREMPLOYEE_H
#define NEW_REGULAREMPLOYEE_H

#include "Employee.h"

//��ʽְ����
class RegularEmployee : public Employee {
private:
    double allowance; //��λ����
    double providentFund; //ס��������
    double pension; //���Ͻ�
    double tax; //����˰
    double insurance; //ҽ�Ʊ���
    double realWage; //ʵ������

public:
    RegularEmployee(int id, const string &name, bool sex, int age, const string &address, double baseWage,
                    double allowance, double providentFund, double pension, double tax, double insurance);

    RegularEmployee();

    // ����ʵ������=����ְ����+��λ����-���Ͻ�-ס��������-����˰-ҽ�Ʊ���
    void calculateRealWage() override;

    //��ʾְ����Ϣ
    void displayInfo() override;

    //����Ļ����ְ����Ϣ
    void readInfo() override;

    //�����������
    friend ostream &operator<<(ostream &os, const RegularEmployee &employee);

    void setAllowance(double allowance);

    void setProvidentFund(double providentFund);

    void setPension(double pension);

    void setTax(double tax);

    void setInsurance(double insurance);

    double getAllowance() const;

    double getTax() const;

    double getInsurance() const;

    double getRealWage() const override;

    ~RegularEmployee() override;

};


#endif //NEW_REGULAREMPLOYEE_H
