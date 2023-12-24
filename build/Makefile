CFLAGS = -Wall -Wno-missing-braces -std=c++17
LINKFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
BUILD_MODE ?= DEBUG


ifeq ($(BUILD_MODE), DEBUG)
    CFLAGS += -g -O0 
else
	CFLAGS += -s -O1
endif


default:
	g++ "../src/*.cpp" -o main.exe\
		$(CFLAGS) \
		-I ../include \
		-L ../lib \
		$(LINKFLAGS)
# -I D:\dev\gui\raylib\raylib\raylib\src 
#  default g++ folder
#  C:\ProgramData\mInGw64\1.20\w64devkit\bin
#
