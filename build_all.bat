@echo off
REM Build Everything

PUSHD Engine
CALL build.bat
POPD
if %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

PUSHD Editor
CALL build.bat
POPD
if %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

echo "Build Successfull"