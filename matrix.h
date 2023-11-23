#pragma once

#include "colors.h"

#include <chrono>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <ctime>
#include <ostream>
#include <istream>
#include <random>
#include <vector>
#include <string>
#include <typeinfo>

template<typename T>
class matrix
{
private:
    vector< vector<T> > _data;

public:
    matrix(int n, int m): _data(n)
    {
        for (int i = 0; i < n; i++)
            _data[i].resize(m);
    }

    vector<T> & operator[](int i)
    {
        return _data[i];
    }

    vector<T>  operator[](int i) const
    {
        return _data[i];
    }

    int size() const
    {
        return _data.size();
    }

    // Ввод с клавиатуры
    friend istream & operator>>(istream & is, matrix<T> & matr)
    {
        int n = matr.size();
        int m = matr[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                bool cell;
                cin >> cell;
                matr._data[i][j] = cell;
            }
        }
        return is;
    }

    // Вставить другую матрицу в любую точку текущей
    void pasteMatr(const matrix<T> & matr, int posI, int posJ)
    {
        int n = matr.size();
        int m = matr[0].size();
        if (posI + n > _data.size()) throw out_of_range("int posI is out of range");
        if (posJ + m > _data[0].size()) throw out_of_range("int posJ is out of range");

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                _data[i + posI][j + posJ] = matr[i][j];
            }
        }
    }

    // Реализация чтения матрицы из строки
    matrix<T> & operator=(string s)
    {
        int i = 0;
        int j = 0;
        char prevLex = ' ';
        for (char lexem: s)
        {
            if (lexem == ' ')
                j++;
            else if (prevLex != ' ')
            {
                i++;
                j = 0;
                _data[i][j] = lexem - '0';
            }
            else
                _data[i][j] = lexem - '0';

            prevLex = lexem;
        }

        return *this;
    }

    // Представление матрицы в виде цветного «экрана»
    string toString(cellColor theme)
    {
        string black = color(BG, HIDE, 232);
        string res;
        res.reserve(_data.size() * _data[0].size());
        int i = 0;
        for (const vector<int> & vec: _data)
        {
            for (int elem: vec)
            {
                string s = (elem ? getColor(theme, elem) : black)+ to_string(elem) + reset;
                res.append(s);
            }
            i++;
            if (i < _data.size())
                res.append("\n");
        }

        return res;
    }

    // Есть ли живые рядом
    bool any(int posX, int posY) const
    {
        int _n = _data.size();
        int _m = _data[0].size();
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                int x = posX;
                int y = posY;
                if (i == 0 && j == 0)
                    continue;

                if (x + i < 0) x = _n + i;
                else x = (x + i) % _n;
                if (y + j < 0) y = _m + j;
                else y = (y + j) % _m;

                if (_data[x][y])
                    return true;
            }
        }
        return false;
    }

    // Заполнить всю матрицу одним элементом
    void fill(T elem)
    {
        for (vector<T> & x: _data)
            std::fill(x.begin(), x.end(), elem);
    }

    // Неправильное заполнение учатска, но на самом деле оказалось имеет интересный эффект
    void fillIncor(int posI, int posJ, int n, int m, T elem)
    {
        for (int i = 0; i < n; ++i)
            std::fill(_data[posI + i].begin() + posJ, _data[posI + i].end() + m, elem);
    }

    // Заполнить участок матрицы
    void fill(int posI, int posJ, int n, int m, T elem)
    {
        for (int i = 0; i < n; ++i)
            std::fill(_data[posI + i].begin() + posJ, _data[posI + i].begin() + posJ + m, elem);
    }

    // Посчитать живых рядом и вписать значение в клетку
    void countAlive()
    {
        int _n = _data.size();
        int _m = _data[0].size();
        for (int posX = 0; posX < _n; posX++)
        {
            for (int posY = 0; posY < _m; posY++)
            {
                int res = 0;
                if (_data[posX][posY]) {
                    for (int i = -1; i < 2; i++) {
                        for (int j = -1; j < 2; j++) {
                            int x = posX;
                            int y = posY;
                            if (i == 0 && j == 0)
                                continue;

                            if (x + i < 0) x = _n + i;
                            else x = (x + i) % _n;
                            if (y + j < 0) y = _m + j;
                            else y = (y + j) % _m;

                            if (_data[x][y]) res++;
                        }
                    }
                }
                _data[posX][posY] = res;

            }
        }

    }
};