#pragma once
#include <iostream>
#include <imgui.h>
#include <stdio.h>



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
    
    bool clicked = true;

    char* name = "DefaultButton"; // Unique name of each button NOTE: MUST BE A UNIQUE NAME

    ImVec2 position = ImVec2(10.0, 10.0); // Button Position in frame
    ImVec2 size = ImVec2(60,60); // Total button size
    ImVec2 buttonBoundSize, textSize, textBoxSize;

    float borderWeight = 2; // Border thickness of the button (NOTE: This will be bound checked to keep image intelligible)
    float alertWeight = 5; // alert boundary

    bool activeState = false;  // Lets default the pushbutton state to inactive or "off" 
    bool enabledState = true;  // Button press enable, enabled by default.  Useful if you have the switch occupied by other autonomous systems

    ImVec4 statusColor; // Color of status indicator 

    const char* stateON   = "ON";
    const char* stateOFF  = "OFF";
    const char* stateAUTO = "AUTO";

};


class PushButton 
{
public:
	void draw(buttonParameters &b);

private:
    ImVec2 textPos; // Text position in Button
    float textHeight; // Height of font used for text (for resizing buttons)

    void debugWindow(buttonParameters &b);
};



/*
ImColor RED = ImColor(225, 0, 0);
ImColor GREEN = ImColor(0, 225, 0);
ImColor BLUE = ImColor(0, 0, 255);
ImColor YELLOW = ImColor(255, 255, 0);
ImColor CYAN = ImColor(0, 255, 255);
ImColor MAGNETA = ImColor(255, 0, 255);
*/