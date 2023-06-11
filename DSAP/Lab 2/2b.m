c=.4;
a=.3*i;
t=-10:0.05:10;
subplot(2,2,1);
y=c*exp(a*t);
plot(t,y)
title('c>0, a>0');

c=-.4;
subplot (2, 2, 2);
y=c* exp (a*t);
plot (t,y)
title('c<0, a>0');

c=.4;
a=-.3i;
y=c*exp(a*t);
subplot(2,2,3);
plot(t,y)
title('c>0, a<0');

c=-.4;
y=c*exp(a*t);
subplot(2,2,4);
plot(t,y)
 title('c<0, a<0');