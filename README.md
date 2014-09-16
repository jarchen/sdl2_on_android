SDL2 on Android
===========

This project is going to teach you how to port SDL2 library to Android platform.

You need to do is following the steps.

## Environment
* OS: Ubuntu 12.04 64-bit
* NDK: r9d
* SDL2 Library source code [here](https://www.libsdl.org/download-2.0.php).
 
## Steps for porting
1. Copy _android-project_ from **${SDL2_SOURCE}/android-project** to other location, ex: **${your_path}/android-project**.
1. Create SDL folder and copy files into my/android-project/.

    ````
    mkdir "${your_path}/android-project/jni/SDL"
    cp -r "${SDL2_SOURCE}/src" "${your_path}/android-project/jni/SDL/"
    cp -r "${SDL2_SOURCE}/include" "${your_path}/android-project/jni/SDL/"
    cp "${SDL2_SOURCE}/Android.mk" "${your_path}/android-project/jni/SDL/"
    ````
1. Create a new file (ex: **main.c**) under **${your_path}/android-project/jni/src/** and define _main function_ like following

    ````
    // main.c
    #include "SDL.h"
    
    int main (int argc, char** argv) {
        // Some sdl code here
        return 0;
    }
    ````
1. Open **${your_path}/android-project/jni/src/Android.mk** and change **"YourSourceHere.c"** to yours (ex: **"main.c"**).
1. Compile SDL2 library by ndk tool.

    ````
    cd ${your_path}/android-project/
    ${NDK_PATH}/ndk-build
    ````
