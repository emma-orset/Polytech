%%
% Exercice 2

% --------PROBLEM--------

% Maximize the beneficial point to have two bags with maximum useful items
prob = optimproblem("ObjectiveSense",'min');


% --------SET--------

% Number of warehouses
nb_warehouse = 3;

% Number of customers
nb_customer = 4;


% --------PARAMETERS--------

% Per-unit operating cost at warehouse
% + transportation cost from warehouse to customer
Cost = [6 2 6 7;
        4 9 5 3;
        8 8 1 5];

% Fixed operating cost for each warehouse if opened
Fixed_cost = [30 25 21];

% Min demand for each customer
Demand = [15 17 22 12];


% --------DECISION VARIABLE--------

x = optimvar("x", nb_warehouse, nb_customer, LowerBound=0, Type="integer");
y = optimvar("y", nb_warehouse, LowerBound=0, Type="integer", UpperBound=1);


% --------OBJECTIVE FUNCTION--------

obj = 0;
for i=1:nb_warehouse
    obj = obj + sum(x(i, :) .* c(i, :)) + f(i)*y(i);
end


% --------CONSTRAINTS--------

% Each column of custumer has to be equal to the demand
constr_equal = optimconstr(nb_customer);
for i=1:nb_customer
    constr_equal(i) = sum(x(:, i)) == Demand(i);
end

% --------FINAL STEP--------

prob.Constraints.constr_equal = constr_equal;
prob.Objective = obj;
[val, sol] = solve(prob)

%%