#include "universe.h"

void Universe::randomUniverse()
{
    for (int i = 0; i < _n; ++i)
    {
        for (int j = 0; j < _m; ++j)
        {
            _board[i][j] = rand() % 2;
        }
    }
}

void Universe::Update()
{
    if (_frame == 5)
        _frame = 5;
    for (int i = 0; i < _n; ++i)
    {
        for (int j = 0; j < _m; ++j)
        {
            if (i == 24 && j == 64 && _frame == 5)
                _frame = 5;
            if (_toCheck[i][j])
                changeState(i, j);
            else
            {
                _changed[i][j] = 0;
                _newBoard[i][j] = _board[i][j];
            }
        }
    }

    for (int i = 0; i < _n; ++i)
    {
        for (int j = 0; j < _m; ++j)
        {
            if (!_changed.any(i, j) )
                _toCheck[i][j] = 0;
            else
                _toCheck[i][j] = 1;
        }
    }
    _board = _newBoard;

    if (_init == 4)
    {
        if (_frame >= 16 && (_frame - 16) % 7 == 0) {
            addToUniverse(Heart(), 1 * _n / 6 - 4, _m / 2, 0, 0);
            addToUniverse(Heart(), 3 * _n / 6 - 3, _m / 2, 5, 5);
            addToUniverse(Heart(), 5 * _n / 6, _m / 2, 0, 0);
        }

        if (_frame == 20) {
            _board.fill(_n / 2 - 5, _m / 4 - 5, 8, 8, 0);
            _board.fill(_n / 2 - 5, 3 * _m / 4 - 5, 8, 8, 0);
        }
    }

    _frame++;
}

bool Universe::checkState(int i, int j)
{
    int alive = countAlive(i, j);
    int cell = _board[i][j];
    if (!cell && alive == 3)
    {
        return false;
    }
    else if (cell && alive != 2 && alive != 3 )
    {
        return false;
    }

    if (cell) _board[i][j] = alive;

    return true;
}

void Universe::changeState(int i, int j)
{
    if (!checkState(i, j))
    {
        _newBoard[i][j] = !_board[i][j];
        _changed[i][j] = 1;
    }
    else
    {
        _newBoard[i][j] = _board[i][j];
        _changed[i][j] = 0;
    }
}

int Universe::countAlive(int posX, int posY) const
{
    int res = 0;
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

            if (_board[x][y]) res++;
        }
    }
    return res;
}

void Universe::addToUniverse(const matrix<int> & mtr, int posI, int posJ, int n, int m)
{
    _board.pasteMatr(mtr, posI, posJ);
    if (n != 0 && m != 0)
        _changed.fill(posI - 1, posJ - 1, n + 2, m + 2, 1);
        _toCheck.fill( posI - 1, posJ - 1, n + 2, m + 2, 1);
}