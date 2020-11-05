#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <locale>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
using namespace std;

int main(void)
{
	setlocale(LC_ALL, "RUS");
	int file_read = 0, count = 0, sum = 0;

	char buff[1024];
	if ((file_read = _open("passwd.txt", O_RDONLY)) == -1)
	{
		printf("Файл для прочтения не найден!\n");
		cout << endl;
		exit(1);
	}
	count = _read(file_read, buff, 1024);
	while (count > 0)
	{
		sum += count * 4;
		if (sum > 1024)
		{
			cout << "Размер читаемого файла привысил 1024 байта.";
			cout << endl;
			return 0;
		}
		for (int i = 0; i < count; i++)
			cout << buff[i];
		count = _read(file_read, buff, 1024);
	}
	cout << "\n" << "\nКоличество байт = " << sum << "\n";
	cout << endl;
	return 0;
}