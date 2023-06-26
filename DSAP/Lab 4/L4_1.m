b = [0.0663, 0.1989, 0.1989, 0.0663]
a = [1, -0.9349, 0.5668, -0.1015]

% L4_1.a
figure(1);
freqz(b, a);

% L4_1.c
figure(2);
[h, w] = freqz(b, a);
plot(w/pi, abs(h));
title('Frequency Response');
grid on;