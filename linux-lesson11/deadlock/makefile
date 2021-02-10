all:safe_test test_safe
safe_test:test1.cpp
	g++ $^ -o $@ -g -lpthread
test_safe:test.cpp
	g++ $^ -o $@ -g -lpthread
