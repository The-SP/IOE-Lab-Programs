t=-10:10;
w0=2*pi/5;
y1=cos(w0*t);
subplot(2,3,1);
plot(y1)
title('x_1(t) = cos(w0*t)');

subplot(2,3,2);
y2=cos(2*w0*t);
plot(y2)
title('x_2(t) = cos(2*w0*t)');

subplot(2,3,3);
y3=cos(3*w0*t);plot(y3)
title('x_3(t) = cos(3*w0*t)');

subplot(2,3,4);
y4=cos(4*w0*t);
plot(y4)
title('x_4(t) = cos(4*w0*t)');

subplot(2,3,5);
y5=cos(5*w0*t);
plot(y5)
title('x_5(t) = cos(5*w0*t)');

subplot(2,3,6);
y = y1+y2+y3+y4+y5;
plot(y)
title('x(t) = x_1(t)+x_2(t)+x_3(t)+x_4(t)+x_5(t)');