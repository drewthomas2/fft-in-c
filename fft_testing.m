rng('default')
fs = 100;                                % sample frequency (Hz)
d = 2;                                  % 2 second duration
t = 0:1/fs:d-1/fs;                      % time vector
x = (1.3)*sin(2*pi*15*t) ...             % 15 Hz component
  + (1.7)*sin(2*pi*40*(t-2)) ...         % 40 Hz component
  + 2.5*randn(size(t));                  % Gaussian noise;
y = fft(x);
n = length(x);          % number of samples
f = (0:n-1)*(fs/n);     % frequency range
power = abs(y).^2/n;    % power of the DFT

writematrix(x,'input_matlab.csv') 
writematrix(y,'output_matlab.csv') 
writematrix(power,'power_matlab.csv') 

plot(f,power)
xlabel('Frequency')
ylabel('Power')