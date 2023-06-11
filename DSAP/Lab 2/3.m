a = 0.5;
theta = pi/4;
n = -20:20;
y = (a*exp(j*theta)).^n;
stem(n,y)