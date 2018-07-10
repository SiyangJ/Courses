%%

%% 3
   % mag1A = img1 (sigma = 2)
   % mag1B = img1 (sigma = 5)
   % mag2A = img2 (sigma = 2)
   % mag2B = img2 (sigma = 5)
   % operation = the operation the filter takes
   
   LoGF = @(u,v,s) exp(-2*pi^2*s^2*(u.^2+v.^2))*(u.^2+v.^2);
   
ims = {img1,img2};
nims = length(ims);
APs = cell(2,nims);

for i=1:nims
    [APs{1,i},APs{2,i}] = AmpPhaseDFT(ims{i});
end
   
   sigs = [2,5];
nsigs = length(sigs);

Ms = cell(nsigs);

for i=1:nsigs
    M = zeros(65,65);

    for k=1:65
        for j=1:65
            M(k,j)=LoGF((k-1)/128,(j-1)/128,sigs(i));
        end
    end
    
    Ms{i} = zeros(65,128);
    Ms{i}(:,1:65) = M;
    Ms{i}(:,66:128) = fliplr(M(:,2:end-1));
end

mag1A = APs{1,1}.*Ms{1};
mag1B = APs{1,1}.*Ms{2};
mag2A = APs{1,2}.*Ms{1};
mag2B = APs{1,2}.*Ms{2};

%% 4

LoGF = @(u,v,s) exp(-2*pi^2*s^2*(u.^2+v.^2))*(u.^2+v.^2);
   
ims = {img1,img2};
nims = length(ims);
APs = cell(2,nims);

for i=1:nims
    [APs{1,i},APs{2,i}] = AmpPhaseDFT(ims{i});
end
   
   sigs = [2,5];
nsigs = length(sigs);

Ms = cell(nsigs);

for i=1:nsigs
    M = zeros(65,65);

    for k=1:65
        for j=1:65
            M(k,j)=LoGF((k-1)/128,(j-1)/128,sigs(i));
        end
    end
    
    Ms{i} = zeros(65,128);
    Ms{i}(:,1:65) = M;
    Ms{i}(:,66:128) = fliplr(M(:,2:end-1));
end

Recons = cell(nims,nsigs);
for i=1:nims
    for j=1:nsigs
        Recons{i,j} = ReconfromAmpPhase(APs{1,i}.*Ms{j},APs{2,i});
    end
end

I1A = Recons{1,1};
I1B = Recons{1,2};
I2A = Recons{2,1};
I2B = Recons{2,2};

%% 5

img1 = A;
img2 = D;

LoGF = @(u,v,s) exp(-2*pi^2*s^2*(u.^2+v.^2))*(u.^2+v.^2);
   
ims = {img1,img2};
nims = length(ims);
APs = cell(2,nims);

for i=1:nims
    [APs{1,i},APs{2,i}] = AmpPhaseDFT(ims{i});
end
   
   sigs = [2,5];
nsigs = length(sigs);

Ms = cell(nsigs);

for i=1:nsigs
    M = zeros(65,65);

    for k=1:65
        for j=1:65
            M(k,j)=LoGF((k-1)/128,(j-1)/128,sigs(i));
        end
    end
    
    Ms{i} = zeros(65,128);
    Ms{i}(:,1:65) = M;
    Ms{i}(:,66:128) = fliplr(M(:,2:end-1));
end

Recons = cell(nims,nsigs);
for i=1:nims
    for j=1:nsigs
        Recons{i,j} = ReconfromAmpPhase(APs{1,i}.*Ms{j},APs{2,i});
    end
end

e = 1e-7;
val = 1000;
ZCs = cell(nims,nsigs);
for i=1:nims
    for j=1:nsigs
        temp=zeros(dim);
        for k=1:dim
            for l=1:dim
                if abs(Recons{i,j}(k,l))>e
                    for dk=[-1,0,1]
                        kk = k+dk;
                        if kk<1 || kk>dim
                            continue;
                        end
                        for dl=[-1,0,1]
                            ll = l+dl;
                            if ll<1 || ll>dim
                                continue;
                            end
                            if abs(Recons{i,j}(kk,ll))>e && sign(Recons{i,j}(kk,ll))*sign(Recons{i,j}(k,l))<0
                                temp(k,l)=val;
                            end
                        end
                    end
                end
            end
        end
        ZCs{i,j}=temp;
    end
end