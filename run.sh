f="$1"
s="$2"

echo $r;

if ([ "$f" == "-t" ] || [ "$s" == "-t" ]) && [ -d "./build" ]; then
  rm -r "build"
fi

[ ! -d "./build" ] && mkdir "./build"

cd ./build
cmake .. &&
make &&

if [ "$f" == "-t" ] || [ "$s" == "-t" ]; then
  ./unittest
elif [ "$f" == "-r" ] || [ "$s" == "-r" ]; then
  ./demo_rec
else
  ./demo
fi
