@REM Build for Visual Studio compiler. Run your copy of vcvars32.bat or vcvarsall.bat to setup command-line compiler.
@set OUT_DIR=Debug
@set OUT_EXE=demo
@set INCLUDES=/I..\imgui /I..\imgui\backends /I..\imgui\examples\libs\glfw\include\GLFW\glfw3.h
@set SOURCES=main.cpp ..\imgui\backends\imgui_impl_glfw.cpp ..\imgui\backends\imgui_impl_opengl3.cpp ..\imgui\imgui*.cpp
@set LIBS=/LIBPATH:..imgui\examples\libs\glfw\lib-vc2010-64\glfw3.lib opengl32.lib gdi32.lib shell32.lib
mkdir %OUT_DIR%
cl /nologo /Zi /MD %INCLUDES% %SOURCES% /Fe%OUT_DIR%/%OUT_EXE%.exe /Fo%OUT_DIR%/ /link %LIBS%
