rng(2)

n = 10;

P = randi([1,1000],[n,2]);

[Ps,I] = sortrows(P,1);

