C=4;a=3;
t=[-10:.001:10];
y=C*exp(a*t);
subplot(2,2,1);
plot(y,t);
title('c>0, a>0');

C=-4;a=3;
y=C*exp(a*t);
subplot(2,2,2);
plot(y,t)
title('c<0, a>0');

C=4;a=-3;
y=C*exp(a*t);
subplot(2,2,3);
plot(y,t)
title('c>0, a<0');

C=-4;a=-3;
y=C*exp(a*t);
subplot(2,2,4);
plot(y,t)
title('c<0, a<0');