#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstring>
#include <cstdlib>
#include "raylib.h"

#define TextToFloat(text) (float)atof(text)
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

using namespace std;

// === كلاسات المنطق المالي ===
class BaseAccount
{
protected:
    string userID, password, type;
    double balance;

public:
    BaseAccount(string id, string pass, double bal, string t) : userID(id), password(pass), balance(bal), type(t) {}
    
    string getID() const { return userID; }
    string getPassword() const { return password; }
    string getType() const { return type; }
    double getBalance() const { return balance; }
    bool checkPassword(const string &pass) const { return password == pass; }
    
    virtual ~BaseAccount() = default;
    virtual void deposit(double amount)
    {
        if (amount > 0)
            balance += amount;
    }
    virtual bool withdraw(double amount) { return false; }
};

class CheckingAccount : public BaseAccount
{
public:
    CheckingAccount(string id, string pass, double bal) : BaseAccount(id, pass, bal, "Checking") {}
    bool withdraw(double amount) override
    {
        if (amount > 0 && balance >= amount)
        {
            balance -= amount;
            return true;
        }
        return false;
    }
};

class SavingsAccount : public BaseAccount
{
public:
    SavingsAccount(string id, string pass, double bal) : BaseAccount(id, pass, bal, "Savings") {}
};

// === كلاس النظام والواجهة ===
class SystemATM
{
private:
    vector<shared_ptr<BaseAccount>> accounts;
    enum Screen
    {
        LOGIN,
        CUSTOMER_MENU,
        ADMIN_MENU,
        ADD_USER_SCREEN
    };
    Screen currentScreen = LOGIN;
    shared_ptr<BaseAccount> loggedInAccount = nullptr;

    // متغيرات الواجهة
    char idInput[64] = "";
    char passInput[64] = "";
    char amountInput[64] = "";

    // متغيرات إضافة عميل جديد
    char newIdInput[64] = "";
    char newPassInput[64] = "";
    char initialBalInput[64] = "";
    bool isChecking = true;

    bool editId = false, editPass = false, editAmount = false;
    bool editNewId = false, editNewPass = false, editInitialBal = false;

    string statusMessage = "Welcome to Modern CyberBank";

public:
    SystemATM()
    {
        // حسابات افتراضية للتجربة
        accounts.push_back(make_shared<CheckingAccount>("user1", "1234", 5000));
        accounts.push_back(make_shared<SavingsAccount>("Teto", "0000", 15000));
    }

    void runGUI()
    {
        InitWindow(800, 600, "Modern CyberBank ATM - Full System");
        SetTargetFPS(60);

        Font modernFont = LoadFontEx("font.ttf", 28, 0, 0);
        GuiSetFont(modernFont);

        GuiSetStyle(DEFAULT, TEXT_SIZE, 22);
        GuiSetStyle(DEFAULT, BACKGROUND_COLOR, ColorToInt(Color{15, 23, 42, 255}));
        GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, ColorToInt(RAYWHITE));
        GuiSetStyle(TEXTBOX, TEXT_ALIGNMENT, TEXT_ALIGN_CENTER);
        GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, ColorToInt(Color{30, 41, 59, 255}));

        while (!WindowShouldClose())
        {
            BeginDrawing();
            ClearBackground(Color{15, 23, 42, 255});

            switch (currentScreen)
            {
            case LOGIN:
                drawLoginScreen();
                break;
            case CUSTOMER_MENU:
                drawCustomerScreen();
                break;
            case ADMIN_MENU:
                drawAdminScreen();
                break;
            case ADD_USER_SCREEN:
                drawAddUserScreen();
                break;
            }

            DrawRectangle(0, 560, 800, 40, Color{30, 41, 59, 255});
            int textWidth = MeasureTextEx(modernFont, statusMessage.c_str(), 20, 1).x;
            DrawTextEx(modernFont, statusMessage.c_str(), Vector2{(float)(800 - textWidth) / 2, 570}, 20, 1, LIGHTGRAY);

            EndDrawing();
        }
        UnloadFont(modernFont);
        CloseWindow();
    }

private:
    void drawLoginScreen()
    {
        DrawRectangleRounded(Rectangle{200, 100, 400, 380}, 0.05f, 10, Color{30, 41, 59, 255});
        DrawRectangleRoundedLines(Rectangle{200, 100, 400, 380}, 0.05f, 10, 2, Color{51, 65, 85, 255});

        DrawText("System Login", 320, 130, 24, RAYWHITE);
        DrawLine(230, 170, 570, 170, Color{51, 65, 85, 255});

        DrawText("User ID (type 'admin' for Admin Mode):", 240, 190, 18, LIGHTGRAY);
        if (GuiTextBox(Rectangle{240, 220, 320, 45}, idInput, 64, editId))
            editId = !editId;

        DrawText("Password:", 240, 280, 18, LIGHTGRAY);
        if (GuiTextBox(Rectangle{240, 310, 320, 45}, passInput, 64, editPass))
            editPass = !editPass;

        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(Color{37, 99, 235, 255}));
        if (GuiButton(Rectangle{240, 390, 320, 50}, "SIGN IN"))
        {
            if (strcmp(idInput, "admin") == 0 && strcmp(passInput, "admin") == 0)
            {
                currentScreen = ADMIN_MENU;
                statusMessage = "Admin Mode Activated.";
                return;
            }

            bool found = false;
            for (auto &acc : accounts)
            {
                if (acc->getID() == idInput && acc->checkPassword(passInput))
                {
                    loggedInAccount = acc;
                    currentScreen = CUSTOMER_MENU;
                    statusMessage = "Login Successful!";
                    found = true;
                    break;
                }
            }
            if (!found)
                statusMessage = "Error: Invalid ID or Password!";
        }
    }

    void drawAdminScreen()
    {
        DrawRectangle(0, 0, 800, 70, Color{30, 41, 59, 255});
        DrawText("ADMINISTRATOR DASHBOARD", 30, 25, 24, RAYWHITE);

        if (GuiButton(Rectangle{660, 15, 110, 40}, "Log Out"))
        {
            currentScreen = LOGIN;
            statusMessage = "Logged out of Admin Mode.";
            memset(idInput, 0, sizeof(idInput));
            memset(passInput, 0, sizeof(passInput));
        }

        // لوحة الإحصائيات والأزرار
        DrawRectangleRounded(Rectangle{30, 90, 740, 90}, 0.1f, 10, Color{51, 65, 85, 255});
        DrawText("Total Accounts:", 50, 120, 24, LIGHTGRAY);
        DrawText(to_string(accounts.size()).c_str(), 240, 110, 40, GREEN);

        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(Color{16, 185, 129, 255}));
        if (GuiButton(Rectangle{500, 105, 250, 55}, "ADD NEW CUSTOMER"))
        {
            currentScreen = ADD_USER_SCREEN;
            statusMessage = "Fill in the details for the new account.";
        }

        // --- جدول بيانات العملاء ---
        DrawText("Registered Customers Data:", 30, 210, 22, RAYWHITE);

        // رسم رأس الجدول (Header)
        DrawRectangle(30, 240, 740, 40, Color{30, 41, 59, 255});
        DrawText("User ID", 50, 250, 20, RAYWHITE);
        DrawText("Password", 250, 250, 20, RAYWHITE);
        DrawText("Account Type", 450, 250, 20, RAYWHITE);
        DrawText("Balance", 650, 250, 20, RAYWHITE);
        DrawLine(30, 280, 770, 280, Color{51, 65, 85, 255});

        // رسم سطور الجدول (بيانات العملاء)
        for (size_t i = 0; i < accounts.size(); i++)
        {
            int y = 295 + (i * 40); // حساب مكان السطر
            if (y > 520)
            {
                DrawText("... (More accounts hidden)", 50, y, 18, GRAY);
                break; // عشان الكلام ما يخرجش بره الشاشة لو زادوا عن الحد
            }

            DrawText(accounts[i]->getID().c_str(), 50, y, 20, LIGHTGRAY);
            DrawText(accounts[i]->getPassword().c_str(), 250, y, 20, Color{239, 68, 68, 255}); // الباسورد بلون أحمر للتنبيه
            DrawText(accounts[i]->getType().c_str(), 450, y, 20, LIGHTGRAY);
            DrawText(TextFormat("$%.2f", accounts[i]->getBalance()), 650, y, 20, GREEN);

            DrawLine(30, y + 25, 770, y + 25, Color{30, 41, 59, 255}); // خط خفيف بين كل عميل
        }
    }

    void drawAddUserScreen()
    {
        DrawText("Create New Account", 50, 30, 30, RAYWHITE);

        DrawText("New User ID:", 50, 100, 20, LIGHTGRAY);
        if (GuiTextBox(Rectangle{50, 130, 300, 45}, newIdInput, 64, editNewId))
            editNewId = !editNewId;

        DrawText("New Password:", 50, 190, 20, LIGHTGRAY);
        if (GuiTextBox(Rectangle{50, 220, 300, 45}, newPassInput, 64, editNewPass))
            editNewPass = !editNewPass;

        DrawText("Initial Balance ($):", 50, 280, 20, LIGHTGRAY);
        if (GuiTextBox(Rectangle{50, 310, 300, 45}, initialBalInput, 64, editInitialBal))
            editInitialBal = !editInitialBal;

        DrawText("Account Type:", 420, 100, 20, LIGHTGRAY);
        if (GuiButton(Rectangle{420, 130, 150, 45}, isChecking ? "[X] Checking" : "[ ] Checking"))
            isChecking = true;
        if (GuiButton(Rectangle{590, 130, 150, 45}, !isChecking ? "[X] Savings" : "[ ] Savings"))
            isChecking = false;

        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(Color{37, 99, 235, 255}));
        if (GuiButton(Rectangle{50, 400, 300, 60}, "SAVE ACCOUNT"))
        {
            if (strlen(newIdInput) > 0 && strlen(newPassInput) > 0)
            {
                double bal = atof(initialBalInput);
                if (isChecking)
                    accounts.push_back(make_shared<CheckingAccount>(newIdInput, newPassInput, bal));
                else
                    accounts.push_back(make_shared<SavingsAccount>(newIdInput, newPassInput, bal));

                statusMessage = "Account created successfully!";
                memset(newIdInput, 0, sizeof(newIdInput));
                memset(newPassInput, 0, sizeof(newPassInput));
                memset(initialBalInput, 0, sizeof(initialBalInput));
                currentScreen = ADMIN_MENU;
            }
            else
            {
                statusMessage = "Error: ID and Password cannot be empty!";
            }
        }

        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(Color{239, 68, 68, 255}));
        if (GuiButton(Rectangle{380, 400, 300, 60}, "CANCEL & RETURN"))
        {
            currentScreen = ADMIN_MENU;
            statusMessage = "Operation cancelled.";
        }
    }

    void drawCustomerScreen()
    {
        DrawRectangle(0, 0, 800, 70, Color{30, 41, 59, 255});
        string header = "Card Holder: " + loggedInAccount->getID() + "  |  Account: " + loggedInAccount->getType();
        DrawText(header.c_str(), 30, 25, 22, RAYWHITE);

        if (GuiButton(Rectangle{660, 15, 110, 40}, "Log Out"))
        {
            loggedInAccount = nullptr;
            currentScreen = LOGIN;
            statusMessage = "Logged out securely.";
            memset(idInput, 0, sizeof(idInput));
            memset(passInput, 0, sizeof(passInput));
        }

        DrawRectangleRounded(Rectangle{50, 110, 700, 150}, 0.1f, 10, Color{16, 185, 129, 255});
        DrawText("Current Balance", 80, 130, 20, Color{209, 250, 229, 255});
        string balText = "$" + to_string((long long)loggedInAccount->getBalance());
        DrawText(balText.c_str(), 80, 170, 60, WHITE);

        DrawText("Enter Amount ($):", 50, 320, 24, LIGHTGRAY);
        if (GuiTextBox(Rectangle{260, 310, 300, 50}, amountInput, 64, editAmount))
            editAmount = !editAmount;

        double amount = atof(amountInput);

        GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(Color{37, 99, 235, 255}));
        if (GuiButton(Rectangle{50, 400, 300, 60}, "DEPOSIT FUNDS"))
        {
            if (amount > 0)
            {
                loggedInAccount->deposit(amount);
                statusMessage = "Deposited $" + to_string((long long)amount) + " successfully.";
                memset(amountInput, 0, sizeof(amountInput));
            }
            else
            {
                statusMessage = "Error: Please enter a valid amount.";
            }
        }

        if (loggedInAccount->getType() == "Checking")
        {
            GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, ColorToInt(Color{239, 68, 68, 255}));
            if (GuiButton(Rectangle{380, 400, 300, 60}, "WITHDRAW FUNDS"))
            {
                if (loggedInAccount->withdraw(amount))
                {
                    statusMessage = "Withdrew $" + to_string((long long)amount) + " successfully.";
                    memset(amountInput, 0, sizeof(amountInput));
                }
                else
                {
                    statusMessage = "Failed: Insufficient funds or invalid amount.";
                }
            }
        }
    }
};

int main()
{
    SystemATM atm;
    atm.runGUI();
    return 0;
}