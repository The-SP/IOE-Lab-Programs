b = [0.0018,0.0073,0.011,0.007,0.008];
a = [1,-3.0544,3.8291,2.2925,0.55072];
freqz(b,a);
%[h,w] = freqz(b,a);
%plot(w/pi,abs(h));