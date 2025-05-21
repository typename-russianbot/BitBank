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
        //~ @fn: Program Version
        if (arg == "-v" || arg == "--version")
            cout << _version << endl;
        //~ @fn: Program Usage
        else if (arg == "-h" || arg == "--help" || arg == "--usage")
            usage();

        //* @defgroup: Account Functions
        //~ @fn: Saving
        else if (arg == "-c" || arg == "--create")
        {
        }
        //~ @fn: Loading
        else if (arg == "-l" || arg == "--load")
        {
            string username;
            if (argv[i + 1])
                username = argv[i + 1];

            if (account.load(username))
                cout << "Account Loading Status: <success>" << endl;
            else
                cerr << "Account Loading Status: <error>" << endl;
        }
        //~ @fn: Deleting
        else if (arg == "-d" || arg == "--delete")
        {
            string target;
            if (argv[i + 1])
                target = argv[i + 1];

            if (account.remove(target))
                cout << "Account Removal Status: <success>" << endl;
            else
                cerr << "Account Removal Status: <error>" << endl;
        }

        //* @defgroup: BitBank Access Functions
    }

    return 0;
}

//& @fn: main(void)
int main(int argc, char *argv[])
{
    ifstream outfile("resources/.logs/export.csv");
    Account t;
    t.fetch();
    t.import(outfile);
    t.sortByNewest();
    t.list();

    // return driver(argc, argv);
}