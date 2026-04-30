# 🏦 005-Cpp-ATM-GUI

A robust and user-friendly Automated Teller Machine (ATM) GUI application developed in C++ using the Qt framework.

## 🚀 Badges

![License](https://img.shields.io/badge/License-MIT-blue.svg)
![Build Status](https://github.com/your-username/005-Cpp-ATM-GUI/actions/workflows/ci.yml/badge.svg?branch=main) <!-- Replace your-username with your GitHub username -->
![Language](https://img.shields.io/badge/language-C%2B%2B-blue.svg)
![GitHub Stars](https://img.shields.io/github/stars/your-username/005-Cpp-ATM-GUI?style=social) <!-- Replace your-username with your GitHub username -->

## 📝 Description

This repository hosts a simulation of an Automated Teller Machine (ATM) with a graphical user interface (GUI), implemented entirely in C++. Designed for both educational purposes and as a practical demonstration of C++ GUI development using the Qt framework, this project provides a secure and interactive experience for common banking operations. It aims to showcase robust object-oriented programming principles, secure data handling (using a simple file-based system), and an intuitive user experience.

## ✨ Features

-   **Secure User Authentication**: PIN-based login system for account access.
-   **Account Balance Inquiry**: Users can view their current account balance.
-   **Cash Deposit Functionality**: Allows users to deposit funds into their account.
-   **Cash Withdrawal Functionality**: Enables users to withdraw funds, with balance checks.
-   **Transaction History**: View a log of recent deposits and withdrawals.
-   **User-friendly Graphical Interface**: Built with Qt for a smooth and responsive experience.
-   **Error Handling and Input Validation**: Robust handling of invalid inputs and operational errors.
-   **Session Management**: Secure logout functionality to end an ATM session.
-   **File-based Persistence**: Account data and transaction history are saved to and loaded from files.

## 🛠️ Tech Stack

-   **Language**: C++11 (or newer)
-   **GUI Framework**: [Qt 5.x / 6.x](https://www.qt.io/) (for cross-platform GUI development)
-   **Build System**: [CMake](https://cmake.org/) (Cross-platform build automation)

## 📦 Installation

To get a local copy up and running, follow these simple steps.

### Prerequisites

-   A C++ compiler (e.g., GCC, Clang, MSVC)
-   CMake (version 3.10 or higher)
-   Qt SDK (version 5 or 6, installed and configured. Ensure `qmake` and other Qt tools are in your system's PATH or CMake can find them.)

### Steps

1.  **Clone the repository**:
    ```bash
    git clone https://github.com/your-username/005-Cpp-ATM-GUI.git
    cd 005-Cpp-ATM-GUI
    ```
    *(Replace `your-username` with the actual GitHub username)*

2.  **Create a build directory and navigate into it**:
    ```bash
    mkdir build
    cd build
    ```

3.  **Configure the project with CMake**:
    ```bash
    cmake ..
    ```
    *For Windows users using Visual Studio, you might need to specify the generator:*
    ```bash
    cmake -G "Visual Studio 16 2019" .. # Adjust Visual Studio version as needed
    ```

4.  **Build the project**:
    ```bash
    make # On Linux/macOS
    ```
    *Or for cross-platform building with CMake:*
    ```bash
    cmake --build .
    ```
    *If using Visual Studio, open the generated `.sln` file in the `build` directory and build the solution.*

## 🚀 Usage

To run the application, navigate to the `build` directory (or wherever your executable is generated) and execute it:

```bash
./atm_gui       # On Linux/macOS
atm_gui.exe     # On Windows
```

### Predefined Accounts for Testing

The application comes with a few predefined accounts for testing purposes. Use these credentials to log in and test the ATM functionalities:

| Account Number | PIN  | Initial Balance |
| :------------- | :--- | :-------------- |
| `123456`       | `1234` | `$1,000.00`     |
| `654321`       | `4321` | `$500.00`       |
| `987654`       | `5678` | `$2,500.00`     |

*Feel free to modify or add new accounts by directly editing the data files (e.g., `accounts.txt`) or extending the application with an administrative interface.*

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.