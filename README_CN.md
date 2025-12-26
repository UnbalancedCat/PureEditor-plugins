# PureEditor Python Runtime Plugin 🐍

[中文] | [English](README.md)

**PureEditor (HarmonyOS)** 的离线 Python 运行环境插件包。

本仓库托管了 PureEditor 所需的 Python 运行时核心文件。通过安装此插件，你可以在 PureEditor 中开启本地、离线、安全的 Python 代码编写与运行功能。

> **核心版本信息**：
>
> - **Python**: 3.13.0
> - **Pyodide**: 0.29.0 (基于 WebAssembly)
> - **架构**: Wasm (跨平台，本地沙箱运行)

PureEditor 在 v0.6.20 版本开始支持 Wasm 插件功能，目前仅支持 Python。未来版本计划提供 C、C++、Rust 的编译运行支持。

------

## ✨ 特性

- **⚡️ 完全离线**：内置完整的 Python 标准库，无需联网即可运行。
- **🔒 安全沙箱**：基于 WebAssembly 技术，代码在隔离的虚拟环境中运行，不触及系统底层文件。
- **🤝 交互支持**：支持标准输出 (stdout/stderr) 捕获，并完美支持 `input()` 同步交互。
- **📦 开箱即用**：安装后自动部署演示脚本 `hello_pure.py`，立即体验。

------

## 📥 下载与安装

### 第一步：下载插件包

请在右侧 [release] 页面下载最新的插件包：

- 文件名：`plugin_pyodide_3.13.zip`

### 第二步：解锁功能 🥚

由于这是实验性功能，默认处于隐藏状态。请按照以下步骤解锁：

1. 打开 **PureEditor** App。
2. 进入 **侧边栏** > **关于**。
3. 找到 **版本号** (例如 v0.6.x)，**连续快速点击 10 次**。
4. 当出现 "Wasm 实验性功能已解锁" 提示时，即表示成功。
5. 额外内容会在我的文件、侧边栏、设置页面中显示。

### 第三步：导入安装

1. 返回 **设置** 页面，此时会出现 **显示隐藏文件夹** 与 **插件管理** 分组。
2. 点击 **插件管理**。
3. 点击 **导入环境包**，在文件选择器中选择刚刚下载的 `plugin_pyodide_3.13.zip`。
4. 等待校验和解压完成（约需几秒钟）。

------

## 🚀 如何使用

1. **新建/打开文件**：确保文件后缀名为 `.py`（例如 `test.py`）。
2. **唤出菜单**：打开侧边栏（点击左上角图标或从左侧边缘向右滑）。
3. **运行**：点击侧边栏中的 **「编译运行」** 按钮。
4. **交互**：程序将启动并在控制台输出结果。如果代码中包含 `input()`，底部会自动弹出输入框等待输入。

> **提示**：首次安装完成后，在“我的文件”根目录下会自动生成一个 `Hello_PureEditor_demo.py`，你可以直接运行它来测试环境。

------

## 🛠 技术细节与校验

为了确保安全性，PureEditor 会对导入的插件包进行 **SHA-256** 指纹校验。请确保你下载的是本仓库发布的、未经篡改的 Zip 包。

### 文件结构

`plugin_pyodide_3.13.zip` 解压后包含以下核心文件：

- `pyodide.js`: 引导加载器
- `pyodide.asm.wasm`: Python 解释器编译后的二进制文件
- `python_stdlib.zip`: Python 标准库压缩包
- `Hello_PureEditor_demo.py`: 演示脚本

### 常见问题 (FAQ)

Q: 运行 sys.platform 为什么显示 emscripten 而不是 linux?

A: 这是正常的。因为 Python 是通过 Emscripten 编译为 WebAssembly 的，它运行在一个模拟的 POSIX 环境中，而不是直接运行在手机的 Linux 内核上。这证明了代码确实是在本地沙箱中离线运行的。

Q: 可以安装第三方库 (如 pandas, numpy) 吗?

A: 目前版本主要支持 Python 标准库。对于纯 Python 编写的第三方库（Wheel），未来版本可能会提供支持，敬请期待。你也可以在设置 > 

Q: 为什么输入 input() 时界面没有卡死?

A: 我们使用了 SharedArrayBuffer 和 Atomics.wait 技术，将 Python 运行在独立的 Worker 线程中，实现了非阻塞的主线程交互。

**Q: 为什么采用插件形式提供运行环境，而不是直接内置?**
A: 为了保持 PureEditor 主体的 **轻量与纯粹**。
完整的 Python 运行时（包含 Wasm 解释器和标准库）体积较大（解压后约 30MB+）。如果直接内置，会导致应用体积成倍增加，影响启动速度。通过插件形式，我们把选择权交给用户——普通用户享受极致轻便的文本编辑器，而开发者用户可以按需扩展强大的代码执行能力。

------

## ⚖️ 许可证

本项目插件包基于 **Pyodide** 构建。

- **PureEditor Plugin**: MIT License
- **Python**: PSF License
- **Pyodide**: Mozilla Public License 2.0

---

*Created with ❤️ by UnbalancedCat*