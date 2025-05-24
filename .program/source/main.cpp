#include "../includes/data/data.h"

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
    //~ OBJECTS=

    //~ FUNCTIONS
    if (argc == 1)
        usage();

    for (int i = 1; i < argc; i++)
    {
        string arg = argv[i];

        //* @defgroup: General Functions
        //^ @fn: Program Version

        //^ @fn: Program Usage

        //^ @fn: save

        //^ @fn: load

        //^ @fn: delete

        //^ @fn: search

        //^ @fn: fetch

        //^ @fn: import

        //^ @fn: list

        //^ @fn: sort

        //^ @fn: edit
    }

    return 0;
}

//& @fn: main(void)
int main(int argc, char *argv[]) {
    // return driver(argc, argv);
};