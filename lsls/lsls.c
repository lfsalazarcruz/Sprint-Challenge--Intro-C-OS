#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <libgen.h>

/**
 * Main
 */
int main(int argc, char **argv)
{
  // Parse command line
  DIR *dir;
  struct dirent *dp;

  // Open directory
  for (int i = 0; i < argc; i++) {
    if (argc == 1) {
      dir = opendir(".");
    } else if (argc > 1) {
      dir = opendir(argv[1]);
    }
  }

  // Repeatly read and print entries
while ((dp = readdir (dir)) != NULL) {
  printf("%s \n", dp->d_name);
}

  // Close directory
  closedir(dir);

  return 0;
}