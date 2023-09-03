t=[-10:0.005:10];
w0=2*pi/3;
th=pi/3;
C=2+3i;
r=0;
subplot(2,2,1);
y=abs(C)*exp(r*t).*(cos(w0*t+th)+i*sin(w0*t+th));
plot(t,y);

r=-1;
subplot(2,2,2);
y=abs(C)*exp(r*t).*(cos(w0*t+th)+i*sin(w0*t+th));
plot(t,y);


r=1;
subplot(2,2,3);
y=abs(C)*exp(r*t).*(cos(w0*t+th)+i*sin(w0*t+th));
plot(t,y);