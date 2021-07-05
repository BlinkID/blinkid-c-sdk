DEMO_SRC_PATH := ../../../src

API_RES_PATH := ../../../../resources/non-android
API_INC_PATH := ../../../../include
API_LIB_PATH := ../../../../lib/linux/x64

FLAGS := -g -ansi -m64 -DLICENSEE=\"test\" -DLICENSE_KEY=\"sRwAAAUEdGVzdGZnyBMppn/pdSTAoOSBvuxZEXwor3IxMt+wBXbyb+2436AUWDLJvA+g51k+t6W7PBs3W/9L0BusgnJaNPqyDI+PXHX4yUpE6tjFGPaHVP5kn8bVEo+oxgZnro5T5B3jNSFisda6SPdXfvm9HvLiH80fuNcjgPWQhfQrNLtbwDp8M5+gjacUhzVZ2bw41kpAdOFhtWtkorSkATbP4x8mmzN18UN/+3b/0NaAzUf68m2P5Qpne4dELyL7mT71/IJlYysG3Ni53K3ayVabSasAHYfsBrybzVEQ2JYXtcKjeYKow4crrtVL/f1E5u9flHZ0KNFmT8t4mHu08NpRU2FXVe7QgT8=\"
CC    := gcc

all: run

demo: $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/linux/RecognizerImageWrapper.c
	$(CC) $(FLAGS) $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/linux/RecognizerImageWrapper.c -o demo -I $(API_INC_PATH) -I $(DEMO_SRC_PATH)/utils -I $(DEMO_SRC_PATH)/utils/linux -L $(API_LIB_PATH) -lRecognizerApi -ljpeg

run-demo: demo
	LD_LIBRARY_PATH=$(API_LIB_PATH) ./demo $(API_RES_PATH) $(DEMO_SRC_PATH)/demo/id.jpg

run: run-demo

clean:
	rm demo || true
