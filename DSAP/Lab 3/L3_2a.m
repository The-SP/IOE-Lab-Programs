n1 = 0:6;
x = n1/3;
n2 = -2:2;
h = ones(1, length(n2));

y = conv(n1, n2);
n = min(n1) + min(n2) : max(n1) + max(n2);

subplot(2,2,1);
stem(n1, x);
title('x[n]');

subplot(2,2,2);
stem(n2, h);
title('h[n]');

subplot(2,2,3);
stem(n, y);
title('y[n] = x[n] * h[n]');
xlabel('n');
ylabel('y[n]');