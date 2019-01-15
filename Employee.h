﻿//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_EMPLOYEE_H
#define NEW_EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

//ְ����
class Employee {
protected:
    bool type; //���� tureΪ��ʽְ�� falseΪ��ʱְ��
    int id; //���
    string name; //����
    bool sex; //�Ա� tureΪ�� falseΪŮ
    int age; //����
    string address; //��ͥסַ
    double baseWage; //����ְ����
    virtual void calculateRealWage() = 0;

public:
    virtual void displayInfo() = 0;

    virtual void readInfo() = 0;

    Employee(int id, const string &name, bool sex, int age, const string &address, double baseWage);

    Employee();

    friend ostream &operator<<(ostream &os, const Employee &employee);

    void setId(int id);

    void setName(const string &name);

    void setSex(bool sex);

    void setAge(int age);

    void setAddress(const string &address);

    void setBaseWage(double baseWage);

    bool isType() const;

    int getId() const;

    const string &getName() const;

    bool isSex() const;

    int getAge() const;

    const string &getAddress() const;

    double getBaseWage() const;

    virtual double getRealWage() const = 0;

    virtual ~Employee();
};


#endif //NEW_EMPLOYEE_H
