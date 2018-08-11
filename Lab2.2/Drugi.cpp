#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include<vector>
#include <string>


int arr_int[] = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };

template <typename Iterator, typename Predicate>
Iterator mymax(Iterator cur, Iterator last, Predicate pred) {
	Iterator max = cur;
	Iterator i = cur;
	while(i!=last)
	{
		if (pred(i, max)) {
			max = i;
		}
		++i;
	}

	return max;
}

bool gt_int(const void* f,const void* s)
{
	
	return *(int*)f > *(int*)s ? true : false;
}

bool gt_char(const void* prvi, const void* drugi) {
	return *(char*)prvi > *(char*)drugi ? true : false;
}

bool gt_str(std::vector<std::string>::iterator prvi, std::vector<std::string>::iterator drugi) {
	return prvi->length()> drugi->length() ? true : false;
	
}

int main() {
	const int* maxint = mymax(&arr_int[0],
		&arr_int[sizeof(arr_int) / sizeof(*arr_int)], gt_int);
	std::cout << *maxint << "\n";

	std::vector<int> vecInt = { 1, 3, 5, 7, 4, 6, 9, 2, 0 };
	maxint = mymax(&vecInt[0], &vecInt.back(), gt_int);
	std::cout << *maxint << "\n";

	std::vector<std::string> strings= {"Ovo", "je", "test", "za", "stringove", "kuzis"};
	std::vector<std::string>::iterator maxString = mymax(strings.begin(), strings.end(), gt_str);

	std::cout << *maxString << std::endl;
	system("pause");
}