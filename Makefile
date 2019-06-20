GCC=g++ -std=c++11 -fno-exceptions
CLANG=clang++ -std=c++11 -fno-exceptions -stdlib=libc++
LD=g++
STATICOPT=-static-libstdc++ -static-libgcc -Wl,--exclude-libs=ALL 

clean: 
	rm -f ./bin/*
	echo Clean done

bin/a_iceberg.o: lib/iceberg.cc
	$(GCC) -fpic -D ICEBERG_FUNCTION_PREFIX=a_ -c $< -o $@

bin/a_libiceberg.so: bin/a_iceberg.o
	$(LD) -shared $(STATICOPT) $^ -o $@

bin/b_iceberg.o: lib/iceberg.cc
	$(CLANG) -fpic -D ICEBERG_FUNCTION_PREFIX=b_ -c $< -o $@ 

bin/b_libiceberg.so: bin/b_iceberg.o
	$(CLANG) -shared $(STATICOPT) -lpthread -lc++abi $^ -o $@

bin/main.o: main/main.cc
	$(GCC) -c $< -o $@
	
bin/main: bin/a_libiceberg.so bin/b_libiceberg.so  bin/main.o 
	$(LD) $^ -o $@

ldd/main: bin/main
	ldd bin/main
	ldd bin/a_libiceberg.so
	ldd bin/b_libiceberg.so
