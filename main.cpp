#include "Table.h"
#include <iomanip>

using namespace std;
Table *table = nullptr;
string nowOpenedFile = "";

void outputMenu() {
    cout << "-------欢迎使用职工工资信息管理系统-------\n";
    cout << "-   0.退出系统                         -\n";
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
    cout << "-   11.显示职工信息                     -\n";
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
        table = nullptr;
        cout << "成功!文件已关闭！\n";
    }
}

//4.数据统计(工资总额/平均工资)
void wageStatistic() {
    if (table == nullptr) {
        cout << "未打开文件，请打开后再试\n";
    } else {
        int choice;
        Employee **p = nullptr;
        bool flag = true;
        while (flag) {
            cout << "输入统计关键字  1.全体员工  2.正式职工  3.临时工\n";
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
                    cout << "输入信息有误，重新输入\n";
                    flag = true;
                }

            }
        }
        table->calculateWage(p);
    }
}

//5.排序输出每个职工实发工资
void sortByWage() {
    if (table == nullptr) {
        cout << "未打开文件，请打开后再试\n";
    } else {
        table->sortByRealWage();
        string sex;
        for (int i = 0; i < table->getApacity(); i++) {
            if (table->getTableArr()[i] != nullptr) {
                if (table->getTableArr()[i]->isSex()) {
                    sex = "男";
                } else {
                    sex = "女";
                }
                cout.precision(2);
                cout.setf(ios_base::fixed);
                if (table->getTableArr()[i]->isType()) {
                    auto *tmpReg = dynamic_cast<RegularEmployee *>(table->getTableArr()[i]);
                    if (tmpReg != nullptr) {
                        cout << "正式职工：" << setw(5) << tmpReg->getId() << setw(10) << tmpReg->getName() << setw(5)
                             << sex << setw(25) << tmpReg->getAddress() << setw(10) << tmpReg->getBaseWage() << setw(10)
                             << tmpReg->getAllowance() << setw(10) << tmpReg->getProvidentFund()<< setw(10)<<tmpReg->getPension()
                                << setw(10) << tmpReg->getTax()<< setw(10) << tmpReg->getInsurance() << setw(10) << tmpReg->getRealWage() << endl;
                    }
                } else {
                    auto *tmpTem = dynamic_cast<TemporaryEmployee *>(table->getTableArr()[i]);
                    if (tmpTem != nullptr) {
                        cout << "临时职工：" << setw(5) << tmpTem->getId() << setw(10) << tmpTem->getName() << setw(5)
                             << sex << setw(25) << tmpTem->getAddress() << setw(10) << tmpTem->getBaseWage()
                             << setw(10) << tmpTem->getBonus() << setw(10) << tmpTem->getTax()
                             << setw(10) << tmpTem->getRealWage() << endl;
                    }
                }
            }
        }
    }
}

//6.添加职工信息
void insertInfo() {
    if (table == nullptr) {
        cout << "未打开文件，请打开后再试\n";
    } else {
        table->readFromScreen();
        table->saveInFile(nowOpenedFile, true);
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
        Employee **p = nullptr;
        while (flag) {
            Employee::checkInput(choice);

            switch (choice) {
                case 1: {
                    cout << "请输入编号:";
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
                    cout << "请输入姓名:";
                    string tmpName;
                    Employee::checkInput(tmpName);
                    p = table->searchEmployee(tmpName);
                    cout << "查找完成:";
                    flag = false;
                    break;
                }

                case 3: {
                    cout << "请输入实发工资:";
                    double tmpRealWage;
                    Employee::checkInput(tmpRealWage);
                    p = table->searchEmployee(tmpRealWage);
                    flag = false;
                    break;
                }
                default: {
                    cout << "输入信息有误，重新输入:";
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
    cout << "请输入修改的职工编号:";
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
    cout << "请确认这是否是您要修改的职工(1是 0否):";
    bool choice;
    Employee::checkInput(choice);
    if (choice) {
        table->updateEmployee((table->getTableArr())[pos]);
        table->saveInFile(nowOpenedFile, true);
    } else {
        return;
    }
}

// 9.删除职工信息
void deleteInfo() {
    if (table == nullptr) {
        cout << "未打开文件，请打开后再试\n";
    } else {
        cout << "请输入选项(1.移除职工信息(可恢复)  2.彻底删除职工信息)：";
        bool flag = true;
        while (flag) {
            int option;
            Employee::checkInput(option);
            if (!table->display(true)) {
                cout << "无信息\n";
                return;
            }
            switch (option) {
                case 1: {
                    cout << "请输入要移除的职工的id:";
                    int id;
                    Employee::checkInput(id);
                    if (table->logicalDeleteEmployee(id, nowOpenedFile)) {
                        cout << "移除成功！\n";
                    } else {
                        cout << "移除失败！请检查输入id！\n";
                    }
                    flag = false;
                    break;
                }
                case 2: {

                    cout << "请输入要彻底删除的职工的id:";
                    int id;
                    Employee::checkInput(id);
                    if (table->physicalDeleteEmployee(id, nowOpenedFile)) {
                        cout << "彻底删除成功！\n";
                    } else {
                        cout << "彻底删除失败！请检查输入id！\n";
                    }
                    flag = false;
                    break;
                }
                default: {
                    cout << "选项不存在，请重新输入";
                }
            }
        }
    }
}

// 10.恢复职工信息
void recoverInfo() {
    if (table == nullptr) {
        cout << "未打开文件，请打开后再试\n";
    } else {
        table->readFromFile("delete" + nowOpenedFile, false);
        if (!table->display(false)) {
            cout << "无信息\n";
            return;
        }
        cout << "请输入要恢复的职工的id" << endl;
        int id;
        Employee::checkInput(id);
        if (table->recoverDeleteEmployee(id, nowOpenedFile)) {
            cout << "恢复成功！" << endl;
        } else {
            cout << "恢复失败！请检查输入id！" << endl;
        }
    }
}

//11.显示职工信息
void displayInfo() {
    if (table == nullptr) {
        cout << "未打开文件，请打开后再试\n";
    } else {

        if (!table->display(true)) {
            cout << "无信息\n";
        }
    }
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
                cout << "请输入正确的选项\n";
                break;
            }
        }
    }
    return 0;
}
