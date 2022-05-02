#ifndef EM_VAL
#define EM_VAL

#include "string.h"

int emailAutomat[7][128];
void BuildAutomat()
{
    for(int sust = 0; sust < 7; sust++)
    {
        for(char a = 0; a < 127; a++)
        {
            switch(sust)
            {
                case 0:
                {
                    if((a >= 'a' && a <= 'z')||(a >= 'A' && a <= 'Z'))
                    {
                        emailAutomat[sust][a] = 1;
                    }
                    else
                    {
                        emailAutomat[sust][a] = 6;
                    }
                    break;
                }
                case 1:
                {
                    if(a == '.')
                    {
                        emailAutomat[sust][a] = 6;
                    }
                    else if(a == '@')
                    {
                        emailAutomat[sust][a] = 2;
                    }
                    else
                    {
                        emailAutomat[sust][a] = 1;
                    }
                    break;
                }
                case 2:
                {
                    if((a >= 'a' && a <= 'z')||(a >= 'A' && a <= 'Z')||(a >= '0' && a <= '9'))
                    {
                        emailAutomat[sust][a] = 3;
                    }
                    else
                    {
                        emailAutomat[sust][a] = 6;
                    }
                    break;
                }
                case 3:
                {
                    if((a >= 'a' && a <= 'z')||(a >= 'A' && a <= 'Z')||(a >= '0' && a <= '9'))
                    {
                        emailAutomat[sust][a] = 3;
                    }
                    else if(a == '.')
                    {
                        emailAutomat[sust][a] = 4;
                    }
                    else
                    {
                        emailAutomat[sust][a] = 6;
                    }
                    break;
                }
                case 4:
                {
                    if((a >= 'a' && a <= 'z')||(a >= 'A' && a <= 'Z'))
                    {
                        emailAutomat[sust][a] = 5;
                    }
                    else
                    {
                        emailAutomat[sust][a] = 6;
                    }
                    break;
                }
                case 5:
                {
                    if((a >= 'a' && a <= 'z')||(a >= 'A' && a <= 'Z'))
                    {
                        emailAutomat[sust][a] = 5;
                    }
                    else
                    {
                        emailAutomat[sust][a] = 6;
                    }
                    break;
                }
                case 6:
                {
                    emailAutomat[sust][a] = 6;
                    break;
                }

            }
        }
    }
}
bool validateEmail(String email)
{
    int cursust = 1;
    for(int i=0; i<email.Size(); i++)
    {
        cursust = emailAutomat[cursust][email[i]];   
    }
    return cursust == 5;
}
#endif