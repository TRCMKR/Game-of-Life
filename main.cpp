#include "gameOfLife.h"
#include "matrix.h"
#include <iostream>
#if _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <clocale>
#include <cstdlib>

#endif

int main()
{
#if _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
//    setlocale(LC_ALL, "RUSSIAN");
    system("chcp 65001");
#endif
    if (system("clear")) system("cls"); // кросс-платформенная чистка экрана

    // Блок ускоренения вывода/ввода (на всякий)
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // значения Игры по умолчанию
    int height = 50; // min 20
    int width = 130; // min 20

    // фпс лучше ставить до 30 либо 100
    Game GoL = Game(height, width, 30); // <=30, 100
    GoL.Setup();
    GoL.Start();

    /// СИНТАКСИС ИГРЫ:
    /// В НАЧАЛЬНОЙ СЦЕНЕ ЕСТЬ НЕСКОЛЬКО ВАРИАНТОВ ГОТОВЫХ ФИГУР И ОДНА СЛУЧАЙНАЯ
    /// ВЫБОР ОСУЩЕСТВЛЯЕТСЯ ПОСРЕДСТВОМ ВВОДА СООТВЕТСВУЮЩЕГО ЧИСЛА
    /// ЧТОБЫ ВВЕСТИ СВОЮ ФИГУРУ НУЖНО ПРОСТО ВВОДИТЬ ЧИСЛА 0 1 КАК И ДЛЯ ЛЮБЫХ ДРУГИХ МАТРИЦ В CPP
    /// СМЕНИТЬ ТЕМУ: theme={rColor, gColor, pColor}
    /// СМЕНИТЬ МАСШТАБ: h{число}w{число}
    /// ИЗМЕНИТЬ FPS: FPS={число}
    /// ЗАКРЫТЬ ИГРУ: :q                ))))

    return 0;
}