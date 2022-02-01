#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string name_of_month(int num_mon) {
    string months[12] = { "ЯНВАРЬ", "ФЕВРАЛЬ", "МАРТ", "АПРЕЛЬ", "МАЙ", "ИЮНЬ", "ИЮЛЬ", "АВГУСТ", "СЕНТЯБРЬ", "ОКТЯБРЬ", "НОЯБРЬ", "ДЕКАБРЬ" };
    return  months[num_mon - 1];
}

int leap_year(int year) {
    return ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0);
}

int days_of_month(int month, int year) {
    int days[12] = { 31, 28 + leap_year(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return days[month - 1];
}


int first_day_of_month(int year, int month) {
    int k_vis_year = 0, n = 0;
    for (int i = 1; i < year; i++) { // находим кол-во високосных годов до введённого
        k_vis_year += leap_year(i);
    }
    for (int i = 1; i < month; i++) { // находим кол-во дней от начала года до начала указанного месяца
        n += days_of_month(i, year);
    }
    int days = year * 365 + k_vis_year + (month == 1 ? 0 : n); // находим кол-во дней с начала летоисчесления(начала н.э.) до 1 января введённого года
    int week_day = days % 7; // остаток от деления общ. кол-ва дней до начал опред. месяца на кол-во дней в неделе(7)
    return (week_day == 0 ? 7 : week_day);
}

void calendar(int month, int year) {
    cout << " " << name_of_month(month) << " " << year << endl << " ПН ВТ СР ЧТ ПТ СБ ВС" << endl;
    int  num_day = 1, wd = 8 - first_day_of_month(year, month); //wd количество дней, которые надо вывести
    if (first_day_of_month(year, month) != 1) { //пробелы для первой строки календаря
        cout << setw(3 * (first_day_of_month(year, month) - 1)) << " ";
    }
    while (num_day <= days_of_month(month, year)) {
        while (wd > 0 && num_day <= days_of_month(month, year)) { //ограничение на номер дня и количесво выводимых чисел
            cout << setw(3) << num_day;
            num_day++;
            wd--;
        }
        wd = 7;
        cout << endl;
    }
}

int main()
{
    int number_of_month, year;
    cout << "Введите номер месяца и года: ";
    cin >> number_of_month >> year;
    calendar(number_of_month, year);
    return 0;
}






