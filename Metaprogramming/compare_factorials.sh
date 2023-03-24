#

g++ -std=c++20 ./factorial.cc -o factorial
time (
for i in {1..1000}
do
  ./factorial > /dev/null
done
)

g++ -std=c++20 ./meta_factorial.cc -o meta_fact
time (
for i in {1..1000}
do
  ./meta_fact > /dev/null
done
)
