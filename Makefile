all:
	$(CC) -o vulnorig vulnorig.c
	$(CXX) -o vulnmix vulnmix.cpp -ldeepstate
	$(CXX) -o vuln vuln.cpp -ldeepstate
