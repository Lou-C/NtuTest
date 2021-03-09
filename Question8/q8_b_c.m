function q8_b_c

k1 = 100; k2 = 600; k3 = 150;   % um/min
E0 = 1;  S0 = 10; ES0 = 0;  P0 = 0;   % um
z0 = [E0, S0, ES0, P0]';
tspan = [0, 0.05];
[t,z] = ode45(@fun, tspan, z0);

figure;  hold on
plot(t,z(:,1));     plot(t,z(:,2));
plot(t,z(:,3));     plot(t,z(:,4));
xlabel('t/min');   ylabel('um');
legend('E','S','ES','P');

Vm = k3 .* z(:,1);
Km = (k2 + k3) / k1;
v = Vm .* z(:,2) ./ (z(:,2) + Km);

end

function dz = fun(t,z)

k1 = 100; k2 = 600; k3 = 150;   % um/min

% z = [E S ES P]
% dz = diff z

dz(1) = -k1 * z(2) * z(2) + (k2 + k3) * z(3);
dz(2) = -k1 * z(2) * z(2) + k2 * z(3);
dz(3) = k1 * z(2) * z(2) - (k2 + k3) * z(3);
dz(4) = k3 * z(3);
dz = dz';

end
