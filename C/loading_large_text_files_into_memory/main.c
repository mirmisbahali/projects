#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int STEPSIZE = 100;

char** loadfile(char *filename, int *length);

int main(int argc, char *argv[]) {
  if (argc == 1) {
    fprintf(stderr, "Must supply a filename to read\n");
    exit(1);
  }

  // Load file into data structure
  int length = 0;
  char **words = loadfile(argv[1], &length);
  if (!words) {
    fprintf(stderr, "Can't build data Structure\n");
    exit(1);
  }

  // Display the entire file
  for (int i = 0; i < length; i++) {
    printf("%s\n", words[i]);
  }
  printf("Done\n");
  return 0;
}

char** loadfile(char *filename, int *len) {
  FILE *f = fopen(filename, "r");
  
  if (!f) {
    fprintf(stderr, "Can't open %s for reading\n", filename);
    return NULL;
  }

  int arrlen = STEPSIZE;

  // Allocate space for arrlen char*
  char **lines = (char**)malloc(arrlen*sizeof(char *));

  char buf[1000];
  int i = 0;
  while(fgets(buf,1000, f)) {

    if (i == arrlen) {
      arrlen += STEPSIZE;
      char **newlines = realloc(lines, arrlen * sizeof(char*));
      if (!newlines) {
        fprintf(stderr, "Can't realloc\n");
        exit(1);
      }
      lines = newlines;
    }
    
    // Trim off newline char
    buf[strlen(buf)-1] = '\0';

    // Get length of buf
    int slen = strlen(buf);

    // Allocate space for the string
    char *str = (char *)malloc((slen + 1) * sizeof(char));

      // Copy string from buf to str
    strcpy(str, buf);

    // Attach str to data structure
    lines[i] = str;
    
    i++;
  }
  *len = i; // Set the length of the array of char *s
  return lines;
}