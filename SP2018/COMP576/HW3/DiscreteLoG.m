function M = DiscreteLoG(dim,s,varargin)
%DISCRETELOG Summary of this function goes here
%   Detailed explanation goes here

whole = false;
if ~isempty(varargin) && varargin{1}==true
    whole=true;
end

M = zeros(dim);

for i=1:dim
    for j=1:dim
        M(i,j)=LoG(i-1,j-1,s);
    end
end

if whole
    ret = zeros(2*dim-1);
    ret(dim:end,dim:end) = M;
    ret(dim:end,1:dim-1) = fliplr(M(:,2:end));
    ret(1:dim-1,:) = flipud(ret(dim+1:end,:));
    M = ret;
end

end

