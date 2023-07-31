f=[0 pi/6 pi/6 pi];
H=[1 1 0 0];
M=31;
w=0:pi/30:pi;

h=hamming(M);
subplot(2,2,1);plot(w/pi,h);
title('Hamming Window (M=31)');

[H1 w]=freqz(h,1,1024);
subplot(2,2,2);plot(w/pi,abs(H1));
title('Frequency Response for Hamming Window Function');

B=fir1(M-1,1/6); % M-1 becz it uses Hamming window of length M+1 by default
[H2 w]=freqz(B,1,1024);
subplot(2, 2, 3);plot(w/pi,abs(H2));
ylabel('Amplitude');
xlabel('Radian Frequency');
title('Frequency Response of FIR filter using Hamming window');

gk=20.*log(abs(H2));
subplot(2,2,4);plot(w/pi,gk);
ylabel('dB');
xlabel('Radian Frequency');

figure(2);
f=[0 pi/6 pi/6 pi];
H=[1 1 0 0];
M=61;
w=0:pi/60:pi;
h=hamming(M);
subplot(2,2,1);plot(w/pi,h);
title('Hamming Window (M=61)');
[H1 w]=freqz(h,1,1024);
subplot(2,2,2);plot(w/pi,abs(H1));
title('Frequency Response for Hamming Window Function');
B=fir1(M-1,1/6); % M-1 becz it uses Hamming window of length M+1 by default
[H2 w]=freqz(B,1,1024);
subplot(2, 2, 3);plot(w/pi,abs(H2));
ylabel('Amplitude');
xlabel('Radian Frequency');
title('Frequency Response of FIR filter using Hamming window');
gk=20.*log(abs(H2));
subplot(2,2,4);plot(w/pi,gk);
ylabel('Magnitude dB');
xlabel('Radian Frequency');