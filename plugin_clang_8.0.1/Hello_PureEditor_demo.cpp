#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

// 用于模拟耗时操作的简单函数
// 注意：在某些基础 Wasm 环境中 sleep() 可能未实现，这里使用计算循环代替
void simulate_work() {
    volatile long long sum = 0;
    for (int i = 0; i < 5000000; ++i) {
        sum += i;
    }
}

int main() {
    // 1. 欢迎信息
    std::cout << "========================================" << std::endl;
    std::cout << "👋 欢迎来到 PureEditor C++ 环境" << std::endl;
    std::cout << "========================================" << std::endl;

    // 2. 展示环境信息 (测试宏定义)
    std::cout << "✅ 编译器: Clang " << __clang_version__ << std::endl;
    std::cout << "💻 标准库: C++ Standard Library" << std::endl;

    // 3. 演示标准库计算 (测试 Math 和 IO 格式化)
    std::cout << "\n[数学计算演示]" << std::endl;
    double radius = 5.0;
    double area = M_PI * std::pow(radius, 2);
    
    // 使用 fixed 和 setprecision 格式化输出
    std::cout << "半径为 " << radius << " 的圆面积是: " 
              << std::fixed << std::setprecision(2) << area << std::endl;

    // 4. STL 容器与排序 (测试内存分配和算法库)
    std::cout << "\n[STL 容器测试]" << std::endl;
    std::vector<int> numbers = {42, 1, 100, 7, 23};
    std::cout << "原始数组: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    std::sort(numbers.begin(), numbers.end());
    
    std::cout << "排序之后: ";
    for (int n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    // 5. 演示模拟耗时操作 (验证流式输出 flush)
    std::cout << "\n[性能测试]" << std::endl;
    std::cout << "正在执行计算任务..." << std::flush; // 关键：必须 flush 才能立即显示
    
    for (int i = 0; i < 5; ++i) {
        simulate_work();
        std::cout << "." << std::flush; // 关键：让点一个个蹦出来
    }
    std::cout << " 完成!" << std::endl;

    // 6. 演示核心交互功能 (Input)
    // 注意：这需要你的 UniversalRunner 正确实现了 input 拦截
    std::cout << "\n[交互演示]" << std::endl;
    std::cout << "PureEditor 支持 std::cin 同步输入！" << std::endl;
    
    std::string name;
    std::cout << "👉 可以告诉我你的昵称吗: " << std::flush; // 提示语必须 flush
    
    // 使用 getline 以支持包含空格的名字
    if (std::getline(std::cin, name) && !name.empty()) {
        std::cout << "你好, " << name << "! C++ 运行效率很高对吧？" << std::endl;
    } else {
        std::cout << "你好, 神秘人!" << std::endl;
    }

    std::cout << "\n🎉 演示结束，开始编写你的 C++ 代码吧！" << std::endl;

    return 0;
}