/***********************************************************************

  Copyright (c) 2017 Stefan Helmert <stefan.helmert@t-online.de>

 ***********************************************************************/

#include "findpathwild.h"
#include "stdio.h"

int main(void) {
    char resultPath[MAX_STR_LEN] = "";
    char wildPath[] = "/???/???/nvidia-???/";
    //char wildPath[] = "/not/existing/";

    if(NULL != findPathWild(resultPath, wildPath)) {
        printf("found = %s\n", resultPath);
    } else {
        printf("not found\n");
    }
    
    return 0;
}

