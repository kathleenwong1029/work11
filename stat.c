#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

int main(){
  int file = open("text.txt",O_CREAT, 0666);
  struct stat stats;
  stat("text.txt", &stats);
  printf("file size:%lld\n", stats.st_size);
  printf("mode(permissions):%o\n", stats.st_mode);
  printf("last time of access:%s\n", ctime(&stats.st_atime));
}
