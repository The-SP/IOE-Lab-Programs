x1 = [1,1,1,1,1];
n1 = [-2,-1,0,1,2];
x2 = [1,0,0,0,0,0,0,0,0,0];
n2 = -4:5;

y = conv(x1, x2);
n = min(n1) + min(n2) : max(n1) + max(n2);

subplot(2,2,1);
stem(n1, x1);
title('x[n]')

subplot(2,2,2);
stem(n2, x2);
title('h[n]')

subplot(2,2,3);
stem(n, y);
title('y[n] = x[n] * h[n]')
xlabel('n')
ylabel('y[n]')
