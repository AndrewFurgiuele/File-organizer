#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>

#include "fileHandling.h"
#include "helperFunctions.h"




void handleFile(struct dirent* file, char* cwd){

	char* name = file -> d_name;

	
	//counting the number of periods in the file to assure it has an extension
	int i = 0;
	int numPeriods =0;
	for (i =0; i < strlen(name); i++){
		if(name[i] == '.'){
			numPeriods++;
		}	
	}
	
	//prevents working with files without extensions and also the ".." file
	if(strlen(name) > 2 && numPeriods > 0){	
		char* extension = getFileExtension(name);
		//printf("%s %s \n", name, extension);
			//handles the files according to the extension
			if(strcmp(extension, "mp3") == 0){
				//printf("%s\n", "mp3");
				mp3File(file, cwd);
			}
			else if(strcmp(extension, "mkv") == 0){
				//printf("%s\n", "mkv");
				mkvFile(file, cwd);
			}
			else if(strcmp(extension, "png") == 0){
				//printf("%s\n", "png");
				pngFile(file, cwd);
			}
			else if(strcmp(extension, "jpg") == 0){
				//printf("%s\n", "jpg");
				jpgFile(file, cwd);
			}
			else if(strcmp(extension, "docx") == 0){
				//printf("%s\n", "docx");
				docxFile(file, cwd);
			}
			else if(strcmp(extension, "txt") == 0){
				//printf("%s\n", "txt");
				txtFile(file,cwd );
			}
			else{
				//puts("other");
				otherFile(file, cwd);
			}	
	}
}


void organizer(char* cwd){
	//create the directories
  createDirs(cwd);
  
  //getting the directory and the current file

  
  
  DIR* fd = opendir(cwd);
  struct dirent* cur_file;


  while((cur_file = readdir(fd))){
	//handle all the files
	if(cur_file == NULL){
		puts("could not open input file");
	}
	
	
	handleFile(cur_file, cwd);
  }
  
  closedir(fd);
  
}



char* getFileExtension(char* fileName){
	//getting the file extension
	char *period = strrchr(fileName, '.');
	if(!period || period == fileName){
		return "Could not find filename";
	}else{
		return period +1;
	}	
	
}




void createDirs(char* cwd){
	//create all the directories with full permissions
	
	char workingMusic[1024];
	char workingMovies[1024];
	char workingShows[1024];
	char workingDocs[1024];
	char workingPics[1024];
	char workingOther[1024];
	
	strcpy(workingMusic,cwd);
	strcpy(workingMovies,cwd);
	strcpy(workingShows,cwd);
	strcpy(workingDocs,cwd);
	strcpy(workingPics,cwd);
	strcpy(workingOther,cwd);
	
	strcat(workingMusic, "/music");
	strcat(workingMovies, "/movies");
	strcat(workingShows, "/shows");
	strcat(workingDocs, "/documents");
	strcat(workingPics, "/pictures");
	strcat(workingOther, "/other");

		
	  mkdir(workingMusic, 0777); 
	  mkdir(workingMovies, 0777);
	  mkdir(workingShows, 0777);
	  mkdir(workingDocs, 0777);
	  mkdir(workingPics, 0777);
	  mkdir(workingOther, 0777);

  
  
  
}