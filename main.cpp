#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
    int p, remainder, yourX, x;
    int i = 0;
    bool next = true;
    char arr[30] = {};
    string number = "";
    cout << "Введите номер системы счисления.. ";
    cin >> p;
    if(p < 2 || p > 36) { //проверка на систему счисления
        cout << "Неверная система счисления";
        return 0;
    }
    cout << "Введите число для перевода.. ";
    cin >> yourX;
    if(yourX < 0) { //проверка на знак введенного числа
        cout << "Вы ввели неверное число";
        return 0;
    }
    x = yourX;
    if(x < p){ //если число меньше системы счисления -> останется это же число
        number += to_string(x);
        next = false; //условие для цикла перевода СС
        i++;
    }
    while(x > 0 && next){
//        cout << "i = " << i << endl;
//        cout << "x = " << x << endl;
        if(x >= p) { //если число больше или равно СС
            remainder = x % p; //вычисляем остаток от деления на СС
            if (remainder > 9) //буква или цифра
                arr[i] = 65 + (char)remainder - 10;
            else
                arr[i] = 48 + (char)remainder;
        }
        else if(x > 9) //буква или цифра
            arr[i] = 55 + x;
        else
            arr[i] = 48 + x;
//        cout << "arr = " << arr[i] << endl;
        x /= p;
        i++;
    }
    for(int k = i - 1; k >= 0; k--) { //собираем строка number с конца массива
        number += arr[k];
    }
    cout << endl << "Число " << yourX << " в " <<  "системе счисления " << p << " = " << number;
    return 0;
}