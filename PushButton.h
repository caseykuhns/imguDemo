#pragma once
#include <iostream>
#include <imgui.h>


/*

General button design 
Text diplays the state ON/OFF/AUTO
The (==) indicator displays a color to indicate active or not active
 __________
| ________ |      
| | TEXT | | <-- Status text Box around text hugs largest text size to limit re-sizing
| |------| | 
| | (==) | | <-- Indicatior "Lamp"
| |______| |
|__________| <-- Button Border This hugs the window

*/

// These are button parameters that the user can edit
// Variables that are needed to be tracked for rendering purposes are housed in private variables
// 

struct buttonParameters {
    
    char* name; // Unique name of each button NOTE: MUST BE A UNIQUE NAME

    ImVec2 position; // Button Position in frame
    ImVec2 size;     // Total button size

    float borderThickness; // Border thickness of the button (NOTE: This will be bound checked to keep image intelligible)

    ImVec4 statusTextColor; // Color of status text (

    const char* stateON   = "ON";
    const char* stateOFF  = "OFF";
    const char* stateAUTO = "AUTO";

};


class PushButton 
{
public:
	void init(buttonParameters &button);

private:
    ImVec2 textPos; // Text position in Button
    float textHeight; // Height of font used for text (for resizing buttons)

};



/*
ImColor RED = ImColor(225, 0, 0);
ImColor GREEN = ImColor(0, 225, 0);
ImColor BLUE = ImColor(0, 0, 255);
ImColor YELLOW = ImColor(255, 255, 0);
ImColor CYAN = ImColor(0, 255, 255);
ImColor MAGNETA = ImColor(255, 0, 255);
*/