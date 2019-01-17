//
// Created by xunmi on 2019/1/12.
//

#include "Table.h"
#include<fstream>
#include <algorithm>

double Table::getThisRealWage(Employee *p) {
    if (p->isType()) {
        return dynamic_cast<RegularEmployee *>(p)->getRealWage();
    } else {
        return dynamic_cast<TemporaryEmployee *>(p)->getRealWage();
    }

}

Table::Table() {
    tableArr = new Employee *[ARR_SIZE];    //总表
    for (int i = 0; i < ARR_SIZE; i++) {
        tableArr[i] = nullptr;
    }
    apacity = 0;
    size = ARR_SIZE;

    deleteArr = new Employee *[ARR_SIZE];    //逻辑删除表
    for (int i = 0; i < ARR_SIZE; i++) {
        deleteArr[i] = nullptr;
    }
    deleteApacity = 0;
    deleteSize = ARR_SIZE;
}

int Table::getApacity() const {
    return apacity;
}

Employee **Table::getTableArr() const {
    return tableArr;
}

bool Table::memExtension(bool tableType) {
    if (tableType) {
        auto **desMem = new Employee *[size + ARR_INCREMENT];
        for (int i = 0; i < size + ARR_INCREMENT; i++) {
            desMem[i] = nullptr;
        }
        for (int i = 0; i < size; i++) {
            desMem[i] = tableArr[i];
        }

        delete[] tableArr;
        tableArr = desMem;
        size += ARR_INCREMENT;
        return true;
    } else {
        auto **desMem = new Employee *[deleteSize + ARR_INCREMENT];
        for (int i = 0; i < deleteSize + ARR_INCREMENT; i++) {
            desMem[i] = nullptr;
        }
        for (int i = 0; i < deleteSize; i++) {
            desMem[i] = deleteArr[i];
        }
        delete[] deleteArr;
        deleteArr = desMem;
        deleteSize += ARR_INCREMENT;
        return true;
    }
}

void Table::pushBack(Employee *employee, bool tableType) {
    if (tableType) {
        if (apacity >= size)
            if (!memExtension(tableType)) {
                cout << "memory error";
                return;
            }
        tableArr[apacity] = employee;
        apacity++;
    } else {
        if (deleteApacity >= deleteSize)
            if (!memExtension(tableType)) {
                cout << "memory error";
                return;
            }
        deleteArr[deleteApacity] = employee;
        deleteApacity++;
    }

}

bool Table::display(bool tableType) {
    if (tableType) {
        if (apacity == 0) {
            return false;
        }
        for (int i = 0; i < apacity; i++) {
            if (tableArr[i] != nullptr) {
                if (tableArr[i]->isType()) {
                    dynamic_cast<RegularEmployee *>(tableArr[i])->displayInfo();
                } else {
                    dynamic_cast<TemporaryEmployee *>(tableArr[i])->displayInfo();
                }
            }
        }
    } else {
        if (deleteApacity == 0) {
            return false;
        }
        for (int i = 0; i < deleteApacity; i++) {
            if (deleteArr[i] != nullptr) {
                if (deleteArr[i]->isType()) {
                    dynamic_cast<RegularEmployee *>(deleteArr[i])->displayInfo();
                } else {
                    dynamic_cast<TemporaryEmployee *>(deleteArr[i])->displayInfo();
                }
            }
        }
    }
    return true;
}

bool Table::readFromFile(string fileName, bool tableType) {
    ifstream infile(fileName);
    if (!infile.is_open()) {
        cout << "不存在此文件\n" << endl;
        return false;
    } else {
        bool type;
        while (infile >> type) {
            double tmpAllowance, tmpProvidentFund, tmpPension, tmpTax,
                    tmpInsurance, tmpBaseWage, tmpRealWage, tmpBonus;
            int tmpId, tmpAge;
            bool tmpSex;
            string tmpName, tmpAddress;
            Employee *p;
            if (type) {
                infile >> tmpId >> tmpName
                       >> tmpSex >> tmpAge
                       >> tmpAddress >> tmpBaseWage
                       >> tmpAllowance >> tmpProvidentFund
                       >> tmpPension >> tmpTax
                       >> tmpInsurance;
                p = new RegularEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpAllowance,
                                        tmpProvidentFund, tmpPension, tmpTax, tmpInsurance);
            } else {
                infile >> tmpId >> tmpName
                       >> tmpSex >> tmpAge
                       >> tmpAddress >> tmpBaseWage
                       >> tmpBonus >> tmpTax;
                p = new TemporaryEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpBonus,
                                          tmpTax);
            }
            pushBack(p, tableType);
        }
        infile.close();
        cout << "读入成功！\n" << endl;
        return true;
    }
}

bool Table::readFromScreen() {
    bool type;
    cout << "请输入要添加的职工种类(1表示正式职工 0表示临时职工):";
    Employee::checkInput(type);
    Employee *p;
    if (type) {
        p = new RegularEmployee();
        p->readInfo();
    } else {
        p = new TemporaryEmployee();
        p->readInfo();
    }
    pushBack(p, true);
    cout << "添加成功\n";
    return true;
}

int Table::searchEmployee(int id, bool tableType) {
    int j = 0;
    if (tableType) {
        for (int i = 0; i < apacity; i++) {
            if (tableArr[i] != nullptr) {
                if (tableArr[i]->getId() == id) {
                    return i;
                }
            }
        }

    } else {
        for (int i = 0; i < deleteApacity; i++) {
            if (deleteArr[i] != nullptr) {
                if (deleteArr[i]->getId() == id) {
                    return i;
                }
            }

        }
    }
    return -1;
}

Employee **Table::searchEmployee(string name) {
    auto **p = new Employee *[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++) {
        p[i] = nullptr;
    }
    int j = 0;
    for (int i = 0; i < apacity; i++) {
        if (tableArr[i] != nullptr) {
            if (tableArr[i]->getName() == name) {
                p[j++] = tableArr[i];
            }
        }
    }
    return p;
}

Employee **Table::searchEmployee(double realWage) {
    auto **p = new Employee *[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++) {
        p[i] = nullptr;
    }
    int j = 0;
    for (int i = 0; i < apacity; i++) {
        if (tableArr[i] != nullptr) {
            if (tableArr[i]->getRealWage() == realWage) {
                p[j++] = tableArr[i];
            }
        }
    }
    return p;
}

Employee **Table::searchEmployee(bool type) {
    auto **p = new Employee *[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; i++) {
        p[i] = nullptr;
    }
    int j = 0;
    for (int i = 0; i < apacity; i++) {
        if (tableArr[i] != nullptr) {
            if (tableArr[i]->isType() == type) {
                p[j++] = tableArr[i];
            }
        }
    }
    return p;
}

bool Table::updateEmployee(Employee *tmpEmployee) {
    int c;
    if (tmpEmployee->isType()) {
        auto *employee = (RegularEmployee *) tmpEmployee;

        cout << "1.编号  2.姓名  3.性别  4.年龄  5.家庭住址 6.基本职务工资\n" <<
             "7.岗位津贴  8.住房公积金  9.养老金  10.所得税  11.医疗保险\n";
        cout << "输入要修改的项目:";
        Employee::checkInput(c);
        switch (c) {
            case 1: {
                cout << "输入修改后的编号:";
                int tmpId;
                Employee::checkInput(tmpId);
                employee->setId(tmpId);
                break;
            }
            case 2: {
                cout << "输入修改后的姓名:";
                string tmpName;
                Employee::checkInput(tmpName);
                employee->setName(tmpName);
                break;
            }
            case 3: {
                cout << "修改后的性别：男生1 女生0";
                bool tmpSex;
                Employee::checkInput(tmpSex);
                employee->setSex(tmpSex);
                break;
            }
            case 4: {
                cout << "修改后的年龄:";
                int tmpAge;
                Employee::checkInput(tmpAge);
                employee->setAge(tmpAge);
                break;
            }
            case 5: {
                cout << "修改后的家庭住址:";
                string tmpAddress;
                Employee::checkInput(tmpAddress);
                employee->setAddress(tmpAddress);
                break;
            }
            case 6: {
                cout << "修改后的基本职务工资:";
                double tmpBaseWage;
                Employee::checkInput(tmpBaseWage);
                employee->setBaseWage(tmpBaseWage);
                break;
            }
            case 7: {
                cout << "修改后的岗位津贴:";
                double tmpAllowance;
                Employee::checkInput(tmpAllowance);
                employee->setAllowance(tmpAllowance);
                break;
            }
            case 8: {
                cout << "修改后的住房公积金:";
                double tmpProvidentFund;
                Employee::checkInput(tmpProvidentFund);
                employee->setProvidentFund(tmpProvidentFund);
                break;
            }
            case 9: {
                cout << "修改后的养老金:";
                double tmpPension;
                Employee::checkInput(tmpPension);
                employee->setPension(tmpPension);
                break;
            }
            case 10: {
                cout << "修改后的所得税:";
                double tmpTax;
                Employee::checkInput(tmpTax);
                employee->setTax(tmpTax);
                break;
            }
            case 11: {
                cout << "修改后的医疗保险:";
                double tmpInsurance;
                Employee::checkInput(tmpInsurance);
                employee->setInsurance(tmpInsurance);
                break;
            }
            default: {
                cout << "请输入正确的选项:";
                break;
            }

        }
    } else {
        auto *employee = (TemporaryEmployee *) tmpEmployee;
        cout << "1.编号  2.姓名  3.性别  4.年龄  5.家庭住址 6.基本职务工资\n" <<
             "7.奖金  8.所得税\n";
        cout << "输入要修改的项目:";
        Employee::checkInput(c);
        switch (c) {
            case 1: {
                cout << "输入修改后的编号:";
                int tmpId;
                Employee::checkInput(tmpId);
                employee->setId(tmpId);
                break;
            }
            case 2: {
                cout << "输入修改后的姓名:";
                string tmpName;
                Employee::checkInput(tmpName);
                employee->setName(tmpName);
                break;
            }
            case 3: {
                cout << "修改后的性别：男生1 女生0";
                bool tmpSex;
                Employee::checkInput(tmpSex);
                employee->setSex(tmpSex);
                break;
            }
            case 4: {
                cout << "修改后的年龄:";
                int tmpAge;
                Employee::checkInput(tmpAge);
                employee->setAge(tmpAge);
                break;
            }
            case 5: {
                cout << "修改后的家庭住址:";
                string tmpAddress;
                Employee::checkInput(tmpAddress);
                employee->setAddress(tmpAddress);
                break;
            }
            case 6: {
                cout << "修改后的基本职务工资:";
                double tmpBaseWage;
                Employee::checkInput(tmpBaseWage);
                employee->setBaseWage(tmpBaseWage);
                break;
            }
            case 7: {
                cout << "修改后的奖金:";
                double tmpBonus;
                Employee::checkInput(tmpBonus);
                employee->setBonus(tmpBonus);
                break;
            }
            case 8: {
                cout << "修改后的所得税:";
                double tmpTax;
                Employee::checkInput(tmpTax);
                employee->setTax(tmpTax);
                break;
            }
            default: {
                cout << "请输入正确的选项:";
                break;
            }
        }
    }
    tmpEmployee->calculateRealWage();
    cout << "修改成功!\n";
    return true;
}

bool Table::logicalDeleteEmployee(int id, string nowOpenedFile) {
    int pos = searchEmployee(id, true);
    if (pos == -1) {
        return false;
    } else {
        pushBack(tableArr[pos], false);
        fstream f;
        f.open("delete" + nowOpenedFile);
        if (f.is_open()) {
            f.close();
        } else {
            ofstream oFile("delete" + nowOpenedFile);
            oFile.close();
        }
        readFromFile("delete" + nowOpenedFile, false);
        saveInFile("delete" + nowOpenedFile, false);
        for (int i = 0; deleteArr[i] != nullptr; i++) {
            delete deleteArr[i];
            deleteArr[i] = nullptr;
        }
        deleteApacity = 0;
        tableArr[pos] = nullptr;
        cout << "到此处了\n";
        saveInFile(nowOpenedFile, true);
        return true;
    }
}

bool Table::physicalDeleteEmployee(int id, string nowOpenedFile) {
    int pos = searchEmployee(id, true);
    if (pos == -1) {
        return false;
    } else {
        delete tableArr[pos];
        tableArr[pos] = nullptr;
        saveInFile(nowOpenedFile, true);
        return true;
    }
}

bool Table::recoverDeleteEmployee(int id, string nowOpenedFile) {
    int pos = searchEmployee(id, false);
    if (pos == -1) {
        return false;
    } else {
        pushBack(deleteArr[pos], true);
        saveInFile(nowOpenedFile, true);
        deleteArr[pos] = nullptr;
        saveInFile("delete" + nowOpenedFile, false);
        for (int i = 0; i < deleteApacity; i++) {
            if (i != pos && deleteArr[i] != nullptr) {
                delete deleteArr[i];
                deleteArr[i] = nullptr;
            }
        }

        return true;
    }
}

bool Table::saveInFile(string fileName, bool tableType) {
    ofstream out;
    out.open(fileName, ios::out);
    if (tableType) {
        for (int i = 0; i < apacity; ++i) {
            if (tableArr[i] != nullptr) {
                if (tableArr[i]->isType()) {
                    out << (*dynamic_cast<RegularEmployee *>(tableArr[i])) << endl;
                } else {
                    out << (*dynamic_cast<TemporaryEmployee *>(tableArr[i])) << endl;
                }
            }
        }
    } else {
        for (int i = 0; i < deleteApacity; ++i) {
            if (deleteArr[i] != nullptr) {
                if (deleteArr[i]->isType()) {
                    out << *dynamic_cast<RegularEmployee *>(deleteArr[i]) << endl;
                } else {
                    out << *dynamic_cast<TemporaryEmployee *>(deleteArr[i]) << endl;
                }
            }
        }
    }
    out.close();
    return true;
}

//计算指针数组中所有指针指向对象的工资总值 平均工资
void Table::calculateWage(Employee **arr) {
    double sum = 0;
    double average = 0;
    int cot = 0;
    for (int i = 0; i < ARR_SIZE; i++) {
        if (arr[i] != nullptr) {
            sum += arr[i]->getRealWage();
            cot++;
        }
    }
    average = sum / cot;
    cout.precision(2);
    cout.setf(ios_base::fixed);
    cout << "工资总值：" << sum << endl;
    cout << "平均工资：" << average << endl;
}

//将总表按实发工资进行排序
void Table::sortByRealWage() {
//    for (int i = 0; i < apacity; i++) {
//        if (tableArr[i] != nullptr) {
//            double tmpI = getThisRealWage(tableArr[i]);
//            for (int j = i + 1; j < apacity; j++) {
//                if (tableArr[j] != nullptr) {
//                    double tmpJ = getThisRealWage(tableArr[j]);
//                    if (tmpI < tmpJ) {
//                        Employee *t = tableArr[i];
//                        tableArr[i] = tableArr[j];
//                        tableArr[j] = t;
//                    }
//                }
//            }
//        }
//    }
    quickSort(0, apacity - 1);
}

void Table::quickSort(int start, int last) {
    int i = start;
    int j = last;
    while (tableArr[i] == nullptr) {
        i++;
    }
    double temp = getThisRealWage(tableArr[i]);
    Employee *tmp = tableArr[i];
    if (i < j) {
        while (i < j) {
            while (i < j && (tableArr[j] == nullptr || getThisRealWage(tableArr[j]) >= temp)) {
                j--;
            }
            if (i < j) {
                tableArr[i] = tableArr[j];
                i++;
            }
            while (i < j && (tableArr[i] == nullptr || temp > getThisRealWage(tableArr[i]))) {
                i++;
            }
            if (i < j) {
                tableArr[j] = tableArr[i];
                j--;
            }
        }
        tableArr[i] = tmp;
        quickSort(start, i - 1);
        quickSort(i + 1, last);
    }
}

Table::~Table() = default;
