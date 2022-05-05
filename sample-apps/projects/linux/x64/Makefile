DEMO_SRC_PATH := ../../../src

API_RES_PATH := ../../../../resources/non-android
API_INC_PATH := ../../../../include
API_LIB_PATH := ../../../../lib/linux/x64

FLAGS := -g -ansi -m64 -DLICENSEE=\"test\" -DLICENSE_KEY=\"sRwAAAUEdGVzdGZnyBMppn/pdSTAUOUhsOQ31AyaftyEgdHqi5DOoOHFvN7zRNoS71a3k7PeYqG+Lib8I/NsxnpcBjxUr7x1JM109kv33Ak/QynPGcV2shwIPTCu3eng+OyHJU57mcXFvz9QuJR43wEfbOecghAlrwpieROU98A9i3hPMSRRiSrkRxe93zlseAL9IgTXYH3mjuLtKD7wyBCnhamcuLUGU+D79eU9Q1PfvjDLmkadO+w4e50YUrRpryvNiSe9esS6yPkpqKs5ua8gh3OEeCLd1fAHHJZPjF6WkQgf0P1JXLJoge/ZQgjp9iloksLAAFGXQu7z0amRFkvYWsnKEEr9XkCc\"
CC    := gcc

all: run

demo: $(DEMO_SRC_PATH)/demo/demo.c
	$(CC) $(FLAGS) $(DEMO_SRC_PATH)/demo/demo.c -o demo -I $(API_INC_PATH) -I $(DEMO_SRC_PATH)/utils -L $(API_LIB_PATH) -lRecognizerApi

run-demo: demo
	LD_LIBRARY_PATH=$(API_LIB_PATH) ./demo $(API_RES_PATH) $(DEMO_SRC_PATH)/demo/id.jpg

run: run-demo

clean:
	rm demo || true
