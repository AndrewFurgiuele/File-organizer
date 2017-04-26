#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>


#include "fileHandling.h"


int main(int argc, char** argv){

//working directory
  char working[1024];
  if(argc == 1){
    //use current dir
    if(getcwd(working,sizeof(working)) != NULL){
      organizer(working);
    }else{
      puts("failure opening current working directory");
    }
}
  else if(argc == 2){
    //use argv
	strcpy(working, argv[1]);
    organizer(working);
  }else{
    //too many arguements
    puts("too many command line arguements");
	exit(1);
  }
  return 1;

}


