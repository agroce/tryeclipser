# CXX should be a recent clang.  build DeepState with AFL instrumentation and copy lib to get deepstate_AFL

all:
	$(CXX) -o vuln vuln.cpp -ldeepstate
	$(CXX) -o vulnLF vuln.cpp -fsanitize=fuzzer -ldeepstate_LF
	$(AFL_CXX) -o vulnAFL vuln.cpp -ldeepstate_AFL
