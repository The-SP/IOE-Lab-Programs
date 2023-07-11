% Bilinear transformation method
plot(Wa/(2*pi),20*log10(abs(Ha)),'LineWidth',2); hold on;
[bz,az]=bilinear(b,a,fs);
[Hz,Wz] = freqz(bz,az,512);
plot(Wz,20*log10(abs(Hz)),'r--');
xlabel('Frequency (Hz)'), ylabel('Magnitude (dB)');
title('Magnitude Response Comparison');
legend('Analog Filter','Digital Filter');
xlabel('Frequency (Hz)'), ylabel('Magnitude (dB)');
title('Magnitude Response Comparison');
legend('Analog Filter','Digital Filter');