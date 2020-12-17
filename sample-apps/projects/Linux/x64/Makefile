DEMO_SRC_PATH := ../../../src

API_RES_PATH := ../../../../resources/non-android
API_INC_PATH := ../../../../include
API_LIB_PATH := ../../../../lib/Linux/x64

FLAGS := -g -ansi -m64 -DLICENSEE=\"test\" -DLICENSE_KEY=\"sRwAAAUEdGVzdGZnyBMppn/pdSTAoOEhueDLhJyxrRWdM+Cx4/gOeXbBb/MLojlOstcwSIuEQhrwWdJaG/CLyk9WQN1BiIRBr1E67BwUjwYbRExfVcPypGbZyMYTrVc8j9wMpIUENAwE8MISu+VH0P3fF7oDYOu7t6RnAks/NJt43SZxq/N0QLeo1igQuaHaNZyxEBIlaGMzUYOivG86wmc+i0Ye6L5LwZGGwLv6IsYF1ETmTqBVdIzZ87IgxQdrnTZk0+lshWm1Op1AW/V8BmgQVHOatwlhulNZnRMA5n6bnzD12TxrcnKTe87OTLgTVqa/fJZRmo61jFpeJJ80mw==\"
CC    := gcc

all: run

demo: $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/Linux/RecognizerImageWrapper.c
	$(CC) $(FLAGS) $(DEMO_SRC_PATH)/demo/demo.c $(DEMO_SRC_PATH)/utils/Linux/RecognizerImageWrapper.c -o demo -I $(API_INC_PATH) -I $(DEMO_SRC_PATH)/utils -I $(DEMO_SRC_PATH)/utils/Linux -L $(API_LIB_PATH) -lRecognizerApi -ljpeg

run-demo: demo
	LD_LIBRARY_PATH=$(API_LIB_PATH) ./demo $(API_RES_PATH) $(DEMO_SRC_PATH)/demo/id.jpg

run: run-demo

clean:
	rm demo || true
