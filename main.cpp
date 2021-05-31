#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int Col(const string vvod2, const int kolvo)
{
    int n = 0;
    //Нужные буквы алфавита
    string abc = "AaEeIiUuYyOo";

    for (int i = 0; i < kolvo; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if (vvod2[i] == abc[j])
            {
                n++;
            }
        }
    }

    return n;
}

int main()
{
    setlocale(LC_ALL, "ru");

    int num = 0, k, kolvo, n, m = 0;

    ifstream F1("F1.txt");
    fstream F2("F2.txt");
    string vvod1, vvod2;


    cout << "Введите номер строки: ";
    cin >> k;
    cout << endl;
    cout << endl;

    cout << "Текст первого файла: " << endl << endl;
    //Проверка на открытие 1 файла
    if (F1.is_open()) {
        while (!F1.eof()) {
            num++;
            getline(F1, vvod1);
            //Перезапись нужного куска файла 1 в файл 2
            if (num >= k && num < k + 5) {
                F2 << vvod1 << endl;
            }
            cout << vvod1 << endl;
        }
    }
    //Если файл 1 не открылся
    else {
        cout << "Файл не открыт." << endl;
    }

    cout << endl;
    cout << endl;

    F1.close();
    F2.close();

    ifstream F3("F2.txt");

    cout << "Текст второго файла: " << endl << endl;
    //Открытие 2 файла и проверка на открытие как выше
    if (F3.is_open()) {
        while (!F3.eof()) {

            getline(F3, vvod2);

            kolvo = vvod2.length();
            n = Col(vvod2, kolvo);
            m = m + n;
            //Вывод второго файла на экран
            cout << vvod2 << endl;
        }
    }
    else {
        cout << "Файл не открыт." << endl;
    }
    F3.close();

    cout << endl;
    cout << endl;

    cout << "Колличество гласных букв во втором файле:" << m << endl;

    return(0);
}