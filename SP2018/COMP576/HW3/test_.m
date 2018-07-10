% Create and display four zero-crossing images from the images in part 4
% For each pixel, test whether the pixel's intensity is far away from 0.0 (e.g. you can test whether the magnitude is less than 10E-7). If the pixel's magnitude is close to 0, set it equal to 0 in the zero-crossing image
% For each remaining pixel, test whether it has any (horizontal, vertical, or diagonal) neighbor pixels with intensity with the opposite sign (not zero). If it has such neighbors, set the intensity to 1000 in the zero-crossing image and if not, set it to 0 in the zero-crossing image
% Display and submit the four zero-crossing images


function [I1A, I1B, I2A, I2B] = problemFive(img1, img2)
    filter_2 = DiscreteLoGF(2);
    filter_5 = DiscreteLoGF(5);
    [amp1,phase1] = AmpPhaseDFT(img1);
    [amp2,phase2] = AmpPhaseDFT(img2);
    % mag1A = img1 (sigma = 2)
    mag1A = amp1 .* filter_2;
    % mag1B = img1 (sigma = 5)
    mag1B = amp1 .* filter_5;
    % mag2A = img2 (sigma = 2)
    mag2A = amp2 .* filter_2;
    % mag2B = img2 (sigma = 5)
    mag2B = amp2 .* filter_5;
    
    % Reconstructed images
    % I1A = img1 (sigma = 2)
    I1A = ReconfromAmpPhase(mag1A, phase1);
    % I1B = img1 (sigma = 5)
    I1B = ReconfromAmpPhase(mag1B, phase1);
    % I2A = img2 (sigma = 2)
    I2A = ReconfromAmpPhase(mag2A, phase2);
    % I2B = img1 (sigma = 5)
    I2B = ReconfromAmpPhase(mag2B, phase2);
    nims = 2;
    nsigs = 2;
    Recons = cell(nims,nsigs);
    Recons{1,1} = I1A;
    Recons{1,2} = I1B;
    Recons{2,1} = I2A;
    Recons{2,2} = I2B;
    % Zero crossings of reconstructed images
    dim = 128;
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
                            for dl=[-1,0,1]
                                kk = min(max(k+dk,1),dim);
                                ll = min(max(l+dl,1),dim);
                                if abs(Recons{i,j}(kk,ll))>e && sign(Recons{i,j}(kk,ll))*sign(Recons{i,j}(k,l))<0
                                    temp(k,l)=val;
                                end
                            end
                        end
                        
                    else
                        ZCs{i,j}(k,l) = 0;
                    end
                end
            end
            ZCs{i,j}=temp;
        end
    end
    
    
    
    % I1A = img1 (sigma = 2)
    I1A = ZCs{1,1};
    % I1B = img1 (sigma = 5)
    I1B = ZCs{1,2};
    % I2A = img2 (sigma = 2)
    I2A = ZCs{2,1};
    % I2B = img2 (sigma = 5)
    I2B = ZCs{2,2};
end




function M = DiscreteLoGF(s)
    LoGF = @(u,v,s) (u^2+v^2)*exp(-2*pi^2*s^2*(u^2+v^2));
    
    M = zeros(65,128);

    for i=1:65
        for j=1:65
            M(i,j)=LoGF((i-1)/128,(j-1)/128,s);
        end
        for j=66:128
            M(i,j)=LoGF((i-1)/128,(j-129)/128,s);
        end
    end

end

