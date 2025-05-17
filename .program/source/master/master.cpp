#include "../../includes/master/master.h"

//~ @def: Functions
////////////////////////////////////////////////////////////////////////////
//^ @public: operator(ostream&, const Type&)
ostream &operator<<(ostream &out, const Type &type)
{
    switch (type)
    {
    case infusion:
        out << "Infusion";
        break;

    case withdrawal:
        out << "Withdrawal";
        break;

    default:
        out << "Null";
        break;
    }

    return out;
}
////////////////////////////////////////////////////////////////////////////