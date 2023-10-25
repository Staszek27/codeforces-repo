g++ wzor.cpp -o rozw -std=c++17  -W -Wall -fstack-protector-all -O3
./rozw < ../test.in
rm -f rozw