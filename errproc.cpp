#include "errproc.h"
#include <iostream>

void errproc::errOutExit(errno_t nError)
{
    std::cout << strerror(nError) << std::endl;
    exit(nError);
}