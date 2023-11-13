g++ $1 -o sol -std=c++20  -W -Wall -fstack-protector-all -O3
./sol < test.in
rm -f sol