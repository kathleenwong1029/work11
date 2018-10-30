#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

int main(){
  int file = open("text.txt",O_CREAT, 0666);
  struct stat stats;
  stat("text.txt", &stats);
  printf("file size:%lld\n", stats.st_size);
  printf("mode(permissions):%o\n", stats.st_mode);
  printf("last time of access:%s\n", ctime(&stats.st_atime));
  //Modify the size so it is printed out in human readable form
  size_t size = stats.st_size;
  char *str = malloc(256);
  int gb  = size / 1024;
  int mb = size / (int) pow(1024,3);
  int kb = size / (int) pow(1024,6);
  int b = size / (int) pow(1024,9);
  sprintf(str, "file size: %dGB, %dMB, %dKB, %dB", gb, mb, kb, b);
  printf("%s\n", str);

}
