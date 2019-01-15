#include <iostream>
#include "Table.h"

using namespace std;
Table *table = nullptr;
string nowOpenedFile = "";

void outputMenu() {
    cout << "-------欢迎使用职工工资信息管理系统-------\n";
    cout << "-   1.新建数据文件                      -\n";
    cout << "-   2.打开数据文件                      -\n";
    cout << "-   3.保存数据文件并关闭                 -\n";
    cout << "-   4.数据统计(工资总额/平均工资)        -\n";
    cout << "-   5.排序输出每个职工实发工资           -\n";
    cout << "-   6.添加职工信息                      -\n";
    cout << "-   7.查询职工信息                      -\n";
    cout << "-   8.修改职工信息                      -\n";
    cout << "-   9.删除职工信息                      -\n";
    cout << "-   10.恢复职工信息                     -\n";
    cout << "----------------------------------------\n";
}

//1.新建数据文件
void newDataFile() {
    if (table != nullptr) {
        cout << "已打开文件，请关闭后再试\n";
    } else {
        cout << "请输入新文件名：";
        string fileName;
        Employee::checkInput(fileName);
        fstream outFile;
        outFile.open(fileName);
        if (outFile.is_open()) {
            outFile.close();
            cout << "文件已存在,是否覆盖(1覆盖 0不覆盖)：";
            bool flag;
            Employee::checkInput(flag);
            if (flag) {
                cout << "覆盖成功\n";
            } else {
                cout << "新建失败\n";
                return;
            }
        } else {
            cout << "新建成功\n";
        }
        ofstream oFile(fileName);
        oFile.close();
        table = new Table();
        nowOpenedFile = fileName;
    }

}

//2.打开数据文件
void readDataFile() {
    if (table != nullptr) {
        cout << "已打开文件，请关闭后再试\n";
    } else {
        cout << "请输入读取文件名：";
        string fileName;
        Employee::checkInput(fileName);
        table = new Table();
        table->readFromFile(fileName, true);
        nowOpenedFile = fileName;
    }
}

//3.保存数据文件并关闭
void saveDataFile() {
    if (table == nullptr) {
        cout << "未打开文件，请打开后再试\n";
    } else {
        cout << "保存到(1原文件 0新文件)：";
        bool fileType;
        Employee::checkInput(fileType);
        if (fileType) {
            table->saveInFile(nowOpenedFile, true);
            cout << "保存";
        } else {
            cout << "请输入新文件名：";
            string fileName;
            Employee::checkInput(fileName);
            ifstream outFile;
            outFile.open(fileName);
            if (outFile.is_open()) {
                outFile.close();
                cout << "文件已存在,是否覆盖(1覆盖 0不覆盖)：";
                bool flag;
                Employee::checkInput(flag);
                if (flag) {
                    cout << "覆盖";
                } else {
                    cout << "保存失败\n";
                    return;
                }
            } else {
                cout << "保存";
            }
            table->saveInFile(fileName, true);
        }
        nowOpenedFile = "";
        delete table;
        cout << "成功!文件已关闭！\n";
    }
}

int main() {

    outputMenu();
    newDataFile();
//    cout << "你好风格士大夫" << endl;
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
