DEMO_SRC_PATH := ../../../src

API_RES_PATH := ../../../../resources/non-android
API_INC_PATH := ../../../../include
API_LIB_PATH := ../../../../lib/Linux/x64

FLAGS := -g -ansi -m64 -DLICENSEE=\"test\" -DLICENSE_KEY=\"sRwAAAUEdGVzdGZnyBMppn/pdSTAoOXhtOAx1HFWF5IMW7dOf34f8vyE9MUOaETOxCnWLk2bC42hET/U3EnyB1gU2yIXKVsXvz3H6ErbEiegO3GZ0H2ffxkNtdjLAFyHz1Z1CweFT/RgEOea3Pi2OQIY5XBIfmDdMkQ2oWLakmtL1N2HRTXwgF/TEN4qV0x7Gm7DIFA293jxiYsnZmRaWudPIrCSUtWl2G7fU0+jrg/USfGJ14VvQj3izkQFEF9rEfRyZZoMh3aJY8OtmrHdjYL4my6sC0oZDsjJVsYRE3mpcUaBMWkFP2T4YnLs7wi4C7yc96f0Dg==\"
CC    := gcc

all: run

demo: $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/Linux/RecognizerImageWrapper.c
	$(CC) $(FLAGS) $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/Linux/RecognizerImageWrapper.c -o demo -I $(API_INC_PATH) -I $(DEMO_SRC_PATH)/utils -I $(DEMO_SRC_PATH)/utils/Linux -L $(API_LIB_PATH) -lRecognizerApi -ljpeg

run-demo: demo
	LD_LIBRARY_PATH=$(API_LIB_PATH) ./demo $(API_RES_PATH) $(DEMO_SRC_PATH)/demo/id.jpg

run: run-demo

clean:
	rm demo || true
