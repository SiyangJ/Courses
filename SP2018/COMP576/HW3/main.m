dim = 128;

d = 500*ones(dim,1);
%D = diag(2*d,0)+diag(d(1:end-1),-1)+diag(d(1:end-1),1);
D = tril(1000*ones(dim),-1)+triu(zeros(dim),1)+diag(500*ones(1,dim));


LoG = @(x,y,s) (x^2+y^2-2*s^2)/s^4*exp(-(x^2+y^2)/2/s^2);
LoGF_ = @(u,v,s) exp(-2*pi^2*s^2*(u.^2+v.^2))*(u.^2+v.^2);

%%
A = im2double(imread('img1c.jpg'));
B = im2double(imread('img2c.jpg'));

ims = {A,B,D};
nims = length(ims);
APs = cell(2,nims);

for i=1:nims
    [APs{1,i},APs{2,i}] = AmpPhaseDFT(ims{i});
end

%%

sigs = [2,5];
nsigs = length(sigs);

Ms = cell(nsigs);
Ms_ = cell(nsigs);

for i=1:nsigs
    M = zeros(65,65);

    for k=1:65
        for j=1:65
            M(k,j)=LoGF_((k-1)/128,(j-1)/128,sigs(i));
        end
    end
    
    
    Ms{i} = zeros(65,128);
    Ms{i}(:,1:65) = M;
    Ms{i}(:,66:128) = fliplr(M(:,2:end-1));
    
    Ms_{i} = [M,fliplr(M(:,2:end-1))];
    
end

Recons = cell(nims,nsigs);
for i=1:nims
    for j=1:nsigs
        Recons{i,j} = ReconfromAmpPhase(APs{1,i}.*Ms{j},APs{2,i});
    end
end

%%
k=1;
for i=1:nims
    for j=1:nsigs
        subplot(nims,nsigs,k)
        imshow(Recons{i,j},[min(min(Recons{i,j})),max(max(Recons{i,j}))])
        k=k+1;
    end
end

%%
e = 1e-6;
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
%                             if abs(Recons{i,j}(kk,ll))>e &&...
%                                     abs(Recons{i,j}(kk,ll))+abs(Recons{i,j}(k,l))~=...
%                                     abs(Recons{i,j}(kk,ll)+Recons{i,j}(k,l))
%                                 temp(k,l)=val;
%                             end
                        end
                    end
                end
            end
        end
        ZCs{i,j}=temp;
    end
end

%%
% e = 1e-7;
% val = 1000;
% ZCs = cell(nims,nsigs);
% for i=1:nims
%     for j=1:nsigs
%         
%         ZCs{i,j}=1000*edge(Recons{i,j},'zerocross',e);
%     end
% end


%%
figure
k=1;
for i=1:nims
    for j=1:nsigs
        subplot(nims,nsigs,k)
        imshow(ZCs{i,j},[min(min(ZCs{i,j})),max(max(ZCs{i,j}))])
        k=k+1;
    end
end

