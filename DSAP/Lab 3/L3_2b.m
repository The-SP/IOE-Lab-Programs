t = -10:0.001:10;
ut = (t >= 0);
x = double(ut);
a = 0.5; % a<0
h = exp(-a*t).*ut;

y = conv(x, h);

subplot(2,2,1);
plot(t, x);
title('x(t) = u(t)')

subplot(2,2,2);
plot(t, h);
title('h(t) = e^-^a^t*u(t)');

subplot(2,2,3);
r = -(length(t)-1):length(t)-1;
plot(r, y);
title('y(t) = x(t) * h(t)');
xlabel('t')
ylabel('y(t)')