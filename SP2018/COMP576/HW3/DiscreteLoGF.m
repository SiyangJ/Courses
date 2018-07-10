function M = DiscreteLoGF(s)
%DISCRETELOGF Summary of this function goes here
%   Detailed explanation goes here

% whole = false;
% if ~isempty(varargin) && varargin{1}==true
%     whole=true;
% end

M = zeros(65,128);

for i=1:65
    for j=1:65
        M(i,j)=2*LoGF(2*pi*(i-1)/128,2*pi*(j-1)/128,s);
    end
    for j=66:128
        M(i,j)=2*LoGF(2*pi*(i-1)/128,2*pi*(j-129)/128,s);
    end
end

% if whole
%     ret = zeros(2*dim-1);
%     ret(dim:end,dim:end) = M;
%     ret(dim:end,1:dim-1) = fliplr(M(:,2:end));
%     ret(1:dim-1,:) = flipud(ret(dim+1:end,:));
%     M = ret;
% end

end

