To compile fonts into your program you can follow instructions here: https://github.com/ocornut/imgui/blob/master/misc/fonts/binary_to_compressed_c.cpp

OR just use the precompiled exe program called binary_to_compressed_c.

In command line type:

binary_to_compressed_c  "YOUR FONT.ttf/otf" fontNameInProgram > fontFileName.cpp

This will create a .cpp that you can embed in yoursource so you don't have to carry fonts with you in your deployment.   You might be able to use this for images too but I haven't tried it.

Then to load your font use 

font = io.Fonts->AddFontFromMemoryCompressedTTF( your font name as defined in .cpp);