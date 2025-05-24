#include "../../includes/master/master.h"

//& @def: Structures
////////////////////////////////////////////////////////////////////////////
//^ @struct: termios
struct termios TerminalVisible, TerminalHidden;
////////////////////////////////////////////////////////////////////////////

//& @defgroup: Overloads
////////////////////////////////////////////////////////////////////////////
//^ @public: operator<<
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

//& @defgroup: Functions
////////////////////////////////////////////////////////////////////////////
bool Verify(const ofstream &file) //^ @fn: Verify(const ofstream&)
{
    if (file.is_open())
        return true;

    return false;
}
bool Verify(const ifstream &file) //^ @fn: Verify(const ifstream&)
{
    if (file.is_open())
        return true;

    return false;
}
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
void show(void) //^ @fn: show(void)
{
    tcsetattr(STDIN_FILENO, TCSANOW, &TerminalVisible);
    cout << endl;
}
void hide(void) //^ @fn: hide(void)
{
    tcgetattr(STDIN_FILENO, &TerminalVisible);

    TerminalHidden = TerminalVisible;
    TerminalHidden.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &TerminalHidden);

    return;
}
////////////////////////////////////////////////////////////////////////////
