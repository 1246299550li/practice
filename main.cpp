#include "Table.h"
#include <iomanip>

using namespace std;
Table *table = nullptr;
string nowOpenedFile = "";

void outputMenu() {
    cout << "-------��ӭʹ��ְ��������Ϣ����ϵͳ-------\n";
    cout << "-   0.�˳�ϵͳ                         -\n";
    cout << "-   1.�½������ļ�                      -\n";
    cout << "-   2.�������ļ�                      -\n";
    cout << "-   3.���������ļ����ر�                 -\n";
    cout << "-   4.����ͳ��(�����ܶ�/ƽ������)        -\n";
    cout << "-   5.�������ÿ��ְ��ʵ������           -\n";
    cout << "-   6.���ְ����Ϣ                      -\n";
    cout << "-   7.��ѯְ����Ϣ                      -\n";
    cout << "-   8.�޸�ְ����Ϣ                      -\n";
    cout << "-   9.ɾ��ְ����Ϣ                      -\n";
    cout << "-   10.�ָ�ְ����Ϣ                     -\n";
    cout << "-   11.��ʾְ����Ϣ                     -\n";
    cout << "----------------------------------------\n";
}

//1.�½������ļ�
void newDataFile() {
    if (table != nullptr) {
        cout << "�Ѵ��ļ�����رպ�����\n";
    } else {
        cout << "���������ļ�����";
        string fileName;
        Employee::checkInput(fileName);
        fstream outFile;
        outFile.open(fileName);
        if (outFile.is_open()) {
            outFile.close();
            cout << "�ļ��Ѵ���,�Ƿ񸲸�(1���� 0������)��";
            bool flag;
            Employee::checkInput(flag);
            if (flag) {
                cout << "���ǳɹ�\n";
            } else {
                cout << "�½�ʧ��\n";
                return;
            }
        } else {
            cout << "�½��ɹ�\n";
        }
        ofstream oFile(fileName);
        oFile.close();
        table = new Table();
        nowOpenedFile = fileName;
    }

}

//2.�������ļ�
void readDataFile() {
    if (table != nullptr) {
        cout << "�Ѵ��ļ�����رպ�����\n";
    } else {
        cout << "�������ȡ�ļ�����";
        string fileName;
        Employee::checkInput(fileName);
        table = new Table();
        if (table->readFromFile(fileName, true)) {
            nowOpenedFile = fileName;
        } else {
            delete table;
            table = nullptr;
        }

    }

}

//3.���������ļ����ر�
void saveDataFile() {
    if (table == nullptr) {
        cout << "δ���ļ�����򿪺�����\n";
    } else {
        cout << "���浽(1ԭ�ļ� 0���ļ�)��";
        bool fileType;
        Employee::checkInput(fileType);
        if (fileType) {
            table->saveInFile(nowOpenedFile, true);
            cout << "����";
        } else {
            cout << "���������ļ�����";
            string fileName;
            Employee::checkInput(fileName);
            ifstream outFile;
            outFile.open(fileName);
            if (outFile.is_open()) {
                outFile.close();
                cout << "�ļ��Ѵ���,�Ƿ񸲸�(1���� 0������)��";
                bool flag;
                Employee::checkInput(flag);
                if (flag) {
                    cout << "����";
                } else {
                    cout << "����ʧ��\n";
                    return;
                }
            } else {
                cout << "����";
            }
            table->saveInFile(fileName, true);
        }
        nowOpenedFile = "";
        delete table;
        table = nullptr;
        cout << "�ɹ�!�ļ��ѹرգ�\n";
    }
}

//4.����ͳ��(�����ܶ�/ƽ������)
void wageStatistic() {
    if (table == nullptr) {
        cout << "δ���ļ�����򿪺�����\n";
    } else {
        int choice;
        Employee **p = nullptr;
        bool flag = true;
        while (flag) {
            cout << "����ͳ�ƹؼ���  1.ȫ��Ա��  2.��ʽְ��  3.��ʱ��\n";
            Employee::checkInput(choice);
            switch (choice) {
                case 1: {
                    table->calculateWage(table->getTableArr());
                    return;
                }
                case 2: {
                    p = table->searchEmployee(true);
                    flag = false;
                    break;
                }
                case 3: {
                    p = table->searchEmployee(false);
                    flag = false;
                    break;
                }
                default: {
                    cout << "������Ϣ������������\n";
                    flag = true;
                }

            }
        }
        table->calculateWage(p);
    }
}

//5.�������ÿ��ְ��ʵ������
void sortByWage() {
    if (table == nullptr) {
        cout << "δ���ļ�����򿪺�����\n";
    } else {
        table->sortByRealWage();
        string sex;
        for (int i = 0; i < table->getApacity(); i++) {
            if (table->getTableArr()[i] != nullptr) {
                if (table->getTableArr()[i]->isSex()) {
                    sex = "��";
                } else {
                    sex = "Ů";
                }
                cout.precision(2);
                cout.setf(ios_base::fixed);
                if (table->getTableArr()[i]->isType()) {
                    auto *tmpReg = dynamic_cast<RegularEmployee *>(table->getTableArr()[i]);
                    if (tmpReg != nullptr) {
                        cout << "��ʽְ����" << setw(5) << tmpReg->getId() << setw(10) << tmpReg->getName() << setw(5)
                             << sex << setw(25) << tmpReg->getAddress() << setw(10) << tmpReg->getBaseWage() << setw(10)
                             << tmpReg->getAllowance() << setw(10) << tmpReg->getProvidentFund()<< setw(10)<<tmpReg->getPension()
                                << setw(10) << tmpReg->getTax()<< setw(10) << tmpReg->getInsurance() << setw(10) << tmpReg->getRealWage() << endl;
                    }
                } else {
                    auto *tmpTem = dynamic_cast<TemporaryEmployee *>(table->getTableArr()[i]);
                    if (tmpTem != nullptr) {
                        cout << "��ʱְ����" << setw(5) << tmpTem->getId() << setw(10) << tmpTem->getName() << setw(5)
                             << sex << setw(25) << tmpTem->getAddress() << setw(10) << tmpTem->getBaseWage()
                             << setw(10) << tmpTem->getBonus() << setw(10) << tmpTem->getTax()
                             << setw(10) << tmpTem->getRealWage() << endl;
                    }
                }
            }
        }
    }
}

//6.���ְ����Ϣ
void insertInfo() {
    if (table == nullptr) {
        cout << "δ���ļ�����򿪺�����\n";
    } else {
        table->readFromScreen();
        table->saveInFile(nowOpenedFile, true);
    }
}

//7.��ѯְ����Ϣ
void selectInfo() {
    if (table == nullptr) {
        cout << "δ���ļ�����򿪺�����\n";
    } else {
        cout << "���������ѡ�� 1.�����  2.������  3.��ʵ������\n";
        int choice;
        bool flag = true;
        Employee **p = nullptr;
        while (flag) {
            Employee::checkInput(choice);

            switch (choice) {
                case 1: {
                    cout << "��������:";
                    int tmpId;
                    Employee::checkInput(tmpId);
                    int pos = table->searchEmployee(tmpId, true);
                    if (pos == -1) {
                        cout << "�����ڴ�Ա����\n";
                        return;
                    }
                    if ((table->getTableArr())[pos]->isType()) {
                        dynamic_cast<RegularEmployee *>((table->getTableArr())[pos])->displayInfo();
                    } else {
                        dynamic_cast<TemporaryEmployee *>((table->getTableArr())[pos])->displayInfo();
                    }
                    return;
                }
                case 2: {
                    cout << "����������:";
                    string tmpName;
                    Employee::checkInput(tmpName);
                    p = table->searchEmployee(tmpName);
                    cout << "�������:";
                    flag = false;
                    break;
                }

                case 3: {
                    cout << "������ʵ������:";
                    double tmpRealWage;
                    Employee::checkInput(tmpRealWage);
                    p = table->searchEmployee(tmpRealWage);
                    flag = false;
                    break;
                }
                default: {
                    cout << "������Ϣ������������:";
                }

            }
        }
        if (p[0] == nullptr) {
            cout << "�����ڴ�Ա����\n";
            return;
        }
        for (int i = 0; p[i] != nullptr; i++) {
            if (p[i]->isType()) {
                dynamic_cast<RegularEmployee *>(p[i])->displayInfo();
            } else {
                dynamic_cast<TemporaryEmployee *>(p[i])->displayInfo();
            }
        }
        delete[] p;
    }
}

//8.�޸�ְ����Ϣ
void updateInfo() {
    cout << "�������޸ĵ�ְ�����:";
    int tmpId;
    Employee::checkInput(tmpId);
    int pos = table->searchEmployee(tmpId, true);
    if (pos == -1) {
        cout << "�����ڴ�Ա����\n";
        return;
    }
    if ((table->getTableArr())[pos]->isType()) {
        dynamic_cast<RegularEmployee *>((table->getTableArr())[pos])->displayInfo();
    } else {
        dynamic_cast<TemporaryEmployee *>((table->getTableArr())[pos])->displayInfo();
    }
    cout << "��ȷ�����Ƿ�����Ҫ�޸ĵ�ְ��(1�� 0��):";
    bool choice;
    Employee::checkInput(choice);
    if (choice) {
        table->updateEmployee((table->getTableArr())[pos]);
        table->saveInFile(nowOpenedFile, true);
    } else {
        return;
    }
}

// 9.ɾ��ְ����Ϣ
void deleteInfo() {
    if (table == nullptr) {
        cout << "δ���ļ�����򿪺�����\n";
    } else {
        cout << "������ѡ��(1.�Ƴ�ְ����Ϣ(�ɻָ�)  2.����ɾ��ְ����Ϣ)��";
        bool flag = true;
        while (flag) {
            int option;
            Employee::checkInput(option);
            if (!table->display(true)) {
                cout << "����Ϣ\n";
                return;
            }
            switch (option) {
                case 1: {
                    cout << "������Ҫ�Ƴ���ְ����id:";
                    int id;
                    Employee::checkInput(id);
                    if (table->logicalDeleteEmployee(id, nowOpenedFile)) {
                        cout << "�Ƴ��ɹ���\n";
                    } else {
                        cout << "�Ƴ�ʧ�ܣ���������id��\n";
                    }
                    flag = false;
                    break;
                }
                case 2: {

                    cout << "������Ҫ����ɾ����ְ����id:";
                    int id;
                    Employee::checkInput(id);
                    if (table->physicalDeleteEmployee(id, nowOpenedFile)) {
                        cout << "����ɾ���ɹ���\n";
                    } else {
                        cout << "����ɾ��ʧ�ܣ���������id��\n";
                    }
                    flag = false;
                    break;
                }
                default: {
                    cout << "ѡ����ڣ�����������";
                }
            }
        }
    }
}

// 10.�ָ�ְ����Ϣ
void recoverInfo() {
    if (table == nullptr) {
        cout << "δ���ļ�����򿪺�����\n";
    } else {
        table->readFromFile("delete" + nowOpenedFile, false);
        if (!table->display(false)) {
            cout << "����Ϣ\n";
            return;
        }
        cout << "������Ҫ�ָ���ְ����id" << endl;
        int id;
        Employee::checkInput(id);
        if (table->recoverDeleteEmployee(id, nowOpenedFile)) {
            cout << "�ָ��ɹ���" << endl;
        } else {
            cout << "�ָ�ʧ�ܣ���������id��" << endl;
        }
    }
}

//11.��ʾְ����Ϣ
void displayInfo() {
    if (table == nullptr) {
        cout << "δ���ļ�����򿪺�����\n";
    } else {

        if (!table->display(true)) {
            cout << "����Ϣ\n";
        }
    }
}

int main() {
    while (true) {
        outputMenu();
        cout << "������ѡ��";
        int choice;
        Employee::checkInput(choice);
        if (!choice) {
            break;
        }
        switch (choice) {
            case 1: {
                newDataFile();
                break;
            }
            case 2: {
                readDataFile();
                break;
            }
            case 3: {
                saveDataFile();
                break;
            }
            case 4: {
                wageStatistic();
                break;
            }
            case 5: {
                sortByWage();
                break;
            }
            case 6: {
                insertInfo();
                break;
            }
            case 7: {
                selectInfo();
                break;
            }
            case 8: {
                updateInfo();
                break;
            }
            case 9: {
                deleteInfo();
                break;
            }
            case 10: {
                recoverInfo();
                break;
            }
            case 11: {
                displayInfo();
                break;
            }
            default: {
                cout << "��������ȷ��ѡ��\n";
                break;
            }
        }
    }
    return 0;
}
