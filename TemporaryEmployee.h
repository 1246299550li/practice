//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_TEMPORARYEMPLOYEE_H
#define NEW_TEMPORARYEMPLOYEE_H

#include <fstream>
#include "Employee.h"

//��ʱְ����
class TemporaryEmployee : public Employee {
private:
    double bonus; //����
    double tax; //����˰
    double realWage; //ʵ������

public:
    TemporaryEmployee(int id, const string &name, bool sex, int age, const string &address, double baseWage,
                      double bonus, double tax);

    TemporaryEmployee();

    //����ʵ������=����ְ����+����-����˰
    void calculateRealWage() override;

    //��ʾְ����Ϣ
    void displayInfo() override;

    //����Ļ����ְ����Ϣ
    void readInfo() override;

    //д����Ϣ���ļ�
    friend ostream &operator<<(ostream &os, const TemporaryEmployee &employee);

    void setBonus(double bonus);

    void setTax(double tax);

    double getBonus() const;

    double getTax() const;

    double getRealWage() const override;

    ~TemporaryEmployee() override;
};


#endif //NEW_TEMPORARYEMPLOYEE_H
