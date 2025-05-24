////////////////////////////////////////////////////////////////////////////
//~ @author: Mr. Yellow || Matthew J. Hong
//~ Program 'BitBank' is a bank/money manager with the goal of cutting
//~ out wasteful spending
////////////////////////////////////////////////////////////////////////////
#pragma once

//~ @def: Dependencies
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

//~ @def: Macros
#define _version "BitBank v1.0.0" //& @macro: _version no.

//~ @def: Enumerations
////////////////////////////////////////////////////////////////////////////
//? @enum: Type
enum Type
{
    deposit,
    withdrawal,
    retail,
    food,
    transportation,
    subscription,
    online,
    healthcare,
    insurance,
    groceries,
    none
};
////////////////////////////////////////////////////////////////////////////

//~ @def: Functions
////////////////////////////////////////////////////////////////////////////
//^ @public: CleanString(string&)
//^ @def:

void CleanString(string &);
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//^ @public: CleanDescription(string&)
//^ @def:

void CleanDescription(string &);
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//^ @public: SearchString(const string)
//^ @def:

const Type SearchString(const string);
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//^ @public: Verify(const ofstream&)
//^ @def:

bool Verify(const ofstream &);
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//^ @public: VerifyFile(const ifstream&)
//^ @def:

bool Verify(const ifstream &);
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//^ @public: ShowTerminal(void)
//^ @def: sets current terminal state to visible

void ShowTerminal(void);
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
//^ @public: HideTerminal(void)
//^ @def: sets current terminal state to hidden

void HideTerminal(void);
////////////////////////////////////////////////////////////////////////////

//~ @defgroup: Overloads
////////////////////////////////////////////////////////////////////////////
//^ @public: operator<<(ostream&, const Type&)
//^ @def: overload to display the transaction type

ostream &
operator<<(ostream &, const Type &);
////////////////////////////////////////////////////////////////////////////

//~ @defgroup: Sorting Methods
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//* @public: sortByNewest(void)
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// //^ @protected: saveTransactions(void)
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
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////