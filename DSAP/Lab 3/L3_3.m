n1 = 0:4;
x = ones(1, length(n1));
n2 = 0:6;
h = 2.^n2;

y = conv(x, h);
n = min(n1) + min(n2) : max(n1) + max(n2);

subplot(2,2,1);
stem(n1, x);
title('x[n]')

subplot(2,2,2);
stem(n2, h);
title('h[n]')

subplot(2,2,3);
stem(n, y);
title('y[n] = x[n] * h[n]')
xlabel('n')
ylabel('y[n]')
