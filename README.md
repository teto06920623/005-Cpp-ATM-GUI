# 🏦 005-Cpp-ATM-GUI: Secure & Interactive ATM Simulator

A robust and user-friendly Automated Teller Machine (ATM) GUI application developed in C++ using the Qt framework, simulating core banking operations with a focus on security and user experience.

---

## 🚀 Badges

[![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Build Status](https://github.com/your-username/005-Cpp-ATM-GUI/actions/workflows/ci.yml/badge.svg?branch=main)](https://github.com/your-username/005-Cpp-ATM-GUI/actions/workflows/ci.yml) <!-- Replace your-username with your GitHub username -->
[![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)](https://en.cppreference.com/w/)
[![C++ Standard](https://img.shields.io/badge/C%2B%2B-11%20%7C%2014%20%7C%2017-blue.svg)](https://en.cppreference.com/w/cpp/compiler_support)
[![GUI Framework](https://img.shields.io/badge/Framework-Qt5%20%7C%20Qt6-green.svg)](https://www.qt.io/)
[![GitHub Stars](https://img.shields.io/github/stars/your-username/005-Cpp-ATM-GUI?style=social)](https://github.com/your-username/005-Cpp-ATM-GUI/stargazers) <!-- Replace your-username with your GitHub username -->

---

## 📋 Table of Contents

-   [🚀 Badges](#🚀-badges)
-   [📝 Description](#📝-description)
-   [✨ Features](#✨-features)
-   [🛠️ Tech Stack](#🛠️-tech-stack)
-   [📂 Project Structure](#📂-project-structure)
-   [📦 Installation](#📦-installation)
    -   [Prerequisites](#prerequisites)
    -   [Steps](#steps)
-   [🚀 Usage](#🚀-usage)
    -   [Predefined Accounts for Testing](#predefined-accounts-for-testing)
-   [🤝 Contributing](#🤝-contributing)
-   [📄 License](#📄-license)
-   [📧 Contact](#📧-contact)

---

## 📝 Description

This repository hosts a robust simulation of an Automated Teller Machine (ATM) with a modern graphical user interface (GUI). Developed entirely in C++ leveraging the powerful Qt framework, this project serves as an excellent educational resource and a practical demonstration of cross-platform C++ GUI development.

The ATM application provides users with a secure and interactive experience for common banking operations. It is designed to showcase:
-   **Robust Object-Oriented Programming (OOP) Principles**: Clean, modular, and maintainable code.
-   **Secure Data Handling**: Account and transaction data persistence using a simple file-based system.
-   **Intuitive User Experience**: A smooth and responsive GUI built with Qt.
-   **Error Handling**: Comprehensive input validation and error reporting.

Whether you're looking to learn C++ GUI development or exploring a practical application of fundamental programming concepts, this project offers a clear and functional example.

---

## ✨ Features

-   🔒 **Secure User Authentication**: PIN-based login system for exclusive account access.
-   💰 **Account Balance Inquiry**: Users can instantly view their current account balance.
-    depositing funds into their account.
-   💳 **Cash Withdrawal Functionality**: Enables users to withdraw funds safely, with real-time balance checks to prevent overdrafts.
-   📜 **Transaction History**: View a chronological log of recent deposits and withdrawals for transparency.
-   🖥️ **User-friendly Graphical Interface**: Built with Qt for a sleek, responsive, and cross-platform user experience.
-   ⚠️ **Error Handling and Input Validation**: Robust mechanisms to handle invalid inputs and operational errors gracefully.
-   🚪 **Session Management**: Secure logout functionality to end an ATM session and protect user data.
-   💾 **File-based Persistence**: Account data and transaction history are securely saved to and loaded from local files, ensuring data integrity across sessions.

---

## 🛠️ Tech Stack

-   **Language**: ![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white) C++11 (or newer, typically C++14/17 for modern features)
-   **GUI Framework**: ![Qt](https://img.shields.io/badge/Qt-41CD52?style=for-the-badge&logo=qt&logoColor=white) [Qt 5.x / 6.x](https://www.qt.io/) (for high-performance, cross-platform GUI development)
-   **Build System**: ![CMake](https://img.shields.io/badge/CMake-008FBA?style=for-the-badge&logo=cmake&logoColor=white) [CMake](https://cmake.org/) (Cross-platform build automation for C++ projects)

---

## 📂 Project Structure

The project is organized into a clear, modular structure:

```
005-Cpp-ATM-GUI/
├── src/
│   ├── main.cpp                # Entry point of the application
│   ├── atm.h                   # ATM logic interface
│   ├── atm.cpp                 # ATM logic implementation
│   ├── account.h               # Account class definition
│   ├── account.cpp             # Account class implementation
│   ├── transaction.h           # Transaction class definition
│   ├── transaction.cpp         # Transaction class implementation
│   ├── gui/
│   │   ├── loginwindow.h       # Login window GUI definition
│   │   ├── loginwindow.cpp     # Login window GUI implementation
│   │   ├── mainwindow.h        # Main ATM operations window definition
│   │   ├── mainwindow.cpp      # Main ATM operations window implementation
│   │   └── ...                 # Other GUI components (e.g., deposit, withdraw, history dialogs)
│   └── util/
│       └── filemanager.h       # Utility for file operations (data persistence)
│       └── filemanager.cpp     # Utility implementation
├── data/
│   ├── accounts.txt            # Stores account data (initially pre-populated)
│   └── transactions.txt        # Stores transaction history
├── CMakeLists.txt              # CMake build configuration for the entire project
├── resources/
│   └── images/                 # Optional: Placeholder for application icons, backgrounds, etc.
├── LICENSE                     # Project license file
└── README.md                   # This README file
```

---

## 📦 Installation

To get a local copy of the project up and running, follow these simple steps.

### Prerequisites

Ensure you have the following software installed on your system:

-   **C++ Compiler**:
    -   [GCC](https://gcc.gnu.org/) (GNU Compiler Collection) on Linux/macOS
    -   [Clang](https://clang.llvm.org/) on Linux/macOS
    -   [MSVC](https://visualstudio.microsoft.com/vs/features/cplusplus/) (Microsoft Visual C++) with Visual Studio on Windows
-   **CMake**: Version 3.10 or higher.
    -   [Download CMake](https://cmake.org/download/)
-   **Qt SDK**: Version 5 or 6, installed and configured.
    -   **Crucial**: Ensure `qmake` and other Qt tools (like `moc`, `uic`, `rcc`) are in your system's `PATH` environment variable, or that CMake can locate your Qt installation.
    -   [Download Qt](https://www.qt.io/download) (Choose open-source version for development)
    -   *Tip for Windows*: When installing Qt, make sure to select the toolchains corresponding to your Visual Studio version (e.g., MSVC 2019 64-bit) or MinGW if you prefer.

### Steps

1.  **Clone the repository**:
    ```bash
    git clone https://github.com/your-username/005-Cpp-ATM-GUI.git
    cd 005-Cpp-ATM-GUI
    ```
    *(Remember to replace `your-username` with the actual GitHub username)*

2.  **Create a build directory and navigate into it**:
    It's standard practice to build projects out-of-source.
    ```bash
    mkdir build
    cd build
    ```

3.  **Configure the project with CMake**:
    This step generates the build system files (e.g., Makefiles on Linux/macOS, Visual Studio solution files on Windows).
    ```bash
    cmake ..
    ```
    *For **Windows** users using **Visual Studio**, you might need to specify the generator for your installed version:*
    ```bash
    # Example for Visual Studio 2019
    cmake -G "Visual Studio 16 2019" ..
    # Example for Visual Studio 2022
    cmake -G "Visual Studio 17 2022" ..
    ```
    *If CMake struggles to find Qt, you might need to specify the Qt installation path using `CMAKE_PREFIX_PATH`:*
    ```bash
    cmake -DCMAKE_PREFIX_PATH="C:/Qt/6.5.0/msvc2019_64" .. # Adjust path to your Qt installation
    ```

4.  **Build the project**:
    This compiles the source code and links it into an executable.
    ```bash
    # On Linux/macOS (using Makefiles generated by CMake)
    make
    ```
    *Or for cross-platform building with CMake (recommended for consistency):*
    ```bash
    cmake --build .
    ```
    *If using **Visual Studio** on Windows, open the generated `.sln` file (e.g., `005-Cpp-ATM-GUI.sln`) in the `build` directory and build the solution (`Build > Build Solution`).*

---

## 🚀 Usage

Once the project is successfully built, you can run the application. Navigate to the `build` directory (or wherever your executable is generated, typically `build/bin` or directly in `build` on some systems) and execute it:

```bash
# On Linux/macOS
./atm_gui

# On Windows
.\atm_gui.exe
```

A login window will appear, prompting for an Account Number and PIN.

### Predefined Accounts for Testing

The application comes with a few predefined accounts stored in `data/accounts.txt` for immediate testing purposes. Use these credentials to log in and test the ATM functionalities:

| Account Number | PIN  | Initial Balance | Notes                               |
| :------------- | :--- | :-------------- | :---------------------------------- |
| `123456`       | `1234` | `$1,000.00`     | Standard account for general testing |
| `654321`       | `4321` | `$500.00`       | Lower balance for withdrawal limits  |
| `987654`       | `5678` | `$2,500.00`     | Higher balance for larger transactions |

*Feel free to modify or add new accounts by directly editing the `data/accounts.txt` file. The application will load and save data to this file, ensuring persistence across sessions.*

---

## 🤝 Contributing

We welcome contributions to enhance this ATM GUI project! If you'd like to contribute, please follow these steps:

1.  **Fork** the repository.
2.  **Create a new branch** (`git checkout -b feature/AmazingFeature`).
3.  **Implement your changes** and ensure they are well-tested.
4.  **Commit your changes** (`git commit -m 'Add some AmazingFeature'`).
5.  **Push to the branch** (`git push origin feature/AmazingFeature`).
6.  **Open a Pull Request**.

Please ensure your code adheres to good C++ practices and maintainability standards.

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 📧 Contact

Your Name/Organization - [@your_twitter](https://twitter.com/your_twitter) - your.email@example.com

Project Link: [https://github.com/your-username/005-Cpp-ATM-GUI](https://github.com/your-username/005-Cpp-ATM-GUI) <!-- Replace your-username -->