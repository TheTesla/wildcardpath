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
  
    char resultPathListDelim[MAX_STR_LEN] = "";
    char wildPathListDelim[] = "/usr/lib/nvidia-???/xorg,/usr/lib/xorg/modules"; // sometimes comma separarted

    if(NULL != findPathListWildDelim(resultPathListDelim, wildPathListDelim, ',')) {
        printf("found = %s\n", resultPathListDelim);
    } else {
        printf("not found\n");
    }

    char foundDriver[MAX_STR_LEN];
    char wildDriver[] = "nvidia_???_drm";

    if(findDriverWild(foundDriver, wildDriver)) {
        printf("found = %s\n", foundDriver); 
    } else {
        printf("not found\n");
    }
    
    return 0;
}

