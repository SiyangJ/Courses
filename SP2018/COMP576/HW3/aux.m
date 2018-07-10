T = zeros(dim/2);
s = 2;
for i=1:dim/2
    for j=1:dim/2
        T(i,j) = LoG(i-0.5,j-0.5,s);
    end
end

TT = zeros(dim);
TT(dim/2+1:dim,dim/2+1:dim) = T;
TT(dim/2+1:dim,1:dim/2) = fliplr(T);
TT(1:dim/2,:) = flipud(TT(dim/2+1:dim,:));

%%
[TTa,TTp] = AmpPhaseDFT(TT);
%%
Aa = APs{1,3};
Ap = APs{2,3};

temp = Aa.*TTa;
new = ReconfromAmpPhase(temp,Ap);
%%
imshow(TT,[min(min(TT)),max(max(TT))])
%%
TTFF2 = fft2(TT);
%%
imshow(TTFF2)

%%
AA = magic(3);
BB = eye(3);

d = imabsdiff(AA,BB);

if d>0.1
    disp('Haha');
end

%%
% Err I1A
%      1410000
% 
% Err I1B
%       926000
% 
% Err I2A
%      2882000
% 
% Err I2B
%      1506000
%%
% Err I1A
%      1025000
% 
% Err I1B
%       814000
% 
% Err I2A
%      2155000
% 
% Err I2B
%      1032000
