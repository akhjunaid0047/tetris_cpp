#pragma once
#include <raylib.h>
#include <vector>
extern const Color darkgray = {26, 31, 40, 255};
extern const Color f94144 = {249, 65, 68, 255};
extern const Color f3722c = {243, 114, 44, 255};
extern const Color f8961e = {248, 150, 30, 255};
extern const Color f9c74f = {249, 199, 79, 255};
extern const Color n0be6d = {144, 190, 109, 255};
extern const Color f3aa8b = {67, 170, 139, 255};
extern const Color fi77590 = {87, 117, 144, 255};
std::vector<Color> getColour()
{
    return {darkgray, f94144, f3722c, f8961e, f9c74f, n0be6d, f3aa8b, fi77590};
}