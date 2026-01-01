# PureEditor Runtime Plugins 🧩

[中文](README_CN.md) | [English]

**Offline Runtime Plugin Packages for PureEditor (HarmonyOS).**

This repository hosts the core runtime files required for PureEditor. By installing these plugins, you can enable local, offline, and secure code writing and execution capabilities (Python & C/C++) within PureEditor.

> **Core Version Information**:
>
> - **Python**: 3.13.0 (Pyodide 0.29.0)
> - **C/C++**: Clang 8.0.1 (Based on WASI SDK)
> - **Architecture**: Wasm (Cross-platform, local sandbox execution)

PureEditor supports Wasm plugin functionality starting from version v0.6.20. Currently supports Python and C/C++.

------

## ✨ Features

- **⚡️ Fully Offline**: Built-in complete Python standard library, runs without an internet connection.
- **🔒 Secure Sandbox**: Based on WebAssembly technology, code runs in an isolated virtual environment without touching the underlying system files.
- **🤝 Interactive Support**: Supports standard output (stdout/stderr) capture and perfect support for synchronous `input()` interaction.
- **📦 Out-of-the-Box**: Automatically deploys the `hello_pure.py` demo script after installation for immediate testing.

------

## 📥 Download & Installation

### Step 1: Download the Plugin Package

Please download the latest plugin package from the [Releases] page on the right:

- **Python Runtime**: `plugin_pyodide_3.13.zip`
- **C/C++ Runtime**: `plugin_clang_8.0.1.zip`

### Step 2: Unlock Features 🥚

Since this is an experimental feature, it is hidden by default. Please follow these steps to unlock it:

1. Open the **PureEditor** App.
2. Go to **Sidebar** > **About**.
3. Find the **Version Number** (e.g., v0.6.x) and **tap it 10 times quickly**.
4. Success is indicated when the prompt "Wasm experimental feature unlocked" appears.
5. Additional content will now appear in My Files, Sidebar, and Settings pages.

### Step 3: Import and Install

1. Return to the **Settings** page. You will now see the **Show Hidden Folders** and **Plugin Management** group.
2. Tap **Plugin Management**..zip` package you just downloaded (supports batch import).
4. Wait for the verification and decompression to complete (this may take a few seconds).

------

## 🚀 How to Use

1. **New/Open File**: Ensure the file has a supported suffix (e.g., `.py` for Python, `.c`/`.cpp` for C/C++).
2. **Open Menu**: Open the sidebar (tap the top-left icon or swipe right from the left edge).
3. **Run**: Click the **"Compile & Run"** button in the sidebar.
4. **Interact**: The program will start, and results will be output to the console. If the code contains `input()` or `cin`, an input box will automatically pop up at the bottom waiting for input.

> **Tip**: After the first installation, a demo file (e.g., `Hello_PureEditor_demo.py` or `Hello_PureEditor_demo.cpp`)
> **Tip**: After the first installation, a `Hello_PureEditor_demo.py` will be automatically generated in the root directory of "My Files". You can run it directly to test the environment.

------

## 🛠 Technical Details & Verification

To ensure security, PureEditor performs **SHA-256** fingerprint verification on imported plugin packages. Please ensure you download the zip package released by this repository without tampering.

### File Structure

**Python Plugin (`plugin_pyodide_3.13.zip`)**:
- `pyodide.js`: Bootloader
- `pyodide.asm.wasm`: Python Interpreter
- `python_stdlib.zip`: Standard Library
- `Hello_PureEditor_demo.py`: Demo Script

**C/C++ Plugin (`plugin_clang_8.0.1.zip`)**:
- `clang.js`: Compiler Bootloader
- `clang.wasm`: Clang Compiler Core
- `lld.wasm`: LLD Linker
- `sysroot.tar`: Standard Headers & Libs (Libc/Libc++)
- `Hello_PureEditor_demo.cpp`: Demo Script

### FAQ

**Q: Why does running `sys.platform` show `emscripten` instead of `linux`?**

A: This is normal. Because Python is compiled to WebAssembly via Emscripten, it runs in a simulated POSIX environment rather than directly on the phone's Linux kernel. This proves that the code is indeed running offline in a local sandbox.

**Q: Can I install third-party libraries (e.g., pandas, numpy)?**

A: The current version mainly supports the Python standard library. Support for third-party libraries written in pure Python (Wheels) may be provided in future versions. Stay tuned.

**Q: Why doesn't the UI freeze when using `input()`?**

A: We utilize `SharedArrayBuffer` and `Atomics.wait` technology to run Python in a separate Worker thread, enabling non-blocking synchronous interaction with the main thread.

**Q: Why is the runtime provided as a plugin instead of being built-in?**

A: To keep the main PureEditor app **lightweight and pure**.
The complete Python runtime (s are built based on **Pyodide** and **LLVM/Clang**.

- **PureEditor Plugin**: MIT License
- **Python**: PSF License
- **Pyodide**: Mozilla Public License 2.0
- **LLVM/Clang**: Apache License 2.0 with LLVM Exceptions

This project's plugin package is built based on **Pyodide**.

- **PureEditor Plugin**: MIT License
- **Python**: PSF License
- **Pyodide**: Mozilla Public License 2.0

---

*Created with ❤️ by UnbalancedCat*