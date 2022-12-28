# Greatest of three numbers

echo "Enter A"
read a
echo "Enter B"
read b 
echo "Enter C"
read c 
if [ $a -gt $b -a $a -gt $c ]
then
    echo "A is greatest"
elif [ $b -gt $a -a $b -gt $c ]
then
    echo "B is greatest"
else
    echo "C is greatest"
fi 