CFLAGS = -Wall -Wno-missing-braces -std=c++17
LINKFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
BUILD_MODE ?= DEBUG
ifeq ($(BUILD_MODE), DEBUG)
    CFLAGS += -g -O0 
else
	CFLAGS += -s -O1
endif



#	$env:Path = "~/Documents/w64devkit/bin/$env:Path;"

#linux:
#default:
	#g++ "src/*.cpp"  -o build/main.out\
		$(CFLAGS) \
		-I include \
		-L lib \
		$(LINKFLAGS)
	#./build/main.exe

# windows
default:	# debug mode
	g++ "src/*.cpp" -o main_debug.exe\
		$(CFLAGS) \
		-I include \
		-L lib \
		$(LINKFLAGS)
	./main_debug.exe

release:	# release mode
	g++ "src/*.cpp" -o main_release.exe\
		-Wall -Wno-missing-braces -std=c++17 -s -O1 \
		-I include \
		-L lib \
		$(LINKFLAGS)
	./main_release.exe

rundebug:
	./main_debug.exe

runrelease:
	./main_release.exe

# -I D:\dev\gui\raylib\raylib\raylib\src 
#  default g++ folder
#  C:\ProgramData\mInGw64\1.20\w64devkit\bin
#
