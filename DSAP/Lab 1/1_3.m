a=0;b=1;c=0,odd=0,even=0; 
res = [a, b];
while (a+b) <= 10000
    c = a+b;
    res = [res, c]
    if rem(c, 2) == 0
        even = even + 1
    else
        odd = odd + 1
    end
    a = b;
    b = c;
end

x = [1:1:length(res)]
plot(x, res)