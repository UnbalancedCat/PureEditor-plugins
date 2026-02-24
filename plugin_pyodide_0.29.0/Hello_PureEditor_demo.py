import sys
import math
import time
import random

# 1. 欢迎信息
print("="*40)
print("👋 欢迎来到 PureEditor Python 环境")
print("="*40)

# 2. 展示环境信息
print(f"✅ Python 版本: {sys.version.split()[0]}")
print(f"💻 运行平台: {sys.platform}")

# 3. 演示标准库计算
print("\n[数学计算演示]")
radius = 5
area = math.pi * (radius ** 2)
print(f"半径为 {radius} 的圆面积是: {area:.2f}")

# 4. 演示模拟耗时操作 (验证界面不卡死)
print("\n[性能测试]")
print("正在生成随机数...", end="", flush=True)
for _ in range(5):
    time.sleep(0.2)
    print(".", end="", flush=True)
print(" 完成!")
lucky_num = random.randint(1, 100)
print(f"你的今日幸运数字是: {lucky_num}")

# 5. 演示核心交互功能 (Input)
print("\n[交互演示]")
print("PureEditor 支持同步 input() 输入！")
try:
    print("👉 可以告诉我你的昵称吗: ")
    name = input()
    if name:
        print(f"你好, {name}! 很高兴见到你。")
    else:
        print("你好, 神秘人!")
except Exception as e:
    print(f"交互失败: {e}")

print("\n🎉 演示结束，开始编写和测试你自己的代码吧！")