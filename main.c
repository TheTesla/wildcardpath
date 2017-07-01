/***********************************************************************

  Copyright (c) 2017 Stefan Helmert <stefan.helmert@t-online.de>

 ***********************************************************************/

#include "findpathwild.h"

int main(void) {
    char path[MAX_STR_LEN] = "";
    //char wild[] = "/usr/l??/nvidia-???/";
    //char wild[] = "/usr/???/nvidia-???";
    char wild[] = "/???/???/nvidia-???/";
    //char wild[] = "/usr/src/nvidia-???/";
    //char wild[] = "/usr/lib/nvidia-375/";
    //char wild[] = "/usr/lib/nvidia-475/";
    //char wild[] = "/usr/lib/nvidia-???/";


    printf("found = %s\n", findPathWild(path, wild));

    return 0;
}
