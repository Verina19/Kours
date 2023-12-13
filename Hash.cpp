#include "Hash.h"

FILE* file1;

// ‘ункци€ записи в файл
void Savefile(hashbase* myhash, char* filename) {
	if (!fopen_s(&file1, filename, "w")) { // запись базы в файл
		for (int i = 0; i < TABLE_SIZE; i++) {
			if (strcmp(myhash->key1[i], "\0")) {// записываем только заполненные €чейки в формате ключ;значение
				fputs(myhash->key1[i], file1); // запись строки ключа
				fputs(";", file1); // добавл€ем разделитель
				fputs(myhash->value[i], file1); // запись строки данных
				fputs(";", file1); // добавл€ем разделитель
				fputs(myhash->url_image[i], file1); // запись строки url
				fputs("\n", file1); // добавл€ем конец строки
			}
		}
		fclose(file1);
	}
}

// хэш-функци€ дл€ вычислени€ индекса в хэш-таблице. 
// суммирует значени€ ASCII-кодов символов ключа и возвращает остаток от делени€ на размер хэш-таблицы
int hash1(char* key) {
	int hash_value = 0;
	for (int i = 0; key[i] != '\0'; i++) {
		hash_value += (unsigned char)key[i];
	}
	return hash_value % TABLE_SIZE;
}

// хэш-функци€ дл€ вычислени€ индекса в хэш-таблице. 
// суммирует значени€ ASCII-кодов символов ключа и предыдущее значение хэш, и возвращает остаток от делени€ на размер хэш-таблицы
int hash2(int hash_value, char* key) {
	for (int i = 0; key[i] != '\0'; i++) {
		hash_value += (unsigned char)key[i];
	}
	return hash_value % (TABLE_SIZE - 1) + 1;
}

// ‘ункци€ проверки наличи€ элемента в базе
int Find(hashbase* myhash, char* key) {
	int index = hash1(key);// вычисл€ем индекс (хэш)
	if (!strcmp(myhash->key1[index], key)) {// провер€ем что элемент равен содержимому €чейки
		return index;
	}
	else {
		int count = 0;// если €чейка была зан€та отправл€ем на второе хэширование
		while (1) {
			index = hash2(index, key);
			if (!strcmp(myhash->key1[index], key)) {// провер€ем что элемент равен содержимому €чейки
				return index;
			}
			count++;
			if (count > TABLE_SIZE) break;
		}
		return -1;
	}
}
// ‘ункци€ добавл€ет новую запись в хэш-таблицу
int AddElement(hashbase* myhash, char* key, char* element, char* url) {
	if (Find(myhash, key) >= 0) {
		return 1;
	}
	int index = hash1(key); // вычисл€ем индекс (хэш)
	if (!strcmp(myhash->key1[index], "\0")) { // провер€ем что €чейка пуста€
		strcpy_s(myhash->key1[index], 101, key); // копируем ключ
		strcpy_s(myhash->value[index], 101, element); // копируем данные
		strcpy_s(myhash->url_image[index], 101, url); // копируем данные
		return 0;
	}
	else {// если €чейка была зан€та отправл€ем на второе хэширование
		while (1) {
			index = hash2(index, key);
			if (!strcmp(myhash->key1[index], "\0")) { // провер€ем что €чейка пуста€
				strcpy_s(myhash->key1[index], 101, key); // копируем ключ
				strcpy_s(myhash->value[index], 101, element); // копируем данные
				strcpy_s(myhash->url_image[index], 101, url); // копируем данные
				return 0;
			}
		};
	}
	return 1; // ќшибка, все зан€то
}

// ‘ункци€ удал€ет запись из таблицы
void RemoveElement(hashbase* myhash, char* key, char* filename) {
	int index = Find(myhash, key); // »щем такой ключ
	if (index >= 0) {// если нашли удал€ем
		strcpy_s(myhash->key1[index], 101, "\0"); // очищаем €чейку ключа
		strcpy_s(myhash->value[index], 101, "\0"); // очищаем €чейку данных
		strcpy_s(myhash->url_image[index], 101, "\0"); // очищаем €чейку данных
		Savefile(myhash, filename);
	}
	else { printf("“акой элемент отсутствует\n"); }// не нашли
}


void Openfile(hashbase* myhash, char* filename) {
	char element[1001];
	char key[401];
	char url[401];
	if (!fopen_s(&file1, filename, "r")) { // запись базы в файл
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
	else printf("ќшибка открыти€ файла. ѕроверьте правильность ввода имени файла\n");
}

//