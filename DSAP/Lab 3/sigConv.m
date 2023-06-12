n1=-2:2;
x=[1,1,1,1,1];
n2=-4:5;
h=[1,0,0,0,0,0,0,0,0,0];

i = -6:7;
s = zeros(1, length(i));
[y2_fold, n_fold] = sigfold(x1, n1);
temp = 1;
for j = i
    [y_shift, n_shift] = sigshift_m(y2_fold, n_fold, j);
    [y_multi, n_multi] = sigmulti(y_shift, n_shift, x2, n2);
    for k = 1:length(n_multi)
        s(temp) = s(temp) + y_multi(k);
    end
    temp = temp + 1;
end

subplot(2,2,1);
stem(n1, x1);
title('x[n]')

subplot(2,2,2);
stem(n2, h);
title('h[n]')

subplot(2,2,3);
stem(i, s);
title('y[n] = x[n] * h[n]');
xlabel('n');
ylabel('y[n]');