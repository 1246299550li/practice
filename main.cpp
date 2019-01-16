#include <iostream>
#include "Table.h"
#include<iomanip>

using namespace std;

void outputMenu() {
    cout << "-------欢迎使用职工工资信息管理系统-------\n";
    cout << "-   1.新建数据文件                      -\n";
    cout << "-   2.打开数据文件                      -\n";
    cout << "-   3.保存数据到文件                    -\n";
    cout << "-   4.数据统计(计算工资总额、平均值)      -\n";
    cout << "-   5.排序输出每个职工实发工资           -\n";
    cout << "-   6.添加职工信息                      -\n";
    cout << "-   7.查询职工信息                      -\n";
    cout << "-   8.修改职工信息                      -\n";
    cout << "-   9.删除职工信息                      -\n";
    cout << "-   10.恢复职工信息                     -\n";
    cout << "---------------------------------------\n";
}


void deleteEmployeeInfo(Table* table) {
    if (table) {
        cout << "-   0.返回上级菜单                         -\n";
        cout << "-   1.移除职工信息                         -\n";
        cout << "-   2.彻底删除职工信息                     -\n";
        int option;
        cin >> option;
        switch (option) {
            case 0: {
                return;
            }
            case 1: {
                table->display(true);
                while (true) {
                    cout << "请输入要移除的职工的id" << endl;
                    int id;
                    cin >> id;
                    if (table->logicalDeleteEmployee(id)) {
                        cout << "移除成功！" << endl;
                        break;
                    } else {
                        cout << "移除失败！请检查输入id！" << endl;
                    }
                }
                break;
            }
            case 2: {
                table->display(false);
                while (true) {
                    cout << "请输入要彻底删除的职工的id" << endl;
                    int id;
                    cin >> id;
                    if (table->physicalDeleteEmployee(id)) {
                        cout << "彻底删除成功！" << endl;
                        break;
                    } else {
                        cout << "彻底删除失败！请检查输入id！" << endl;
                    }
                }
                break;
            }
        }
    } else {
        cout << "表不存在!";
    }
}
void recoverEmployeeInfo(Table* table){
    if (table) {
        cout << "-   0.返回上级菜单                         -\n";
        cout << "-   1.恢复职工信息                         -\n";
        int option;
        cin >> option;
        switch (option) {
            case 0: {
                return;
            }
            case 1: {
                table->display(false);
                while (true) {
                    cout << "请输入要恢复的职工的id" << endl;
                    int id;
                    cin >> id;
                    if (table->undeleteEmployee(id)) {
                        cout << "恢复成功！" << endl;
                        break;
                    } else {
                        cout << "恢复失败！请检查输入id！" << endl;
                    }
                }
                break;
            }
        }
    } else {
        cout << "表不存在!";
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
