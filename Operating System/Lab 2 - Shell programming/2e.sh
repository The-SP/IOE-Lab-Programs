# Arithmetic operation using case
#!/bin/bash

read -p "Enter first number: " a 
read -p "Enter second number: " b
read -p "Enter operator (+, -, *, /): " op 

case $op in
    '+') r=$((a+b)) ;;
    '-') r=$((a-b)) ;;
    '*') r=$((a*b)) ;;
    '/') r=$((a/b)) ;;
    *) echo "Invalid operator" ;;
esac

echo "$a $op $b = $r"