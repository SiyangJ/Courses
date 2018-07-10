nT = 5e4;
Ts = zeros(1,nT);
Ts(2) = 2;
for i=3:nT
    for j=2:i-1
        Ts(i) = Ts(i)+Ts(j);
    end
    Ts(i) = Ts(i)*2/i;
end
Ts = Ts*30;
%%
V = (1:nT).*log2(1:nT);

%%
figure
hold on
plot(Ts);
plot(V);
hold off
legend('Ts','V')
set(gca,'YScale','log')
set(gca,'XScale','log')