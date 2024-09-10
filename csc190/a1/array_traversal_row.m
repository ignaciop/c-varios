% array_traversal_row.m
% Sums a two dimensional array of ones using row-major order
% Elizabeth Patitsas; Dec 24, 2012

n = 1773;
B = ones(n, n); % creates an n-dimensional array filled with '1'

sum = 0;
for i=1:n,
    for j=1:n,
        sum = sum + B(i, j);
    end
end 

% print the sum and then exit
sum
exit
