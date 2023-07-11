fs=8000;pb=1200;sb=2000;Rp=0.5;Rs=40;
fn=fs/2;
wp=pb/fn;
ws=sb/fn;

% Butterworth Filter
figure(1)
[N,wc]=buttord(wp,ws,Rp,Rs);
[num1,den1]=butter(N,wc);

[Hd,wd]=freqz(num1,den1);
magd=abs(Hd);
phase=angle(Hd)*180/pi;
subplot(2,1,1);
plot(wd/pi,magd);title('Magnitude Plot')
subplot(2,1,2);
plot(wd/pi,phase);title('Phase Plot')

% Chebyshev Filter
figure(2)
[N,wc]=cheb1ord(wp,ws,Rp,Rs);
[num1,den1]=cheby1(N,Rp,wc);

[Hd,wd]=freqz(num1,den1);
magd=abs(Hd);
phase=angle(Hd)*180/pi;
subplot(2,1,1);
plot(wd/pi,magd);title('Magnitude Plot')
subplot(2,1,2);
plot(wd/pi,phase);title('Phase Plot')

% Elliptical Filter
figure(3)
[N,wc]=ellipord(wp,ws,Rp,Rs);
[num1,den1]=ellip(N,Rp, Rs, wc);

[Hd,wd]=freqz(num1,den1);
magd=abs(Hd);
phase=angle(Hd)*180/pi;
subplot(2,1,1);
plot(wd/pi,magd);title('Magnitude Plot')
subplot(2,1,2);
plot(wd/pi,phase);title('Phase Plot')