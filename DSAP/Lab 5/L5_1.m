b=[1 0.1];
a=[1 0.2 9.01];
% Ts=0.1;
Ts=0.5;
fs=1/Ts;
[Ha,Wa] = freqs(b,a,512);
plot(Wa/(2*pi), 20*log10(abs(Ha)), 'LineWidth', 2); hold on;
% Converting the analog filter to discrete one
[bz,az] = impinvar(b,a,fs);
[Hz,Wz] = freqz(bz,az,512);
plot(Wz,20*log10(abs(Hz)),'r--');
xlabel('Frequency (Hz)'), ylabel('Magnitude (dB)');
title('Magnitude Response Comparison');
legend('Analog Filter','Digital Filter');