all: demo
demo: libjieba.a
	gcc -o demo demo.c -L./ -ljieba -lstdc++ -lm
libjieba.a:
	g++ -o jieba.o -c -DLOGGING_LEVEL=LL_WARNING -I./deps/ lib/jieba.cpp
	ar rs libjieba.a jieba.o 
libjieba.so:
	g++ -shared -fPIC -o libjieba.so -c  -I./deps/ lib/jieba.cpp
clean:
	rm -f *.a *.o *.so demo
