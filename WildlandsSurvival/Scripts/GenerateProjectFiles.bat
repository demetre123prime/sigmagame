@echo off
setlocal
set "UPROJECT=%~dp0..\WildlandsSurvival.uproject"
for %%V in (5.6 5.5 5.4) do (
  if exist "C:\Program Files\Epic Games\UE_%%V\Engine\Build\BatchFiles\GenerateProjectFiles.bat" (
    call "C:\Program Files\Epic Games\UE_%%V\Engine\Build\BatchFiles\GenerateProjectFiles.bat" -project="%UPROJECT%" -game -engine
    exit /b %%errorlevel%%
  )
)
echo Unreal Engine 5.4, 5.5, or 5.6 was not found in the standard install directory.
echo Install UE through Epic Games Launcher, then right-click the .uproject and choose Generate Visual Studio project files.
exit /b 1
