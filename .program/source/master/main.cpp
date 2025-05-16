#include "../../includes/master/master.h"

int main(void)
{
    cout << "Welcome to BitBank!" << endl;

    string password = "changeme";
    string password2 = "changeme";

    unsigned char hash[SHA256_DIGEST_LENGTH];
    unsigned char hash2[SHA256_DIGEST_LENGTH];

    SHA256((unsigned char *)password.c_str(), password.size(), hash);
    SHA256((unsigned char *)password2.c_str(), password2.size(), hash2);

    cout << hash << endl;

    ofstream savefile("resources/.cache/accounts.txt");
    if (savefile.is_open())
        cout << "file opened" << endl;
    else
        cerr << "file failed to open" << endl;

    stringstream ss;
    for (unsigned char c : hash)
    {
        ss << hex << setw(2) << setfill('x') << (int)c;
    }

    stringstream ss2;
    for (unsigned char c : hash2)
    {
        ss2 << hex << setw(2) << setfill('x') << (int)c;
    }
    string hashkey2 = ss2.str();

    string hashkey1 = ss.str();

    if (hashkey1 == hashkey2)
    {
        cout << hashkey1 << " == " << hashkey2 << endl;
        savefile << hashkey1 << endl;
    }
    savefile.close();

    return 0;
}