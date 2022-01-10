#pragma once

#include <iostream>
#include <imgui.h>
#include <stdio.h>


/*

General Table Design

 __________
| ________ |
| | TEXT | | <-- Status text Box around text hugs largest text size to limit re-sizing
| |------| |
| | (==) | | <-- Indicatior "Lamp"
| |______| |
|__________| <-- Button Border This hugs the window

*/

class displayTable
{
public:
	char* name = "Default Table";
	int rows = 1;
	int columns = 1;


private:


};

