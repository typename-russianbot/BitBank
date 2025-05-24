////////////////////////////////////////////////////////////////////////////
//& @author: Mr. Yellow || Matthew J. Hong
//& Program 'BitBank' is a bank/money manager with the goal of cutting
//& out wasteful spending
////////////////////////////////////////////////////////////////////////////

//& @def: Dependencies
#pragma once
#include <iostream>
#include <termios.h>
#include <fstream>
#include <time.h>
#include <sstream>
#include <stdio.h>
#include <curl/curl.h>
#include <termios.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <openssl/sha.h>
#include <filesystem>
#include <vector>
#include <unistd.h>
#include <algorithm>
using namespace std;

//&&& @notes: ofstream==write && ifstream==read

//& @def: Macros
#define _version "BitBank v1.0.0" //& @macro: _version no.

//& @def: Enumerations
////////////////////////////////////////////////////////////////////////////
enum Type //~ @enum: Type
{
    transportation,
    subscription,
    healthcare,
    withdrawal,
    insurance,
    groceries,
    deposit,
    retail,
    online,
    food,
    none
};
ostream &operator<<(ostream &, const Type &); //! @fn: operator<<
////////////////////////////////////////////////////////////////////////////

//& @def: Functions
////////////////////////////////////////////////////////////////////////////
bool Verify(const ofstream &); //^ @fn: Verify(const ofstream&)
bool Verify(const ifstream &); //^ @fn: Verify(const ifstream&)
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void show(void); //^ @fn: show(void) || @def: shows terminal input
void hide(void); //^ @fn: hide(void) || @def: hides terminal input

////////////////////////////////////////////////////////////////////////////

// void Account::sortByNewest(void)
// {
// for (size_t i = 1; i < container.size(); i++)
// {
//     for (size_t j = 0; j < container.size(); j++)
//     {

//         if (container[i].getDate().year < container[j].getDate().year)
//         {
//             Transaction temp = container[i];
//             container[i] = container[j];
//             container[j] = temp;
//         }
//         else if (container[i].getDate().year == container[j].getDate().year && container[i].getDate().month < container[j].getDate().month)
//         {
//             Transaction temp = container[i];
//             container[i] = container[j];
//             container[j] = temp;
//         }
//         else if (container[i].getDate().year == container[j].getDate().year && container[i].getDate().month == container[j].getDate().month && container[i].getDate().day < container[j].getDate().day)
//         {
//             Transaction temp = container[i];
//             container[i] = container[j];
//             container[j] = temp;
//         }
//     }
// }
//     return;
// }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: sortByOldest(void)
// void Account::sortByOldest(void)
// {
// for (size_t i = 0; i < container.size(); i++)
// {
//     for (size_t j = 1; j < container.size(); j++)
//     {

//         if (container[i].getDate().year > container[j].getDate().year)
//         {
//             Transaction temp = container[i];
//             container[i] = container[j];
//             container[j] = temp;
//         }
//         else if (container[i].getDate().year == container[j].getDate().year && container[i].getDate().month > container[j].getDate().month)
//         {
//             Transaction temp = container[i];
//             container[i] = container[j];
//             container[j] = temp;
//         }
//         else if (container[i].getDate().year == container[j].getDate().year && container[i].getDate().month == container[j].getDate().month && container[i].getDate().day > container[j].getDate().day)
//         {
//             Transaction temp = container[i];
//             container[i] = container[j];
//             container[j] = temp;
//         }
//     }
// }
//     return;
// }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//^ @protected: saveTransactions(void)
// bool Account::saveTransactions(void)
// {
//     // ifstream tempfile("resources/.logs/export.csv");           //& @var: tempfile
//     // ofstream savefile("resources/.logs/" + username + ".csv"); //& @var: savefile

//     // //& @note: file verification
//     // if (!Verify(tempfile) || !Verify(savefile))
//     //     return false;

//     // string current_line;
//     // while (getline(tempfile, current_line))
//     // {
//     //     savefile << current_line << endl;
//     // }

//     // return true;
// }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////