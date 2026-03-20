#include "Building.hpp"
#include <string>

Building::Building(int totalFloors) : totalFloors(totalFloors) {
    // 題目要求：樓層從 1 開始，直到 totalFloors
    for (int i = 1; i <= totalFloors; ++i) {
        // 題目要求：每間公司的名稱為 "company" + 樓層數字
        std::string companyName = "company" + std::to_string(i);

        // 建立 Company 物件 (使用 shared_ptr)
        // 假設 Company 的建構子是 (name, floorNumber)
        auto newCompany = std::make_shared<Company>(companyName, i);

        // 存入列表
        this->companies.push_back(newCompany);
    }
}

// 2. 取得總樓層數
int Building::getTotalFloors() {
    return this->totalFloors;
}

// 3. 取得大樓內所有公司的列表
std::vector<std::shared_ptr<Company>> Building::getCompanies() {
    return this->companies;
}

// 4. 計算正在上班的公司數量
int Building::CountWorkingCompanies() {
    int count = 0;

    // 遍歷所有公司
    for (const auto& comp : this->companies) {
        // 檢查該公司是否正在上班 (isWork)
        if (comp->isWork()) {
            count++;
        }
    }

    return count;
}