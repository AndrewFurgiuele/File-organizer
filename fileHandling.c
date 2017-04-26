#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>


#include "fileHandling.h"


void mp3File(struct dirent* file, char* cwd){
	
	/*
	1) breaks the file into artist song and album
	2) gets current working directory (cwd)
	3) appends /music/ to the cwd
	4) creates a song directory for it if does not exist
	5) moves the file and renames the file Name
	*/
	

	
	
	char artist[100];
	char album[100];
	char song[100];
	
	char* nameOriginal = file -> d_name;

	char* name = malloc(strlen(nameOriginal));
	strcpy(name, nameOriginal);
	
	char *x = strtok(name,  "-");
	strcpy(artist, x);

	x = strtok(NULL, "-");
	strcpy(album, x);
	
	x = strtok(NULL, "-");
	strcpy(song,x);
	
	


	char working[1024];
	
	//strcpy(working, "./");
	//strcpy(working, cwd);

		DIR* fd = opendir(cwd);
	  struct dirent* cur_file;


	  while((cur_file = readdir(fd))){
		//handle all the files
		char* n = cur_file -> d_name;
		if(cur_file == NULL){
			puts("could not open input file");
		}
		if(n == "music"){
			strcpy(working, n);
		}
		
		//puts(n);
	  }
	  
	  closedir(fd);

	
	strcat(working,"/music/");
	strcat(working, artist);
	strcat(working,"/");
	

	
	
	
	if(mkdir(working, 0777) == -1){	
		if(errno == EEXIST){
		//	puts("directory exists");
		}else{
		//	printf("%s\n", strerror(errno));
		}
	
	}
	
	
	
	strcat(working, album);
	strcat(working, "/");
	
	if(mkdir(working, 0777) == -1){	
		if(errno == EEXIST){
		//	puts("directory exists");
		}else{
		//	printf("%s\n", strerror(errno));
		}
	}
	

	strcat(working, song);
	
	printf("%s\n", working);
	rename(nameOriginal,working);
	//perror("rename");

	
	
}
void mkvFile(struct dirent* file, char* cwd){
	
		/*
		1)counts the number of dashes to see if it is a show or movie
		2) breaks the file into year and title for movies and name season and title for show
		3) gets current working directory (cwd)
		4) appends /shows/ or /movies/ to the cwd
		5) creates the new directories
		6) moves the file and renames the file Name
		*/
	
	
		char* nameOriginal = file -> d_name;
		int i = 0;
		int numDashes=0;
		
		for(i =0; i < strlen(nameOriginal); i++){
			if(nameOriginal[i] == '-'){
				numDashes++;
			}
		}
		//printf("%s\n", nameOriginal);
		
		if(numDashes == 1){
			
			char year[100];
			char title[100];
			
			char* name = malloc(strlen(nameOriginal));
			strcpy(name, nameOriginal);
			
			char *x = strtok(name,"-");
			strcpy(year, x);
			
			x = strtok(NULL,"-");
			strcpy(title, x);
			
			char working[1024];
			strcpy(working, cwd);
			
			
		
			
			strcat(working, "/movies/");
			strcat(working, year);
			strcat(working,"/");

			if(mkdir(working, 0777) == -1){	
				if(errno == EEXIST){
					//puts("directory exists");
				}else{
					//printf("%s\n", strerror(errno));
					perror("mkdir");
				}
			}

			strcat(working, title);
			rename(nameOriginal, working);
	
		}
		else if(numDashes == 3){
			
			char tvSeries[100];
			char season[100];
			char title[100];
			
			char* name = malloc(strlen(nameOriginal));
			strcpy(name, nameOriginal);
			
			char *x = strtok(name, "-");
			strcpy(tvSeries, x);
			
			x = strtok(NULL, "-");
			strcpy(season, x);
			
			x = strtok(NULL, "-");
			strcpy(title,x);
			
			x = strtok(NULL, "-");
			strcat(title,"-");
			strcat(title, x);
			
			
			char working[1024];
			strcpy(working, cwd);

			strcat(working, "/shows/");
			strcat(working, tvSeries);
			strcat(working, "/");
			
			if(mkdir(working, 0777) == -1){	
				if(errno == EEXIST){
					//puts("directory exists");
				}else{
					//printf("%s\n", strerror(errno));
				}
			}
			
			strcat(working, season);
			strcat(working, "/");
			
			
			if(mkdir(working, 0777) == -1){	
				if(errno == EEXIST){
					//puts("directory exists");
				}else{
					//printf("%s\n", strerror(errno));
				}
			}
			
			strcat(working, title);
			
			rename(nameOriginal, working);
			
			
		}else{
			puts("mkv file is not a show or movie");
		}
		
		
		
	
	
	
}
void pngFile(struct dirent* file, char* cwd){
	
		/*
		1) get the current directory
		2) get the file name
		3) move file
		*/
	
	
	char working[1024];
	char nameFull[1024];
	
	char* name = file -> d_name;
	
	
	strcpy(working, cwd);
	
	strcat(working,"/pictures/");
	strcat(working, name);
	
	
	rename(name,working);
}
void jpgFile(struct dirent* file, char* cwd){
		/*
		1) get the current directory
		2) get the file name
		3) move file
		*/
	
	char working[1024];
	char nameFull[1024];
	
	char* name = file -> d_name;
	
		strcpy(working, cwd);
	
	strcat(working,"/pictures/");
	strcat(working, name);
	
	
	rename(name,working);
}
void docxFile(struct dirent* file, char* cwd){
		/*
		1) get the current directory
		2) get the file name
		3) move file
		*/
	
	char working[1024];
	char nameFull[1024];
	
	char* name = file -> d_name;
	
	
	
	strcpy(working, cwd);

	
	strcat(working,"/documents/");
	strcat(working, name);
	
	
	rename(name,working);

	
	 
	 
}
void txtFile(struct dirent* file, char* cwd){
	char working[1024];
	char nameFull[1024];
	
	char* name = file -> d_name;
	

	
	
	 strcpy(working, cwd);

	
	strcat(working,"/documents/");
	strcat(working, name);

	
	rename(name,working);
}
void otherFile(struct dirent* file, char* cwd){
		/*
		1) get the current directory
		2) get the file name
		3) move file
		*/
	
	char working[1024];
	char nameFull[1024];
	
	char* name = file -> d_name;
	

	strcpy(working, cwd);
	
	strcat(working,"/other/");
	strcat(working, name);
	
	
	rename(name,working);
}





