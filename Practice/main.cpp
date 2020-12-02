#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;
int V = 0;

// Мультипоточный сортировщик
int multisorter(vector<string>& stringV) {
	lock_guard<mutex> lock(mtx);
	sort(stringV[V].begin(), stringV[V].end());
	V++;
	mtx.unlock();
	return 0;
}

int main() {
	
	// Запрос времени
	auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
	
	// Вывод авторства и времени
	cout << "Автор: Елизавета Пономаренко" << endl <<
		"Настоящее время/дата: " << ctime(&timenow) << endl;

	// Начало работы с файлом
    string charset = "";
	fstream charsfile("charset.txt");

	// Сид генератора случайных чисел от времени [секунды]
	srand(time(NULL));

	// Генерация списка 100 случайных латинских букв нижнего регистра
    for (int i=0; i<100; i++) {
		charset += 'a'+(rand()%26);
    }
	
	// Запись и закрытие файла
	charsfile << charset;
	charsfile.close();

	// Объявление вектора строк
	vector<string> stringsV(10);
	
	// Деление на десять слов по десять букв
	{
		int C=0;
		for (int i=0; i<10; i++) {
			for (int j=0; j<10; j++) {
				stringsV[i] += charset[C];
				C++;
			}
		}
	}
	
	// Объявление вектора потоков
	vector<thread> threadV;

	// Запуск потоков
	for (int i=0; i<10; i++) {
		threadV.emplace_back([&](){multisorter(ref(stringsV));});
	}

	// Перехват окончания всех бобочных потоков и возврат в основной
	for(auto& t: threadV) {
		t.join();
	}

	// Сортировка слов в общем порядке
	sort(stringsV.begin(), stringsV.end());

	// Запуск именнованного канала
	char buff[11];
	int p[2];
	if (pipe(p)<0) _exit(1);

	// Запись именнованного канала и вывод слов в обратном порядке
	for (int i=9; i>-1; i--) {
		write(p[1], stringsV[i].c_str(), 11);
		cout << stringsV[i] << endl;
	}

	// Чтение именнованного канала
	for (int i=0; i<10; i++) {
		read(p[0], buff, 11);
	}

	return 0;
}
