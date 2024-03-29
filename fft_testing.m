rng('default')
fs = 100E3;                             % sample frequency (Hz)
d = 0.02;                                  % 2 second duration
%t = 0:1/fs:d-1/fs;                      % time vector
t = 0:1/fs:63/fs;  
x = (1.3)*sin(2*pi*15*t) ...             % 15 Hz component
  + (1.7)*sin(2*pi*40*(t-2)) ...         % 40 Hz component
  + 2.5*randn(size(t))+3*sin(2*pi*20000*t);                  % Gaussian noise;
y = fft(x);
n = length(x);          % number of samples
f = (0:n-1)*(fs/n);     % frequency range
power = abs(y).^2/n;    % power of the DFT
phase = angle(y)
mag = abs(y)

writematrix(x,'input_matlab.csv') 
writematrix(y,'output_matlab.csv') 
writematrix(power,'power_matlab.csv') 
my_pwr=importdata("fft_pwr.csv",',')
my_fft=importdata('fft.csv',',')
my_phase=importdata('fft_phase.csv',',')
my_mag=importdata('fft_mag.csv',',')
%my_angle = angle(my_fft)
%my_mag = abs(my_fft)
%my_pwr = abs(my_fft).^2/n

%phase_diff=my_phase-phase
%mag_diff=my_mag - mag

tiledlayout(2,4)

nexttile([1,2])
plot(f,power)
title('MATLAB FFT:')
xlabel('Frequency')
ylabel('Power')

nexttile([1,2])
plot(f,my_pwr)
title('Drew FFT:')
xlabel('Frequency')
ylabel('Power')

nexttile
plot(f,mag)
title('MATLAB FFT:')
xlabel('Frequency')
ylabel('Magnitude')

nexttile
plot(f,phase)
title('MATLAB FFT:')
xlabel('Frequency')
ylabel('Phase')

nexttile
plot(f,my_mag)
title('Drew FFT:')
xlabel('Frequency')
ylabel('Magnitude')

nexttile
plot(f,my_phase)
title('Drew FFT:')
xlabel('Frequency')
ylabel('Phase')

