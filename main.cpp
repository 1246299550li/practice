#include <iostream>
#include "Table.h"

using namespace std;
Table *table = nullptr;
string nowOpenedFile = "";

void outputMenu() {
    cout << "-------��ӭʹ��ְ��������Ϣ����ϵͳ-------\n";
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
        cout << "�ɹ�!�ļ��ѹرգ�\n";
    }
}

//6.���ְ����Ϣ
void insertInfo() {
    if (table == nullptr) {
        cout << "δ���ļ�����򿪺�����\n";
    } else {
        table->readFromScreen();
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
        Employee **p;
        while (flag) {
            Employee::checkInput(choice);

            switch (choice) {
                case 1: {
                    cout << "��������\n";
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
                    cout << "����������\n";
                    string tmpName;
                    Employee::checkInput(tmpName);
                    p = table->searchEmployee(tmpName, true);
                    cout << "�������\n";
                    flag = false;
                }
                    break;
                case 3: {
                    cout << "������ʵ������\n";
                    double tmpRealWage;
                    Employee::checkInput(tmpRealWage);
                    p = table->searchEmployee(tmpRealWage, true);
                    flag = false;
                    break;
                }
                default: {
                    cout << "������Ϣ������������\n";
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
                break;
            }
            case 5: {
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
                break;
            }
            case 9: {
                break;
            }
            case 10: {
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
