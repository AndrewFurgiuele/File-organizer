#ifndef FILEHANDLING_H
#define FILEHANDLING_H


void mp3File(struct dirent*, char*);
void mkvFile(struct dirent*, char* );
void pngFile(struct dirent* , char*);
void jpgFile(struct dirent* , char*);
void docxFile(struct dirent* , char*);
void txtFile(struct dirent* , char*);
void otherFile(struct dirent* , char*);


#endif