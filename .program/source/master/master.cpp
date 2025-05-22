#include "../../includes/master/master.h"

//~ @def: Structures
////////////////////////////////////////////////////////////////////////////
//& @struct: termios
struct termios TerminalVisible, TerminalHidden;
////////////////////////////////////////////////////////////////////////////

//~ @defgroup: Functions

////////////////////////////////////////////////////////////////////////////
//* @public: CleanString(string&)
void CleanString(string &value)
{
    //& @def: removes the parenthesis around the original variables
    if (value.size() >= 2 && value.front() == '"' && value.back() == '"')
        value = value.substr(1, value.size() - 2);

    return;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//* @public: CleanDescription(string&)
void CleanDescription(string &desc)
{
    //& @def: find first
    size_t posA = desc.find_first_of("-");
    if (posA != string::npos)
        desc = desc.substr(posA + 2);

    size_t posB = desc.find_last_of("-");
    if (posB != string::npos)
        desc = desc.substr(0, posB + 1);

    return;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//* @public: SearchString(const string)
const Type SearchString(const string);
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//* @public: Hash()
const string Hash(const string text)
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
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//* @public: Verify(const ofstream&)
bool Verify(const ofstream &file)
{
    if (file.is_open())
        return true;

    return false;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//* @public: Verify(const ifstream&)
bool Verify(const ifstream &file)
{
    if (file.is_open())
        return true;

    return false;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//^ @fn: HideTerminal(void)
void HideTerminal(void)
{
    tcgetattr(STDIN_FILENO, &TerminalVisible);

    TerminalHidden = TerminalVisible;
    TerminalHidden.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &TerminalHidden);

    return;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//^ @fn: ShowTerminal(void)
void ShowTerminal(void)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &TerminalVisible);
    cout << endl;
}
////////////////////////////////////////////////////////////////////////////

//~ @defgroup: Overloads
////////////////////////////////////////////////////////////////////////////
//^ @public: operator(ostream&, const Type&)
ostream &operator<<(ostream &out, const Type &type)
{
    switch (type)
    {
    case deposit:
        out << "Deposit";
        break;

    case withdrawal:
        out << "Withdrawal";
        break;

    case food:
        out << "Food";
        break;

    case transportation:
        out << "Transportation";
        break;

    case subscription:
        out << "Subscription";
        break;

    case online:
        out << "Online";
        break;

    case healthcare:
        out << "Healthcare";
        break;

    case insurance:
        out << "Insurance";
        break;

    case groceries:
        out << "Groceries";
        break;

    default:
        out << "None";
        break;
    }

    return out;
}
////////////////////////////////////////////////////////////////////////////
