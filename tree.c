/*
** EPITECH PROJECT, 2019
** firtree
** File description:
** prints a firtree
*/

#include <unistd.h>
#include <stdio.h>

void my_putchar(char c){write(1,&c,1);}

int init_spaces(int size)
{
    int init_spaces = 6;
    int stock = size;
    int i = 2;
    int j = 0;

    if (size % 2 == 1) {
        init_spaces = 3;
        i = 1;
    }
    while (i < stock) {
        if (size % 2 == 1)
            init_spaces = init_spaces + (7 + j);
        if (size % 2 == 0)
            init_spaces = init_spaces + (8 + j);
        j += 2;
        i += 2;
    }
    return(init_spaces);
}

void print_spaces(int spaces)
{
    while (spaces > 0) {
        my_putchar(' ');
        spaces -= 1;
    }
}

int print_stars (int nb_stars)
{
    while (nb_stars != 0) {
        my_putchar('*');
        nb_stars -= 1;
    }
    return (nb_stars);
}

void print_trunc(int size, int spaces)
{
    int i = 0;
    int j = 0;

    if (size % 2 == 0)
        j = -1;
    while (i != size) {
        i = i + 1;
        print_spaces(spaces - size/2);
        while (j != size) {
            j = j + 1;
            my_putchar('|');
        }
        if (size % 2 == 0)
            j = -1;
        else
            j = 0;
        my_putchar('\n');
        }
}

void tree(int size)
{
    int nb_stars = 1;
    int stock_stars = 7;
    int i = 1;
    int spaces = init_spaces(size);
    int stock_spaces = spaces;
    int stars_it = 0;
    int nb_layers = 0;

    if (size <= 0)
        return;
    while (nb_layers < size) {
        while (nb_stars <= stock_stars + stars_it) {
            print_spaces(spaces);
            print_stars(nb_stars);
            my_putchar('\n');
            spaces -= 1;
            nb_stars += 2;
        }
        nb_stars = stock_stars - (2 * i);
        i -= 3;
        stars_it += 7;
        nb_layers += 1;
        spaces = stock_spaces + i;
        if (nb_layers == size){
        }
    }
    print_trunc(size, stock_spaces);
}

int main(int ac, char **av)
{
    if (ac != 2)
        tree(1);
    else
        tree(atoi(av[1]));
    return (0);
}
