## HOW TO RUN
just run the "main_debug.exe" or "main_release.exe" inside the "run" folder
_make sure to not move them outside of that folder structure_ <br>


<br> <br> <br> 




## HOW TO BUILD
assuming make (mingw; see **step X** or **step Y**) is installed in windows system OR included in the environment; <br>
**OR if not** you could instead do the following: <br> <br>

### if u are accessing from the WWW
- & if u do not have g++ and make installed; 
- download the zip file or clone this repository instead;
- extract this in the downloads folder
- download "https://github.com/skeeto/w64devkit/releases/download/v1.21.0/w64devkit-1.21.0.zip"
- extract it in the downloads folder
- open powershell and run this script:

```md
# for make and g++ to be addedd onto the current path instance of powershell
$env:Path = "C:\Users\_______PC_NUMBER______\Downloads\w64devkit\bin;$env:Path";
cd "C:\Users\________PC_NUMBER________\Downloads\smashbuton-raylib-main\build\"
make runrelease
```

<br> <br>



### if u have access to the usb to be passed onto the prof;
- & if u do not have g++ and make installed 
- open powershell and run this script:

```md
# for make and g++ to be addedd onto the current path instance of powershell
$env:Path = "____DRIVE_LETTER____:\group1\w64devkit\bin;$env:Path";
cd "____DRIVE_LETTER____:\group1\smashbuton-raylib-main\build\"
make runrelease
```



<br> <br> <br>
------------------------------------------------------
<br> <br> <br>

#### step X (installing msys for g++)
1. Install msys; please follow very closely: [Installing the MinGW-w64 toolchain](https://code.visualstudio.com/docs/cpp/config-mingw#_installing-the-mingww64-toolchain)
2. download the repository (either zip or cloning; just make sure to extract the zip)
3. run the msys terminal
4. go to the repository that you downloaded in step X:2ndstep inside the msys terminal 
- this can be done using the `cd parentfoldername/childfoldername/childchildfoldername/etc.etc./`
- using `ls` can list the folders and files in your current directory (i.e., location);
5. Do `ls` to check if you are at the intended location;
- YOU SHOULD SEE the folders: build, depreciated, include, lib, src, Makefile, README.md, plan.txt
6. If all from the above is oke, run `mingw32-make.exe`
<br> <br> <br>

#### step Y (installing mingw directly for g++)
1. download and choose this choice **[w64devkit-1.21.0.zip](https://github.com/skeeto/w64devkit/releases)**
2. extract the zip file from somewhere (LET US *SAY* youve put it in `C:\Users\usernamemobading\Desktop`); take note of the location of the **bin folder** that is inside the extracted zip (e.g., `C:\Users\usernamemobading\Desktop\w64devkit\bin`)
3. edit your path environment variable:
- type `environment variables` in windows search bar
- find `Environment Variables` at the bottom-right of the "system properties window"; it should appear a new window
- two main boxes; the top (user variables for ______), double pindot `Path`; it should appear a new window
- pindot new, and paste the location of the bin folder of the extracted file from step Y:2ndstep;
4. press oke, oke, oke to exit the `system properties window` <br><br>
5. download the repository (either zip or cloning; just make sure to extract the zip)
6. open powershell
7. navigate or go to the extracted repository
8. if all from the above is oke, run `make.exe`
