#include "../../includes/account/account.h"

//& @defgroup: Resources
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
    //* @note: saved
    if (Save())
        return true;

    //! @note: failed to save
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: load(const string)
bool Account::load(const string target)
{
    //* @note: loaded
    if (Load(target))
        return true;

    //! @note: failed to load
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: remove(const string)
bool Account::remove(const string target)
{
    //* @note: removed
    if (Remove(target))
        return true;

    //! @note: failed to remove
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: search(const string)
bool Account::search(const string target)
{
    //* @note:target found
    if (Search(target))
        return true;

    //! @note: failed to find target
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TODO @public: fetch(void) || replace w/ something like update || should implement
//  bool Account::fetch(void)
//  {
//      //? should automatically download the file from a url
//      filesystem::path downloads = filesystem::path(getenv("HOME")) / "Downloads/export.csv";

//     filesystem::path cwd = filesystem::current_path() / "resources/.logs/export.csv";

//     try
//     {
//         filesystem::rename(downloads, cwd);
//         return true;
//     }
//     catch (const filesystem::filesystem_error &error)
//     {
//         cerr << "<error>=export_file_missing" << endl;
//         return false;
//     }
// }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//& @defgroup: Mutators
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

//& @defgroup: Accessors
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: getUsername(void)
const string Account::getUsername(void) const
{
    return username;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: getPasskey(void)
const string Account::getPasskey(void) const
{
    return passkey;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//& @defgroup: Overloads
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: operator<<
ostream &operator<<(ostream &out, const Account &account)
{
    out << "Username: " << account.username;

    return out;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//& @defgroup: Helpers
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: Save(void)
bool Account::Save(void)
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

            savefile.close();
            cachefile.close();
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
    ifstream savefile("resources/.cache/.save.csv");
    ifstream cachefile("resources/.cache/.cache.csv");
    ofstream tempfile("resources/.cache/.temp.csv");

    //& @note: file verification
    if (!Verify(savefile) || !Verify(cachefile))
        return false;

    //& @note: if cache file isnt empty, check for a
    if (!cachefile.eof())
    {
        string cache_line;
        getline(cachefile, cache_line);
        if (cache_line.find(target + ',') != string::npos)
        {
            ofstream tmp("resources/.cache/.tmp.csv");
            rename("resources/.cache/.tmp.csv", "resources/.cache/.cache.csv");
            tmp.close();
        }
    }

    //& @note: begin file parsing
    string current_line;
    while (getline(savefile, current_line))
    {
        if (current_line.find(target + ",") == string::npos)
            tempfile << current_line << endl;
    }

    //& @note: overwrite the file
    rename("resources/.cache/.temp.csv", "resources/.cache/.save.csv");

    //& @note: close both files
    savefile.close();
    cachefile.close();
    tempfile.close();

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

        //* @note: hit
        if (getline(row, name, ',') && target == name)
        {
            savefile.close();
            return true;
        }
    }

    //! @note: miss
    savefile.close();
    return false;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: Hash(const string)
const string Account::Hash(const string text)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char *)text.c_str(), text.size(), hash);

    stringstream toHash;
    for (unsigned char character : hash)
    {
        toHash << hex << setw(2) << setfill('x') << int(character);
    }

    return toHash.str();
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
