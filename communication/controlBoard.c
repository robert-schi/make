#include <stdio.h>

#include "controlBoard.h"

#include "myComm.h"

int setState(int a)
{
    switch(a)
    {
        case 0: myOff(); break;
        case 1: myOn(); break;
        default: fputs("Invalid state\n", stderr); return 1;
    }
    return 0;
}
