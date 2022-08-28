mkdir .working
g++ wzor.cpp -o .working/wzor -std=c++17 -O3
g++ brut.cpp -o .working/brut -std=c++17 -O3
g++ gen.cpp -o .working/gen -std=c++17 -O3

for i in {1..10000}; do
    echo $i
    ./.working/gen $i > .working/test.in
    ./.working/wzor < .working/test.in > .working/test_wzor.out
    ./.working/brut < .working/test.in > .working/test_brut.out
    if diff -bq .working/test_wzor.out .working/test_brut.out; then echo $i
    else break
    fi
done