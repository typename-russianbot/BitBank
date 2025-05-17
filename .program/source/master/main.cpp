#include "../../includes/account/account.h"
#include "../../includes/data/transaction.h"

//& @fn: main(void)
int main(void)
{
    //* @def: BitBank
    cout << "Welcome to BitBank!" << endl;

    Transaction data;

    Account t; 
    t.load("mjh"); 
    
    cout << t << endl; 

    return 0;
}