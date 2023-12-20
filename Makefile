output: main.o vps_aes_gcm.o
	g++  main.o vps_aes_gcm.o -o VPS.out -lssl -lcrypto

main.o: main.cpp
	g++ -c main.cpp

vps_aes_gcm.o: vps_aes_gcm.cpp vps_aes_gcm.h
	g++ -c vps_aes_gcm.cpp

clean:
	rm *.o app