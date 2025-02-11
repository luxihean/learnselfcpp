#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// 商品管理类
class InventorySystem {
private:
    map<string, int> inventory; // 商品名称到库存数量的映射
    const string saveFile = "inventory_data.txt"; // 保存数据的文件名

    // 根据前缀搜索商品
    vector<string> searchByPrefix(const string& prefix) {
        vector<string> results;
        for (const auto& item : inventory) {
            if (item.first.find(prefix) == 0) { // 商品名以 prefix 开头
                results.push_back(item.first);
            }
        }
        return results;
    }

    // 保存库存数据到文件
    void saveToFile() {
        ofstream outFile(saveFile);
        if (outFile.is_open()) {
            for (const auto& item : inventory) {
                outFile << item.first << " " << item.second << "\n";
            }
            outFile.close();
        } else {
            cout << "无法保存数据到文件。\n";
        }
    }

    // 从文件加载库存数据
    void loadFromFile() {
        ifstream inFile(saveFile);
        if (inFile.is_open()) {
            string name;
            int quantity;
            while (inFile >> name >> quantity) {
                inventory[name] = quantity;
            }
            inFile.close();
        }
    }

public:
    // 构造函数
    InventorySystem() {
        loadFromFile();
    }

    // 析构函数
    ~InventorySystem() {
        saveToFile();
    }

    // 入库
    void addStock() {
        string name;
        int quantity;

        cout << "\n1. 新建商品\n2. 查找并入库\n请选择操作：";
        int action;
        cin >> action;

        if (action == 1) {
            cin.ignore();
            cout << "请输入新商品名称：";
            getline(cin, name);
            if (inventory.find(name) == inventory.end()) {
                inventory[name] = 0; // 创建新商品，默认库存为 0
                cout << "新商品创建成功！当前库存为 0。\n";
            } else {
                cout << "商品已存在！当前库存为 " << inventory[name] << "\n";
            }
        } else if (action == 2) {
            cin.ignore();
            cout << "请输入商品名称（支持自动补全）：";
            getline(cin, name);

            vector<string> suggestions = searchByPrefix(name);
            if (!suggestions.empty()) {
                cout << "找到以下匹配商品：\n";
                for (size_t i = 0; i < suggestions.size(); ++i) {
                    cout << i + 1 << ". " << suggestions[i] << endl;
                }
                cout << "输入匹配商品编号以选择（输入0返回主菜单）：";
                int choice;
                cin >> choice;

                if (choice > 0 && choice <= (int)suggestions.size()) {
                    name = suggestions[choice - 1];
                } else {
                    cout << "无效选择，返回主菜单。\n";
                    return;
                }
            } else {
                cout << "未找到匹配商品，返回主菜单。\n";
                return;
            }
        } else {
            cout << "无效操作，返回主菜单。\n";
            return;
        }

        cout << "请输入入库数量：";
        cin >> quantity;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入无效，返回主菜单。\n";
            return;
        }
        inventory[name] += quantity;
        cout << "入库成功！当前库存：" << inventory[name] << "\n";
    }

    // 出库
    void removeStock() {
        string name;
        int quantity;

        cout << "\n请输入商品名称（支持自动补全）：";
        cin.ignore();
        getline(cin, name);

        vector<string> suggestions = searchByPrefix(name);
        if (!suggestions.empty()) {
            cout << "找到以下匹配商品：\n";
            for (size_t i = 0; i < suggestions.size(); ++i) {
                cout << i + 1 << ". " << suggestions[i] << endl;
            }
            cout << "输入匹配商品编号以选择（输入0返回主菜单）：";
            int choice;
            cin >> choice;

            if (choice > 0 && choice <= (int)suggestions.size()) {
                name = suggestions[choice - 1];
            } else if (choice == 0) {
                return;
            } else {
                cout << "无效选择，返回主菜单。\n";
                return;
            }
        } else {
            cout << "未找到匹配商品，返回主菜单。\n";
            return;
        }

        cout << "请输入出库数量：";
        cin >> quantity;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入无效，返回主菜单。\n";
            return;
        }

        if (inventory[name] < quantity) {
            cout << "库存不足！当前库存：" << inventory[name] << "\n";
        } else {
            inventory[name] -= quantity;
            cout << "出库成功！当前库存：" << inventory[name] << "\n";
        }
    }

    // 库存统计
    void showInventory() {
        cout << "\n当前库存情况：\n";
        for (const auto& item : inventory) {
            cout << "- " << item.first << ": " << item.second << "\n";
        }
    }

    // 初始化商品
    void initializeInventory() {
        inventory.clear();
        cout << "\n请输入要初始化的商品数量：";
        int num;
        cin >> num;
        if (cin.fail() || num < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入无效，返回主菜单。\n";
            return;
        }
        cin.ignore();
        for (int i = 0; i < num; ++i) {
            string name;
            cout << "请输入第" << (i + 1) << "个商品名称：";
            getline(cin, name);
            inventory[name] = 0;
        }
        cout << "初始化完成！\n";
    }

    // 清空库存
    void clearInventory() {
        inventory.clear();
        cout << "所有商品已清空！\n";
    }

    // 主菜单
    void run() {
        while (true) {
            cout << "\n======== 出入库管理系统 ========\n";
            cout << "1. 入库\n";
            cout << "2. 出库\n";
            cout << "3. 库存统计\n";
            cout << "4. 初始化库存\n";
            cout << "5. 清空库存\n";
            cout << "6. 退出\n";
            cout << "请选择操作：";

            int choice;
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入无效，请重试。\n";
                continue;
            }

            switch (choice) {
                case 1:
                    addStock();
                    break;
                case 2:
                    removeStock();
                    break;
                case 3:
                    showInventory();
                    break;
                case 4:
                    initializeInventory();
                    break;
                case 5:
                    clearInventory();
                    break;
                case 6:
                    cout << "退出系统。\n";
                    return;
                default:
                    cout << "无效选择，请重试。\n" ;
                break;
            }
        }
    }
};

// 主函数
int main() {
    InventorySystem inventorySystem;
    inventorySystem.run();
    return 0;
}

