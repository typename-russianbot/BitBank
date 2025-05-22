#include "../../includes/account/account.h"

//~ @defgroup: Resources
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: Account(const string, const string)
Account::Account(const string user, const string key) : username(user), passkey(Hash(key)) { return; }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: Account(const Account&)
Account::Account(const Account &) { return; }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: ~Account(void)
Account::~Account(void) { return; }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//~ @defgroup: Functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: save(void)
bool Account::save(void)
{
    if (saveAccount() && saveTransactions())
        return true;

    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: load(const string)
bool Account::load(const string target)
{
    if (Load(target))
        return true;

    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: remove(const string)
bool Account::remove(const string target)
{
    if (Remove(target))
        return true;

    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: search(const string)
bool Account::search(const string target)
{
    if (Search(target))
        return true;

    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: fetch(void)
bool Account::fetch(void)
{

    filesystem::path downloads = filesystem::path(getenv("HOME")) / "Downloads/export.csv";
    cout << downloads << endl;

    filesystem::path cwd = filesystem::current_path() / "resources/.logs/export.csv";

    try
    {
        filesystem::rename(downloads, cwd);
        cout << "file moved" << endl;
        return true;
    }
    catch (const filesystem::filesystem_error &error)
    {
        cerr << "<error>=export_file_missing" << endl;
        return false;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: import(const ifstream&)
bool Account::import(ifstream &readfile)
{
    //! @note: file verification failed
    if (!Verify(readfile))
        return false;

    ofstream logs("resources/.logs/logs.csv");

    string line;
    int line_num = 0;
    while (getline(readfile, line))
    {
        if (line_num > 0)
        {
            //* @defgroup: data variables for parsing
            stringstream currentline(line);
            string s1, s2, s3, s4;
            double amount;
            Date date;

            //& @note: grabs transaction date
            getline(currentline, s1, ',');
            CleanString(s1);
            date.setDate(s1);

            //& @note: grabs & discards empty param
            getline(currentline, s2, ',');

            //& @note: grabs transaction description
            getline(currentline, s3, ',');
            CleanString(s3);
            CleanDescription(s3);

            //& @note: grabs transaction amount
            getline(currentline, s4, ',');
            CleanString(s4);
            if (s4.empty())
            {
                getline(currentline, s4, ',');
                CleanString(s4);
            }
            amount = stod(s4);

            //& @note: get transaction type
            if (amount < 0.0)
            {
                container.push_back(Transaction{Type::withdrawal, date, s3, amount});
                negative_balance += amount;
            }
            else
            {
                container.push_back(Transaction{Type::deposit, date, s3, amount});
                positive_balance += amount;
            }

            net_balance += amount;
        }

        line_num++;
    }
    cout << line_num << endl;
    cout << container.size() << endl;

    readfile.close();
    logs.close();
    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: list(void)
void Account::list(void)
{
    for (int i = 1; i < static_cast<int>(container.size()); i++)
    {
        cout << container[i] << endl;
    }

    return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//~ @defgroup: Sorting Methods
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: sortByNewest(void)
void Account::sortByNewest(void)
{
    for (size_t i = 1; i < container.size(); i++)
    {
        for (size_t j = 0; j < container.size(); j++)
        {

            if (container[i].getDate().year < container[j].getDate().year)
            {
                Transaction temp = container[i];
                container[i] = container[j];
                container[j] = temp;
            }
            else if (container[i].getDate().year == container[j].getDate().year && container[i].getDate().month < container[j].getDate().month)
            {
                Transaction temp = container[i];
                container[i] = container[j];
                container[j] = temp;
            }
            else if (container[i].getDate().year == container[j].getDate().year && container[i].getDate().month == container[j].getDate().month && container[i].getDate().day < container[j].getDate().day)
            {
                Transaction temp = container[i];
                container[i] = container[j];
                container[j] = temp;
            }
        }
    }
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: sortByOldest(void)
void Account::sortByOldest(void)
{
    for (size_t i = 0; i < container.size(); i++)
    {
        for (size_t j = 1; j < container.size(); j++)
        {

            if (container[i].getDate().year > container[j].getDate().year)
            {
                Transaction temp = container[i];
                container[i] = container[j];
                container[j] = temp;
            }
            else if (container[i].getDate().year == container[j].getDate().year && container[i].getDate().month > container[j].getDate().month)
            {
                Transaction temp = container[i];
                container[i] = container[j];
                container[j] = temp;
            }
            else if (container[i].getDate().year == container[j].getDate().year && container[i].getDate().month == container[j].getDate().month && container[i].getDate().day > container[j].getDate().day)
            {
                Transaction temp = container[i];
                container[i] = container[j];
                container[j] = temp;
            }
        }
    }
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//~ @defgroup: Mutators
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: setUsername(const string)
void Account::setUsername(const string nUser)
{
    this->username = nUser;
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: setPasskey(const string)
void Account::setPasskey(const string nKey)
{
    this->passkey = Hash(nKey);
    return;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//~ @defgroup: Accessors
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: getUsername(void)
const string Account::getUsername(void)
{
    return username;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: getPasskey(void)
const string Account::getPasskey(void)
{
    return passkey;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//~ @defgroup: Overloads
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: operator<<(ostream&, const Account&)
ostream &operator<<(ostream &out, const Account &account)
{
    out << "Username: " << account.username << endl
        << "+Balance: \t" << account.positive_balance << endl
        << "-Balance: \t" << account.negative_balance << endl
        << "Net Balance: \t" << account.net_balance << endl;

    return out;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//~ @defgroup: Protected Functions
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: saveAccount(void)
bool Account::saveAccount(void)
{
    ofstream tempfile("resources/.cache/.temp.csv"); //& @var: tempfile
    ifstream savefile("resources/.cache/.save.csv"); //& @var: savefile

    //& @note: file verification
    if (!Verify(savefile) || !Verify(tempfile))
        return false;

    //& @note: begin file parsing
    string current_line;
    while (getline(savefile, current_line))
    {
        //* @note: write currentline data if username != this line
        if (current_line.find(username + ",") == string::npos)
            tempfile << current_line << endl;
    }

    tempfile << username << "," << passkey << endl;
    rename("resources/.cache/.temp.csv", "resources/.cache/.save.csv");
    savefile.close();
    tempfile.close();

    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: saveTransactions(void)
bool Account::saveTransactions(void)
{
    ifstream tempfile("resources/.logs/export.csv");           //& @var: tempfile
    ofstream savefile("resources/.logs/" + username + ".csv"); //& @var: savefile

    //& @note: file verification
    if (!Verify(tempfile) || !Verify(savefile))
        return false;

    string current_line;
    while (getline(tempfile, current_line))
    {
        savefile << current_line << endl;
    }

    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: cache(void)
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: Load(const string)
bool Account::Load(const string target)
{
    //& @note: file verification
    ifstream savefile("resources/.cache/.save.csv");

    if (!Verify(savefile))
        return false;
    else if (!Search(target))
        return false;

    //& @note: file parsing
    string line;
    while (getline(savefile, line))
    {
        stringstream row(line);
        string name, key;

        //* @note: loading hit
        if (getline(row, name, ',') && target == name && getline(row, key))
        {
            ofstream cachefile("resources/.cache/.cache.csv");
            cachefile << name << "," << key << endl;
            ifstream logfile("resources/.logs/" + username + ".csv");
            import(logfile);

            savefile.close();
            cachefile.close();
            logfile.close();
            return true;
        }
    }

    //! @note: loading miss
    savefile.close();
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: Remove(const string)
bool Account::Remove(const string target)
{
    //& @note: file verification
    ofstream tempfile("resources/.cache/.temp.csv");
    ifstream savefile("resources/.cache/.save.csv");
    if (!Verify(savefile) || !Verify(tempfile))
        return false;

    //& @note: begin file parsing
    string current_line;
    while (getline(savefile, current_line))
    {
        if (current_line.find(target + ",") == string::npos)
            tempfile << current_line << endl;
    }

    savefile.close();
    tempfile.close();
    rename("resources/.cache/.temp.csv", "resources/.cache/.save.csv");

    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: Search(const string)
bool Account::Search(const string target)
{
    //& @note: file verification
    ifstream savefile("resources/.cache/.save.csv");
    if (!Verify(savefile))
        return false;

    //& @note: file parsing
    string line;
    while (getline(savefile, line))
    {
        stringstream row(line);
        string name;

        //* @note: search hit
        if (getline(row, name, ',') && target == name)
        {
            savefile.close();
            return true;
        }
    }

    //! @note: search miss
    savefile.close();
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
