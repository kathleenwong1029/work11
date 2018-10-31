#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

int main(){
  struct stat stats;
  stat("stat.c", &stats);
  printf("file size:%ld\n", stats.st_size);
  printf("mode(permissions):%o\n", stats.st_mode);
  printf("last time of access:%s\n", ctime(&stats.st_atime));
  //Modify the size so it is printed out in human readable form
  size_t size = stats.st_size;
  char *str = malloc(256);
  int gb  = size / pow(1024,3);
  int mb = size / pow(1024,2);
  int kb = size / 1024;
  int b = size;
  sprintf(str, "file size: %dGB, %dMB, %dKB, %dB", gb, mb, kb, b);
  printf("%s\n", str);
  printf("mode(permissions): %o\n", stats.st_mode & 511); //511 in binary is 111111111

}
