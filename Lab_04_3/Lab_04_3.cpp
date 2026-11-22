// Lab_04_3.cpp
// Ацедонська Марія Зорянівна
// Лабораторна робота № 4.3
// Табуляція функції, заданої формулою: функція з параметрами.
// Варіант 15

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double a, b, c;        // параметри функції
    double xStart, xEnd;   // початок і кінець інтервалу
    double dx;             // крок табуляції
    double x;              // поточне значення аргументу
    double F;              // значення функції

    cout << "a = ";      cin >> a;
    cout << "b = ";      cin >> b;
    cout << "c = ";      cin >> c;
    cout << "xStart = "; cin >> xStart;
    cout << "xEnd = ";   cin >> xEnd;
    cout << "dx = ";     cin >> dx;

    // Перевірка вхідних даних
    if (!cin || dx <= 0 || xStart > xEnd)
    {
        cout << "Error: invalid parameters!" << endl;
        return 1;
    }

    // Заголовок таблиці
    cout << fixed << setprecision(3);
    cout << "----------------------------" << endl;
    cout << "|" << setw(9) << "x" << " |" << setw(14) << "F" << " |" << endl;
    cout << "----------------------------" << endl;

    // Табуляція функції
    for (int i = 0; ; i++)
    {
        x = xStart + i * dx;
        if (x > xEnd)
            break;

        bool defined = true;  // чи визначена функція для поточного x

        if (x < 0 && b != 0)
        {
            F = -a * x * x + b;
        }
        else if (x > 0 && b == 0)
        {
            if (x == c)
                defined = false;
            else
                F = x / (x - c) + 5.5;
        }
        else
        {
            if (c == 0)
                defined = false;
            else
                F = x / (-c);
        }

        // Виведення одного рядка таблиці
        cout << "|" << setw(9) << x << " |";
        if (defined)
            cout << setw(14) << F;
        else
            cout << setw(14) << "undefined";
        cout << " |" << endl;
    }

    cout << "----------------------------" << endl;

    cin.get();
    return 0;
}