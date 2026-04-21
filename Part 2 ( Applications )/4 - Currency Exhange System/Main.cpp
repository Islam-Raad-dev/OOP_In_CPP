/*
╔══════════════════════════════════════════════════════════════════╗
║         Banking System Console Application  –  OOP v2.0          ║
║         Author    : Islam Raad                                   ║
║         Refactored: 2026-04-20                                   ║
║         Description: Full OOP rewrite with enhanced UI           ║
╚══════════════════════════════════════════════════════════════════╝
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <limits>
#include <stdexcept>

using namespace std;

// ═══════════════════════════════════════════════════════════════
//   ANSI Color Codes  (تعريف الألوان للطرفية)
// ═══════════════════════════════════════════════════════════════
namespace Color
{
    const string RST = "\033[0m";
    const string BOLD = "\033[1m";
    const string DIM = "\033[2m";
    const string BRED = "\033[1;31m";
    const string BGREEN = "\033[1;32m";
    const string BYELLOW = "\033[1;33m";
    const string BBLUE = "\033[1;34m";
    const string BMAGENTA = "\033[1;35m";
    const string BCYAN = "\033[1;36m";
    const string BWHITE = "\033[1;37m";
    const string RED = "\033[0;31m";
    const string GREEN = "\033[0;32m";
    const string YELLOW = "\033[0;33m";
    const string CYAN = "\033[0;36m";
    const string MAGENTA = "\033[0;35m";
}

// ═══════════════════════════════════════════════════════════════
//   Utility  –  Static helper functions
// ═══════════════════════════════════════════════════════════════
class Util
{
public:
    static string trim(const string &s)
    {
        static const string WS = " \t\r\n\f\v";
        size_t first = s.find_first_not_of(WS);
        if (first == string::npos)
            return "";
        size_t last = s.find_last_not_of(WS);
        return s.substr(first, last - first + 1);
    }

    static vector<string> split(const string &str, const string &delim)
    {
        vector<string> tokens;
        size_t start = 0, pos;
        while ((pos = str.find(delim, start)) != string::npos)
        {
            string tok = str.substr(start, pos - start);
            if (!tok.empty())
                tokens.push_back(tok);
            start = pos + delim.size();
        }
        string last = str.substr(start);
        if (!last.empty())
            tokens.push_back(last);
        return tokens;
    }

    static string truncate(const string &s, int maxLen)
    {
        if ((int)s.size() <= maxLen)
            return s;
        return s.substr(0, maxLen - 3) + "...";
    }

    static string formatAmount(double amount)
    {
        ostringstream oss;
        oss << fixed << setprecision(2) << amount;
        return oss.str();
    }

    static void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    // Read a full text line, skipping leading whitespace
    static string readLine(const string &prompt)
    {
        cout << prompt;
        string s;
        getline(cin >> ws, s);
        return trim(s);
    }

    // Read a non-negative double, clear buffer after
    static double readDouble(const string &prompt)
    {
        double val = 0;
        while (true)
        {
            cout << prompt;
            if (cin >> val && val >= 0)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Color::BRED << "  ✗  Invalid input. Enter a valid positive number.\n"
                 << Color::RST;
        }
        return val;
    }

    // Read int in [min, max], clear buffer after
    static int readInt(const string &prompt, int minVal, int maxVal)
    {
        int val = 0;
        while (true)
        {
            cout << prompt;
            if (cin >> val && val >= minVal && val <= maxVal)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Color::BRED << "  ✗  Please enter a number between "
                 << minVal << " and " << maxVal << ".\n"
                 << Color::RST;
        }
        return val;
    }

    // Read yes/no answer
    static bool readYesNo(const string &prompt)
    {
        cout << prompt;
        string line;
        getline(cin >> ws, line);
        return !line.empty() && (line[0] == 'y' || line[0] == 'Y');
    }

    // Pause until user presses Enter (buffer must be clear)
    static void pressEnterToContinue()
    {
        cout << "\n"
             << Color::DIM << "  Press Enter to continue ..." << Color::RST;
        cin.get();
    }
};

// ═══════════════════════════════════════════════════════════════
//   UI  –  Display helpers & box drawing
// ═══════════════════════════════════════════════════════════════
class UI
{
public:
    static const int BOX_W = 55; // inner box width (without borders)

    // Full-width banner for each screen
    static void printBanner(const string &icon, const string &title,
                            const string &color = Color::BBLUE)
    {
        cout << "\n"
             << color;
        cout << "  ╔═══════════════════════════════════════════════════════╗\n";
        printBannerLine(icon + "  " + title, color);
        cout << "  ╚═══════════════════════════════════════════════════════╝\n"
             << Color::RST << "\n";
    }

    static void printBannerWithSub(const string &icon, const string &title,
                                   const string &sub,
                                   const string &color = Color::BBLUE)
    {
        cout << "\n"
             << color;
        cout << "  ╔═══════════════════════════════════════════════════════╗\n";
        printBannerLine(icon + "  " + title, color);
        printBannerLine(sub, color);
        cout << "  ╚═══════════════════════════════════════════════════════╝\n"
             << Color::RST << "\n";
    }

    static void printSuccess(const string &msg)
    {
        cout << "\n"
             << Color::BGREEN << "  ✓  " << msg << Color::RST << "\n";
    }

    static void printError(const string &msg)
    {
        cout << "\n"
             << Color::BRED << "  ✗  " << msg << Color::RST << "\n";
    }

    static void printWarning(const string &msg)
    {
        cout << "\n"
             << Color::BYELLOW << "  ⚠  " << msg << Color::RST << "\n";
    }

    static void printMenuOption(int num, const string &label)
    {
        cout << Color::CYAN << "    ◆  "
             << Color::BYELLOW << "[" << num << "]  "
             << Color::BWHITE << label
             << Color::RST << "\n";
    }

    static void printMenuLogout(int num, const string &label)
    {
        cout << Color::DIM << "    ─  "
             << Color::YELLOW << "[" << num << "]  "
             << Color::RST << label << "\n";
    }

    static void printAccessDenied()
    {
        cout << "\n"
             << Color::BRED;
        cout << "  ╔══════════════════════════════════════════╗\n";
        cout << "  ║         ACCESS DENIED                    ║\n";
        cout << "  ║  You don't have permission to do this.   ║\n";
        cout << "  ║  Please contact your administrator.      ║\n";
        cout << "  ╚══════════════════════════════════════════╝\n"
             << Color::RST << "\n";
    }

    // Horizontal divider line
    static void hline(const string &color = Color::DIM)
    {
        cout << color << "  "
             << string(57, '-') << Color::RST << "\n";
    }

    // Section label inside a screen
    static void sectionLabel(const string &label)
    {
        int dashes = max(0, 51 - (int)label.size());
        string line = "";
        for (int i = 0; i < dashes; ++i)
            line += "-";
        cout << "\n"
             << Color::BCYAN << "  -- " << label << " "
             << line << Color::RST << "\n\n";
    }

    // ── Table helpers ────────────────────────────────────────────
    //  Client table  cols: AccNum(16) Pin(10) Name(30) Phone(14) Balance(12)
    static void clientTableTop()
    {
        cout << Color::DIM
             << "  ┌──────────────────┬────────────┬────────────────────────────────┬────────────────┬──────────────┐\n"
             << Color::RST;
    }
    static void clientTableHeader()
    {
        clientTableTop();
        cout << Color::DIM << "  │" << Color::RST
             << Color::BOLD << " " << left << setw(18) << "Account No." << Color::RST
             << Color::DIM << "│" << Color::RST
             << Color::BOLD << " " << left << setw(10) << "Pin Code" << Color::RST
             << Color::DIM << "│" << Color::RST
             << Color::BOLD << " " << left << setw(30) << "Client Name" << Color::RST
             << Color::DIM << "│" << Color::RST
             << Color::BOLD << " " << left << setw(14) << "Phone" << Color::RST
             << Color::DIM << "│" << Color::RST
             << Color::BOLD << " " << left << setw(12) << "Balance" << Color::RST
             << Color::DIM << "│\n"
             << "  ├──────────────────┼────────────┼────────────────────────────────┼────────────────┼──────────────┤\n"
             << Color::RST;
    }
    static void clientTableBottom()
    {
        cout << Color::DIM
             << "  └──────────────────┴────────────┴────────────────────────────────┴────────────────┴──────────────┘\n"
             << Color::RST;
    }

    //  Balance table  cols: AccNum(16) Name(30) Balance(12)
    static void balanceTableHeader()
    {
        cout << Color::DIM
             << "  ┌──────────────────┬────────────────────────────────┬──────────────┐\n"
             << Color::RST;
        cout << Color::DIM << "  │" << Color::RST
             << Color::BOLD << " " << left << setw(18) << "Account No." << Color::RST
             << Color::DIM << "│" << Color::RST
             << Color::BOLD << " " << left << setw(30) << "Client Name" << Color::RST
             << Color::DIM << "│" << Color::RST
             << Color::BOLD << " " << left << setw(12) << "Balance" << Color::RST
             << Color::DIM << "│\n"
             << "  ├──────────────────┼────────────────────────────────┼──────────────┤\n"
             << Color::RST;
    }
    static void balanceTableBottom()
    {
        cout << Color::DIM
             << "  └──────────────────┴────────────────────────────────┴──────────────┘\n"
             << Color::RST;
    }

    //  User table  cols: Username(16) Password(16) Permissions(10)
    static void userTableHeader()
    {
        cout << Color::DIM
             << "  ┌──────────────────┬──────────────────┬────────────┐\n"
             << Color::RST;
        cout << Color::DIM << "  │" << Color::RST
             << Color::BOLD << " " << left << setw(18) << "Username" << Color::RST
             << Color::DIM << "│" << Color::RST
             << Color::BOLD << " " << left << setw(16) << "Password" << Color::RST
             << Color::DIM << "│" << Color::RST
             << Color::BOLD << " " << left << setw(10) << "Permissions" << Color::RST
             << Color::DIM << "│\n"
             << "  ├──────────────────┼──────────────────┼────────────┤\n"
             << Color::RST;
    }
    static void userTableBottom()
    {
        cout << Color::DIM
             << "  └──────────────────┴──────────────────┴────────────┘\n"
             << Color::RST;
    }

private:
    static void printBannerLine(const string &text, const string &color)
    {
        int pad = (BOX_W - (int)text.size()) / 2;
        int rpad = BOX_W - (int)text.size() - pad;
        cout << color << "  ║ " << string(pad, ' ')
             << text << string(max(0, rpad), ' ')
             << " ║\n";
    }
};

// ═══════════════════════════════════════════════════════════════
//   Permissions enum
// ═══════════════════════════════════════════════════════════════
enum class Permission : int
{
    All = -1,
    None = 0,
    ListClients = 1,
    AddClient = 2,
    DeleteClient = 4,
    UpdateClient = 8,
    FindClient = 16,
    Transactions = 32,
    ManageUsers = 64
};

// ═══════════════════════════════════════════════════════════════
//   BankClient  –  data model + file operations
// ═══════════════════════════════════════════════════════════════
class BankClient
{
public:
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double balance;
    bool markedForDelete;

    static const string FILE_NAME;
    static const string SEP;

    BankClient() : balance(0.0), markedForDelete(false) {}

    BankClient(string accNum, string pin, string nm,
               string ph, double bal)
        : accountNumber(move(accNum)), pinCode(move(pin)),
          name(move(nm)), phone(move(ph)),
          balance(bal), markedForDelete(false) {}

    // ── Serialisation ────────────────────────────────────────────
    string toFileLine() const
    {
        return accountNumber + SEP + pinCode + SEP +
               name + SEP + phone + SEP +
               Util::formatAmount(balance);
    }

    static BankClient fromFileLine(const string &line)
    {
        vector<string> v = Util::split(line, SEP);
        if (v.size() < 5)
            throw runtime_error("Malformed client record: " + line);
        BankClient c;
        c.accountNumber = Util::trim(v[0]);
        c.pinCode = Util::trim(v[1]);
        c.name = Util::trim(v[2]);
        c.phone = Util::trim(v[3]);
        c.balance = stod(Util::trim(v[4]));
        return c;
    }

    // ── Display ──────────────────────────────────────────────────
    void printCard() const
    {
        cout << "\n"
             << Color::BCYAN
             << "  ┌────────────────────────────────────────────┐\n"
             << "  │            CLIENT DETAILS                  │\n"
             << "  ├────────────────────────────────────────────┤\n"
             << Color::RST;
        printRow("Account No.", Color::BWHITE + accountNumber + Color::RST);
        printRow("Pin Code", pinCode);
        printRow("Full Name", name);
        printRow("Phone", phone);
        printRow("Balance", Color::BGREEN + Util::formatAmount(balance) + Color::RST);
        cout << Color::BCYAN
             << "  └────────────────────────────────────────────┘\n"
             << Color::RST;
    }

    void printTableRow() const
    {
        cout << Color::DIM << "  │" << Color::RST
             << " " << Color::CYAN << left << setw(18)
             << Util::truncate(accountNumber, 18) << Color::RST
             << Color::DIM << "│" << Color::RST
             << " " << left << setw(10) << Util::truncate(pinCode, 10)
             << Color::DIM << "│" << Color::RST
             << " " << left << setw(30) << Util::truncate(name, 30)
             << Color::DIM << "│" << Color::RST
             << " " << left << setw(14) << Util::truncate(phone, 14)
             << Color::DIM << "│" << Color::RST
             << " " << Color::BGREEN << left << setw(12)
             << Util::formatAmount(balance) << Color::RST
             << Color::DIM << "│" << Color::RST << "\n";
    }

    void printBalanceRow() const
    {
        cout << Color::DIM << "  │" << Color::RST
             << " " << Color::CYAN << left << setw(18)
             << Util::truncate(accountNumber, 18) << Color::RST
             << Color::DIM << "│" << Color::RST
             << " " << left << setw(30) << Util::truncate(name, 30)
             << Color::DIM << "│" << Color::RST
             << " " << Color::BGREEN << left << setw(12)
             << Util::formatAmount(balance) << Color::RST
             << Color::DIM << "│" << Color::RST << "\n";
    }

    // ── File Operations (static) ─────────────────────────────────
    static vector<BankClient> loadAll()
    {
        vector<BankClient> clients;
        ifstream file(FILE_NAME);
        if (!file.is_open())
            return clients;
        string line;
        while (getline(file, line))
        {
            line = Util::trim(line);
            if (!line.empty())
            {
                try
                {
                    clients.push_back(fromFileLine(line));
                }
                catch (...)
                { /* skip malformed lines */
                }
            }
        }
        return clients;
    }

    static void saveAll(const vector<BankClient> &clients)
    {
        ofstream file(FILE_NAME, ios::trunc);
        for (const auto &c : clients)
            if (!c.markedForDelete)
                file << c.toFileLine() << "\n";
    }

    static void appendToFile(const BankClient &client)
    {
        ofstream file(FILE_NAME, ios::app);
        file << client.toFileLine() << "\n";
    }

    static bool existsByAccountNumber(const string &accNum)
    {
        ifstream file(FILE_NAME);
        if (!file.is_open())
            return false;
        string line;
        while (getline(file, line))
        {
            line = Util::trim(line);
            if (!line.empty())
            {
                try
                {
                    BankClient c = fromFileLine(line);
                    if (c.accountNumber == accNum)
                        return true;
                }
                catch (...)
                {
                }
            }
        }
        return false;
    }

    static BankClient *findByAccountNumber(vector<BankClient> &clients,
                                           const string &accNum)
    {
        for (auto &c : clients)
            if (c.accountNumber == accNum)
                return &c;
        return nullptr;
    }

    // ── Input ────────────────────────────────────────────────────
    static BankClient readNew()
    {
        BankClient c;
        c.accountNumber = Util::readLine(Color::BYELLOW + "    Account Number  : " + Color::RST);
        while (c.accountNumber.empty() ||
               existsByAccountNumber(c.accountNumber))
        {
            if (c.accountNumber.empty())
                UI::printError("Account number cannot be empty.");
            else
                UI::printError("Account [" + c.accountNumber + "] already exists.");
            c.accountNumber = Util::readLine(Color::BYELLOW + "    Account Number  : " + Color::RST);
        }
        c.pinCode = Util::readLine(Color::BYELLOW + "    Pin Code         : " + Color::RST);
        c.name = Util::readLine(Color::BYELLOW + "    Full Name         : " + Color::RST);
        c.phone = Util::readLine(Color::BYELLOW + "    Phone             : " + Color::RST);
        c.balance = Util::readDouble(Color::BYELLOW + "    Initial Balance   : " + Color::RST);
        return c;
    }

    static BankClient readUpdated(const string &accNum)
    {
        BankClient c;
        c.accountNumber = accNum;
        c.pinCode = Util::readLine(Color::BYELLOW + "    New Pin Code       : " + Color::RST);
        c.name = Util::readLine(Color::BYELLOW + "    New Full Name       : " + Color::RST);
        c.phone = Util::readLine(Color::BYELLOW + "    New Phone           : " + Color::RST);
        c.balance = Util::readDouble(Color::BYELLOW + "    New Balance         : " + Color::RST);
        return c;
    }

private:
    void printRow(const string &label, const string &val) const
    {
        cout << Color::BCYAN << "  │ " << Color::RST
             << Color::BOLD << left << setw(14) << label << ": " << Color::RST
             << val << "\n";
    }
};

const string BankClient::FILE_NAME = "Clients.txt";
const string BankClient::SEP = "#//#";

// ═══════════════════════════════════════════════════════════════
//   User  –  data model + file operations
// ═══════════════════════════════════════════════════════════════
class User
{
public:
    string username;
    string password;
    int permissions;
    bool markedForDelete;

    static const string FILE_NAME;
    static const string SEP;
    static const string ADMIN_USERNAME;

    User() : permissions(0), markedForDelete(false) {}

    // ── Access Check ─────────────────────────────────────────────
    bool hasPermission(Permission perm) const
    {
        if (permissions == (int)Permission::All)
            return true;
        return (permissions & (int)perm) == (int)perm;
    }

    // ── Serialisation ────────────────────────────────────────────
    string toFileLine() const
    {
        return username + SEP + password + SEP + to_string(permissions);
    }

    static User fromFileLine(const string &line)
    {
        vector<string> v = Util::split(line, SEP);
        if (v.size() < 3)
            throw runtime_error("Malformed user record");
        User u;
        u.username = Util::trim(v[0]);
        u.password = Util::trim(v[1]);
        u.permissions = stoi(Util::trim(v[2]));
        return u;
    }

    // ── Display ──────────────────────────────────────────────────
    void printCard() const
    {
        cout << "\n"
             << Color::BMAGENTA
             << "  ┌────────────────────────────────────────────┐\n"
             << "  │              USER DETAILS                  │\n"
             << "  ├────────────────────────────────────────────┤\n"
             << Color::RST;
        printRow("Username", Color::BWHITE + username + Color::RST);
        printRow("Password", string(password.size(), '*'));
        printRow("Permissions", to_string(permissions) +
                                    (permissions == -1 ? "  (Full Access)" : ""));
        cout << Color::BMAGENTA
             << "  └────────────────────────────────────────────┘\n"
             << Color::RST;
    }

    void printTableRow() const
    {
        cout << Color::DIM << "  │" << Color::RST
             << " " << Color::MAGENTA << left << setw(18)
             << Util::truncate(username, 18) << Color::RST
             << Color::DIM << "│" << Color::RST
             << " " << left << setw(16)
             << string(min((int)password.size(), 16), '*')
             << Color::DIM << "│" << Color::RST
             << " " << Color::BYELLOW << left << setw(10)
             << permissions << Color::RST
             << Color::DIM << "│" << Color::RST << "\n";
    }

    // ── File Operations (static) ─────────────────────────────────
    static vector<User> loadAll()
    {
        vector<User> users;
        ifstream file(FILE_NAME);
        if (!file.is_open())
            return users;
        string line;
        while (getline(file, line))
        {
            line = Util::trim(line);
            if (!line.empty())
            {
                try
                {
                    users.push_back(fromFileLine(line));
                }
                catch (...)
                {
                }
            }
        }
        return users;
    }

    static void saveAll(const vector<User> &users)
    {
        ofstream file(FILE_NAME, ios::trunc);
        for (const auto &u : users)
            if (!u.markedForDelete)
                file << u.toFileLine() << "\n";
    }

    static void appendToFile(const User &user)
    {
        ofstream file(FILE_NAME, ios::app);
        file << user.toFileLine() << "\n";
    }

    static bool existsByUsername(const string &uname)
    {
        ifstream file(FILE_NAME);
        if (!file.is_open())
            return false;
        string line;
        while (getline(file, line))
        {
            line = Util::trim(line);
            if (!line.empty())
            {
                try
                {
                    User u = fromFileLine(line);
                    if (u.username == uname)
                        return true;
                }
                catch (...)
                {
                }
            }
        }
        return false;
    }

    static User *findByUsername(vector<User> &users,
                                const string &uname)
    {
        for (auto &u : users)
            if (u.username == uname)
                return &u;
        return nullptr;
    }

    static bool authenticate(const string &uname,
                             const string &pass, User &out)
    {
        vector<User> users = loadAll();
        for (const auto &u : users)
        {
            if (u.username == uname && u.password == pass)
            {
                out = u;
                return true;
            }
        }
        return false;
    }

    // ── Input ────────────────────────────────────────────────────
    static int readPermissions()
    {
        cout << "\n"
             << Color::BOLD << "  Permission Setup\n"
             << Color::RST;
        UI::hline();
        if (Util::readYesNo(Color::BYELLOW + "    Grant FULL ACCESS? (y/n): " + Color::RST))
            return (int)Permission::All;

        int perms = 0;
        struct Entry
        {
            Permission p;
            const char *label;
        };
        static const Entry entries[] = {
            {Permission::ListClients, "List Clients   "},
            {Permission::AddClient, "Add New Client "},
            {Permission::DeleteClient, "Delete Client  "},
            {Permission::UpdateClient, "Update Client  "},
            {Permission::FindClient, "Find Client    "},
            {Permission::Transactions, "Transactions   "},
            {Permission::ManageUsers, "Manage Users   "}};
        for (const auto &e : entries)
        {
            if (Util::readYesNo("    Allow [" + string(e.label) + "]? (y/n): "))
                perms |= (int)e.p;
        }
        return perms;
    }

    static User readNew()
    {
        User u;
        u.username = Util::readLine(Color::BYELLOW + "    Username  : " + Color::RST);
        while (u.username.empty() || existsByUsername(u.username))
        {
            if (u.username.empty())
                UI::printError("Username cannot be empty.");
            else
                UI::printError("User [" + u.username + "] already exists.");
            u.username = Util::readLine(Color::BYELLOW + "    Username  : " + Color::RST);
        }
        u.password = Util::readLine(Color::BYELLOW + "    Password  : " + Color::RST);
        u.permissions = readPermissions();
        return u;
    }

    static User readUpdated(const string &uname)
    {
        User u;
        u.username = uname;
        u.password = Util::readLine(Color::BYELLOW + "    New Password  : " + Color::RST);
        u.permissions = readPermissions();
        return u;
    }

private:
    void printRow(const string &label, const string &val) const
    {
        cout << Color::BMAGENTA << "  │ " << Color::RST
             << Color::BOLD << left << setw(14) << label << ": " << Color::RST
             << val << "\n";
    }
};

const string User::FILE_NAME = "Users.txt";
const string User::SEP = "#//#";
const string User::ADMIN_USERNAME = "Admin";

// ═══════════════════════════════════════════════════════════════
//   BankApplication  –  main controller & UI logic
// ═══════════════════════════════════════════════════════════════
class BankApplication
{
private:
    User currentUser;

    // ── Access guard ─────────────────────────────────────────────
    bool checkPerm(Permission p) const { return currentUser.hasPermission(p); }

    bool guardPerm(Permission p)
    {
        if (!checkPerm(p))
        {
            UI::printAccessDenied();
            Util::pressEnterToContinue();
            return false;
        }
        return true;
    }

    // ════════════════════════════════════════════════════════════
    //   LOGIN
    // ════════════════════════════════════════════════════════════
    void doLogin()
    {
        bool failed = false;
        while (true)
        {
            Util::clearScreen();
            cout << "\n\n";
            cout << Color::BBLUE
                 << "  ╔═══════════════════════════════════════════════════════╗\n"
                 << "  ║                                                       ║\n"
                 << "  ║         ██████   █████  ███    ██ ██   ██             ║\n"
                 << "  ║         ██   ██ ██   ██ ████   ██ ██  ██              ║\n"
                 << "  ║         ██████  ███████ ██ ██  ██ █████               ║\n"
                 << "  ║         ██   ██ ██   ██ ██  ██ ██ ██  ██              ║\n"
                 << "  ║         ██████  ██   ██ ██   ████ ██   ██             ║\n"
                 << "  ║                                                       ║\n"
                 << "  ║              B A N K I N G   S Y S T E M             ║\n"
                 << "  ║                       v 2.0                           ║\n"
                 << "  ╚═══════════════════════════════════════════════════════╝\n"
                 << Color::RST << "\n";

            if (failed)
                UI::printError("Invalid username or password. Please try again.");

            cout << Color::BCYAN
                 << "  ┌─── Secure Login ──────────────────────────────────────┐\n"
                 << Color::RST;
            string uname = Util::readLine(Color::BYELLOW + "  │  Username : " + Color::RST);
            string pass = Util::readLine(Color::BYELLOW + "  │  Password : " + Color::RST);
            cout << Color::BCYAN
                 << "  └───────────────────────────────────────────────────────┘\n"
                 << Color::RST;

            if (User::authenticate(uname, pass, currentUser))
                break;
            failed = true;
        }
    }

    // ════════════════════════════════════════════════════════════
    //   MAIN MENU  – returns false on logout
    // ════════════════════════════════════════════════════════════
    bool doMainMenu()
    {
        Util::clearScreen();
        UI::printBannerWithSub("", "  BANKING SYSTEM  -  Main Menu",
                               "  Welcome, " + currentUser.username,
                               Color::BBLUE);

        UI::printMenuOption(1, "Show Client List");
        UI::printMenuOption(2, "Add New Client");
        UI::printMenuOption(3, "Delete Client");
        UI::printMenuOption(4, "Update Client Info");
        UI::printMenuOption(5, "Find Client");
        UI::printMenuOption(6, "Transactions");
        UI::printMenuOption(7, "Manage Users");
        cout << "\n";
        UI::printMenuLogout(8, "Logout");
        cout << "\n";

        int ch = Util::readInt(Color::BYELLOW + "  ▶  Choice [1-8]: " + Color::RST, 1, 8);
        switch (ch)
        {
        case 1:
            screenClientList();
            break;
        case 2:
            screenAddClient();
            break;
        case 3:
            screenDeleteClient();
            break;
        case 4:
            screenUpdateClient();
            break;
        case 5:
            screenFindClient();
            break;
        case 6:
            doTransactionsMenu();
            break;
        case 7:
            doManageUsersMenu();
            break;
        case 8:
            return false; // logout
        }
        return true;
    }

    // ════════════════════════════════════════════════════════════
    //   TRANSACTIONS MENU
    // ════════════════════════════════════════════════════════════
    void doTransactionsMenu()
    {
        if (!guardPerm(Permission::Transactions))
            return;
        while (true)
        {
            Util::clearScreen();
            UI::printBanner("", "  Transactions Menu", Color::BGREEN);
            UI::printMenuOption(1, "Deposit");
            UI::printMenuOption(2, "Withdraw");
            UI::printMenuOption(3, "Total Balances Report");
            cout << "\n";
            UI::printMenuLogout(4, "Back to Main Menu");
            cout << "\n";

            int ch = Util::readInt(Color::BYELLOW + "  ▶  Choice [1-4]: " + Color::RST, 1, 4);
            if (ch == 4)
                break;
            switch (ch)
            {
            case 1:
                screenDeposit();
                break;
            case 2:
                screenWithdraw();
                break;
            case 3:
                screenTotalBalances();
                break;
            }
        }
    }

    // ════════════════════════════════════════════════════════════
    //   MANAGE USERS MENU
    // ════════════════════════════════════════════════════════════
    void doManageUsersMenu()
    {
        if (!guardPerm(Permission::ManageUsers))
            return;
        while (true)
        {
            Util::clearScreen();
            UI::printBanner("", "  Manage Users Menu", Color::BYELLOW);
            UI::printMenuOption(1, "List Users");
            UI::printMenuOption(2, "Add New User");
            UI::printMenuOption(3, "Delete User");
            UI::printMenuOption(4, "Update User");
            UI::printMenuOption(5, "Find User");
            cout << "\n";
            UI::printMenuLogout(6, "Back to Main Menu");
            cout << "\n";

            int ch = Util::readInt(Color::BYELLOW + "  ▶  Choice [1-6]: " + Color::RST, 1, 6);
            if (ch == 6)
                break;
            switch (ch)
            {
            case 1:
                screenUserList();
                break;
            case 2:
                screenAddUser();
                break;
            case 3:
                screenDeleteUser();
                break;
            case 4:
                screenUpdateUser();
                break;
            case 5:
                screenFindUser();
                break;
            }
        }
    }

    // ════════════════════════════════════════════════════════════
    //   CLIENT SCREENS
    // ════════════════════════════════════════════════════════════

    // ── List Clients ─────────────────────────────────────────────
    void screenClientList()
    {
        if (!guardPerm(Permission::ListClients))
            return;
        Util::clearScreen();
        auto clients = BankClient::loadAll();
        UI::printBannerWithSub("", "  Client List",
                               "  " + to_string(clients.size()) + " client(s) registered",
                               Color::BCYAN);

        UI::clientTableHeader();
        if (clients.empty())
        {
            cout << Color::DIM << "\n  (No clients in the system)\n\n"
                 << Color::RST;
        }
        else
        {
            for (const auto &c : clients)
                c.printTableRow();
        }
        UI::clientTableBottom();
        Util::pressEnterToContinue();
    }

    // ── Add Clients ───────────────────────────────────────────────
    void screenAddClient()
    {
        if (!guardPerm(Permission::AddClient))
            return;
        Util::clearScreen();
        UI::printBanner("", "  Add New Client", Color::BGREEN);
        do
        {
            UI::sectionLabel("Enter Client Information");
            BankClient c = BankClient::readNew();
            BankClient::appendToFile(c);
            UI::printSuccess("Client [" + c.accountNumber + "] added successfully!");
        } while (Util::readYesNo(Color::BYELLOW + "\n  Add another client? (y/n): " + Color::RST));
        Util::pressEnterToContinue();
    }

    // ── Delete Client ─────────────────────────────────────────────
    void screenDeleteClient()
    {
        if (!guardPerm(Permission::DeleteClient))
            return;
        Util::clearScreen();
        UI::printBanner("", "  Delete Client", Color::BRED);

        string accNum = Util::readLine(Color::BYELLOW + "  Enter Account Number: " + Color::RST);
        auto clients = BankClient::loadAll();
        BankClient *c = BankClient::findByAccountNumber(clients, accNum);

        if (!c)
        {
            UI::printError("No client found with account [" + accNum + "].");
        }
        else
        {
            c->printCard();
            if (Util::readYesNo(Color::BYELLOW +
                                "\n  Permanently DELETE this client? (y/n): " + Color::RST))
            {
                c->markedForDelete = true;
                BankClient::saveAll(clients);
                UI::printSuccess("Client deleted successfully.");
            }
            else
            {
                UI::printWarning("Delete operation cancelled.");
            }
        }
        Util::pressEnterToContinue();
    }

    // ── Update Client ─────────────────────────────────────────────
    void screenUpdateClient()
    {
        if (!guardPerm(Permission::UpdateClient))
            return;
        Util::clearScreen();
        UI::printBanner("", "  Update Client Info", Color::BYELLOW);

        string accNum = Util::readLine(Color::BYELLOW + "  Enter Account Number: " + Color::RST);
        auto clients = BankClient::loadAll();
        BankClient *c = BankClient::findByAccountNumber(clients, accNum);

        if (!c)
        {
            UI::printError("No client found with account [" + accNum + "].");
        }
        else
        {
            c->printCard();
            if (Util::readYesNo(Color::BYELLOW +
                                "\n  Update this client's information? (y/n): " + Color::RST))
            {
                UI::sectionLabel("Enter New Information");
                *c = BankClient::readUpdated(accNum);
                BankClient::saveAll(clients);
                UI::printSuccess("Client updated successfully.");
            }
            else
            {
                UI::printWarning("Update operation cancelled.");
            }
        }
        Util::pressEnterToContinue();
    }

    // ── Find Client ───────────────────────────────────────────────
    void screenFindClient()
    {
        if (!guardPerm(Permission::FindClient))
            return;
        Util::clearScreen();
        UI::printBanner("", "  Find Client", Color::BCYAN);

        string accNum = Util::readLine(Color::BYELLOW + "  Enter Account Number: " + Color::RST);
        auto clients = BankClient::loadAll();
        BankClient *c = BankClient::findByAccountNumber(clients, accNum);

        if (!c)
            UI::printError("No client found with account [" + accNum + "].");
        else
            c->printCard();

        Util::pressEnterToContinue();
    }

    // ════════════════════════════════════════════════════════════
    //   TRANSACTION SCREENS
    // ════════════════════════════════════════════════════════════

    // ── Helper: look up client, retry on not-found ────────────────
    BankClient *lookupClient(vector<BankClient> &clients)
    {
        string accNum = Util::readLine(Color::BYELLOW + "  Enter Account Number: " + Color::RST);
        BankClient *c = BankClient::findByAccountNumber(clients, accNum);
        while (!c)
        {
            UI::printError("Account [" + accNum + "] not found.");
            accNum = Util::readLine(Color::BYELLOW + "  Enter Account Number: " + Color::RST);
            c = BankClient::findByAccountNumber(clients, accNum);
        }
        return c;
    }

    // ── Deposit ───────────────────────────────────────────────────
    void screenDeposit()
    {
        Util::clearScreen();
        UI::printBanner("", "  Deposit", Color::BGREEN);

        auto clients = BankClient::loadAll();
        BankClient *c = lookupClient(clients);
        c->printCard();

        double amount = Util::readDouble(Color::BYELLOW + "\n  Deposit amount: " + Color::RST);
        if (Util::readYesNo(Color::BYELLOW + "  Confirm deposit of " +
                            Util::formatAmount(amount) + "? (y/n): " + Color::RST))
        {
            c->balance += amount;
            BankClient::saveAll(clients);
            UI::printSuccess("Deposit successful!  New balance: " +
                             Util::formatAmount(c->balance));
        }
        else
        {
            UI::printWarning("Transaction cancelled.");
        }
        Util::pressEnterToContinue();
    }

    // ── Withdraw ──────────────────────────────────────────────────
    void screenWithdraw()
    {
        Util::clearScreen();
        UI::printBanner("", "  Withdraw", Color::BRED);

        auto clients = BankClient::loadAll();
        BankClient *c = lookupClient(clients);
        c->printCard();

        double amount = Util::readDouble(Color::BYELLOW + "\n  Withdraw amount: " + Color::RST);
        while (amount > c->balance)
        {
            UI::printError("Amount exceeds balance. Available: " +
                           Util::formatAmount(c->balance));
            amount = Util::readDouble(Color::BYELLOW + "  Enter amount: " + Color::RST);
        }
        if (Util::readYesNo(Color::BYELLOW + "  Confirm withdrawal of " +
                            Util::formatAmount(amount) + "? (y/n): " + Color::RST))
        {
            c->balance -= amount;
            BankClient::saveAll(clients);
            UI::printSuccess("Withdrawal successful!  New balance: " +
                             Util::formatAmount(c->balance));
        }
        else
        {
            UI::printWarning("Transaction cancelled.");
        }
        Util::pressEnterToContinue();
    }

    // ── Total Balances ────────────────────────────────────────────
    void screenTotalBalances()
    {
        Util::clearScreen();
        auto clients = BankClient::loadAll();
        UI::printBannerWithSub("", "  Total Balances Report",
                               "  " + to_string(clients.size()) + " client(s)",
                               Color::BGREEN);

        UI::balanceTableHeader();
        double total = 0;
        if (clients.empty())
        {
            cout << Color::DIM << "\n  (No clients in the system)\n\n"
                 << Color::RST;
        }
        else
        {
            for (const auto &c : clients)
            {
                c.printBalanceRow();
                total += c.balance;
            }
        }
        UI::balanceTableBottom();
        cout << "\n  " << Color::BOLD << "Total Balances: "
             << Color::BGREEN << Util::formatAmount(total)
             << Color::RST << "\n\n";
        Util::pressEnterToContinue();
    }

    // ════════════════════════════════════════════════════════════
    //   USER MANAGEMENT SCREENS
    // ════════════════════════════════════════════════════════════

    // ── List Users ────────────────────────────────────────────────
    void screenUserList()
    {
        Util::clearScreen();
        auto users = User::loadAll();
        UI::printBannerWithSub("", "  User List",
                               "  " + to_string(users.size()) + " user(s) registered",
                               Color::BYELLOW);

        UI::userTableHeader();
        if (users.empty())
        {
            cout << Color::DIM << "\n  (No users in the system)\n\n"
                 << Color::RST;
        }
        else
        {
            for (const auto &u : users)
                u.printTableRow();
        }
        UI::userTableBottom();
        Util::pressEnterToContinue();
    }

    // ── Add Users ─────────────────────────────────────────────────
    void screenAddUser()
    {
        Util::clearScreen();
        UI::printBanner("", "  Add New User", Color::BGREEN);
        do
        {
            UI::sectionLabel("Enter User Information");
            User u = User::readNew();
            User::appendToFile(u);
            UI::printSuccess("User [" + u.username + "] added successfully!");
        } while (Util::readYesNo(Color::BYELLOW + "\n  Add another user? (y/n): " + Color::RST));
        Util::pressEnterToContinue();
    }

    // ── Delete User ───────────────────────────────────────────────
    void screenDeleteUser()
    {
        Util::clearScreen();
        UI::printBanner("", "  Delete User", Color::BRED);

        string uname = Util::readLine(Color::BYELLOW + "  Enter Username: " + Color::RST);

        if (uname == User::ADMIN_USERNAME)
        {
            UI::printError("The Admin account cannot be deleted.");
            Util::pressEnterToContinue();
            return;
        }
        if (uname == currentUser.username)
        {
            UI::printError("You cannot delete your own account.");
            Util::pressEnterToContinue();
            return;
        }

        auto users = User::loadAll();
        User *u = User::findByUsername(users, uname);

        if (!u)
        {
            UI::printError("No user found with username [" + uname + "].");
        }
        else
        {
            u->printCard();
            if (Util::readYesNo(Color::BYELLOW +
                                "\n  Permanently DELETE this user? (y/n): " + Color::RST))
            {
                u->markedForDelete = true;
                User::saveAll(users);
                UI::printSuccess("User deleted successfully.");
            }
            else
            {
                UI::printWarning("Delete operation cancelled.");
            }
        }
        Util::pressEnterToContinue();
    }

    // ── Update User ───────────────────────────────────────────────
    void screenUpdateUser()
    {
        Util::clearScreen();
        UI::printBanner("", "  Update User", Color::BYELLOW);

        string uname = Util::readLine(Color::BYELLOW + "  Enter Username: " + Color::RST);
        auto users = User::loadAll();
        User *u = User::findByUsername(users, uname);

        if (!u)
        {
            UI::printError("No user found with username [" + uname + "].");
        }
        else
        {
            u->printCard();
            if (Util::readYesNo(Color::BYELLOW +
                                "\n  Update this user's information? (y/n): " + Color::RST))
            {
                UI::sectionLabel("Enter New Information");
                *u = User::readUpdated(uname);
                User::saveAll(users);
                UI::printSuccess("User updated successfully.");
            }
            else
            {
                UI::printWarning("Update operation cancelled.");
            }
        }
        Util::pressEnterToContinue();
    }

    // ── Find User ─────────────────────────────────────────────────
    void screenFindUser()
    {
        Util::clearScreen();
        UI::printBanner("", "  Find User", Color::BCYAN);

        string uname = Util::readLine(Color::BYELLOW + "  Enter Username: " + Color::RST);
        auto users = User::loadAll();
        User *u = User::findByUsername(users, uname);

        if (!u)
            UI::printError("No user found with username [" + uname + "].");
        else
            u->printCard();

        Util::pressEnterToContinue();
    }

public:
    // ════════════════════════════════════════════════════════════
    //   ENTRY POINT
    // ════════════════════════════════════════════════════════════
    void run()
    {
        while (true)
        { // outer loop: one iteration per session
            doLogin();
            while (doMainMenu())
                ; // inner loop: one iteration per menu action
            // show goodbye on logout
            Util::clearScreen();
            cout << "\n\n"
                 << Color::BBLUE
                 << "  ╔═══════════════════════════════════════════════════════╗\n"
                 << "  ║                                                       ║\n"
                 << "  ║     You have been logged out successfully.            ║\n"
                 << "  ║     Thank you for using the Banking System!           ║\n"
                 << "  ║                                                       ║\n"
                 << "  ╚═══════════════════════════════════════════════════════╝\n"
                 << Color::RST << "\n\n";
        }
    }
};

// ═══════════════════════════════════════════════════════════════
//   main
// ═══════════════════════════════════════════════════════════════
int main()
{
    BankApplication app;
    app.run();
    return 0;
}