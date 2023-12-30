clear;
clc;

% --------PROBLEM--------

% Minimize the time and the price
prob = optimproblem('ObjectiveSense', 'minimize');


% --------SET--------

% Number of locations
Location = 5;

% Number of transports
Transport = 3;


% --------PARAMETERS--------

% Distances between locations (OD Matrix)
distances_2D = [
    1000, 0.6, 1.3, 5.2, 6.3; % House
    0.6, 1000, 1.5, 4.7, 5.3; % Pharmacy
    1.3, 1.5, 1000, 6.1, 4.8; % Post
    5.2, 4.7, 6.1, 1000, 9.2; % Mall
    6.3, 5.3, 4.8, 9.2, 1000  % Gym
];

distances = repmat(distances_2D, 1, 1, Transport);

% Distances between parking locations
parking_distances = [0.5 0.5 0.5 0.1 0.1];

% Distances between stop locations
stop_distances = [0.2 0.1 0.3 0.5 0.4];

% Time spent in each location (in minutes)
time_location = [90, 60, 5, 10];

% Speed for each transport
speed_walk = 5; % km/h
speed_car = 30; % km/h
speed_bus = 10; % km/h

% Cost for each transport
cost_walk = 0;
cost_car = 0.5; % €/km
cost_bus = 1; % € for each bus change

cost_max = 7; % €
time_max = 300; % min (8 AM to 1 PM)


% --------DECISION VARIABLES--------

% Binary variables indicating the mode of transport (1 if used, 0 otherwise)
x = optimvar('x', Location, Location, Transport, 'Type', 'integer', "LowerBound",0,"UpperBound",1);

% --------OBJECTIVE FUNCTION--------

% Total time spent
total_time = sum(sum(sum(x .* distances))) + sum(time_location);

% Total cost
total_cost = sum(sum(sum(x(:,:,2) .* distances * cost_car))) + sum(sum(sum(x(:,:,3) .* distances * cost_bus))) + sum(x(:,:,1) * cost_walk);

% Set the objective function
prob.Objective = total_time + total_cost;

% --------CONSTRAINTS--------

% Time constraint
time_constraint = total_time <= time_max;

% Cost constraint
cost_constraint = total_cost <= cost_max;

% Unique location constraint (except House)
unique_location_constraint = sum(x(2:end, :, :), [1 2]) == 1;
unique_location_constraint(1, :, :) = 2 * x(1, :, :) == sum(x(2:end, :, :), [1 2]);

% --------ADD CONSTRAINTS TO THE PROBLEM--------

% Add the constraints to the problem
prob.Constraints.time_constraint = time_constraint;
prob.Constraints.cost_constraint = cost_constraint;
prob.Constraints.unique_location_constraint = unique_location_constraint;

% --------SOLVE THE PROBLEM--------

% Solve the problem
[sol, fval, exitflag, output] = solve(prob);

% Extract solution values
x_values = sol.x;

% Display results
disp("Optimal solution:");
disp("Transportation plan:");
disp(x_values);

% Display total time and cost
disp("Total time: " + fval + " minutes");
disp("Total cost: " + total_cost + " euros");

% Display exit flag and solver information
disp("Exit flag: " + exitflag);
disp("Solver information:");
disp(output);

