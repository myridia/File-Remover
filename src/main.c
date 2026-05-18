#include "curl_list.h"
#include "filelist.h"
#include "list_diff.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> // For stat() or lstat()
#include <unistd.h>   // For chdir() or realpath()

int main(int argc, char *argv[]) {
  char *folder_path = "";
  printf("... start main fun \n");

  for (int i = 0; i < argc; i++) {
    if (strncmp(argv[i], "-p", 2) == 0) {
      // printf("  %b\n", strncmp(argv[i], base, 2));
      if (argv[i + 1]) {
        // folder_path = sanitize_string(argv[i + 1]);
        folder_path = argv[i + 1];
      }
    }
  }

  const int capacity = 1000000;
  int counter1 = 0;
  int c1 = 0;
  char *list1[capacity];

  if (folder_path != "") {
    printf("main %s\n", folder_path);
    c1 = filelist(folder_path, list1, capacity, counter1);
    printf("list1:  %d\n", c1);
  }

  // *******************************************************************
  // Get list2

  const char *url = "http://sapir.salamander-jewelry.net/picture_path/name";
  size_t c2;
  char **list2 = curl_list(url, &c2);
  printf("list2:  %d \n", c2);
  // for (size_t i = 0; i < counter; i++) {
  //   printf("%s\n", list2[i]);
  //  }

  // *******************************************************************
  // Get the second list

  // *******************************************************************

  const char *a[] = {"apple", "banana", "cherry", "date"};
  const char *b[] = {"banana", "date", "fig"};
  size_t count;
  // const char **diff = find_missing(a, 4, b, 3, &count);
  const char **diff =
      find_missing((const char **)list1, c1, (const char **)list2, c2, &count);
  // printf("diff:  %d\n", count);

  // const char **diff = find_missing(list2, c2, list1, c1, &count);
  // for (size_t i = 0; i < count; i++) {
  //  printf("%s\n", diff[i]);
  //}
}
