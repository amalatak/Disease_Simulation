% use simulation data to plot %
% for large population, n = 30000 %

% transmission probability = 1 to 50 %
% innoculation percentage = 10:10:80, 85, 90, 95, 97, 98, 99 %

% using 20% trans rate
days70 = [6 12 79 100 88 20 6 8 96 111];
perc70 = [0 0.0665927 48.5649 48.3878 46.2281 0.143678 0 0.0110852 48.6289 41.9013];
mean(perc70)

days0 = [29 28 28 26 25 28 28 32 28];
perc0 = [98.86 98.8767 97.73 98.96 99 98.89 98.8 98.7 98.9];
mean(perc0)

days90 = [6 6 12 7 6 6 6 8 6 9 9];
perc90 = [0 0 .13 .033 0 0 0 .033 0 .033 .033];
mean(perc90)

days50 = [52 54 46 49];
perc50 = [84.5 85.5 85.9 85.7];

days25 = [33 41 33 34];
perc25 = [96.1 96.0 95.9 95.9];


