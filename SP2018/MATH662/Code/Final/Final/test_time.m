
for ver = 1:2
%%system('./runme.sh')
%%
%f_func = @(x,y) (y-50).^2*cos(x.^2)+10*(x-30).*y-50*sin(y.^3);
% Gaussian:
%f_func = @(x,y) 1000*exp(-((x-50).^2+(y-50).^2)/2/50^2);

%f_func = @(x,y) cos(x+y)+10*cos(2*x+3*y-10)+5*cos(5*x-8*y+4)+cos(10*x+20*y-4);

%f_func = @(x,y) rand(size(x));

f_func = @(x,y) x+y;

%f_func = @(x,y) -1000+1000*exp(-((x-50).^2+(y-50).^2)/2/50^2);

%f_func = @(x,y) 2*(y.*(y-100)+x.*(x-100));

%f_func = @(x,y) -2*((1-6*x.^2).*y.^2.*(1-y.^2)+(1-6*y.^2).*x.^2.*(1-x.^2));

t0 = 0;
tf = 100;

%%
if ver==1
    main_path = './main';
else
    main_path = './main_final_version';
end
    %%main_path = './main__'

%%
Ns = [4,8,16,32,64,128,256];
nNs = length(Ns);
Na = 2;
Nb = 2;
omega = 74/90;
ncycle = 35;

ERRORS_N = cell(1,nNs);

for i=1:nNs
    N = Ns(i);
    [f,f_loc] = createf(f_func,N,t0,tf);
    save('Input.mat','-v4')
    tic
    system(main_path)
    TIME_1(ver,i) = toc;
    load('Output.mat','errors')
    ERRORS_N{i} = errors; 
    
end

%%
legendInfo = cell(1,nNs);

figure
hold on
for i=1:nNs
    plot(ERRORS_N{i},'-o')
    legendInfo{i} = sprintf('N=%d',Ns(i));
end
hold off
set(gca,'YScale','log')
legend(legendInfo)
title(sprintf('omega=%.4f,Nb=%d',omega,Nb))

%%
ncycle = 30;
N = 128;
omega = 74/90;

Nbs = [2,4,6];
nNbs = length(Nbs);
ERRORS_NB = cell(1,nNbs);

[f,f_loc] = createf(f_func,N,t0,tf);

for i=1:nNbs
    Nb = Nbs(i);
    Na = Nbs(i);
    save('Input.mat','-v4')
    tic
    system(main_path)
    TIME_2(ver,i) = toc;
    load('Output.mat','errors')
    ERRORS_NB{i} = errors;
end
%%
legendInfo = cell(1,nNbs);

figure
hold on
for i=1:nNbs
    plot((0:ncycle)*2*Nbs(i),ERRORS_NB{i},'-o')
    legendInfo{i} = sprintf('Nb=%d',Nbs(i));
end
hold off
set(gca,'YScale','log')
legend(legendInfo)
title(sprintf('omega=%.4f,N=%d',omega,N))

end
figure
hold on
plot(Ns,TIME_1(1,:))
plot(Ns,TIME_1(2,:))
hold off
legend({'DT','Pointer'})
title('Time vs. N')
figure
hold on
plot(Nbs,TIME_2(1,:))
plot(Nbs,TIME_2(2,:))
hold off
legend({'DT','Pointer'})
title('Time vs. Nb')