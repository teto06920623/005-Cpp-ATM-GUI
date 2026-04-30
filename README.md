# 🏦 005-Cpp-ATM-GUI

![GitHub repo size](https://img.shields.io/github/repo-size/your-username/005-Cpp-ATM-GUI?style=flat-square)
![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg?style=flat-square)
![C++ Standard](https://img.shields.io/badge/C%2B%2B-11%20%7C%2014%20%7C%2017-blue.svg?style=flat-square)
![Qt](https://img.shields.io/badge/GUI-Qt5%20%7C%20Qt6-green.svg?style=flat-square)
![License](https://img.shields.io/badge/license-MIT-success.svg?style=flat-square)

A secure and interactive **ATM simulator** built in **C++** with the **Qt framework**.  
Designed to demonstrate clean object-oriented design, file-based persistence, and a polished desktop GUI experience.

---

## ✨ Overview

This project simulates common banking operations through a user-friendly graphical interface. It is ideal for:

- learning **C++ GUI development**
- practicing **Qt application design**
- exploring **object-oriented programming**
- understanding **basic persistence and transaction workflows**

---

## 📌 Features

| Feature | Description |
|--------|-------------|
| 🔐 Authentication | PIN-based login for account access |
| 💰 Balance Inquiry | Instantly view account balance |
| ➕ Deposit | Add funds to an account |
| 💸 Withdrawal | Withdraw funds with balance validation |
| 🧾 Transaction History | Review recent deposits and withdrawals |
| 🖥️ Qt GUI | Clean, responsive, cross-platform interface |
| ⚠️ Validation | Handles invalid inputs and edge cases gracefully |
| 🚪 Session Management | Secure logout to end sessions safely |
| 💾 Persistence | Stores account and transaction data locally |

---

## 🛠️ Tech Stack

| Layer | Technology |
|------|------------|
| Language | C++11+ |
| GUI Framework | Qt 5 / Qt 6 |
| Build System | CMake |
| Platform Support | Windows, Linux, macOS |

---

## 📂 Project Structure

```bash
005-Cpp-ATM-GUI/
├── src/
│   ├── main.cpp
│   ├── atm.h
│   ├── atm.cpp
│   ├── account.h
│   ├── account.cpp
│   ├── transaction.h
│   ├── transaction.cpp
│   ├── gui/
│   │   ├── loginwindow.h
│   │   ├── loginwindow.cpp
│   │   ├── mainwindow.h
│   │   ├── mainwindow.cpp
│   │   └── ...
│   └── util/
│       ├── filemanager.h
│       └── filemanager.cpp
├── data/
│   ├── accounts.txt
│   └── transactions.txt
├── resources/
│   └── images/
├── CMakeLists.txt
├── LICENSE
└── README.md
```

---

## 🚀 Getting Started

### Prerequisites

Make sure the following tools are installed:

- **C++ Compiler**
  - GCC / Clang on Linux and macOS
  - MSVC with Visual Studio on Windows
- **CMake** 3.10+
- **Qt SDK** 5.x or 6.x
  - Ensure `qmake`, `moc`, `uic`, and `rcc` are available in your `PATH`
  - Or set `CMAKE_PREFIX_PATH` to your Qt installation

---

### Installation

#### 1) Clone the repository

```bash
git clone https://github.com/your-username/005-Cpp-ATM-GUI.git
cd 005-Cpp-ATM-GUI
```

#### 2) Create a build directory

```bash
mkdir build
cd build
```

#### 3) Configure the project

```bash
cmake ..
```

If CMake cannot find Qt, specify your Qt path:

```bash
cmake -DCMAKE_PREFIX_PATH="C:/Qt/6.5.0/msvc2019_64" ..
```

#### 4) Build the project

```bash
cmake --build .
```

Or, on Linux/macOS with Makefiles:

```bash
make
```

---

## ▶️ Usage

After building, run the executable from the build directory:

```bash
# Linux/macOS
./atm_gui

# Windows
.\atm_gui.exe
```

Once launched, the application opens a login window where users enter:

- **Account Number**
- **PIN**

---

## 🔑 Sample Test Accounts

The repository includes predefined accounts in `data/accounts.txt` for testing.

| Account Number | PIN | Initial Balance | Notes |
|---|---:|---:|---|
| `123456` | `1234` | `$1,000.00` | Standard test account |
| `654321` | `4321` | `$500.00` | Useful for withdrawal limit testing |
| `987654` | `5678` | `$2,500.00` | Useful for larger transactions |

> You can edit `data/accounts.txt` to add or update test accounts.

---

## 🧩 How It Works

1. User logs in with account number and PIN.
2. The application validates credentials.
3. The main dashboard allows:
   - balance checks
   - deposits
   - withdrawals
   - transaction history viewing
4. All updates are persisted to local files.

---

## 🧪 Example Workflow

```text
Open app → Login → View balance → Deposit/Withdraw → Check history → Logout
```

---

## 🤝 Contributing

Contributions are welcome!

### Workflow

1. Fork the repository
2. Create a branch:

```bash
git checkout -b feature/amazing-feature
```

3. Commit your changes:

```bash
git commit -m "Add amazing feature"
```

4. Push the branch:

```bash
git push origin feature/amazing-feature
```

5. Open a Pull Request

### Contribution Guidelines

- Keep code clean and maintainable
- Follow modern C++ best practices
- Test your changes before submitting
- Document significant updates when needed

---

## 🐛 Troubleshooting

| Issue | Possible Fix |
|------|--------------|
| Qt not found by CMake | Set `CMAKE_PREFIX_PATH` to your Qt installation |
| Build errors on Windows | Verify the correct MSVC/MinGW kit is selected |
| App fails to launch | Confirm the executable was built successfully and dependencies are installed |
| Missing data files | Ensure the `data/` directory exists and is accessible |

---

## 📄 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for more information.

---

## 📬 Contact

**Project Link:** https://github.com/your-username/005-Cpp-ATM-GUI

**Author:** Your Name / Organization  
**Email:** your.email@example.com  
**X/Twitter:** [@your_twitter](https://twitter.com/your_twitter)