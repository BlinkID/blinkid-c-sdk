DEMO_SRC_PATH := ../../../src

API_RES_PATH := ../../../../resources/non-android
API_INC_PATH := ../../../../include
API_LIB_PATH := ../../../../lib/linux/x64

FLAGS := -g -ansi -m64 -DLICENSEE=\"test\" -DLICENSE_KEY=\"sRwAAAUEdGVzdGZnyBMppn/pdSTAoOBhsewC1jRqgboEex1Nipkyf8sftqSx1jJapC0fQ97r4ftDmKycrydjQt8Tas0oAw2trlAprZYCA99nXUsog5Op3UUzHb+emx+qRRtHlVUaQYCdou9PNPp4IWtihQMz4Z7KMT7AGDTl3YhcFiaACOtsz5jbCM0mFdYJdlqjvq/lzIs38eG53njy0aKt4I9zU6yRz/fzAnejOIXQXdXnpNv3qlR+EkJ+DoedqV1HK05Pikd0iOkb65Wx5QmmjRiKlN+i+cEkfX5bo/hN7Twnti8IyDe5DAHaKPckfkFqGtsfht/6Fz9P713bB3g71ee/m5ncANT6xg==\"
CC    := gcc

all: run

demo: $(DEMO_SRC_PATH)/demo/demo.c
	$(CC) $(FLAGS) $(DEMO_SRC_PATH)/demo/demo.c -o demo -I $(API_INC_PATH) -I $(DEMO_SRC_PATH)/utils -L $(API_LIB_PATH) -lRecognizerApi

run-demo: demo
	LD_LIBRARY_PATH=$(API_LIB_PATH) ./demo $(API_RES_PATH) $(DEMO_SRC_PATH)/demo/id.jpg

run: run-demo

clean:
	rm demo || true
