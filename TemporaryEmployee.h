//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_TEMPORARYEMPLOYEE_H
#define NEW_TEMPORARYEMPLOYEE_H

#include <ostream>
#include "Employee.h"

//��ʱְ����
class TemporaryEmployee : public Employee {
private:
    double bonus; //����
    double tax; //����˰
    double realWage; //ʵ������

protected:
    //����ʵ������=����ְ����+����-����˰
    void calculateRealWage() override {
        realWage = baseWage + bonus - tax;
    };
public:
    template<typename T>
    void checkInput(T &target) {
        while (!(cin >> target)) {
            cout << "\n�����������������";
            cin.clear();
            while (cin.get() != '\n') {
            }
        }
        cout << "\n����ɹ�";
        while (cin.get() != '\n') {
        }
    }

    //��ʾ��Ϣ
    void displayInfo() override;

    //����Ļ������Ϣ
    void readInfo() override;

    TemporaryEmployee(int id, const string &name, bool sex, int age, const string &address, double baseWage,
                      double bonus, double tax);

    TemporaryEmployee();

    //д����Ϣ���ļ�
    friend ostream &operator<<(ostream &os, const TemporaryEmployee &employee);


    ~TemporaryEmployee() override;

    void setBonus(double bonus);

    void setTax(double tax);

    double getBonus() const;

    double getTax() const;

    double getRealWage() const override;
};


#endif //NEW_TEMPORARYEMPLOYEE_H
