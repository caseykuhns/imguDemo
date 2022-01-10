#include "PushButton.h"

void PushButton::draw(buttonParameters &b) {

    ImColor RED = ImColor(225, 0, 0);
    ImColor GRN = ImColor(0, 225, 0);
    ImColor BLU = ImColor(0, 0, 225);
    ImColor WHT = ImColor(225, 225, 225);

    // Begin Rendering the Button

    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0)); // REMEMBER YOU HAVE TO POP STYLE VAR AT IMGUI::END():

       ImGui::Begin(b.name, &b.clicked, ImGuiWindowFlags_NoTitleBar|ImGuiWindowFlags_NoResize);       
       ImGui::SetWindowSize(b.size);

       std::string text;

       b.position = ImGui::GetWindowPos(); // Get the position of the window to render everything else

        auto bDrawList = ImGui::GetWindowDrawList(); // Lets pull a list of items to render.  We'll append to this.

        // Make some state decisions
        if (ImGui::IsWindowHovered()) {
            
            if (b.enabledState == true) { 
                if (ImGui::IsMouseDoubleClicked(0) == true) b.activeState = !b.activeState;
                // Button is clickable
            }
            else {
                // Button is not clickable
            }
            debugWindow(b); //If hovered, popup debug window
        }

        // Now that we shoudl understand the state lets make some color and object choices to show the correct state

        if (b.activeState == 1) text = "ON";
        else text = "OFF";


        // Scale the font to fit in the box
        
        // Lets Identify the longest string available
        // Because I'm lazy I'm going to just identify it as "auto"  Add the "_" to create the buffer size
        std::string longestString = "AUTO_";
        ImVec2 longStringSize = ImGui::CalcTextSize(longestString.c_str());  // Calculate the size of the selected string

        // Let's calculate some Button box sizing
        b.buttonBoundSize = ImVec2((b.size.x * 0.8f), (b.size.y * 0.8f));
        b.textBoxSize = ImVec2((b.size.x * 0.8f), (b.size.y * 0.8f / 2.0f));
 
        ImVec2 Scale;
        Scale.x = (b.textBoxSize.x / (longStringSize.x * 1.1f));
        Scale.y = (b.textBoxSize.y / (longStringSize.y * 1.1f));
        if (Scale.x > Scale.y) ImGui::SetWindowFontScale(Scale.y);
        else ImGui::SetWindowFontScale(Scale.x);

        //Make a working Variable to store offest calculations
        ImVec2 offsetBegin, offsetEnd;

        // Draw alert 
        offsetBegin.x = (b.alertWeight / 2) + b.position.x;
        offsetBegin.y = (b.alertWeight / 2) + b.position.y;
        offsetEnd.x =  b.position.x + b.size.x - (b.alertWeight / 2);
        offsetEnd.y = b.position.y + b.size.y - (b.alertWeight / 2);
        bDrawList->AddRect(offsetBegin, offsetEnd, WHT, (b.alertWeight / 2), 0, b.alertWeight);

        // Draw button boundary
        offsetBegin.x = b.position.x + ((b.size.x - b.buttonBoundSize.x) / 2);
        offsetBegin.y = b.position.y + ((b.size.y - b.buttonBoundSize.y) / 2);
        offsetEnd.x = offsetBegin.x + b.buttonBoundSize.x;
        offsetEnd.y = offsetBegin.y + b.buttonBoundSize.y;
        bDrawList->AddRect(offsetBegin, offsetEnd, WHT, 0, 0, b.borderWeight);

        // Draw Divider 
        const float dividerPercentage = 0.4f; // Set the percentage of the top of the button reserverd for text. Text and indicators scale from this number
        // offsetBegin.x  We can reuse the x points since we are just adding a divider
        // offsetEnd.x  We can reuse the x points since we are just adding a divider
        offsetBegin.y = offsetBegin.y + (b.buttonBoundSize.y * dividerPercentage); //Put the divider at a percentage from the top
        offsetEnd.y = offsetBegin.y; //Since it's a horizontal line the y points will be the same. 
        bDrawList->AddLine(offsetBegin, offsetEnd, WHT, b.borderWeight);

        // Calculate the indicator size
        ImVec2 indicator;
        indicator.x = b.buttonBoundSize.x * 0.8f; //make the indicator a percentage smaller than the button boundary.
        indicator.y = (b.buttonBoundSize.y * (1 - dividerPercentage)) - (b.buttonBoundSize.x - indicator.x);
        // Draw Indicator
        offsetBegin.x = b.position.x + ((b.size.x - indicator.x) / 2);
        offsetBegin.y = offsetBegin.y + (indicator.y - (b.buttonBoundSize.x - indicator.x))/2; //TODO Figure out how to make this work propperlly....
        offsetEnd.x = offsetBegin.x + indicator.x;
        offsetEnd.y = offsetBegin.y + indicator.y;
 
        if (b.activeState == 1) bDrawList->AddRectFilled(offsetBegin, offsetEnd, RED, 0, 0);
        else bDrawList->AddRect(offsetBegin, offsetEnd, WHT, 0, 0, b.borderWeight);


        auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

        ImGui::SetCursorPosX((b.size.x - textWidth) * 0.5f);
        ImGui::SetCursorPosY(b.borderWeight + ((b.size.y - b.textBoxSize.y) / 5)); //MAGIC NUMBER
        ImGui::Text(text.c_str());
        ImGui::SetWindowFontScale(1);
        ImGui::End();
        ImGui::PopStyleVar(); // go back to normal style vars
}


void PushButton::debugWindow(buttonParameters& b) {

    ImGui::BeginTooltip();
    ImGui::PushTextWrapPos(ImGui::GetFontSize() * 40.0f);
    ImGui::Text("Window name = %s", b.name);
    ImGui::Text("Window enabled = %d", b.enabledState);
    ImGui::Text("Window active = %d", b.activeState);
    ImGui::Text("Window position x = %f , y = %f", b.position.x, b.position.y);
    ImGui::Text("Window size x = %f , y = %f", b.size.x, b.size.y);
    ImGui::PopTextWrapPos();
    ImGui::EndTooltip();
}
