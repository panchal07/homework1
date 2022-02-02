#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Creating structure keyword with two entities keyword and count
struct keyword
{
   char* keyword;
   int count;
};

int main(int argc, char** argv){
    int i;
    struct keyword* key = (struct keyword*) malloc(argc* sizeof(struct keyword));
    for(i = 0; i < argc-1; i++){
       key[i].keyword = argv[i+1];
       key[i].count = 0;
    }

    char *line=NULL;
    size_t maxlen=0;
    ssize_t n;

    /* read till end of file (type Control-D to stop)
    and compare the keywords with complete words*/
    while ((n = getline(&line, &maxlen, stdin)) > 0){
      char *breakLine = strtok(line, " ");
      while(breakLine != NULL){
        for (i=0; i<argc-1;i++){
          if(strcmp(breakLine, key[i].keyword)==0){
              key[i].count += 1;
          }
        }
        breakLine = strtok(NULL," ");
      }
      }
      //Displaying Table
     for(i=0; i<argc-1; i++){
       printf("word  Count\n");
       printf("%s     %d\n", key[i].keyword,key[i].count);
     }
     free(line);
}
