DEMO_SRC_PATH := ../../../src

API_RES_PATH := ../../../../resources/non-android
API_INC_PATH := ../../../../include
API_LIB_PATH := ../../../../lib/linux/x64

FLAGS := -g -ansi -m64 -DLICENSEE=\"test\" -DLICENSE_KEY=\"sRwAAAUEdGVzdGZnyBMppn/pdSTAoOcJkUtgshnRl+w9K5UsJIVgitfDc9BSU1nKDZcHHlwf0OLFK8DP+zpELbxR7NymiFVYh4pLX7VRfqSwpdkAUn9sPujQqnIOZj+xUi87yIio5cOiiu0zgKgeuAZsOwrdxBAu8PoYUkh9beMXdn627h2vcDjmeDuMVqDe1FKJy4vh1rFEiyraIrx5Hzf1lcG0KfeV1ck//3Fhpt440CUevQc/psnoFhE9cgHOBK9YiLhYWQfxLYGmK7lPSMfShBEzNS0VG4nqd/9qIrtPtt5R19Y+XA21T+XIzLnhWuz4jBNse/D9nyKs3yk0OANS\"
CC    := gcc

all: run

demo: $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/linux/RecognizerImageWrapper.c
	$(CC) $(FLAGS) $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/linux/RecognizerImageWrapper.c -o demo -I $(API_INC_PATH) -I $(DEMO_SRC_PATH)/utils -I $(DEMO_SRC_PATH)/utils/linux -L $(API_LIB_PATH) -lRecognizerApi -ljpeg

run-demo: demo
	LD_LIBRARY_PATH=$(API_LIB_PATH) ./demo $(API_RES_PATH) $(DEMO_SRC_PATH)/demo/id.jpg

run: run-demo

clean:
	rm demo || true
