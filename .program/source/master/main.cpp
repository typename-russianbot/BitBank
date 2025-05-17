#include "../../includes/account/account.h"
#include "../../includes/data/transaction.h"

int main(void)
{
    //* @def: BitBank
    cout << "Welcome to BitBank!" << endl;

    Transaction data; 
    cout << data << endl; 

    Account t("mjh2001", "passkey");

    cout << t << endl;
    return 0;
}