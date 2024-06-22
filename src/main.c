#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

void
generateDir(const char* dirName, unsigned int mode)
{
  if (mkdir(dirName, mode) == 0) 
  {
    printf("INFO --> Directory: %s created successfully\n", dirName);
  } 
  else 
  {
    printf("ERROR --> generateDir(): can't create %s, errno: %d", dirName, errno);
    exit(EXIT_FAILURE);
  }
}

void
generateFile(const char* fileName, const char* mode)
{
  if (fopen(fileName, mode)) 
  {
    printf("INFO --> File: %s created successfully\n", fileName);
  }
  else
  {
    printf("ERROR --> generateFile(): can't create %s, errno: %d", fileName, errno);
    exit(EXIT_FAILURE);
  }
}


int
main(int argc, char** argv)
{
  generateDir("src", 0755);
  generateFile("src/main.c", "w");

  generateFile("README.md", "w");
  generateFile("project.sh", "w");
  generateFile(".gitignore", "w");
  return 0;
}
