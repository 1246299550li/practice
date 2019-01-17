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
    tableArr = new Employee *[ARR_SIZE];    //�ܱ�
    for (int i = 0; i < ARR_SIZE; i++) {
        tableArr[i] = nullptr;
    }
    apacity = 0;
    size = ARR_SIZE;

    deleteArr = new Employee *[ARR_SIZE];    //�߼�ɾ����
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
        cout << "�����ڴ��ļ�\n" << endl;
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
        cout << "����ɹ���\n" << endl;
        return true;
    }
}

bool Table::readFromScreen() {
    bool type;
    cout << "������Ҫ��ӵ�ְ������(1��ʾ��ʽְ�� 0��ʾ��ʱְ��):";
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
    cout << "��ӳɹ�\n";
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

        cout << "1.���  2.����  3.�Ա�  4.����  5.��ͥסַ 6.����ְ����\n" <<
             "7.��λ����  8.ס��������  9.���Ͻ�  10.����˰  11.ҽ�Ʊ���\n";
        cout << "����Ҫ�޸ĵ���Ŀ:";
        Employee::checkInput(c);
        switch (c) {
            case 1: {
                cout << "�����޸ĺ�ı��:";
                int tmpId;
                Employee::checkInput(tmpId);
                employee->setId(tmpId);
                break;
            }
            case 2: {
                cout << "�����޸ĺ������:";
                string tmpName;
                Employee::checkInput(tmpName);
                employee->setName(tmpName);
                break;
            }
            case 3: {
                cout << "�޸ĺ���Ա�����1 Ů��0";
                bool tmpSex;
                Employee::checkInput(tmpSex);
                employee->setSex(tmpSex);
                break;
            }
            case 4: {
                cout << "�޸ĺ������:";
                int tmpAge;
                Employee::checkInput(tmpAge);
                employee->setAge(tmpAge);
                break;
            }
            case 5: {
                cout << "�޸ĺ�ļ�ͥסַ:";
                string tmpAddress;
                Employee::checkInput(tmpAddress);
                employee->setAddress(tmpAddress);
                break;
            }
            case 6: {
                cout << "�޸ĺ�Ļ���ְ����:";
                double tmpBaseWage;
                Employee::checkInput(tmpBaseWage);
                employee->setBaseWage(tmpBaseWage);
                break;
            }
            case 7: {
                cout << "�޸ĺ�ĸ�λ����:";
                double tmpAllowance;
                Employee::checkInput(tmpAllowance);
                employee->setAllowance(tmpAllowance);
                break;
            }
            case 8: {
                cout << "�޸ĺ��ס��������:";
                double tmpProvidentFund;
                Employee::checkInput(tmpProvidentFund);
                employee->setProvidentFund(tmpProvidentFund);
                break;
            }
            case 9: {
                cout << "�޸ĺ�����Ͻ�:";
                double tmpPension;
                Employee::checkInput(tmpPension);
                employee->setPension(tmpPension);
                break;
            }
            case 10: {
                cout << "�޸ĺ������˰:";
                double tmpTax;
                Employee::checkInput(tmpTax);
                employee->setTax(tmpTax);
                break;
            }
            case 11: {
                cout << "�޸ĺ��ҽ�Ʊ���:";
                double tmpInsurance;
                Employee::checkInput(tmpInsurance);
                employee->setInsurance(tmpInsurance);
                break;
            }
            default: {
                cout << "��������ȷ��ѡ��:";
                break;
            }

        }
    } else {
        auto *employee = (TemporaryEmployee *) tmpEmployee;
        cout << "1.���  2.����  3.�Ա�  4.����  5.��ͥסַ 6.����ְ����\n" <<
             "7.����  8.����˰\n";
        cout << "����Ҫ�޸ĵ���Ŀ:";
        Employee::checkInput(c);
        switch (c) {
            case 1: {
                cout << "�����޸ĺ�ı��:";
                int tmpId;
                Employee::checkInput(tmpId);
                employee->setId(tmpId);
                break;
            }
            case 2: {
                cout << "�����޸ĺ������:";
                string tmpName;
                Employee::checkInput(tmpName);
                employee->setName(tmpName);
                break;
            }
            case 3: {
                cout << "�޸ĺ���Ա�����1 Ů��0";
                bool tmpSex;
                Employee::checkInput(tmpSex);
                employee->setSex(tmpSex);
                break;
            }
            case 4: {
                cout << "�޸ĺ������:";
                int tmpAge;
                Employee::checkInput(tmpAge);
                employee->setAge(tmpAge);
                break;
            }
            case 5: {
                cout << "�޸ĺ�ļ�ͥסַ:";
                string tmpAddress;
                Employee::checkInput(tmpAddress);
                employee->setAddress(tmpAddress);
                break;
            }
            case 6: {
                cout << "�޸ĺ�Ļ���ְ����:";
                double tmpBaseWage;
                Employee::checkInput(tmpBaseWage);
                employee->setBaseWage(tmpBaseWage);
                break;
            }
            case 7: {
                cout << "�޸ĺ�Ľ���:";
                double tmpBonus;
                Employee::checkInput(tmpBonus);
                employee->setBonus(tmpBonus);
                break;
            }
            case 8: {
                cout << "�޸ĺ������˰:";
                double tmpTax;
                Employee::checkInput(tmpTax);
                employee->setTax(tmpTax);
                break;
            }
            default: {
                cout << "��������ȷ��ѡ��:";
                break;
            }
        }
    }
    tmpEmployee->calculateRealWage();
    cout << "�޸ĳɹ�!\n";
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
        cout << "���˴���\n";
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

//����ָ������������ָ��ָ�����Ĺ�����ֵ ƽ������
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
    cout << "������ֵ��" << sum << endl;
    cout << "ƽ�����ʣ�" << average << endl;
}

//���ܱ�ʵ�����ʽ�������
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
