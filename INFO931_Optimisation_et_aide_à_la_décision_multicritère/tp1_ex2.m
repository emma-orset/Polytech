%%
% Exercice 2

% --------PROBLEM--------

% Meet the market requirements at minimum transportation cost
prob = optimproblem("ObjectiveSense",'min');


% --------SET--------

% Number of ports (P(i))
nb_Port = 3;

% Number of markets (M(j))
nb_Market = 4;


% --------PARAMETERS--------

% Cost of transporting one unit of the commodity
% from port to market (b(i,j))
Cost = [6 2 6 7;
        4 9 5 3;
        8 8 1 5];

% Max capacity for each port (r(j))
Max_capacity = [30 25 21];

% Min demand for each market
Min_demand = [15 17 22 12];


% --------VARIABLE--------

% return a matrice (same size as Cost)
x=optimvar("x",nb_Port,nb_Market,"LowerBound",0);


% --------OBJECTIVE FUNCTION--------

% Minimize the cost
% Multiply 2 matrices (same size) elements by element
% x.*Cost => Return a matrice (same size as cost and x)
% sum(x.*Cost) => Return a matrice with the sum of each column

% So, to return the real sum of the matrice =>
obj = sum(sum(x.*Cost));


% --------CONSTRAINTS--------

% Minimum of demand
% x(1,1) + x(2,1) + x(3,1) >= 15
% x(1,2) + x(2,2) + x(3,2) >= 17
% ...
% sum(x(p,m)) >= min_demand(m)
constr_min = optimconstr(nb_Port);
for m=1 : nb_Market
    res = 0;
    for p=1 : nb_Port
       res = res + x(p,m);
    end
    % Without the second for :
    % ":" = all column of market m
    % res = sum(x(:, m))
    constr_min(m) = res >= Min_demand(m);
end

% Maximum of capacity
% x(1,1) + x(1,2) + x(1,3) + x(1,4) <= 30
% x(2,1) + x(2,2) + x(2,3) + x(2,4) <= 25
% ...
% sum(x(p,m)) <= max_capacity(p)
constr_max = optimconstr(nb_Market);
for p=1 : nb_Port
    res = 0;
    for m=1 : nb_Market
       res = res + x(p,m);
    end
    % Without the second for :
    % ":" = all line of port p
    % res = sum(x(p, :))
    constr_max(p) = res <= Max_capacity(p);
end


% --------FINAL STEP--------

prob.Constraints.constr_min = constr_min;
prob.Constraints.constr_max = constr_max;
prob.Objective = obj;

% val => value of decision variables
% sol => res of obj function
[val,sol] = solve(prob);



% --------RESULTS--------
% sol = 161
% val = [2 17 1 0;
%        13 0 0 12;
%        0 0 21 0]
