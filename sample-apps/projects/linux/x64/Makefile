DEMO_SRC_PATH := ../../../src

API_RES_PATH := ../../../../resources/non-android
API_INC_PATH := ../../../../include
API_LIB_PATH := ../../../../lib/linux/x64

FLAGS := -g -ansi -m64 -DLICENSEE=\"test\" -DLICENSE_KEY=\"sRwAAAUEdGVzdGZnyBMppn/pdSTAoOY5lE/kWSL7UHFkgbjYzcTqTGc7wmmZ/nTu9ZbhWa9BxvA4K7PMoHXQ7wRUCV4dmEobS4xOhmcZ/i80nSZLcEVlYef3iZS145gmVDgjYfvAAqm+uEq7nPnWA/p+FtfSeXsD1A9TryaLjM7Y45SIaBVl3mBvDPENsat/7thIUgUyFt/Fo0rmKFdIuoEIq450G5wyVxssc9cDf++Uu+1Z+LJ7zte+B5bHyTq8YEebrafoqAiEQT5bOMQcfcCZFn5b6wG3fk0TqoMvD3VtOQFWOFLLFyfVlb+P2q3doJyXiuxcY4DEzuVeVdLFbPJ5V/1/wkdPlSPy3w==\"
CC    := gcc

all: run

demo: $(DEMO_SRC_PATH)/demo/demo.c
	$(CC) $(FLAGS) $(DEMO_SRC_PATH)/demo/demo.c -o demo -I $(API_INC_PATH) -I $(DEMO_SRC_PATH)/utils -L $(API_LIB_PATH) -lRecognizerApi

run-demo: demo
	LD_LIBRARY_PATH=$(API_LIB_PATH) ./demo $(API_RES_PATH) $(DEMO_SRC_PATH)/demo/id.jpg

run: run-demo

clean:
	rm demo || true
