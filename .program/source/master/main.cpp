#include "../../includes/wrapper/wrapper.h"
#include "../../includes/data/date.h"

//& @fn: usage(void)
void usage(void)
{
    cout << "usage: ./run [operation]\n"
         << endl
         << "operations: " << endl;

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

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];

        //* @defgroup: General Functions
        //^ @fn: Program Version
        if (arg == "-v" || arg == "--version")
            cout << _version << endl;

        //^ @fn: Program Usage
        else if (arg == "-h" || arg == "--help" || arg == "--usage")
            usage();

        //* @defgroup: Account Functions
        //^ @fn: save
        else if (arg == "-c" || arg == "--create")
            break;

        //^ @fn: load
        else if (arg == "-l" || arg == "--load")
            break;

        //^ @fn: delete
        else if (arg == "-d" || arg == "--delete")
            break;

        //^ @fn: search
        else if (arg == "-s" || arg == "--search")
            break;

        //^ @fn: fetch
        else if (arg == "-f" || arg == "--fetch")
            break;

        //^ @fn: import
        else if (arg == "--import")
            break;

        //^ @fn: list
        else if (arg == "--list")
            break;

        //^ @fn: sort
        else if (arg == "--sort")
            break;

        //^ @fn: edit
        else if (arg == "--edit")
            break;
    }

    return 0;
}

//& @fn: main(void)
int main(int argc, char *argv[])
{
    // Account t;
    // if (t.save())
    // {
    //     cout << "account saved" << endl;
    // }

    // if (t.load("mjh2001"))
    //     cout << "account loaded" << endl;

    // cout << t << endl;

    // return driver(argc, argv);
}