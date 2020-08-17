DEMO_SRC_PATH := ../../../src

API_RES_PATH := ../../../../resources/non-android
API_INC_PATH := ../../../../include
API_LIB_PATH := ../../../../lib/Linux/x64

FLAGS := -g -ansi -m64 -DLICENSEE=\"test\" -DLICENSE_KEY=\"sRwAAAUEdGVzdGZnyBNPpn/pdSTAIOLRk0mwsrNAWoqOLkOcdOpTQ1YOg7p1zxCT3fP4ktUB/lCzI64XO8qCWiapjm9j/OYDPQtArosr6FBMCHeJIHD2YGRN7GM/zwxA59Dke0XEzUND1rJFPckqkufWhukzrA8vSJ6gcHL14wJin8lTkaZDeZraL3IbqjezQ8GeTTmnJdqLmFGWzrBjiRPdyuiH5+Yinzf5OGHYBY20RLLvulcYXtrKsvGKAIl4EhGDIAtMtMhfXnewXvXWSkI=\"
CC    := gcc

all: run

demo: $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/Linux/RecognizerImageWrapper.c
	$(CC) $(FLAGS) $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/Linux/RecognizerImageWrapper.c -o demo -I $(API_INC_PATH) -I $(DEMO_SRC_PATH)/utils -I $(DEMO_SRC_PATH)/utils/Linux -L $(API_LIB_PATH) -lRecognizerApi -ljpeg

run-demo: demo
	LD_LIBRARY_PATH=$(API_LIB_PATH) ./demo $(API_RES_PATH) $(DEMO_SRC_PATH)/demo/id.jpg

run: run-demo

clean:
	rm demo || true
