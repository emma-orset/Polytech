% Problem definition
clear all;
clc;

% Distance Matrix
distances = [
    inf 5 7 4 8 6;
    7 inf 3 9 2 8;
    7 3 inf 4 7 6;
    4 9 4 inf 5 1;
    8 2 7 5 inf 3;
    6 8 6 1 3 inf
];

% Genetic Algorithm Parameters
populationSize = 10;
numRoutes = 6;
mutationProbability = 0.05;
crossoverProbability = 0.4;
tournamentSize = 3;
generations = 100;

x = [1:populationSize];
x1 = dec2bin(x, numRoutes);

% Generation Population
[population] = GeneratePopulation(x1);

u = 2;
trovato = 0;

while (trovato ~= 1)
    % Fitness function
    [fitness, ~] = FitnessFunction(population, distances);

    % Selection
    selected_individuals = selection(population, fitness, populationSize, tournamentSize);
    populationSelected = selected_individuals;

    % Crossover
    for j = 1:size(populationSelected, 2)
        for k = 1:size(populationSelected, 2)
            if (j ~= k)
                [populationSelected(j, :), populationSelected(k, :)] = crossover(populationSelected(j, :), populationSelected(k, :), crossoverProbability);
            end
        end
    end

    % Mutation
    for k = 1:size(populationSelected, 2)
        populationSelected(k, :) = mutation(populationSelected(k, :), mutationProbability);
    end

    % Fitness function
    [fitnessAfter, ~] = FitnessFunction(populationSelected, distances);

    % Update population
    population = populationSelected;

    M(u) = 0;
    for t = 1:size(fitnessAfter, 2)
        if fitnessAfter(t) >= M(u)
            M(u) = fitnessAfter(t);
            idx(u) = t;
        end
    end

    if M(u) == M(u - 1)
        trovato = 1;
    end

    u = u + 1;
end

bestRoute = population(idx(end), :);
disp(['Best Route: ', num2str(bestRoute), ', Fitness: ', num2str(M(end))]);

