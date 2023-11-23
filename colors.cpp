#include "colors.h"
#include <algorithm>

string color (colorType type, textMode mode, int i)
{
    return "\033[" + getTextMode(mode) + getColorType(type) + ";5;" + to_string(i) + "m";
}

string getColorType(colorType type)
{
    switch (type)
    {
        case FG: return "38";
        case BG: return "48";
    }
    return "";
}

string getTextMode(textMode mode)
{
    switch (mode)
    {
        case NO: return "";
        case LIGHT: return "1;";
        case DARK: return "2;";
        case ITALIC: return "3;";
        case UNDERLINE: return "4;";
        case BLINK: return "5;";
        case HIDE: return "8;";
        case CROSS: return "9;";
    }
    return "";
}

string getGColor(gColors clr)
{
    switch (clr)
    {
        case G1: return color(BG, HIDE, 22);
        case G2: return color(BG, HIDE, 28);
        case G3: return color(BG, HIDE, 34);
        case G4: return color(BG, HIDE, 40);
        case G5: return color(BG, HIDE, 46);
        case G6: return color(BG, HIDE, 82);
        case G7: return color(BG, HIDE, 118);
        case G8: return color(BG, HIDE, 119);
    }
    return "";
}

string getPColor(pColors clr)
{
    switch (clr)
    {
        case P1: return color(BG, HIDE, 57);
        case P2: return color(BG, HIDE, 93);
        case P3: return color(BG, HIDE, 129);
        case P4: return color(BG, HIDE, 165);
        case P5: return color(BG, HIDE, 201);
        case P6: return color(BG, HIDE, 207);
        case P7: return color(BG, HIDE, 213);
        case P8: return color(BG, HIDE, 219);
    }
    return "";
}

string getRColor(rColors clr)
{
    switch (clr)
    {
        case R1: return color(BG, HIDE, 52);
        case R2: return color(BG, HIDE, 88);
        case R3: return color(BG, HIDE, 124);
        case R4: return color(BG, HIDE, 125);
        case R5: return color(BG, HIDE, 160);
        case R6: return color(BG, HIDE, 161);
        case R7: return color(BG, HIDE, 162);
        case R8: return color(BG, HIDE, 194);
    }
    return "";
}

string getColor(cellColor clr, int cell)
{
    switch (clr)
    {
        case rColor: return getRColor((rColors)cell);
        case gColor: return getGColor((gColors)cell);
        case pColor: return getPColor((pColors)cell);
    }
}

cellColor getTheme(const string & s, cellColor theme)
{
    if (s == "rColor") return rColor;
    if (s == "gColor") return gColor;
    if (s == "pColor") return pColor;
    return theme;
}