#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

void
generateDir(const char* dirName, unsigned int mode)
{
  if (-1 == mkdir(dirName, mode))
  {
    printf("ERROR --> generateDir(): can't create %s, errno: %d", dirName, errno);
    exit(EXIT_FAILURE);
  } 
}

void
generateFile(const char* fileName, const char* mode, const char* text)
{
  FILE *file = fopen(fileName, mode);
  if (NULL == file) 
  {
    printf("ERROR --> generateFile(): can't create %s, errno: %d", fileName, errno);
    exit(EXIT_FAILURE);
  }

  fprintf(file, text);

  if (EOF == fclose(file)) 
  {
    printf("ERROR --> generateFile(): can't close %s, errno: %d", fileName, errno);
    exit(EXIT_FAILURE);
  }
}

int
main(int argc, char** argv)
{
  const char* projectName = "Mitra";
  const char* projectDesc = "A project generator";

  generateDir("src", 0755);
  generateFile("src/main.c", "w", "int\n\
main(int argc, char** argv)\n\
{\n\
  return 0;\n\
}\n");

  generateFile("README.md", "w", "# %s\n%s", projectName, projectDesc);


  //generateFile("project.sh", "w", "");
  //generateFile(".gitignore", "w", "");
  return 0;
}

  //char* fileName = "src/main.c";
  //char* mode = "w";
  //FILE *file = fopen(fileName, mode);
  //if (NULL == file) 
  //{
  //  printf("ERROR --> generateFile(): can't create %s, errno: %d", fileName, errno);
  //  exit(EXIT_FAILURE);
  //}

//  fprintf(file, 
//          "int\n\
//main(int argc, char** argv)\n\
//{\n\
//  return 0;\n\
//}\n");
//
//  if (EOF == fclose(file)) 
//  {
//    printf("ERROR --> generateFile(): can't close %s, errno: %d", fileName, errno);
//    exit(EXIT_FAILURE);
//  }



