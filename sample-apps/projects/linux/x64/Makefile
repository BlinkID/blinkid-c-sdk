DEMO_SRC_PATH := ../../../src

API_RES_PATH := ../../../../resources/non-android
API_INC_PATH := ../../../../include
API_LIB_PATH := ../../../../lib/linux/x64

FLAGS := -g -ansi -m64 -DLICENSEE=\"test\" -DLICENSE_KEY=\"sRwAAAUEdGVzdGZnyBMppn/pdSTAoOOplUsuqlF+6y+MGqz98bP7oPP8s6gQeKlMXvB3XQNrnhQCGoY9Bqs54OrY0IIPTpG2L/EE7vWYcsS2kUK+LsEkQIIDRMZRNBe5TAU/NsAb3/GxVmP1f4PIy8ODqXxFnDJcdZ9uiIlwkLuNdQ6KOn+8utklAOyOPDzg54aWObtYHf0eqJ6KIqYEwJ774yYmuMZxOl7gWfmQh+rYsQcvzNvgP2J8uiA8Yc414dNBVl5aCatrEd9qOxL4jBf7xx+eh0FZ74eQp5CU2LD7tsn3l0vpJ0Wt9OIuRYLybcws54c8bFzcbq1TXs5HHGr0ekaswjopUNLELA==\"
CC    := gcc

all: run

demo: $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/linux/RecognizerImageWrapper.c
	$(CC) $(FLAGS) $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/linux/RecognizerImageWrapper.c -o demo -I $(API_INC_PATH) -I $(DEMO_SRC_PATH)/utils -I $(DEMO_SRC_PATH)/utils/linux -L $(API_LIB_PATH) -lRecognizerApi -ljpeg

run-demo: demo
	LD_LIBRARY_PATH=$(API_LIB_PATH) ./demo $(API_RES_PATH) $(DEMO_SRC_PATH)/demo/id.jpg

run: run-demo

clean:
	rm demo || true
