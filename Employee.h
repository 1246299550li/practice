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
    int id; //编号
    string name; //姓名
    bool sex; //性别
    int age; //年龄
    string address; //家庭住址
    double baseWage; //基本职务工资
    virtual void calculateRealWage() = 0;

public:
    virtual void displayInfo() = 0;
    Employee(int id, const string &name, bool sex, int age, const string &address, double baseWage);

    Employee();

    void setId(int id);

    void setName(const string &name);

    void setSex(bool sex);

    void setAge(int age);

    void setAddress(const string &address);

    void setBaseWage(double baseWage);

    int getId() const;

    const string &getName() const;

    bool isSex() const;

    int getAge() const;

    const string &getAddress() const;

    double getBaseWage() const;

    virtual ~Employee();
};


#endif //NEW_EMPLOYEE_H
