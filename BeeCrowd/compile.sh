g++ --std=c++17 -O2 $1.cpp -o $1.exe
./$1.exe < $1.in > $1.out
cat $1.out