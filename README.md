# PureEditor Python Runtime Plugin 🐍

[中文](README_CN.md) | [English]

**Offline Python Runtime Plugin Package for PureEditor (HarmonyOS).**

This repository hosts the core runtime files required for PureEditor. By installing this plugin, you can enable local, offline, and secure Python code writing and execution capabilities within PureEditor.

> **Core Version Information**:
>
> - **Python**: 3.13.0
> - **Pyodide**: 0.29.0 (Based on WebAssembly)
> - **Architecture**: Wasm (Cross-platform, local sandbox execution)

PureEditor supports Wasm plugin functionality starting from version v0.6.20, currently supporting Python only. Future versions plan to provide compilation and running support for C, C++, and Rust.

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

- Filename: `plugin_pyodide_3.13.zip`

### Step 2: Unlock Features 🥚

Since this is an experimental feature, it is hidden by default. Please follow these steps to unlock it:

1. Open the **PureEditor** App.
2. Go to **Sidebar** > **About**.
3. Find the **Version Number** (e.g., v0.6.x) and **tap it 10 times quickly**.
4. Success is indicated when the prompt "Wasm experimental feature unlocked" appears.
5. Additional content will now appear in My Files, Sidebar, and Settings pages.

### Step 3: Import and Install

1. Return to the **Settings** page. You will now see the **Show Hidden Folders** and **Plugin Management** group.
2. Tap **Plugin Management**.
3. Tap **Import Environment Package** and select the `plugin_pyodide_3.13.zip` you just downloaded in the file picker.
4. Wait for the verification and decompression to complete (this may take a few seconds).

------

## 🚀 How to Use

1. **New/Open File**: Ensure the file has a `.py` suffix (e.g., `test.py`).
2. **Open Menu**: Open the sidebar (tap the top-left icon or swipe right from the left edge).
3. **Run**: Click the **"Compile & Run"** button in the sidebar.
4. **Interact**: The program will start, and results will be output to the console. If the code contains `input()`, an input box will automatically pop up at the bottom waiting for input.

> **Tip**: After the first installation, a `Hello_PureEditor_demo.py` will be automatically generated in the root directory of "My Files". You can run it directly to test the environment.

------

## 🛠 Technical Details & Verification

To ensure security, PureEditor performs **SHA-256** fingerprint verification on imported plugin packages. Please ensure you download the zip package released by this repository without tampering.

### File Structure

The `plugin_pyodide_3.13.zip` contains the following core files after decompression:

- `pyodide.js`: Bootloader
- `pyodide.asm.wasm`: Binary file of the compiled Python interpreter
- `python_stdlib.zip`: Python standard library archive
- `Hello_PureEditor_demo.py`: Demo script

### FAQ

**Q: Why does running `sys.platform` show `emscripten` instead of `linux`?**

A: This is normal. Because Python is compiled to WebAssembly via Emscripten, it runs in a simulated POSIX environment rather than directly on the phone's Linux kernel. This proves that the code is indeed running offline in a local sandbox.

**Q: Can I install third-party libraries (e.g., pandas, numpy)?**

A: The current version mainly supports the Python standard library. Support for third-party libraries written in pure Python (Wheels) may be provided in future versions. Stay tuned.

**Q: Why doesn't the UI freeze when using `input()`?**

A: We utilize `SharedArrayBuffer` and `Atomics.wait` technology to run Python in a separate Worker thread, enabling non-blocking synchronous interaction with the main thread.

**Q: Why is the runtime provided as a plugin instead of being built-in?**

A: To keep the main PureEditor app **lightweight and pure**.
The complete Python runtime (including the Wasm interpreter and standard library) is relatively large (30MB+ when unzipped). Bundling it directly would significantly increase the app size and affect startup speed. By using a plugin system, we give the choice to the user—casual users enjoy a lightning-fast text editor, while developers can extend powerful code execution capabilities on demand.

------

## ⚖️ License

This project's plugin package is built based on **Pyodide**.

- **PureEditor Plugin**: MIT License
- **Python**: PSF License
- **Pyodide**: Mozilla Public License 2.0

---

*Created with ❤️ by UnbalancedCat*