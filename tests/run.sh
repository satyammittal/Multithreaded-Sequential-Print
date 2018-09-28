cmake .
make
counter=0
while read sen; do
  counter=$((counter+1))
  echo "Case" $counter":"
  array=($sen)
  s=${array[0]}
  p=${array[1]}
  k=${array[2]}
  n=${array[3]}
  ./output $s $p $k $n
done < $1