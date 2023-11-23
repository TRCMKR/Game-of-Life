#pragma once

#include <iostream>
#include <string>

//using std::string;
//using std::to_string;
//using std::out_of_range;
//using std::vector;
//using std::istream;
//using std::ostream;
//using std::cin;
//using std::cout;
//using std::ios;

using namespace std;

// Важные константы
const string reset = "\033[0m";
const string FGblack = "\033[38;5;232m";
const string FGwhite = "\033[38;5;255m";
const string BGblack = "\033[48;5;232m";
const string BGwhite = "\033[48;5;255m";
const string hideCursor = "\033[?25l";
const string showCursor = "\033[?25h";

// Темы для игры
enum cellColor {rColor, pColor, gColor};
enum rColors {R1 = 1, R2, R3, R4, R5, R6, R7, R8};
enum pColors {P1 = 1, P2, P3, P4, P5, P6, P7, P8};
enum gColors {G1 = 1, G2, G3, G4, G5, G6, G7, G8};

// Типы текста
enum colorType {BG, FG};
enum textMode {NO, LIGHT, DARK, ITALIC, UNDERLINE, BLINK, HIDE, CROSS};

// Узнать тему из строки
cellColor getTheme(const string & s, cellColor theme);

// Получить цвет из темы
string getColor(cellColor clr, int cell);

// Получить цвет из темы R
string getRColor(rColors clr);

// Получить цвет из темы P
string getPColor(pColors clr);

// Получить цвет из темы G
string getGColor(gColors clr);

// Любой 8битный цвет и текст любого типа
string color (colorType type, textMode mode, int i);

// Получить положение цвета Foreground/Background
string getColorType(colorType type);

// Получить стиль текста
string getTextMode(textMode mode);