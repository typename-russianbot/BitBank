#include "../../includes/data/data.h"

//^ @defgroup: Resources
//////////////////////////////////////////////////////////////////////////////
//* @public: Report(ifstream&)
Report::Report(ifstream &readfile)
{
    //! @note: file verification failed
    if (!Verify(readfile))
        return;

    string line;
    int line_num = 0;
    while (getline(readfile, line))
    {
        if (line_num == 0)
            readfile.ignore();

        //* @defgroup: data variables for parsing
        stringstream currentline(line);
        string s1, s2, s3, s4;
        double amount;
        Date date;

        //& @note: grabs transaction date
        getline(currentline, s1, ',');
        CleanString(s1);
        date.setDate(s1);

        //& @note: grabs & discards empty param
        getline(currentline, s2, ',');

        //& @note: grabs transaction description
        getline(currentline, s3, ',');
        CleanString(s3);
        CleanDescription(s3);

        //& @note: grabs transaction amount
        getline(currentline, s4, ',');
        CleanString(s4);
        if (s4.empty())
        {
            getline(currentline, s4, ',');
            CleanString(s4);
        }
        amount = stod(s4);

        //& @note: get transaction type
        if (amount < 0.0)
        {
            container.push_back(Transaction{Type::withdrawal, date, s3, amount});
        }
        else
        {
            container.push_back(Transaction{Type::deposit, date, s3, amount});
        }

        net_balance += amount;

        line_num++;
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

//^ @defgroup: Functions || Displaying/Listing Functions go here
//////////////////////////////////////////////////////////////////////////////
//* @public: list(void)
//* @def: 

void Report::list(void)
{
    for (int i = 0; i < static_cast<int>(container.size()); i++)
    {
        cout << container[i] << endl;
    }
}
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//* @public: sort(void)
//* @def:
//////////////////////////////////////////////////////////////////////////////

//^ @defgroup: Overloads
//////////////////////////////////////////////////////////////////////////////
//* @public: operator=
//* @def: '=' overload
//////////////////////////////////////////////////////////////////////////////