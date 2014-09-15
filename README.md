SDL2 on Android
===========

This project is going to teach you how to port SDL2 library to Android platform.

You need to do is following the steps.

## Environment
* OS: Ubuntu 12.04 64-bit
* NDK: r9d
* SDL2 Library source code [here](https://www.libsdl.org/download-2.0.php).
 
## Steps for porting
1. Copy _android-project_ from **<sdl2/source/code>/** to other location, ex: **<my/android-project>/**.
1. Create SDL folder and copy files into my/android-project/.

    ````
    mkdir -p "<my/android-project>/jni/SDL"
    cp -r "<sdl2/source/code>/src" "<my/android-project>/jni/SDL/"
    cp -r "<sdl2/source/code>/include" "<my/android-project>/jni/SDL/"
    cp -r "<sdl2/source/code>/Android.mk" "<my/android-project>/jni/SDL/"
    ````
1. Create a new file (ex: **main.c**) under **<my/android-project>/jni/src/** and define _main function_ like following

    ````
    // main.c
    #include "SDL.h"
    
    int main (int argc, char** argv) {
        // Some sdl code here
        return 0;
    }
    ````
1. Open **<my/android-project>/jni/src/Android.mk** and change **"YourSourceHere.c"** to yours (ex: **"main.c"**).
1. Compile SDL2 library by ndk tool.

    ````
    cd <my/android-project>/
    <your/ndk/path>/ndk-build
    ````
