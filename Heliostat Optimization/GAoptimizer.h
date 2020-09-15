#pragma once
# include <cmath>
# include <cstdlib>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <iomanip>
# include <ctime>
# include <cstring>
# include "HeliostatField.h"

using namespace std;
// 
//  Change any of these parameters to match your needs 
//

const int MAXGENS = 1000;
const int PXOVER = 0.8;
const int PMUTATION = 0.15;
const int POPSIZE = 50;
const int NVARS = 2;
//
//  Each GENOTYPE is a member of the population, with
//  gene: a string of variables,
//  fitness: the fitness
//  upper: the variable upper bounds,
//  lower: the variable lower bounds,
//  rfitness: the relative fitness,
//  cfitness: the cumulative fitness.
//

struct genotype
{
    double gene[NVARS];
    double fitness;
    double upper[NVARS];
    double lower[NVARS];
    double rfitness;
    double cfitness;
};

extern struct genotype population[POPSIZE + 1];
extern struct genotype newpopulation[POPSIZE + 1];

int main();
void crossover(int& seed);
void elitist();
double FitnessFunc(double a, double b);
void evaluate();
int i4_uniform_ab(int a, int b, int& seed);
void initialize(string filename, int& seed);
void keep_the_best();
void mutate(int& seed);
double r8_uniform_ab(double a, double b, int& seed);
void report(int generation);
void selector(int& seed);
void timestamp();
void Xover(int one, int two, int& seed);

//****************************************************************************80


