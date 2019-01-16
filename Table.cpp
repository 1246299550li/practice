//
// Created by xunmi on 2019/1/12.
//

#include "Table.h"
#include<fstream>


Table::Table() {
    tableArr = new Employee *[ARR_SIZE];    //�ܱ�
    deleteArr = new Employee *[ARR_SIZE];    //�߼�ɾ����
    deleteSize = ARR_SIZE;
    size = ARR_SIZE;
    apacity = 0;
    deleteApacity = 0;
}


bool Table::readFromFile(string fileName, bool tableType) {

    ifstream infile(fileName);
    if (!infile.is_open()) {
        cout << "false" << endl;
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
        cout << "successful" << endl;
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
    cout << "������Ҫ��ӵ�ְ������(1��ʾ��ʽְ�� 0��ʾ��ʱְ��):";
//    checkInput(type);
cin >> type;
//    cout << "1" << endl;
    Employee *p;
    if (type) {
        p = new RegularEmployee();
        p->readInfo();
    } else {
        p = new TemporaryEmployee();
        p->readInfo();
    }
    pushBack(p, true);
	return true;

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
        cout << "����Ҫ�޸ĵ���Ŀ\n";
        cout << "1.���  2.����  3.�Ա�  4.����  5.��ͥסַ 6.����ְ����\n" <<
             "7.��λ����  8.ס��������  9.���Ͻ�  10.����˰  11.ҽ�Ʊ���\n";
        checkInput(c);
        switch (c) {
            case 1: {
                cout << "�����޸ĺ�ı��\n";
                int tmpId;
                checkInput(tmpId);
                employee->setId(tmpId);
                break;
            }
            case 2: {
                cout << "�����޸ĺ������\n";
                string tmpName;
                checkInput(tmpName);
                employee->setName(tmpName);
                break;
            }
            case 3: {
                cout << "�޸ĺ���Ա�����Ϊ��true Ů��Ϊ��false";
                bool tmpSex;
                checkInput(tmpSex);
                employee->setSex(tmpSex);
                break;
            }
            case 4: {
                cout << "�޸ĺ������\n";
                int tmpAge;
                checkInput(tmpAge);
                employee->setAge(tmpAge);
                break;
            }
            case 5: {
                cout << "�޸ĺ�ļ�ͥסַ\n";
                string tmpAddress;
                checkInput(tmpAddress);
                employee->setAddress(tmpAddress);
                break;
            }
            case 6: {
                cout << "�޸ĺ�Ļ���ְ����\n";
                double tmpBaseWage;
                checkInput(tmpBaseWage);
                employee->setBaseWage(tmpBaseWage);
                break;
            }
            case 7: {
                cout << "�޸ĺ�ĸ�λ����\n";
                double tmpAllowance;
                checkInput(tmpAllowance);
                employee->setAllowance(tmpAllowance);
                break;
            }
            case 8: {
                cout << "�޸ĺ��ס��������\n";
                double tmpProvidentFund;
                checkInput(tmpProvidentFund);
                employee->setProvidentFund(tmpProvidentFund);
                break;
            }
            case 9: {
                cout << "�޸ĺ�����Ͻ�\n";
                double tmpPension;
                checkInput(tmpPension);
                employee->setPension(tmpPension);
                break;
            }
            case 10: {
                cout << "�޸ĺ������˰\n";
                double tmpTax;
                checkInput(tmpTax);
                employee->setTax(tmpTax);
                break;
            }
            case 11: {
                cout << "�޸ĺ��ҽ�Ʊ���\n";
                double tmpInsurance;
                checkInput(tmpInsurance);
                employee->setInsurance(tmpInsurance);
                break;
            }
            default: {
                cout << "��������ȷ��ѡ��\n";
                break;
            }

        }
    } else {
        auto *employee = (TemporaryEmployee *) tmpEmployee;
        cout << "����Ҫ�޸ĵ���Ŀ\n";
        cout << "1.���  2.����  3.�Ա�  4.����  5.��ͥסַ 6.����ְ����\n" <<
             "7.����  8.����˰\n";
        checkInput(c);
        switch (c) {
            case 1: {
                cout << "�����޸ĺ�ı��\n";
                int tmpId;
                checkInput(tmpId);
                employee->setId(tmpId);
                break;
            }
            case 2: {
                cout << "�����޸ĺ������\n";
                string tmpName;
                checkInput(tmpName);
                employee->setName(tmpName);
                break;
            }
            case 3: {
                cout << "�޸ĺ���Ա�����Ϊ��true Ů��Ϊ��false";
                bool tmpSex;
                checkInput(tmpSex);
                employee->setSex(tmpSex);
                break;
            }
            case 4: {
                cout << "�޸ĺ������\n";
                int tmpAge;
                checkInput(tmpAge);
                employee->setAge(tmpAge);
                break;
            }
            case 5: {
                cout << "�޸ĺ�ļ�ͥסַ\n";
                string tmpAddress;
                checkInput(tmpAddress);
                employee->setAddress(tmpAddress);
                break;
            }
            case 6: {
                cout << "�޸ĺ�Ļ���ְ����\n";
                double tmpBaseWage;
                checkInput(tmpBaseWage);
                employee->setBaseWage(tmpBaseWage);
                break;
            }
            case 7: {
                cout << "�޸ĺ�Ľ���\n";
                double tmpBonus;
                checkInput(tmpBonus);
                employee->setBonus(tmpBonus);
                break;
            }
            case 8: {
                cout << "�޸ĺ������˰\n";
                double tmpTax;
                checkInput(tmpTax);
                employee->setTax(tmpTax);
                break;
            }
            default: {
                cout << "��������ȷ��ѡ��\n";
                break;
            }
        }
    }
    cout << "�޸ĳɹ�\n";
	return true;
}
double helpSort(Employee * p) {
		if (p->isType()) {
			return dynamic_cast<RegularEmployee *>(p)->getRealWage();
		}
		else {
			return dynamic_cast<TemporaryEmployee*>(p)->getRealWage();
		}
	
}
void Table::sortByRealWage() {                                         //���ܱ�ʵ�����ʽ�������
    for (int i = 0; i <apacity; i++) {
        if (tableArr[i] != nullptr) {
			double tmpI = helpSort(tableArr[i]);
            for (int j = i + 1; j < apacity; j++) {
                if (tableArr[j] != nullptr) {
					double tmpJ = helpSort(tableArr[j]);
                    if (tmpI< tmpJ) {
                        Employee *t = tableArr[i];
                        tableArr[i] = tableArr[j];
                        tableArr[j] = t;
                    }
                }
            }
        }
   }
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


void Table::display(bool tableType)
{
    if (tableType) {
        for (int i = 0; i < apacity; i++) {
            if (tableArr[i] != nullptr) {
                if (tableArr[i]->isType()) {
                    RegularEmployee *tmp;
                    tmp = dynamic_cast<RegularEmployee *>(tableArr[i]);
                    tmp->displayInfo();
                    cout << endl;
                } else {
                    TemporaryEmployee *tmp;
                    tmp = dynamic_cast<TemporaryEmployee *>(tableArr[i]);
                    tmp->displayInfo();
                    cout << endl;
                }
            }
        }
    }
    else {
        for (int i = 0; i < deleteApacity; i++) {
            if (deleteArr[i] != nullptr) {
                if (deleteArr[i]->isType()) {
                    RegularEmployee *tmp;
                    tmp = dynamic_cast<RegularEmployee *>(deleteArr[i]);
                    tmp->displayInfo();
                    cout << endl;
                } else {
                    TemporaryEmployee *tmp;
                    tmp = dynamic_cast<TemporaryEmployee *>(deleteArr[i]);
                    tmp->displayInfo();
                    cout << endl;
                }
            }
        }
    }
}

Table::~Table() = default;
