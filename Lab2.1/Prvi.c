#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

const void* mymax(const void* base, size_t nmeb, size_t size, int(compar)(const void*, const void*));
int gt_int(const void* prvi, const void* drugi);
int gt_char(const void* prvi, const void* drugi);
int gt_str(const void* prvi, const void* drugi);

int main(void) {
	const void* max = NULL;
	int arr_int[] = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
	char arr_char[] = "Suncana strana ulice";
	const char* arr_str[] = {
		"Gle", "malu", "vocku", "poslije", "kise",
		"Puna", "je", "kapi", "pa", "ih", "njise"
	};
	max = mymax(arr_int, sizeof(arr_int) / sizeof(*arr_int), sizeof(*arr_int), gt_int);
	printf("%d\n", *(const int*)max);
	max = mymax(arr_char, sizeof(arr_char) / sizeof(*arr_char), sizeof(*arr_char), gt_char);
	printf("%c\n", *(const char*)max);
	max = mymax(arr_str, sizeof(arr_str) / sizeof(char*), sizeof(char*), gt_str);
	printf("%s\n", *(const char**)max);
	system("pause");
	return 0;
}

int gt_int(const void* prvi, const void* drugi) {
	return *(int*)prvi > *(int*)drugi ? 1 : 0;
}

int gt_char(const void* prvi, const void* drugi) {
	return *(char*)prvi > *(char*)drugi ? 1 : 0;
}

int gt_str(const void* prvi, const void* drugi) {
	return strcmp(*(char**)prvi, *(char **)drugi) > 0 ? 1 : 0 ;
}

const void* mymax(const void* base, size_t nmeb, size_t size, int(*compar)(const void*, const void*)){
	const uint8_t* byte =  base;
	const void* max;

	if ((*compar)(&byte[0], &byte[size])) {
		max = &byte[0];
	}
	else {
		max = &byte[size];
	}
	for (size_t i = 2; i < nmeb; ++i) {
		if ((*compar)(&byte[i * size], max)) {
			max = &byte[i * size];
		}
	}
	return max;
}