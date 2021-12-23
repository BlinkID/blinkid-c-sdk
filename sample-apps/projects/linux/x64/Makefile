DEMO_SRC_PATH := ../../../src

API_RES_PATH := ../../../../resources/non-android
API_INC_PATH := ../../../../include
API_LIB_PATH := ../../../../lib/linux/x64

FLAGS := -g -ansi -m64 -DLICENSEE=\"test\" -DLICENSE_KEY=\"sRwAAAUEdGVzdGZnyBMppn/pdSTAoOIRkk8M6dK7xsYpQT9SwIbn2dlJvS12BIb5objtpsHlIb2pk7HyV3GLMWxC+nwwah/ZpDTrimUU4HKwdwvh4afJ0CDWRQ4nX2G3vo30Onno7KPADAN2phwl5kn9J+NXdEW6JjuALPRUwosTcoG+tjJ2U4onnI1qIojpsPUuMfhuD2QcM4HxKmLGEcq/mWcaTc2rjgy+v0hxsHe9x/O7mJkUfWqm8MuIid2M6XxP/1K4MqZ+S2c5JArFA+7zj9pfV4ucWJZzNKWKJmUolfPiTEBiM1W4/fKAm2oy9WxYigubR/lOWg9ONG5qbI6JyfG5ydVk6d/8iQ==\"
CC    := gcc

all: run

demo: $(DEMO_SRC_PATH)/demo/demo.c
	$(CC) $(FLAGS) $(DEMO_SRC_PATH)/demo/demo.c -o demo -I $(API_INC_PATH) -I $(DEMO_SRC_PATH)/utils -L $(API_LIB_PATH) -lRecognizerApi

run-demo: demo
	LD_LIBRARY_PATH=$(API_LIB_PATH) ./demo $(API_RES_PATH) $(DEMO_SRC_PATH)/demo/id.jpg

run: run-demo

clean:
	rm demo || true
