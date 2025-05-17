#include "../../includes/account/account.h"
#include "../../includes/data/transaction.h"

//& @fn: main(void)
int main(void)
{
    //* @def: BitBank
    cout << "Welcome to BitBank!" << endl;

    Transaction data;
    cout << data << endl;

    Account t;

    if (t.search("mjh2001"))
        cout << "search hit" << endl;

    cout << t << endl;
    return 0;
}