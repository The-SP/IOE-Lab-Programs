function ck=fourier_coeff(k)
if k == 0 
 ck=0.5;
elseif abs(k)==1
 ck =1/2;
elseif abs(k)==2
 ck = 1/4;
elseif abs(k)==3
 ck = 1/3;
else
 ck=0;
end

function s=sumterms(n,N)
w0=2*pi/N;
s=zeros(size(n));
for k=-3:3
 s=s+fourier_coeff(k)*exp(1i*k*w0*n);
end

n=-10:10;
s5=sumterms(n,10); stem(n,s5,'m');
xlabel('n');
ylabel('x[n]');
title('Systhesis of Fourier Series Coefficients with N = 10')