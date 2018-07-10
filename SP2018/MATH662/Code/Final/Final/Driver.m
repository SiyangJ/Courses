%%system('./runme.sh')
%%
%f_func = @(x,y) (y-50).^2*cos(x.^2)+10*(x-30).*y-50*sin(y.^3);
% Gaussian:
%f_func = @(x,y) 1000*exp(-((x-50).^2+(y-50).^2)/2/50^2);

%f_func = @(x,y) cos(x+y)+10*cos(2*x+3*y-10)+5*cos(5*x-8*y+4)+cos(10*x+20*y-4);

f_func = @(x,y) rand(size(x));

%f_func = @(x,y) x+y;

%f_func = @(x,y) -1000+1000*exp(-((x-50).^2+(y-50).^2)/2/50^2);

%f_func = @(x,y) 2*(y.*(y-100)+x.*(x-100));

%f_func = @(x,y) -2*((1-6*x.^2).*y.^2.*(1-y.^2)+(1-6*y.^2).*x.^2.*(1-x.^2));

t0 = 0;
tf = 100;

%%
    %%main_path = './main';
    main_path = './main_final_version';
    %%main_path = './main__'

%%
Ns = [128,256,512,1024,2048];
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
    system(main_path)
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
Nas = [4,2,2];
nNbs = length(Nbs);
ERRORS_NB = cell(1,nNbs);

[f,f_loc] = createf(f_func,N,t0,tf);

for i=1:nNbs
    Nb = Nbs(i);
    Na = Nas(i);
    save('Input.mat','-v4')
    system(main_path)
    load('Output.mat','errors')
    ERRORS_NB{i} = errors;
end
%%
legendInfo = cell(1,nNbs);

figure
hold on
for i=1:nNbs
    plot((0:ncycle)*(Nas(i)+Nbs(i)),ERRORS_NB{i},'-o')
    legendInfo{i} = sprintf('Nb=%d',Nbs(i));
end
hold off
set(gca,'YScale','log')
legend(legendInfo)
title(sprintf('omega=%.4f,N=%d',omega,N))

%%
omegas = 7/9:1/90:8/9;
nomegas = length(omegas);
Na = 2;
Nb = 2;
N = 128;
ncycle = 40;

[f,f_loc] = createf(f_func,N,t0,tf);

ERRORS_OMEGA = cell(1,nomegas);

for i=1:nomegas
    omega = omegas(i);
    save('Input.mat','-v4')
    system(main_path)
    load('Output.mat','errors')
    ERRORS_OMEGA{i} = errors;  
end

%%
legendInfo = cell(1,nomegas);

figure
hold on
for i=1:nomegas
    plot(ERRORS_OMEGA{i},'-o')
    legendInfo{i} = sprintf('omega=%.4f',omegas(i));
end
hold off
set(gca,'YScale','log')
legend(legendInfo)
title(sprintf('N=%d,Nb=%d',N,Nb))

%%
save('RunResults.mat','ERRORS_OMEGA','ERRORS_NB','ERRORS_N');