
line=$(head -n 1 $1)

echo ${line:1}
echo 'args' $2

eval ${line:1} $2

