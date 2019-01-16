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
        if (table->readFromFile(fileName, true)) {
            nowOpenedFile = fileName;
        } else {
            delete table;
            table = nullptr;
        }

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

//6.添加职工信息
void insertInfo() {
    if (table == nullptr) {
        cout << "未打开文件，请打开后再试\n";
    } else {
        table->readFromScreen();
    }
}

//7.查询职工信息
void selectInfo() {
    if (table == nullptr) {
        cout << "未打开文件，请打开后再试\n";
    } else {
        cout << "请输入查找选项 1.按编号  2.按姓名  3.按实发工资\n";
        int choice;
        bool flag = true;
        Employee **p;
        while (flag) {
            Employee::checkInput(choice);

            switch (choice) {
                case 1: {
                    cout << "请输入编号\n";
                    int tmpId;
                    Employee::checkInput(tmpId);
                    int pos = table->searchEmployee(tmpId, true);
                    if (pos == -1) {
                        cout << "不存在此员工！\n";
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
                    cout << "请输入姓名\n";
                    string tmpName;
                    Employee::checkInput(tmpName);
                    p = table->searchEmployee(tmpName, true);
                    cout << "查找完成\n";
                    flag = false;
                }
                    break;
                case 3: {
                    cout << "请输入实发工资\n";
                    double tmpRealWage;
                    Employee::checkInput(tmpRealWage);
                    p = table->searchEmployee(tmpRealWage, true);
                    flag = false;
                    break;
                }
                default: {
                    cout << "输入信息有误，重新输入\n";
                }

            }
        }
        if (p[0] == nullptr) {
            cout << "不存在此员工！\n";
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

//8.修改职工信息
void updateInfo() {

}

int main() {
    while (true) {
        outputMenu();
        cout << "请输入选择：";
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
                cout << "请输入正确的选项\n";
                break;
            }
        }
    }
    return 0;
}
