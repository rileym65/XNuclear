#include <stdio.h>
#include <string.h>

char* CheckArgs(int argc, char** argv, char* look_for)
  {
    int i,length;
    length=strlen(look_for);
    i=1;
    while (i < argc)
      {
        if (strncmp(argv[i],look_for,length)==0)
          {
            i++;
            if (i<argc) return argv[i];
            else printf("error");
          }
        i++;
      }
    return (char*) NULL;
  }

