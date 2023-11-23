#pragma once

#include "colors.h"
#include "matrix.h"

#include <chrono>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <ctime>
#include <ostream>
#include <random>
#include <vector>

typedef unsigned long long ull;

// Начальные фигуры
const string GLIDER = "0 1 0"
                      "0 0 1"
                      "1 1 1";

const string MYINVENTION = "0 0 0 1 0 0 0"
                           "1 0 0 1 0 0 1"
                           "0 1 1 1 1 1 0";

const string MEHMAT = "1 1 0 0 0 0 0 1 1"
                    "1 1 1 0 0 0 1 1 1"
                    "1 1 1 1 0 1 1 1 1"
                    "1 1 1 1 1 1 1 1 1"
                    "1 1 0 0 0 0 0 1 1"
                    "1 1 0 0 0 0 0 1 1"
                    "1 1 0 0 0 0 0 1 1"
                    "1 1 0 0 0 0 0 1 1";

const string GOURMET = "0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0"
                       "0 0 1 0 1 1 0 1 1 0 1 0 0 0 0 0 1 1 0 0"
                       "0 0 1 1 0 1 0 1 0 1 0 0 0 0 0 0 1 0 0 0"
                       "0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 1 1 0 0"
                       "1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 1 0 1 0 0"
                       "1 1 1 0 0 0 0 0 0 1 1 0 1 1 0 0 1 0 0 0"
                       "0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1"
                       "0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1"
                       "0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0"
                       "0 0 0 1 0 0 0 0 0 0 1 0 1 0 1 0 1 1 0 0"
                       "0 0 1 1 0 0 0 0 0 1 0 1 1 0 1 1 0 1 0 0"
                       "0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0";

const string HEART = "1 1 0 1 1"
                     "1 1 1 1 1"
                     "1 1 1 1 1"
                     "0 1 1 1 0"
                     "0 0 1 0 0";

const string EXAMPLE = "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0"
                       "0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0";

// Класс игрового поля
class Universe
{
private:
    matrix<int> _board;
    matrix<int> _newBoard;
    matrix<int> _changed;
    matrix<int> _toCheck;
    int _n;
    int _m;
    int _frame;
    int _init;

    // Фигура Глайдера
    matrix<int> Glider()
    {
        matrix<int> gl(3, 3);
        gl = GLIDER;

        return gl;
    }

    // Фигура, которую придумал я
    matrix<int> MyInv()
    {
        matrix<int> myInv(3, 7);
        myInv = MYINVENTION;

        return myInv;
    }

    // Анимация (не соответствует правилам Игры в Жизнь) МехМат
    matrix<int> MMCS()
    {
        matrix<int> mmcs(8, 9);
        mmcs = MEHMAT;

        return mmcs;
    }

    // Фигура Гурмэ
    matrix<int> Gourmet()
    {
        matrix<int> gourm(20, 20);
        gourm = GOURMET;

        return gourm;
    }

    // Фигура Сердце – часть мехмата
    matrix<int> Heart()
    {
        matrix<int> heart(5, 5);
        heart = HEART;

        return heart;
    }


public:
    Universe(int n, int m): _board(n, m), _newBoard(n, m), _changed(n, m), _toCheck(n, m)
    {
        _n = n;
        _m = m;
        _toCheck.fill(1);
        _frame = 0;
        _init = 6;
    }

    // Случайный мир
    void randomUniverse();

    // Итерация мира
    void Update();

    // Поменялась клетка или нет
    bool checkState(int i, int j);

    // Поменять состояние клетки
    void changeState(int i, int j);

    // Количество живых соседей
    int countAlive(int x, int y) const;

    // Расщепить пространство и время и добавить в замкнутую систему этого Мира
    void addToUniverse(const matrix<int> & mtr, int posI, int posJ, int n, int m);

    // Инициализировать мир одним из вариантов
    void universeInit(int n)
    {
        _init = n;
        _frame = 0;
        _board.fill(0);
        _toCheck.fill(1);
        _changed.fill(1);
        switch (n)
        {
            case -1:
                randomUniverse();
                break;

            case 2: // Глайдер
                for (int i = 0; i < _m / 5; i++)
                    _board.pasteMatr(Glider(), 0, i * 5);
                for (int i = 0; i < _n / 5; i++)
                    _board.pasteMatr(Glider(), i * 5, 0);
                break;

            case 3: // Моё изобретение
                _board.pasteMatr(MyInv(), _n / 2 - 3, _m / 2 - 4);
                break;

            case 4: // МехМат 🤍
                _board.pasteMatr(MMCS(), _n / 2 - 5, _m / 4 - 5);
                _board.pasteMatr(MMCS(), _n / 2 - 5, 3 * _m / 4 - 5);
                break;

            case 5: // Гурмэ
                _board.pasteMatr(Gourmet(), _n / 2 - 10, _m / 2 - 10);
                break;

//            case 1: // Задаёте свой Мир
//            case 0: // Задаёте свой Мир
//                for (int i = 0; i < _n; ++i)
//                {
//                    for (int j = 0; j < _m; ++j)
//                    {
//                        if (j == 0 && i == 0)
//                        {
//                            _board[0][0] = n;
//                            continue;
//                        }
//                        else
//                        {
//                            cin >> _board[i][j];
//                            if (_board[i][j] != 0 && _board[i][j] != 1)
//                            {
//                                randomUniverse();
//                                return;
//                            }
//                        }
//                    }
//                }
//                fflush(stdin);
                break;
        }
    }

    void universeInit(const string & s)
    {
        int sInd = 0;
        char prevElem = ' ';
        int elem = 0;
        for (int i = 0; i < _n; ++i)
        {
            for (int j = 0; j < _m; ++j)
            {
                if (sInd < s.length() - 1)
                {
                    while (s[sInd] == ' ')
                    {
                        prevElem = s[sInd];
                        sInd++;
                    }
                    elem = s[sInd] - '0';
                    sInd++;
                }
                else
                    cin >> elem;
                if (elem != 0 && elem != 1 || prevElem != ' ')
                {
                    randomUniverse();
                    return;
                }
                else
                {
                    _board[i][j] = elem;
                }
                if (i == 0 && j != 19)
                    prevElem = elem;
                else
                    prevElem = ' ';
            }
        }
    };

    string toString(cellColor theme)
    {
        return _board.toString(theme);
    }

//    void followFrame(ull frame)
//    {
//        int i = ((frame - 1) / 100) % 40;
//        int j = (frame - 1) % 100;
//        int prevI = ((frame - 2) / 100) % 40;
//        int prevJ = (frame - 2) % 100;
//
//        if (frame != 1)
//        {
//            if (_board[prevI][prevJ] == color(BG, HIDE, 232) + "0" + reset)
//                _board[prevI][prevJ] = color(BG, HIDE, 255) + "0" + reset;
//            else
//                _board[prevI][prevJ] = color(BG, HIDE, 232) + "0" + reset;
//        }
//
//        if (_board[i][j] == color(BG, HIDE, 232) + "0" + reset)
//            _board[i][j] = color(BG, HIDE, 255) + "0" + reset;
//        else
//            _board[i][j] = color(BG, HIDE, 232) + "0" + reset;
//    }

    friend ostream & operator<<(ostream & os, const Universe & uni)
    {
        string white = color(BG, HIDE, 255);
        string black = color(BG, HIDE, 232);
        for (int i = 0; i < uni._n; ++i)
        {
            for (int j = 0; j < uni._m; ++j)
            {
                os << (uni._board[i][j] ? white + "1" + reset : black + "0" + reset);
            }
            if (i != uni._n - 1) os << "\n";
        }
        return os;
    }

    matrix<int> Example()
    {
        matrix<int> eg(20, 130);
        eg.pasteMatr(Glider(), 8, 12);
        eg.pasteMatr(MyInv(), 8, 12 + 130 / 4);
        eg.pasteMatr(MMCS(), 6, 10 + 2 * 130 / 4);
        eg.pasteMatr(Gourmet(), 0, 6 + 3 * 130 / 4);

        return eg;
    }
};