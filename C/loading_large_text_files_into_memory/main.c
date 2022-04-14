#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char** loadfile(char *filename, int *len);

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

