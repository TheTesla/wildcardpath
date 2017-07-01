#include <stdio.h>
#include <dirent.h>
#include <string.h>

char* getRootPath(char *rootPath, char *wildPath)
{
    char c;
    c = 1;
    unsigned pidxend = 0;
    for(int i=0; c && i < 512; i++){
      c = wildPath[i];
      rootPath[i] = c;
      if('/' == c){
        pidxend = i;
      }
      if('?' == c){
        rootPath[pidxend] = 0;
        return &wildPath[pidxend+1];
      }
    }
    return "";
}

char* splitStr(char* str, char delim)
{
    char c;
    c = 1;
    for(int i=0; c && i < 512; i++){
      c = str[i];
      if(delim == c){
        str[i] = 0;
        return &str[i+1];
      }

    }
    return "";
}

int cmpStrWild(char* inputStr, char* wildStr)
{
    char ci, cw;
    ci = 1;
    cw = 1;
    for(int i = 0; ci && cw; i++){
        ci = inputStr[i];
        cw = wildStr[i];
        if(ci == cw) continue;
        if('?' == cw) continue; 
        return 0;
    }
    if(0 == ci && 0 == cw) return 1;
    return 0;
} 

char* findPathWild(char* foundPath, char* wildPath)
{
    DIR *dir;
    struct dirent *ent;
    char found[512];
    char rootPath[512];
    char currentLabel[512];
    char* pathEnd;


    int cmpResult;


    if('/' == wildPath[strlen(wildPath) -1]){
        wildPath[strlen(wildPath) -1] = 0;
    }

    pathEnd = getRootPath(rootPath, wildPath);
    strcpy(currentLabel, pathEnd);    
    pathEnd = splitStr(currentLabel, '/');    
    // structur:   /root/Path / currentLabel / p?th/E?d/
    //           | rootPath   | currentLabel | pathEnd

    printf("wild = %s\n", wildPath);
    printf("foundPath = %s\n", foundPath);
    printf("rootPath = %s\n", rootPath);
    printf("currentLabel = %s\n", currentLabel);
    printf("pathEnd = %s\n", pathEnd);



    //if(0 == rootPath[0]){
        strcat(rootPath, "/");
    //}
    printf("opendir = %s\n", rootPath);
    if ((dir = opendir (rootPath)) != NULL) { // acceppt only if path exists 
        printf("pathEnd = %s\n", pathEnd);
        if(0 == currentLabel[0]) { // no currentLabel means end of path reached
            strcpy(foundPath, rootPath);
            printf("1. return: %s\n", foundPath);
            closedir (dir);
            return foundPath; // means the path is found in deepest recursion
        }
        while ((ent = readdir (dir)) != NULL) {  // go through all dirs in rootPath
            cmpResult = cmpStrWild(ent->d_name, currentLabel); // check if wildcard matches
            printf(" next: %s\n", ent->d_name);
            if(cmpResult) {  // found match - next recursion step, process inner directory wildcards
                strcpy(found, rootPath);
                //strcat(found, "/");
                strcat(found, ent->d_name);
                strcat(found, "/");
                strcat(found, pathEnd);
                printf(" found = %s\n", found);
                printf(" foundPath = %s\n", foundPath);
                if(findPathWild(foundPath, found)) {
                    //strcpy(foundPath, found);
                    printf("2. return: %s\n", foundPath);
                    closedir (dir);
                    return foundPath;
                }
            }
        }
        closedir (dir);
        return NULL;
    } else {
        perror ("");
        return NULL;
    }
}



int main(void) {
    DIR *dir;
    struct dirent *ent;
    char path[512] = "";
    //char wild[] = "/usr/l??/nvidia-???/";
    //char wild[] = "/usr/???/nvidia-???";
    char wild[] = "/???/???/nvidia-???/";
    //char wild[] = "/usr/src/nvidia-???/";
    //char wild[] = "/usr/lib/nvidia-375/";
    //char wild[] = "/usr/lib/nvidia-475/";
    //char wild[] = "/usr/lib/nvidia-???/";
    char* pend;
    char val[512];
    int x;
    //pend = getRootPath(path, wild); 
    //printf(path);
    //printf(pend);


    printf("found = %s\n", findPathWild(path, wild));

    /*
    if ((dir = opendir (path)) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
        
        //printf ("pend: %s\n", pend);
        //printf ("name: %s\n", ent->d_name);
        x = cmpStrWild(ent->d_name, pend);
        //printf("%d\n", x);
        if(x) printf("%s\n", ent->d_name);
        //if(NULL != val){
        //  printf("%s\n", val);
        //}
      }
      closedir (dir);
    } else {
      perror ("");
      return -1;
    }
*/
}
