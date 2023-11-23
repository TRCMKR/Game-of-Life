#pragma once

#include "colors.h"
#include "universe.h"

#include <chrono>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <ctime>

#if unix or __MACH__
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#elif _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

typedef unsigned long long ull;

class Game
{
private:
    Universe _universe;
    ull _frame;
    int _width;
    int _height;
    int _fps;
    std::chrono::milliseconds _timeOut;
    void Update();
    void RenderFrame(ull time);
    string _clear;
    string _settings;
    string _window;
    string _prevWindow;
    cellColor _theme;
    bool _toExit;
public:
    Game(int height, int width, int fps = 32): _universe(height, width)
    {
        _frame = 0;
        _width = width;
        _height = height;
        _fps = fps;
        timeOut();
        _clear = string(_height + 1, '\n');
        _settings = "\033[?25h\e[8;50;130t" + BGblack;
        _window = "\033[?25l\e[8;" + to_string(_height) + ";" + to_string(_width) + "t" + BGblack;
        _theme = pColor;
        _toExit = false;

        int columns, rows;
#if unix or __MACH__
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        rows = w.ws_row;
        columns = w.ws_col;

#elif _WIN32
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
        columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
#endif
        _prevWindow = "\033[?25h\e[8;" + to_string(rows) + ";" + to_string(columns) + "t";
    }

    void timeOut()
    {
        _timeOut = std::chrono::milliseconds(1000 / _fps);
    }

    // Пустой экран
    void Blank();

    // Запуск игры
    void Start();

    // Строка настроек
    void Settings(const string & ss);

    // Меню и «консоль» для команд
    void Setup();

    // Метод очистки экрана
    void ClearScreen(const string& s = "\033[2J\033[1;1H");
};

// Эти функции брал из интернета в качестве альтернативы винде
#if unix or __MACH__
void enable_raw_mode();

void disable_raw_mode();

bool kbhit();
#endif