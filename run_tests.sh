#! /bin/bash

test_file=$1
test_directory=test_$1

cp $test_file.* $test_directory

cd $test_directory

rm -f *.o

gcc -c *.c

if [ $? == 0 ]
then
  gcc -o tests *.o

  if [ $? == 0 ]
  then
    rm -f *.o
    rm $test_file*.*

    ./tests
  else
    echo "Linking Failed."
  fi

else
  echo "Compilation Error."
fi
