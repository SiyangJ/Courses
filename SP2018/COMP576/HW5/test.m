% f = @(t) sin(t/5)+cos(t/20)-((t-50)/30).^2;
% 
% ts = 0:10:100;
% xs = f(ts);
% n = length(ts);
% 
% zs = OneDSpline(ts,lambda,xs);
% 
% function [splinedRow,cps] = OneDSpline(t_i,lambda,cps)
%     %%%cp = [0;0;0;0];
%     %%%idx = [0,0,0,1];
%     splinedRow = zeros(1,512);
%     
%     k=2;
%     for t = 1:512
%         if t<t_i(k)+64 || k ==6
%             idx = [((t-t_i(k))/64)^3, ((t-t_i(k))/64)^2, (t-t_i(k)/64), 1];
%             cp = [cps(k-1);cps(k);cps(k+1);cps(k+2)];
%             %%%splinedRow(t) = (1/6)*idx*lambda*cp;
%             A = lambda*cp;
%             splinedRow(t) = idx*A;
%         else
%             k = k+1;
%             idx = [((t-t_i(k))/64)^3, ((t-t_i(k))/64)^2, (t-t_i(k)/64), 1];
%             cp = [cps(k-1);cps(k);cps(k+1);cps(k+2)];
%             %%%splinedRow(t) = (1/6)*idx*lambda*cp;
%             A = lambda*cp;
%             splinedRow(t) = idx*A;
%         end
%     end
% end

t = 10;
k = 2;
idx_ = [((t-t_i(k))/64)^3, ((t-t_i(k))/64)^2, (t-t_i(k)/64), 1]
dx = (t-t_i(k))/64;
idx = [dx^3,dx^2,dx,1]