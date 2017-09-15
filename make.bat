REM Batch file to automate building to main directory in windows 10
msbuild out.vcxproj
copy .\Debug\out.exe ..
