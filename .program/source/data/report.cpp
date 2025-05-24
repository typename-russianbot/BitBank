#include "../../includes/data/data.h"

//& @defgroup: Resources
//////////////////////////////////////////////////////////////////////////////
//* @public: Report(ifstream&)
Report::Report(ifstream &readfile)
{
    //! @note: file verification failed
    if (!Verify(readfile))
        return;

    string line;
    int n = 0;
    while (getline(readfile, line))
    {
        if (n > 0)
        {
            //* @defgroup: data variables for parsing
            stringstream currentline(line);
            string s1, s2, s3, s4;
            double amount;
            Date date;
            int year;

            //& @note: grabs transaction date
            getline(currentline, s1, ',');
            Trim(s1);
            date.setDate(s1);

            //& @note: grabs & discards empty param
            getline(currentline, s2, ',');

            //& @note: grabs transaction description
            getline(currentline, s3, ',');
            Trim(s3);
            CleanDescription(s3);

            //& @note: grabs transaction amount
            getline(currentline, s4, ',');
            Trim(s4);
            if (s4.empty())
            {
                getline(currentline, s4, ',');
                Trim(s4);
            }
            amount = stod(s4);

            //& @note: get transaction type
            if (amount < 0.0)
                container.push_back(Transaction{Type::withdrawal, date, s3, amount});
            else
                container.push_back(Transaction{Type::deposit, date, s3, amount});

            net_balance += amount;
        }
        n++;
    }

    readfile.close();
    return;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//* @public: ~Report(void)
Report::~Report(void)
{
    return;
}
//////////////////////////////////////////////////////////////////////////////

//& @defgroup: Functions || Displaying/Listing Functions go here
//////////////////////////////////////////////////////////////////////////////
//* @public: list(void)
void Report::list(void)
{
    return;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//* @public: sort(void)
//////////////////////////////////////////////////////////////////////////////

//& @defgroup: Helpers
//////////////////////////////////////////////////////////////////////////////
//^ @public: CleanString(string&)
void Report::Trim(string &t)
{
    //& @def: removes the parenthesis around the original variables
    if (t.size() >= 2 && t.front() == '"' && t.back() == '"')
        t = t.substr(1, t.size() - 2);

    return;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//^ @public: CleanDescription(string&)
void Report::CleanDescription(string &d)
{
    //& @def: find firstF
    size_t posA = d.find_first_of("-");
    if (posA != string::npos)
        d = d.substr(posA + 2);

    size_t posB = d.find_last_of("-");
    if (posB != string::npos)
        d = d.substr(0, posB + 1);

    return;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//^ @public: SearchDescription(string&)
const Type Report::SearchDescription(string &d)
{
    return Type::deposit;
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//^ @public:
//////////////////////////////////////////////////////////////////////////////