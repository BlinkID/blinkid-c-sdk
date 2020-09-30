DEMO_SRC_PATH := ../../../src

API_RES_PATH := ../../../../resources/non-android
API_INC_PATH := ../../../../include
API_LIB_PATH := ../../../../lib/Linux/x64

FLAGS := -g -ansi -m64 -DLICENSEE=\"test\" -DLICENSE_KEY=\"sRwAAAUEdGVzdGZnyBNPpn/pdSTAoOXBveCy+clLQmQCpsXMRGbytw++Z+dq5l5RIS1tsS73Y7L2CYn+MMKXSp9Xab9iiqEObdjJs+np+V/S2CtyJCjcfnG1oi4lfILfgqxU3sMP1tdHA55RvtANVs9+wkwgQ3QTRk2PS7mEvBLvQsaA8vDgeJ4sw8OrcFsuwpJLIJFmjSGyjyCT6M3DOeUO00pj1ar2DmId7E8Y35v70RgYkckp5Eh7XybGRKX7EH4y17p0GVFnOGTLg6gkjQ==\"
CC    := gcc

all: run

demo: $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/Linux/RecognizerImageWrapper.c
	$(CC) $(FLAGS) $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/Linux/RecognizerImageWrapper.c -o demo -I $(API_INC_PATH) -I $(DEMO_SRC_PATH)/utils -I $(DEMO_SRC_PATH)/utils/Linux -L $(API_LIB_PATH) -lRecognizerApi -ljpeg

run-demo: demo
	LD_LIBRARY_PATH=$(API_LIB_PATH) ./demo $(API_RES_PATH) $(DEMO_SRC_PATH)/demo/id.jpg

run: run-demo

clean:
	rm demo || true
