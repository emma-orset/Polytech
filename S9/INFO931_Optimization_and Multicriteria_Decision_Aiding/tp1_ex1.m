%%
% Exercice 1

% --------PROBLEM--------

% Supply the required nutrients at minimum cost
prob = optimproblem("ObjectiveSense",'min');


% --------SET--------

% Number of nutrients (N(n))
nb_Nutrient = 5;

% Number of types of food (F(m))
nb_Food = 4;


% --------PARAMETERS--------

% The amount of nutrient (a(i,j))
Nutrients = [239 11 3 0 18;
             145 1 0 0 0;
             119 0 0 0 2;
             190 8 3 0 25];

% The price per unit of food (b(i))
Cost = [0.85 0.85 1.25 2.5];

% The minimum daily requirement of nutrient (c(j))
Min = [1900 30 0 0 0];

% The maximum daily requirement of nutrient
Max = [2200 75 25 2 300];


% --------VARIABLE--------

% x represent each value of Food
x=optimvar("x",nb_Food,"LowerBound",0);


% --------OBJECTIVE FUNCTION--------

% Minimize the cost
obj = sum(Cost * x);


% --------CONSTRAINTS--------

% Minimum :
% x(Donut) * 239 + x(Bagel) * 145 + ... >= 1900
% x(Donut) * 11 + x(Bagel) * 1 + ... >= 30
% ...
constr_min = optimconstr(nb_Food);
for n=1 : nb_Nutrient
    res = 0;
    for f=1 : nb_Food
       res = res + x(f) * Nutrients(f,n);
    end
    constr_min(n) = res >= Min(n);
end

% Maximum :
% x(Donut) * 239 + x(Bagel) * 145 + ... <= 2200
% x(Donut) * 11 + x(Bagel) * 1 + ... <= 75
% ...
constr_max = optimconstr(nb_Food);
for n=1 : nb_Nutrient
    res = 0;
    for f=1 : nb_Food
       res = res + x(f) * Nutrients(f,n);
    end
    constr_max(n) = res <= Max(n);
end


% --------FINAL STEP--------

prob.Constraints.constr_min = constr_min;
prob.Constraints.constr_max = constr_max;
prob.Objective = obj;

% val => value of decision variables
% sol => res of obj function
[val,sol] = solve(prob);
%%

% --------RESULTS--------
% sol = 7.4908
% val = [6.6187 ; 2.1940 ; 0 ; 0]
