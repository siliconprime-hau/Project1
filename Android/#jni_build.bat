call config.bat

setlocal

%CYGWIN_BASH% --login -c "cd %PROJECT_DIR% && %NDK_BUIL%"

endlocal