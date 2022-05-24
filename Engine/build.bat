REM build script to create Engine Dll
@echo off
setlocal EnableDelayedExpansion

REM Get all source files to compile
SET fileNames = 
FOR /R %%i in (*.cpp) do (
   SET fileNames=!fileNames! %%i
)

SET assembly=Engine
SET compilerFlags=-g -shared -Wvarargs -Wall -Werror
REM -wall -Werror

SET includeFlags=-Isource -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/um" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/ucrt" -I"C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0/shared"

SET defines=-Ddebug -DEXPORT -DCRT_SECURE_NO_WARNINGS

echo "Building %assembly%..."
clang %fileNames% %compilerFlags% %includeFlags% %defines% -o ../bin/%assembly%.dll