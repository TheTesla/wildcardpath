# wildcardpath

This library allows you to specify paths with wildcard symbol '?' in it. It is originally designed for the bumblebee project with directories containing version name.

## Idea

You can specify a path like:

```
/usr/lib/nvidia-???/
```

or

```
/???/???/nidia-???/
```

which is (maybe) resolved to:

```
/usr/lib/nvidia-375/
```

The first match counts.

## Usage

This is a c program. You have to provide a char array to store the result string. The function returns ```NULL```, if no match is found.

```c
#include "findpathwild.h"
#include "stdio.h"

int main(void)
{
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
```

It can also handle lists of paths. Try te example below:
```
int main(void)
{
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

```


Please, like, fork, commit ;)
