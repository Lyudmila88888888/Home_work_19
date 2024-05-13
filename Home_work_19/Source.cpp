#include <iostream>

template <typename T>
void print_arr(T arr[], const int length) { //для вывода массива
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
// Задача 1.

int gcd(int n1, int n2) { 
	if (n2 != 0)
		return gcd(n2, n1 % n2);
	else
		return n1;
}
// Задача 2.

int mirror_number(int num) { 
	int reversed = 0;
	while (num > 0) {
		int digit = num % 10;
		reversed = reversed * 10 + digit;
		num /= 10;
	}
	return reversed;
}

  // Задача 3. Тут нет сортировки справа. 
//Я конечно нашла ответы, но не могу понять как это работает, поэтому не стала писать. 
// Нашла вот такой вариант решения
/*int findAndSort(int arr[], int length, int N) {
	int position = -1;
	for (int i = 0; i < length; ++i) {
		if (arr[i] == N) {
			position = i;
			break;
		}
	}
	if (position != -1) {
		// Сортировка элементов справа от N
		std::sort(arr + position + 1, arr + length);
	}
	return position;
}*/     

template <typename T>
int search_index(T arr[], const int length, T key, int begin = 0) {
	for (int i = begin; i < length; i++)
		if (arr[i] == key)
			return i; 
	return -1;
}

// Задача 4.

template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

int main() {
	setlocale(LC_ALL, "Russian");
	// Задача 1.
	int n1, n2;
	std::cout << " Введите 2 целых положительных числа -> ";
	std::cin >> n1 >> n2;
	std::cout << " НОД " << n1 << " и " << n2 << " = " << gcd(n1, n2) << std::endl;
	
	// Задача 2.

	int num;
	std::cout << "Введите число: ";
	std::cin >> num;
	std::cout << "Отражённое число: " << mirror_number(num) << std::endl;
	
	// Задача 3.  // Нет сортировки справа. Не смогла разобраться

	int n;
	const int size = 10;
	int arr[size]{ 5, 20, 10, 8, 5, 20, 7, 8, 20, 1 };
	std::cout << " Массив:\n";
	print_arr(arr, size);

	std::cout << "Введите число для поиска -> ";
	std::cin >> n;

	int index = search_index(arr, size, n); 

	if (index != -1)
		std::cout << " Позиция числа: " << index << std::endl;
	
	else
		std::cout << " Числа нет в массиве.\n";	

	// Задача 4.

	int a, b;
	std::cout << " Введите число для определения начала диапазона массива - > ";
	std::cin >> a;
	std::cout << " Введите число для определения конца диапазона массива - > " ;
	std::cin >> b;
	std::cout << " Массив:\n";
	const int size3 = 10;
	int arr3[size3];
	fill_arr(arr3, size3, a, b);
	print_arr(arr3, size3);
	
	return 0;
}