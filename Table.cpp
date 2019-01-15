//
// Created by xunmi on 2019/1/12.
//

#include "Table.h"
#include<fstream>

template<typename T>
void TemporaryEmployee::checkInput(T &target) {
    while (!(cin >> target)) {
        cout << "\n输入错误！请重新输入";
        cin.clear();
        while (cin.get() != '\n') {
        }
    }
    cout << "\n输入成功";
    while (cin.get() != '\n') {
    }
}

Table::Table() {
    tableArr = new Employee *[ARR_SIZE];    //总表
    deleteArr = new Employee *[ARR_SIZE];    //逻辑删除表
    deleteSize = ARR_SIZE;
    size = ARR_SIZE;
    apacity = 0;
    deleteApacity = 0;
}


bool Table::readFromFile(string fileName, bool tableType) {

    ifstream infile(fileName);
    if (!infile.is_open())
        return false;
    else {
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
                       >> tmpInsurance >> tmpRealWage;
                p = new RegularEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpAllowance,
                                        tmpProvidentFund, tmpPension, tmpTax, tmpInsurance);
            } else {
                infile >> tmpId >> tmpName
                       >> tmpSex >> tmpAge
                       >> tmpAddress >> tmpBaseWage
                       >> tmpBonus >> tmpTax
                       >> tmpRealWage;
                p = new TemporaryEmployee(tmpId, tmpName, tmpSex, tmpAge, tmpAddress, tmpBaseWage, tmpBonus,
                                          tmpTax);
            }
            pushBack(p, tableType);
        }
        infile.close();
        return true;
    }
}


bool Table::memExtension(bool tableType) {
    if (tableType) {
        auto **desMem = new Employee *[size + ARR_INCREMENT];

        for (int i = 0; i < size; i++) {
            desMem[i] = tableArr[i];
        }
        delete[] tableArr;
        tableArr = desMem;
        size += ARR_INCREMENT;
        return true;
    } else {
        auto **desMem = new Employee *[deleteSize + ARR_INCREMENT];

        for (int i = 0; i < size; i++) {
            desMem[i] = deleteArr[i];
        }
        delete[] deleteArr;
        deleteArr = desMem;
        deleteSize += ARR_INCREMENT;
        return true;
    }
}

bool Table::readFromScreen() {
    bool type;
    cout << "请输入要添加的职工种类(1表示正式职工 0表示临时职工):";
    checkInput(type);
    Employee *p;
    if (type) {
        p = new RegularEmployee();
        p->readInfo();
    } else {
        p = new TemporaryEmployee();
        p->readInfo();
    }
    pushBack(p, true);

}

void Table::pushBack(Employee *employee, bool tableType) {
    if (tableType) {
        if (apacity == size)
            if (!memExtension(tableType)) {
                cout << "memory error";
                return;
            }
        tableArr[apacity] = employee;
        apacity++;
    } else {
        if (deleteApacity == deleteSize)
            if (!memExtension(tableType)) {
                cout << "memory error";
                return;
            }
        tableArr[deleteApacity] = employee;
        deleteApacity++;
    }

}

Employee **Table::searchEmployee(int id, bool tableType) {
    auto **p = new Employee *[ARR_SIZE];
    int j = 0;
    if (tableType) {
        for (int i = 0; tableArr[i] != nullptr && i < apacity; i++) {
            if (tableArr[i]->getId() == id) {
                p[j] = tableArr[i];
                j++;
            }
        }
        return p;
    } else {
        for (int i = 0; deleteArr[i] != nullptr && i < deleteApacity; i++) {
            if (deleteArr[i]->getId() == id) {
                p[j] = deleteArr[i];
                j++;
            }
        }
        return p;
    }
}

Employee **Table::searchEmployee(string name, bool tableType) {
    auto **p = new Employee *[ARR_SIZE];
    int j = 0;
    if (tableType) {
        for (int i = 0; tableArr[i] != nullptr && i < apacity; i++) {
            if (tableArr[i]->getName() == name) {
                p[j] = tableArr[i];
                j++;
            }
        }
        return p;
    } else {
        for (int i = 0; deleteArr[i] != nullptr && i < deleteApacity; i++) {
            if (deleteArr[i]->getName() == name) {
                p[j] = deleteArr[i];
                j++;
            }
        }
        return p;
    }
}

Employee **Table::searchEmployee(double realWage, bool tableType) {
    auto **p = new Employee *[ARR_SIZE];
    int j = 0;
    if (tableType) {
        for (int i = 0; tableArr[i] != nullptr && i < apacity; i++) {
            if (tableArr[i]->getRealWage() == realWage) {
                p[j] = tableArr[i];
                j++;
            }
        }
        return p;
    } else {
        for (int i = 0; deleteArr[i] != nullptr && i < deleteApacity; i++) {
            if (deleteArr[i]->getRealWage() == realWage) {
                p[j] = tableArr[i];
                j++;
            }
        }
        return p;
    }
}

bool Table::updateEmployee(Employee *tmpEmployee) {
    int c;
    if (tmpEmployee->isType()) {
        auto *employee = (RegularEmployee *) tmpEmployee;
        cout << "输入要修改的项目\n";
        cout << "1.编号  2.姓名  3.性别  4.年龄  5.家庭住址 6.基本职务工资\n" <<
             "7.岗位津贴  8.住房公积金  9.养老金  10.所得税  11.医疗保险\n";
        checkInput(c);
        switch (c) {
            case 1: {
                cout << "输入修改后的编号\n";
                int tmpId;
                checkInput(tmpId);
                employee->setId(tmpId);
                break;
            }
            case 2: {
                cout << "输入修改后的姓名\n";
                string tmpName;
                checkInput(tmpName);
                employee->setName(tmpName);
                break;
            }
            case 3: {
                cout << "修改后的性别：男生为：true 女生为：false";
                bool tmpSex;
                checkInput(tmpSex);
                employee->setSex(tmpSex);
                break;
            }
            case 4: {
                cout << "修改后的年龄\n";
                int tmpAge;
                checkInput(tmpAge);
                employee->setAge(tmpAge);
                break;
            }
            case 5: {
                cout << "修改后的家庭住址\n";
                string tmpAddress;
                checkInput(tmpAddress);
                employee->setAddress(tmpAddress);
                break;
            }
            case 6: {
                cout << "修改后的基本职务工资\n";
                double tmpBaseWage;
                checkInput(tmpBaseWage);
                employee->setBaseWage(tmpBaseWage);
                break;
            }
            case 7: {
                cout << "修改后的岗位津贴\n";
                double tmpAllowance;
                checkInput(tmpAllowance);
                employee->setAllowance(tmpAllowance);
                break;
            }
            case 8: {
                cout << "修改后的住房公积金\n";
                double tmpProvidentFund;
                checkInput(tmpProvidentFund);
                employee->setProvidentFund(tmpProvidentFund);
                break;
            }
            case 9: {
                cout << "修改后的养老金\n";
                double tmpPension;
                checkInput(tmpPension);
                employee->setPension(tmpPension);
                break;
            }
            case 10: {
                cout << "修改后的所得税\n";
                double tmpTax;
                checkInput(tmpTax);
                employee->setTax(tmpTax);
                break;
            }
            case 11: {
                cout << "修改后的医疗保险\n";
                double tmpInsurance;
                checkInput(tmpInsurance);
                employee->setInsurance(tmpInsurance);
                break;
            }
            default: {
                cout << "请输入正确的选项\n";
                break;
            }

        }
    } else {
        auto *employee = (TemporaryEmployee *) tmpEmployee;
        cout << "输入要修改的项目\n";
        cout << "1.编号  2.姓名  3.性别  4.年龄  5.家庭住址 6.基本职务工资\n" <<
             "7.奖金  8.所得税\n";
        checkInput(c);
        switch (c) {
            case 1: {
                cout << "输入修改后的编号\n";
                int tmpId;
                checkInput(tmpId);
                employee->setId(tmpId);
                break;
            }
            case 2: {
                cout << "输入修改后的姓名\n";
                string tmpName;
                checkInput(tmpName);
                employee->setName(tmpName);
                break;
            }
            case 3: {
                cout << "修改后的性别：男生为：true 女生为：false";
                bool tmpSex;
                checkInput(tmpSex);
                employee->setSex(tmpSex);
                break;
            }
            case 4: {
                cout << "修改后的年龄\n";
                int tmpAge;
                checkInput(tmpAge);
                employee->setAge(tmpAge);
                break;
            }
            case 5: {
                cout << "修改后的家庭住址\n";
                string tmpAddress;
                checkInput(tmpAddress);
                employee->setAddress(tmpAddress);
                break;
            }
            case 6: {
                cout << "修改后的基本职务工资\n";
                double tmpBaseWage;
                checkInput(tmpBaseWag);
                employee->setBaseWage(tmpBaseWage);
                break;
            }
            case 7: {
                cout << "修改后的奖金\n";
                double tmpBonus;
                checkInput(tmpBonus);
                employee->setBonus(tmpBonus);
                break;
            }
            case 8: {
                cout << "修改后的所得税\n";
                double tmpTax;
                checkInput(tmpTax);
                employee->setTax(tmpTax);
                break;
            }
            default: {
                cout << "请输入正确的选项\n";
                break;
            }
        }
    }
    cout << "修改成功\n";
}

void Table::sortByRealWage() {                                         //将总表按实发工资进行排序
//    for (int i = 0; i < size; i++) {
//        if (*tableArr[i] != nullptr) {
//            for (int j = i + 1; j < size; j++) {
//                if (*tableArr[j] != nullptr) {
//                    if (*tableArr[i]->realwage < *tableArr[j]->realwage) {
//                        double t = *tableArr[i];
//                        *tableArr[i] = *tableArr[j];
//                        *tableArr[j] = t;
//                    }
//                }
//            }
//        }
//    }
}

bool Table::saveInFile(string fileName, bool tableType) {
    ofstream out;
    out.open(fileName);
    if (tableType) {
        for (int i = 0; i < apacity; ++i) {
            if (tableArr[i] != nullptr) {
                out << tableArr[i] << endl;
            }
        }
    } else {
        for (int i = 0; i < deleteApacity; ++i) {
            if (tableArr[i] != nullptr) {
                out << tableArr[i] << endl;
            }
        }
    }

    out.close();
    return true;
}

bool Table::logicalDeleteEmployee(int id) {
    Employee **resArr = searchEmployee(id, true);
    if (resArr[0] == nullptr) {
        return false;
    } else {
        pushBack(resArr[0], false);
        saveInFile("DeletedStaffInfo.txt", false);
        return true;
    }

}

bool Table::physicalDeleteEmployee(int id) {
    Employee **deletion = searchEmployee(id, false);
    if (*deletion == nullptr) {
        return false;
    } else {
        delete *deletion;
        *deletion = nullptr;
        saveInFile("DeletedStaffInfo.txt", false);
        return true;
    }
}

bool Table::undeleteEmployee(int id) {
    Employee **recovery = searchEmployee(id, false);
    if (*recovery == nullptr) {
        return false;
    } else {
        pushBack(*recovery, false);
        saveInFile("DeletedStaffInfo.txt", false);
        return true;
    }
}


void Table::calculateWage(Employee **) {        //计算指针数组中所有指针指向对象的工资总值 平均工资
    double sum = 0;
    double average = 0;
    for (int i = 0; i < apacity; i++) {
        if (tableArr[i] != nullptr)
            sum = sum + tableArr[i]->getRealWage();
    }
    average = sum / apacity;
    cout << "工资总值：" << sum << "\n";
    cout << "平均工资：" << average << "\n";
}

