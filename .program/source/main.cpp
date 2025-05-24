#include "../includes/account/account.h"

//& @fn: test1
void test1(void)
{
    Account account("test_username", "test_hash");

    // if (account.save())
    //     cout << "saved: " << account.getUsername() << endl;

    // if (account.load("mjh2001"))
    //     cout << "loaded: " << account.getUsername() << endl;

    if (account.search(account.getUsername()))
    {
        account.remove(account.getUsername());
        cout << "removed: " << account.getUsername() << endl;
    }
}

void test2(void)
{
    ifstream xport("resources/.logs/export.csv");
    Report report(xport);
    report.list(); 
}

// //& @fn: driver(int, char**)
// int driver(int argc, char **argv)
// {
//     //~ OBJECTS=

//     //~ FUNCTIONS
//     if (argc == 1)
//         usage();

//     for (int i = 1; i < argc; i++)
//     {
//         string arg = argv[i];

//         //* @defgroup: General Functions
//         //^ @fn: Program Version

//         //^ @fn: Program Usage

//         //^ @fn: save

//         //^ @fn: load

//         //^ @fn: delete

//         //^ @fn: search

//         //^ @fn: fetch

//         //^ @fn: import

//         //^ @fn: list

//         //^ @fn: sort

//         //^ @fn: edit
//     }

//     return 0;
// }

//& @fn: main(void)
int main(int argc, char *argv[])
{

    test2();
    // test1();
};