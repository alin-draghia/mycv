@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
set compiler_flags=/Od /Zi /EHsc /MDd /Iopencv/include
set linker_flags=/OUT:sample.exe
cl.exe %compiler_flags% ^
    sample\Main.cpp^
    opencv/x64/vc14/lib/opencv_core2413d.lib^
    opencv/x64/vc14/lib/opencv_imgproc2413d.lib^
    opencv/x64/vc14/lib/opencv_highgui2413d.lib^
    opencv/x64/vc14/lib/opencv_legacy2413d.lib^
     /link %linker_flags%
