#include <iostream>
int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Введите строку: ";

    // Выделяем память для динамического массива
    char* primer = new char[256]; // Предполагаем, что строка не превышает 255 символов
    std::cin.getline(primer, 256); // Считываем строку целиком

    // Определяем длину введенной строки
    int length = 0;
    while (primer[length] != '\0')
    {
        length++;
    }
    int size = sizeof(primer) / sizeof(primer[0]); // Определяем размер массива (sizeof(primer[0]) - первый символ )

    int kolvoznakov = 0;
    bool vchisle = false; // Флаг, указывающий, находимся ли мы внутри числа
    int colvocifer = 0; // Счетчик цифр в текущем числе
    int mnogoznachnoechislo = 0; // Счетчик многозначных чисел

    // Проходим по всем символам в массиве 
    for (int i = 0; primer[i] != '\0'; ++i) {
        char simvol = primer[i];

        if (simvol >= '0' && simvol <= '9') {
            // Если символ - цифра
            if (!vchisle) {
                vchisle = true; // Начало числа
                colvocifer = 1; // Счетчик цифр в числе
            }
            else {
                colvocifer++; // Увеличиваем счетчик цифр
            }
        }
        else {
            // Если символ не является цифрой
            if (vchisle) {
                vchisle = false; // Завершили число
                if (colvocifer > 1) {
                    mnogoznachnoechislo++; // Если число многозначное
                }
            }
            // Проверяем, является ли символ знаком
            if (simvol != ' ' && simvol != '\n' && simvol != '\t')
                // Игнорируем пробелы и переносы строк
            {
                kolvoznakov++;
            }
        }
    }

    // Если строка заканчивается многозначным числом
    if (vchisle && colvocifer > 1) {
        mnogoznachnoechislo++;
    }

    // Вывод результатов
    std::cout << "Количество чисел: " << colvocifer << std::endl;
    std::cout << "Количество многозначных чисел: " << mnogoznachnoechislo << std::endl;
    std::cout << "Количество символов: " << kolvoznakov << std::endl;

}
//----------------------------------------