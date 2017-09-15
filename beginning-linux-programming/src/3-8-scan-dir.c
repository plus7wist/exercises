#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

void printdir(const char* dir, int depth) {
  DIR* dp;
  struct dirent *entry;
  struct stat statbuf;

  if ((dp = opendir(dir)) == NULL) {
    fprintf(stderr, "cannnot open directory: %s\n", dir);
    return ;
  }
  chdir(dir);
  while ((entry = readdir(dp)) != NULL) {
    const char* file_name = entry->d_name;
    lstat(file_name, &statbuf);
    if (S_ISDIR(statbuf.st_mode)) {
      const char* dir_name = file_name;
      // ignore . and ..
      if (strcmp(".", dir_name) == 0 ||
          strcmp("..", dir_name) == 0)
        continue;
      printf("%*s%s/\n", depth, " ", dir_name);
      printdir(dir_name, depth + 4);
    }
    else {
      printf("%*s%s\n", depth, " ", file_name);
    }
  }
  chdir("..");
  closedir(dp);
}

int main() {
  printdir(".", 0);
  return 0;
}
