/***********************************************************************

  Copyright (c) 2017 Stefan Helmert <stefan.helmert@t-online.de>

 ***********************************************************************/


#define MAX_STR_LEN 512

char* getRootPath(char *rootPath, char *wildPath);
char* splitStr(char* str, char delim);
int cmpStrWild(char* inputStr, char* wildStr);
char* findPathWild(char* foundPath, char* wildPath);





