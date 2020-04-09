#include "header.h"
double stod(char s[10000])
{
    int i = 0, o = false, f = false;
    double sm = 0, d = 1;
    if (s[0] == '-')
    {
        o = true;
        i++;
    }
    if (s[0] == '\0' || s[0] == '\n')
        return 0;
    while (s[i] != '\0' && s[i] != '\n')
    {
        if (f)
            d *= 10;
        if (s[i] >= '0' && s[i] <= '9')
            sm = sm * 10 + (s[i] - '0');
        else if (s[i] == '.' && !f)
            f = true;
        else
            return err;

        if (sm >= maxEl / 100)
            return err;
        i++;
    }
    if (o == true)
        return -1 * sm / d;
    else
        return sm / d; 
}