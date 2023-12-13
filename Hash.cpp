#include "Hash.h"

FILE* file1;

// ������� ������ � ����
void Savefile(hashbase* myhash, char* filename) {
	if (!fopen_s(&file1, filename, "w")) { // ������ ���� � ����
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (strcmp(myhash->key1[i], "\0")) {// ���������� ������ ����������� ������ � ������� ����;��������
				fputs(myhash->key1[i], file1); // ������ ������ �����
				fputs(";", file1); // ��������� �����������
				fputs(myhash->value[i], file1); // ������ ������ ������
				fputs(";", file1); // ��������� �����������
				fputs(myhash->url_image[i], file1); // ������ ������ url
				fputs("\n", file1); // ��������� ����� ������
			}
		}
		fclose(file1);
	}
}

// ���-������� ��� ���������� ������� � ���-�������. 
// ��������� �������� ASCII-����� �������� ����� � ���������� ������� �� ������� �� ������ ���-�������
int hash1(char* key) {
	int hash_value = 0;
	for (int i = 0; key[i] != '\0'; i++) {
		hash_value += (unsigned char)key[i];
	}
	return hash_value % TABLE_SIZE;
}

// ���-������� ��� ���������� ������� � ���-�������. 
// ��������� �������� ASCII-����� �������� ����� � ���������� �������� ���, � ���������� ������� �� ������� �� ������ ���-�������
int hash2(int hash_value, char* key) {
	for (int i = 0; key[i] != '\0'; i++) {
		hash_value += (unsigned char)key[i];
	}
	return hash_value % (TABLE_SIZE - 1) + 1;
}

// ������� �������� ������� �������� � ����
int Find(hashbase* myhash, char* key) {
	int index = hash1(key);// ��������� ������ (���)
	if (!strcmp(myhash->key1[index], key)) {// ��������� ��� ������� ����� ����������� ������
		return index;
	}
	else {
		int count = 0;// ���� ������ ���� ������ ���������� �� ������ �����������
		while (1) {
			index = hash2(index, key);
			if (!strcmp(myhash->key1[index], key)) {// ��������� ��� ������� ����� ����������� ������
				return index;
			}
			count++;
			if (count > TABLE_SIZE) break;
		}
		return -1;
	}
}
// ������� ��������� ����� ������ � ���-�������
int AddElement(hashbase* myhash, char* key, char* element, char* url) {
	if (Find(myhash, key) >= 0) {
		return 1;
	}
	int index = hash1(key); // ��������� ������ (���)
	if (!strcmp(myhash->key1[index], "\0")) { // ��������� ��� ������ ������
		strcpy_s(myhash->key1[index], 101, key); // �������� ����
		strcpy_s(myhash->value[index], 101, element); // �������� ������
		strcpy_s(myhash->url_image[index], 101, url); // �������� ������
		return 0;
	}
	else {// ���� ������ ���� ������ ���������� �� ������ �����������
		while (1) {
			index = hash2(index, key);
			if (!strcmp(myhash->key1[index], "\0")) { // ��������� ��� ������ ������
				strcpy_s(myhash->key1[index], 101, key); // �������� ����
				strcpy_s(myhash->value[index], 101, element); // �������� ������
				strcpy_s(myhash->url_image[index], 101, url); // �������� ������
				return 0;
			}
		};
	}
	return 1; // ������, ��� ������
}

// ������� ������� ������ �� �������
void RemoveElement(hashbase* myhash, char* key, char* filename) {
	int index = Find(myhash, key); // ���� ����� ����
	if (index >= 0) {// ���� ����� �������
		strcpy_s(myhash->key1[index], 101, "\0"); // ������� ������ �����
		strcpy_s(myhash->value[index], 101, "\0"); // ������� ������ ������
		strcpy_s(myhash->url_image[index], 101, "\0"); // ������� ������ ������
		Savefile(myhash, filename);
	}
	else { printf("����� ������� �����������\n"); }// �� �����
}


void Openfile(hashbase* myhash, char* filename) {
	char element[1001];
	char key[401];
	char url[401];
	if (!fopen_s(&file1, filename, "r")) { // ������ ���� � ����
		char f[11002];
		int i, j, k;
		while ((fgets(f, 10001, file1)) != NULL) {
			for (i = 0; i < strlen(f); i++) {
				if ((unsigned char)f[i] == ';') { key[i] = '\0';  break; }
				else key[i] = f[i];
			}
			i++;
			for (j = 0; j < strlen(f) - i; j++) {
				if ((unsigned char)f[j+i] == ';') { element[j] = '\0'; break; }
				else element[j] = f[i + j];
			}
			j++;
			for (k = 0; k < strlen(f) - j - i; k++) {
				if ((unsigned char)f[k+i+j] == ';') { url[k] = '\0'; break; }
				else url[k] = f[i + j + k];
			}
			if (url[strlen(f) - i - j - 1] == '\n') {
			url[strlen(f) - i - j - 1] = '\0';
			}
			else url[strlen(f) - i - j] = '\0';
			AddElement(myhash, key, element, url);
		}
		fclose(file1);
	}
	else printf("������ �������� �����. ��������� ������������ ����� ����� �����\n");
}

//