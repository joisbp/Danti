REM build script to create Editor.exe
@echo off
setlocal EnableDelayedExpansion

REM Get all source files to compile
SET fileNames = 
FOR /R %%i in (*.cpp) do (
   SET fileNames=!fileNames! %%i
)

SET assembly=Editor
SET compilerFlags=-g
REM -wall -Werror

SET includeFlags=-Isource -I../Engine/source/
SET linkerFlags=-L../bin/ -lEngine.lib
SET defines=-Ddebug -DIMPORT

echo "Building %assembly%..."
clang %fileNames% %compilerFlags% %includeFlags% %defines% %linkerFlags% -o ../bin/%assembly%.exe