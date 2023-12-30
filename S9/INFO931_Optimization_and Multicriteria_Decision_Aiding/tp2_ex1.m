%%
% Exercice 1

% --------PROBLEM--------

% Maximize the beneficial point to have two bags with maximum useful items
prob = optimproblem("ObjectiveSense",'max');


% --------SET--------

% Number of items
nb_item = 8;

% Number of carry bags
nb_bag = 2;


% --------PARAMETERS--------

% Benefit points of each item
Benefit = [14 6 9 15 2 4 7 8];

% Weight of each item
Weight = [16 8 7 6 1 6 10 2];

% Max capacity of each bag
Max_capacity = [10 15];


% --------DECISION VARIABLE--------

% Indicating whether an item is selected or not
% x(i, b) = 1 if item i is in bag b, 0 otherwise
x = optimvar("x", nb_item, nb_bag, "Type", "integer", "LowerBound", 0, "UpperBound", 1);


% --------OBJECTIVE FUNCTION--------

% Maximize the total benefit of selected items
obj = sum(Benefit * x);


% --------CONSTRAINTS--------

% Maximum capacity
constr_capacity = optimconstr(nb_bag);
for b = 1:nb_bag
    constr_capacity(b) = sum(Weight * x(:, b)) <= Max_capacity(b);
end

% Each item can be in at most one bag
constr_item_once = optimconstr(nb_item);
for i = 1:nb_item
    constr_item_once(i) = sum(x(i, :)) <= 1;
end


% --------FINAL STEP--------

prob.Constraints.constr_capacity = constr_capacity;
prob.Constraints.constr_item_once = constr_item_once;
prob.Objective = obj;
[val,sol] = solve(prob);


% --------RESULTS--------
% sol = 40 (sum of benefit)
% val =
% [0 0
%  1 0
%  0 1
%  0 1
%  0 1
%  0 0
%  0 0
%  1 0]
% So, we have to take :
% Carry bag 1 : Torch + Book (10kg)
% Carry bag 2 : Bottle + Glucose + Apple (14kg)
