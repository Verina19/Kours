#pragma once
#include <fstream>

#define TABLE_SIZE 200// TABLE_SIZE - размер хэш-таблицы
struct hashbase {
	char key1[TABLE_SIZE][401];
	char value[TABLE_SIZE][1001];
	char url_image[TABLE_SIZE][401];
};


int Find(hashbase* myhash, char* key);
void Openfile(hashbase* myhash, char* filename);
void Savefile(hashbase* myhash, char* filename);
int AddElement(hashbase* myhash, char* key, char* element, char* url);
void RemoveElement(hashbase* myhash, char* key, char* filename);
