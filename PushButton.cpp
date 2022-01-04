#include "PushButton.h"



void PushButton::init(buttonParameters &button) {
    //Let's try to render a button shape....
    { //Prototype a button render.
        bool buttonClicked = true;

        ImGui::Begin(button.name, &buttonClicked, ImGuiWindowFlags_None);

        // Let's taks some window measuremnets and locations
        const ImVec2 buttonSize = ImVec2(300, 300); // 300 x 300 default size. This will be bound checked



        const ImVec2 buttonPosition = ImGui::GetWindowPos();

        auto buttonWidth = buttonSize.x;
        auto buttonHeight = buttonSize.y;

        auto pDrawList = ImGui::GetWindowDrawList(); //Lets pull a list of items to render.  We'll append to this below

        ImColor RED = ImColor(225, 0, 0);
        ImColor GREEN = ImColor(0, 225, 0);
        ImColor BLUE = ImColor(0, 0, 255);
        ImColor YELLOW = ImColor(255, 255, 0);
        ImColor CYAN = ImColor(0, 255, 255);
        ImColor MAGNETA = ImColor(255, 0, 255);

        auto buttonStatusColor = ImColor(225, 225, 0);

        //AddRect(const ImVec2 & p_min, const ImVec2 & p_max, ImU32 col, float rounding, ImDrawFlags flags, float thickness)
        
            pDrawList->AddRect(ImVec2(10 + buttonPosition.x, 10 + buttonPosition.y), ImVec2(300 + buttonPosition.x, 300 + buttonPosition.y), RED, 10, 0, 20);
        

        std::string text = "hello world";


        auto textWidth = ImGui::CalcTextSize(text.c_str()).x;

        ImGui::SetCursorPosX((buttonWidth - textWidth) * 0.5f);
        ImGui::Text(text.c_str());

        ImGui::End();

    }
}


