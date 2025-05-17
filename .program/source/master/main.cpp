#include "../../includes/account/account.h"

//& @fn: usage(void)
void usage(void)
{
    cout << "usage implementation required" << endl;
    return;
}

//& @fn: driver(int, char**)
int driver(int argc, char **argv)
{
    //~ OBJECTS
    Account account;

    //~ FUNCTIONS
    if (argc == 1)
        usage();

    string name;
    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];

        if (arg == "-v" || arg == "--version")
            cout << _version << endl;

        else if (arg == "-h" || arg == "--help")
            usage();

        else if (arg == "-s" || arg == "save")
        {
        }

        else if (arg == "-l" || arg == "--load")
        {
            string username;
            if (argv[i + 1])
                username = argv[i + 1];

            account.load(username);
            cout << account << endl;
        }
    }

    return 0;
}

//& @fn: main(void)
int main(int argc, char *argv[])
{
    // // //* @def: BitBank
    // cout << "Welcome to BitBank!" << endl;

    // Transaction data;

    // Account t;
    // t.load("999");

    // cout << t << endl;

    // return 0;

    return driver(argc, argv); 
}