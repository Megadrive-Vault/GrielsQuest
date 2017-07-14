#include "../inc/include.h"




const static u8 *language_name [ ] =
{
    "English",
    "Espa�ol",
    "Italiano",
    "Fran�ais",
    "Catal�",
    "Suomi",
    "Galego",
    NULL
};



u8 *getLanguage ( u8 i )
{
    return (u8*) language_name[i];
}


u8 countLanguages ( )
{
    u8 inc = 0 ;

    while ( getLanguage(inc++) != NULL );

    return inc-1;
}

