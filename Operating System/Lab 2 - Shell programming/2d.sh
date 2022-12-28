# Generate fibonacci series
#!/bin/bash

i=0
a=0
b=1
while [ $i -lt 10 ]
do
    echo -n "$a " 
    c=$((a+b))
    a=$b 
    b=$c
    i=$((i+1))
done
