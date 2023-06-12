t = -10:0.005:10;
Tp = 4; k = 1;
h = 2*t/Tp.*sinc(k*2*t/Tp);
x = double(and(t>0, t<=100));

subplot(2,2,1);
plot(t, x);
title('x(t) = 1, 1<=t<=100');

subplot(2,2,2);
plot(t, h);
title('h(t) = 2t/Tp*sinc(2t/Tp)');

subplot(2,2,3);
r = -(length(t)-1):length(t)-1;
y = conv(x, h);
plot(r, y);
title('y(t) = x(t) * h(t)');
xlabel('t');
ylabel('y(t)');