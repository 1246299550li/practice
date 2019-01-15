#include <iostream>
#include "Table.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Table t;
//    t.readFromFile("E:\\new\\1.txt", true);
    t.readFromScreen();
    system("pause");
    t.tableArr[0]->displayInfo();
    system("pause");
    t.saveInFile("E:\\new\\output.txt", true);
    system("pause");
    return 0;
}
