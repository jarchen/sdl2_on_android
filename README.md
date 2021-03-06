SDL2 on Android
===========

**SDL** is very popular and usefull library for rendering video, playin audio, and handling keyboard, mouse, and joystick events, etc.
For helping the person, who want to use SDL to develop any applications. This project is going to give the instruction for proting SDL2 library on Android devices.

## Environment
* OS: Ubuntu 12.04 64-bit
* NDK: r9d

## Download
* SDL2 source code download from [here](https://www.libsdl.org/download-2.0.php).
 
## Steps:
1. Copy _android-project_ from **${SDL2_SOURCE}/android-project** to other location (ex: **${your_path}/android-project**).
1. Create SDL folder and copy files into **${your_path}/android-project/**.

    ````
    mkdir "${your_path}/android-project/jni/SDL"
    cp -r "${SDL2_SOURCE}/src" "${your_path}/android-project/jni/SDL/"
    cp -r "${SDL2_SOURCE}/include" "${your_path}/android-project/jni/SDL/"
    cp "${SDL2_SOURCE}/Android.mk" "${your_path}/android-project/jni/SDL/"
    ````
1. Create a new c/c++ file (ex: [**main.c**](./android-project/jni/src/main.c)) under **${your_path}/android-project/jni/src/** and define _main function_ like following

    ````
    // main.c
    #include "SDL.h"
    
    int main (int argc, char** argv) {
        // Some sdl code here
        return 0;
    }
    ````
1. Change **"YourSourceHere.c"** to yours (ex: **"main.c"**) which defined in **${your_path}/android-project/jni/src/[Android.mk](./android-project/jni/src/Android.mk)**
1. Compile SDL2 library by ndk tool.

    ````
    cd ${your_path}/android-project/
    ${NDK_PATH}/ndk-build
    ````
1. Create a java file extends **SDLActivity** like [MainActivity.java](./android-project/src/my/app/MainActivity.java).

### Notes:
You can set the platforms you want to build for. Bulding platforms are defined by `APP_ABI` in **${your_path}/android-project/jni/[Application.mk](./android-project/jni/Application.mk)**

## Start to develop your SDL application.
