// Dear ImGui: standalone example application for SDL2 + DirectX 11
// (SDL is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs

#include "imgui.h"
#include "imconfig.h"
//#include "imgui.cpp"
//#include "imgui_draw.cpp"
//#include "imgui_widgets.cpp"
//#include "imgui_internal.h"
//#include "imgui_tables.cpp"
//#include "imstb_rectpack.h"
//#include "imstb_textedit.h"
//#include "imstb_truetype.h"

#include <stdio.h>

int main(int, char**)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();

    // Build atlas
    unsigned char* tex_pixels = NULL;
    int tex_w, tex_h;
    io.Fonts->GetTexDataAsRGBA32(&tex_pixels, &tex_w, &tex_h);

    for (int n = 0; n < 20; n++)
    {
        printf("NewFrame() %d\n", n);
        io.DisplaySize = ImVec2(1920, 1080);
        io.DeltaTime = 1.0f / 60.0f;
        ImGui::NewFrame();

        static float f = 0.0f;
        ImGui::Text("Hello, world!");
        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        ImGui::ShowDemoWindow(NULL);

        ImGui::Render();
    }

    printf("DestroyContext()\n");
    ImGui::DestroyContext();
    return 0;
}
