%Utr__ = eig()


%%

figure
k = 1;
for j=1:40
    subplot(5,8,k)
    J = eigFaceArr(:,:,j);
    imshow(J,[min(min(J)),max(max(J))])
    k = k+1;
end

%%
for j=1:5
norm(Vtr(:,j))
end

%%
jj = 1:5:41;
toDisp = cell(1,length(jj));
for j=jj
    toDisp{j} = zeros(dim);
    for k = 1:30
        toDisp{j} = toDisp{j} + coeffArr(j,k) * eigFaceArr(:,:,k);
    end
    figure
    subplot(1,2,1)
    imshow(toDisp{j},[min(min(toDisp{j})),max(max(toDisp{j}))])
    subplot(1,2,2)
    im = reshape(trainImArr(j,:),[128,128]);
    imshow(im,[min(min(im)),max(max(im))])
end

%%
for i = 1:20
    im = reshape(reconIms(i,:),[dim,dim]);
    subplot(5,4,i)
    imshow(im,[min(min(im)),max(max(im))]);
end

%%
figure
for i=1:4
    subplot(2,2,i)
    imshow(mat2gray(reshape(recons(i,:),[128,128])))
end
figure
for i=1:4
    subplot(2,2,i)
    imshow(mat2gray(reshape(im_array(turnIndices(i),:),[128,128])))
end