#include "gameOfLife.h"
#include "universe.h"

#include <iostream>
#include <cstdlib>
#include <thread>
#include <string>
#include <cstdio>
#if unix or __MACH__
#include <termios.h>
#include <sys/ioctl.h>
#elif _WIN32
#include "conio.h"
#endif

using namespace std;

/// Важно понимать, что я работаю на Маке (читать Линуксе),
/// поэтому мне нужно было добиться кросс-платформы с Виндой.
/// Это была серьёзная проблема из-за больших отличий в библ-
/// иотеках, поведении и тд. Поэтому ходил окольными пятями,
/// говнокодил, условно компилировал, а поведение всё равно
/// разное, зато работает!

void Game::Blank()
{
    puts(_settings.c_str());
    //fflush(stdout);
}

void Game::Start()
{
    if (_toExit)
    {
        printf("\033]2;Thank you for playing!\a");
#if unix or __MACH__
        system("clear");
#elif _WIN32
        system("cls");
#endif
        Settings(_prevWindow);
        return;
    }
    //fputs(_window.c_str(), stdout);
#if unix or __MACH__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    //ClearScreen();
    //ClearScreen(_clear);
    puts(_window.c_str());
    //fflush(stdout);

    _frame = 0;

    Update();
}

void Game::Update()
{
    printf("\033]2;Running…\a");
#if unix or __MACH__
    enable_raw_mode();
    while (_frame == 0 || !kbhit())
    {
        system("clear");
        RenderFrame(_frame);
        _universe.Update();
        this_thread::sleep_for(_timeOut);
        //ClearScreen();
        //ClearScreen(_clear);
        //if (system("clear")) system("cls");
        _frame++;
    }
#elif _WIN32
    while (_frame == 0 || !_kbhit())
    {
        system("cls");
        RenderFrame(_frame);
        _universe.Update();
        this_thread::sleep_for(_timeOut);
        //ClearScreen();
        //ClearScreen(_clear);
        //if (system("clear")) system("cls");
        _frame++;
    }
#endif

#if unix or __MACH__
    disable_raw_mode();
    tcflush(0, TCIFLUSH);
#elif _WIN32
    _getch();
    //tcflush(0, TCIFLUSH); // к сожалению, такой функции нет на Винде, а сам написать не могу//
#endif

    fputs(_settings.c_str(), stdout);
    fflush(stdout);

#if unix or __MACH__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    Setup();
    Start();
}

void Game::RenderFrame(ull frame)
{
    //if (_frame) cout << "\n" << flush;
    // _universe.randomUniverse();
    // _universe.followFrame(frame);
    //cout << _universe;
    fputs((_window + _universe.toString(_theme)).c_str(), stdout);
    //cout << "\033[1F";
    fflush(stdout);
//    int i = frame % 256;
//    string line = color(BG, HIDE, i) + std::string(_width, '0');
//    for (int j = 0; j < _height; ++j)
//        cout << line << reset << flush;
//    if (i == 15 || (i > 15 && (i - 15) % 6 == 0) )
//        cout << "\n" << flush;
}

void Game::Settings(const string & s)
{
//    cout << s;
    fputs(s.c_str(), stdout);
}

void Game::Setup()
{
    Blank();
    Settings(_settings);
#if unix or __MACH__
    system("clear");
#elif _WIN32
    system("cls");
#endif
    Settings(_settings);

    fputs("/// СИНТАКСИС ИГРЫ:\n"
          "/// В НАЧАЛЬНОЙ СЦЕНЕ ЕСТЬ НЕСКОЛЬКО ВАРИАНТОВ ГОТОВЫХ ФИГУР И ОДНА СЛУЧАЙНАЯ\n"
          "/// ВЫБОР ОСУЩЕСТВЛЯЕТСЯ ПОСРЕДСТВОМ ВВОДА СООТВЕТСВУЮЩЕГО ЧИСЛА\n"
          "/// ЧТОБЫ ВВЕСТИ СВОЮ ФИГУРУ НУЖНО ПРОСТО ВВОДИТЬ ЧИСЛА 0 1 КАК И ДЛЯ ЛЮБЫХ ДРУГИХ МАТРИЦ В CPP\n"
          "/// СМЕНИТЬ ТЕМУ: theme={rColor, gColor, pColor}\n"
          "/// СМЕНИТЬ МАСШТАБ: h{число}w{число}\n"
          "/// ИЗМЕНИТЬ FPS: FPS={число}\n"
          "/// ЗАКРЫТЬ ИГРУ: :q                ))))\n\n", stdout);

    printf("\033]2;Menu\a");

    cout << "Выберите вселенную или задайте свою по размерам экрана: (-1 – случайная вселенная) " << _height << "x" <<_width << " FPS=" << _fps << "\n\n" << flush;
    cout << color(FG, LIGHT, 255) << "2" << string((130 - 4) / 4, ' ') << "3" << string((130 - 4) / 4, ' ') << "4" << string((130 - 4) / 4, ' ') << "5\n\n" << flush;
    matrix<int> eg = _universe.Example();
    eg.countAlive();
    puts(eg.toString(_theme).c_str());

    string s;
    char n;
    int nInt = -1;
    bool flagTheme = false;
    bool flagDim = false;
    bool flagFPS = false;

    cout << BGblack << flush;
    // Реализация команд и небольшого интерпретатора
    while (nInt < 0 || nInt > 5)
    {
//        cin >> s;
        getline(cin, s);
        int sInd = 0;
        string firstNum;
        while (s[sInd] != ' ' && sInd != s.length())
        {
            firstNum.push_back(s[sInd]);
            sInd++;
        }


        // Узнать, какое число для вариантов из меню -1, 2, 3, 4, 5
        if (firstNum.length() <= 2)
        {
            n = firstNum[0];
            nInt = n - '0';
            if (n == '-')
            {
                n = firstNum[1];
                if (n == '1')
                {
                    nInt = -1;
                    break;
                }
            }
            else if (n == ':')
            {
                n = firstNum[1];
                if (n == 'q')
                {
                    _toExit = true;
                    return;
                }
            }
            fflush(stdin);
        }
        // Проверки реализации ввода темы Игры
        else if (s.length() != 6 && s.find("theme=") != string::npos)
        {
            _theme = getTheme(string(s.begin() + 6, s.end()), _theme);
            flagTheme = true;
            break;
        }
        // Проверки для изменения масшатаба игрового окна и поля. Меню всегда одного размера
        if (s[0] == 'h' && s.find('w') != string::npos)
        {
            flagDim = true;
            int h = 0;
            int w = 0;
            int * side = &h;
            for (int i = 1; i < s.length(); ++i)
            {
                n = s[i];
                nInt = n - '0';
                if (nInt >= 0 && nInt <= 9)
                {
                    *side = *side * 10 + nInt;
                    continue;
                }
                if (s[i] == 'w')
                {
                    side = &w;
                }
                else
                {
                    flagDim = false;
                    break;
                }
            }
            if (flagDim && h >= 20 && w >= 20)
            {
                _width = w;
                _height = h;
                nInt = -1;
                break;
            }
        }
        if (s.find("FPS=") != string::npos)
        {
            int res = 0;
            for (int i = 4; i < s.length(); ++i)
            {
                n = s[i];
                nInt = n - '0';
                if (nInt >= 0 && nInt <= 9)
                {
                    res = res * 10 + nInt;
                    continue;
                }
                else break;
            }
            if (res > 50)
                _fps = 100;
            else if (res <= 1)
                _fps = 1;
            else
                _fps = res;
            timeOut();
            flagFPS = true;
            break;
        }
    }
    if (flagTheme || flagDim || flagFPS) Setup();
    // Избежать рекурсии
    if (!flagTheme && !flagDim && !flagFPS)
    {
        if (nInt == 4 && (_height < 50 || _width < 100)) {
            _universe = Universe(50, 130);
            _window = "\033[?25l\e[8;" + to_string(50) + ";" + to_string(130) + "t" + BGblack;;
        }
        else {
            _universe = Universe(_height, _width);
            _window = "\033[?25l\e[8;" + to_string(_height) + ";" + to_string(_width) + "t" + BGblack;
        }
        if (nInt == 0 || nInt == 1)
            _universe.universeInit(s);
        else
            _universe.universeInit(nInt);
    }
}

void Game::ClearScreen(const string& s)
{
    printf("%s", s.c_str());
}

// Писал не сам, но является аналогом соответствующей функции из windows.h
#if unix or __MACH__
void enable_raw_mode()
{
    termios term;
    tcgetattr(0, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Disable echo as well
    tcsetattr(0, TCSANOW, &term);
}

void disable_raw_mode()
{
    termios term;
    tcgetattr(0, &term);
    term.c_lflag |= ICANON | ECHO;
    tcsetattr(0, TCSANOW, &term);
}

bool kbhit()
{
    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);
    return byteswaiting > 0;
}
#endif