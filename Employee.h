//
// Created by xunmi on 2019/1/12.
//

#ifndef NEW_EMPLOYEE_H
#define NEW_EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

//职工类
class Employee {
protected:
    bool type; //类型 ture为正式职工 false为临时职工
    int id; //编号
    string name; //姓名
    bool sex; //性别 ture为男 false为女
    int age; //年龄
    string address; //家庭住址
    double baseWage; //基本职务工资
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
