b1=[.0007378,2*0.0007378,0.0007378]
a1=[1,-1.2686,0.7051]
b2=[1,2,1]
a2=[1,-1.0106,0.3583]
b3=[1,2,1]
a3=[1,-0.9044,0.2155]

subplot(2,2,1)
zplane(b1,a1)
subplot(2,2,2)
zplane(b2,a2)
subplot(2,2,3)
zplane(b3,a3)

sos=[b1,a1;b2,a2;b3,a3]
[b,a]=sos2tf(sos)
subplot(2,2,4)
zplane(b,a)


% L4_3b convolution method
figure(2);
b = conv(b1, conv(b2, b3));
a = conv(a1, conv(a2, a3));
zplane(b, a);
