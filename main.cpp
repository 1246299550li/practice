#include <iostream>
#include "Table.h"

using namespace std;
Table *table = nullptr;

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

void newDataFile() {
    if (table != nullptr){
        cout << "�Ѵ��ļ�"
    }

}

int main() {


    outputMenu();
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
