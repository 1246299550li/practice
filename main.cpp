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
        table->readFromFile(fileName, true);
        nowOpenedFile = fileName;
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

int main() {

    outputMenu();
    newDataFile();
//    cout << "��÷��ʿ���" << endl;
//    Table t;
//    t.readFromFile("E:\\new\\1.txt", true);
//    t.readFromScreen();
//    system("pause");
//    t.tableArr[0]->displayInfo();
//    system("pause");
//    t.saveInFile("E:\\new\\output.txt", true);
//    system("pause");
    return 0;
}
