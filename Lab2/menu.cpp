#include <iostream>
#include "menu.h"
#include "set.h"


SetMenu::SetMenu() {}

Set SetMenu::creatSet() {
    std::cout << "Введите максимальный размер множества.\n";
    int max_el;
    do {
        max_el = 0;
        std::cin >> max_el;
    }
    while (max_el < 1);

        return Set (max_el);
}


void SetMenu::settingOptions(Set& set) {

    std::cout << "Какую операцию Вы хотите выполнить?\n";
    std::cout << "1) Проверить, содержиться ли данный элемент в множестве.\n";
    std::cout << "2) Добавить элементы во множество.\n";
    std::cout << "3) Изъять конкретный элемент из множества.\n";
    std::cout << "4) Изъять последний элемент из множества.\n";
    std::cout << "5) Вывести множество на экран.\n";
    std::cout << "Введите номер соответствующей операции или -1, если хотие выйти из программы.\n";

    int option = 0;
    while (option != -1) {
        std::cin >> option;
        switch (option) {
            case 1: {
                std::cout << "Введите элемент, чтобы проверить, является ли он элементом данного множества:\n";
                int el;
                std::cin >> el;
                if (set.find_el(el))
                    std::cout << "Множество содержит данный элемент.\n";
                else
                    std::cout << "Данного элемента нет в множестве.\n";

                    std::cout << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case 2: {
                std::cout << "Введите элементы, которые хотите добавить (b, чтобы перейти в меню):\n";
                char el = 0;
                while (el != 'b') {
                    std::cin >> el;
                    if (el != 'b')
                    set.add_el(el-'0');
                }
                std::cout << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case 3: {
                    std::cout << "Введите элемент, который хотите изъять из множества:\n";
                    int el;
                    std::cin >> el;
                    set.remove_el(el);
                std::cout << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case 4: {
                    set.remove_last_el();
                std::cout << "Операция выполнена. Укажите следующую или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case 5: {
                    std::cout << "В множестве: ";
                    set.print();
                std::cout << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
                } case -1: {
                    break;
                }
            default: {
                    std::cout << " Введите значения от 1 до 5 или -1, чтобы выйти из программы.\n";
                break;
            }
        }
    }
}

void SetMenu::settingOptions (Set &set1, Set &set2) {
    std::cout << "Какую операцию Вы хотите выполнить с данными множествами?\n";
    std::cout << "1) Добавить во второе множество все элементы, содержащиеся в первом.\n";
    std::cout << "2) Добавить в первое множество все элементы, содержащиеся во втором.\n";
    std::cout << "3) Изъять из первого множества все элементы, содержащиеся во втором.\n";
    std::cout << "4) Изъять из второго множества все элементы, содержащиеся в первом.\n";
    std::cout << "5) Пересечение множеств.\n";
    std::cout << "6) Объединение множеств.\n";
    std::cout << "7) Вывести первое множество.\n";
    std::cout << "8) Вывести второе множество.\n";
    std::cout << "Введите номер соответствующей операции или -1, если хотие выйти из программы.\n";


    int option = 0;
    while (option != -1) {
        std::cin >> option;
        switch (option) {
            case 1: {
                set1 += set2;
                std::cout
                        << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case 2: {
                set2 += set1;
                std::cout
                        << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case 3: {
                set1 -= set2;
                std::cout
                        << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case 4: {
                set2 -= set1;
                std::cout
                        << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case 5: {
                std::cout << "Пересечение множеств: ";
                Set set3 = set1.intersection(set2);
                set3.print();
                std::cout
                        << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case 6: {
                std::cout << "Объединение множеств: ";
                Set set3 = set1.set_union(set2);
                set3.print();
                std::cout
                        << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case 7: {
                std::cout << "В множестве: ";
                set1.print();
                std::cout
                        << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case 8: {
                std::cout << "В множестве: ";
                set2.print();
                std::cout
                        << "Операция выполнена. Укажите следующую операцию или введите -1, чтобы выйти из программы.\n";
                break;
            }
            case -1: {
                break;
            }
            default: {
                std::cout << " Введите значения от 1 до 5 или -1, чтобы выйти из программы.\n";
                break;
            }

        }
    }
}
