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

int main(void) {
    char resultPath[MAX_STR_LEN] = "";
    char wildPath[] = "/???/???/nvidia-???/";
    
    if(NULL != findPathWild(resultPath, wild)) {
        printf("found = %s\n", resultPath);
    } else {
        printf("not found\n");
    }
    
    return 0;
}
```

Please, like, fork, commit ;)
