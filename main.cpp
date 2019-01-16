#include <iostream>
#include "Table.h"
#include<iomanip>

using namespace std;

void outputMenu() {
    cout << "-------��ӭʹ��ְ��������Ϣ����ϵͳ-------\n";
    cout << "-   1.�½������ļ�                      -\n";
    cout << "-   2.�������ļ�                      -\n";
    cout << "-   3.�������ݵ��ļ�                    -\n";
    cout << "-   4.����ͳ��(���㹤���ܶƽ��ֵ)      -\n";
    cout << "-   5.�������ÿ��ְ��ʵ������           -\n";
    cout << "-   6.���ְ����Ϣ                      -\n";
    cout << "-   7.��ѯְ����Ϣ                      -\n";
    cout << "-   8.�޸�ְ����Ϣ                      -\n";
    cout << "-   9.ɾ��ְ����Ϣ                      -\n";
    cout << "-   10.�ָ�ְ����Ϣ                     -\n";
    cout << "---------------------------------------\n";
}


void deleteEmployeeInfo(Table* table) {
    if (table) {
        cout << "-   0.�����ϼ��˵�                         -\n";
        cout << "-   1.�Ƴ�ְ����Ϣ                         -\n";
        cout << "-   2.����ɾ��ְ����Ϣ                     -\n";
        int option;
        cin >> option;
        switch (option) {
            case 0: {
                return;
            }
            case 1: {
                table->display(true);
                while (true) {
                    cout << "������Ҫ�Ƴ���ְ����id" << endl;
                    int id;
                    cin >> id;
                    if (table->logicalDeleteEmployee(id)) {
                        cout << "�Ƴ��ɹ���" << endl;
                        break;
                    } else {
                        cout << "�Ƴ�ʧ�ܣ���������id��" << endl;
                    }
                }
                break;
            }
            case 2: {
                table->display(false);
                while (true) {
                    cout << "������Ҫ����ɾ����ְ����id" << endl;
                    int id;
                    cin >> id;
                    if (table->physicalDeleteEmployee(id)) {
                        cout << "����ɾ���ɹ���" << endl;
                        break;
                    } else {
                        cout << "����ɾ��ʧ�ܣ���������id��" << endl;
                    }
                }
                break;
            }
        }
    } else {
        cout << "������!";
    }
}
void recoverEmployeeInfo(Table* table){
    if (table) {
        cout << "-   0.�����ϼ��˵�                         -\n";
        cout << "-   1.�ָ�ְ����Ϣ                         -\n";
        int option;
        cin >> option;
        switch (option) {
            case 0: {
                return;
            }
            case 1: {
                table->display(false);
                while (true) {
                    cout << "������Ҫ�ָ���ְ����id" << endl;
                    int id;
                    cin >> id;
                    if (table->undeleteEmployee(id)) {
                        cout << "�ָ��ɹ���" << endl;
                        break;
                    } else {
                        cout << "�ָ�ʧ�ܣ���������id��" << endl;
                    }
                }
                break;
            }
        }
    } else {
        cout << "������!";
    }

}


int main() {
    cout << "Hello, World!" << endl;
    Table *t=new Table();
    outputMenu();
    //t.readFromFile("in.txt", true);
    t->readFromScreen();
    t->saveInFile("output.txt", true);
    deleteEmployeeInfo(t);
    recoverEmployeeInfo(t);
    system("pause");
    system("pause");
   // t->saveInFile("output.txt", true);
    system("pause");
    return 0;
}
