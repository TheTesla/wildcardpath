/***********************************************************************

  Copyright (c) 2017 Stefan Helmert <stefan.helmert@t-online.de>

 ***********************************************************************/

#include "findpathwild.h"
#include "stdio.h"

int main(void)
{
    char resultPath[MAX_STR_LEN] = "";
    char wildPath[] = "/???/???/nvidia-???/";
    //char wildPath[] = "/not/existing/"; // produces NULL

    if(NULL != findPathWild(resultPath, wildPath)) {
        printf("found = %s\n", resultPath);
    } else {
        printf("not found\n");
    }
    
    char resultPathList[MAX_STR_LEN] = "";
    //char wildPathList[] = "/???/???/nvidia-???/:/???/???32/nvidia-???/";
    //char wildPathList[] = "/not/existing/:/also/not/existing/"; // produces empty list (=string)
    char wildPathList[] = "/???/???/nvidia-??/:/???/???/nvidia-???/:/???/???/nvidia-????/:/???/???32/nvidia-??/:/???/???32/nvidia-???/:/???/???32/nvidia-????/"; // idea: multiple alternatives

    if(NULL != findPathListWild(resultPathList, wildPathList)) {
        printf("found = %s\n", resultPathList);
    } else {
        printf("not found\n");
    }
    
    return 0;
}

