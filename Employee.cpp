//
// Created by xunmi on 2019/1/12.
//

#include "Employee.h"

Employee::Employee(int id, const string &name, bool sex, int age, const string &address, double baseWage) :
        id(id), name(name), sex(sex), age(age), address(address), baseWage(baseWage) {

}

Employee::Employee() = default;

ostream &operator<<(ostream &os, const Employee &employee) {
    os << " " << employee.type << " " << employee.id << " " << employee.name << " " << employee.sex
       << " " << employee.age << " " << employee.address << " " << employee.baseWage;
    return os;
}

void Employee::setId(int id) {
    Employee::id = id;
}

void Employee::setName(const string &name) {
    Employee::name = name;
}

void Employee::setSex(bool sex) {
    Employee::sex = sex;
}

void Employee::setAge(int age) {
    Employee::age = age;
}

void Employee::setAddress(const string &address) {
    Employee::address = address;
}

void Employee::setBaseWage(double baseWage) {
    Employee::baseWage = baseWage;
}

bool Employee::isType() const {
    return type;
}

int Employee::getId() const {
    return id;
}

const string &Employee::getName() const {
    return name;
}

bool Employee::isSex() const {
    return sex;
}

const string &Employee::getAddress() const {
    return address;
}

double Employee::getBaseWage() const {
    return baseWage;
}

Employee::~Employee() = default;