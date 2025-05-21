@echo off
:: Set shortcut name and target
set "SHORTCUT_NAME=TypeLangFixer.lnk"
set "SHORTCUT_PATH=./install_dir"
set "TARGET_PATH=install_dir/bin/TypeLangFixer.exe"

:: Create the shortcut using PowerShell
powershell -Command "$s=(New-Object -COM WScript.Shell).CreateShortcut('%SHORTCUT_PATH%');$s.TargetPath='%TARGET_PATH%';$s.Save()"

echo Shortcut created on Desktop: %SHORTCUT_NAME%
pause