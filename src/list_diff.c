#include "list_diff.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> // For stat() or lstat()
#include <unistd.h>   // For chdir() or realpath()

const char **find_missing(const char **list1, size_t n1, const char **list2,
                          size_t n2, size_t *out_count) {

  for (size_t i = 0; i < 4; i++) {
    printf("f: %s \n", list1[i]);
  }

  printf("n1: %d\n", n1);
  printf("n2: %d\n", n2);

  const char **result = malloc(n1 * sizeof(char *));
  size_t count = 0;

  // for (size_t i = 0; i < 111; i++) {
  // int found = 0;
  // printf("missing: %d \n", i);
  //     printf("missing: %s \n", list1[i]);

  /*
  for (size_t j = 0; j < n2; j++) {
    if (strcmp(list1[i], list2[j]) == 0) {
      found = 1;
      break;
    }
  }
  if (!found) {
    // printf("missing: %s\n", list1[i]);

    // result[count++] = list1[i];
    }*/
  //}
  *out_count = count;

  return result;
}
