#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "animal.h"

bool show_animals(Animal* animals, int number_of_animals)
{
    if (number_of_animals == 0)
    {
        printf("No animals in the shelter\n");
        return false;
    }
    else
    {
        for (int i = 0; i < number_of_animals; i++)
        {
            printf("Name: %s\n", animals[i].name);
            if (animals[i].species == 0)
            {
                printf("Species: CAT\n");
            }
            else if (animals[i].species == 1)
            {
                printf("Species: CHINCHILLA\n");
            }
            else if (animals[i].species == 2)
            {
                printf("Species: DOG\n");
            }
            else if (animals[i].species == 3)
            {
                printf("Species: TURTLE\n");
            }
            
            printf("Chip number: %d\n", animals[i].chip_number);
            printf("--------------------\n");
        }
        return true;
    }
}

bool add_animal(Animal* animals, int* number_of_animals, Animal new_animal)
{
    if (*number_of_animals == MAX_NUMBER_ANIMAL)
    {
        printf("The shelter is full\n");
        return false;
    }
    else
    {
        animals[*number_of_animals] = new_animal;
        *number_of_animals += 1;
        printf("Animal added\n");
        return true;
    }
}

bool search_animals_by_name(Animal* animals, int number_of_animals, char name[])
{
    bool found = false;
    for (int i = 0; i < number_of_animals; i++)
    {
        if (strcmp(animals[i].name, name) == 0)
        {
            printf("Name: %s\n", animals[i].name);
            if (animals[i].species == 0)
            {
                printf("Species: CAT\n");
            }
            else if (animals[i].species == 1)
            {
                printf("Species: CHINCHILLA\n");
            }
            else if (animals[i].species == 2)
            {
                printf("Species: DOG\n");
            }
            else if (animals[i].species == 3)
            {
                printf("Species: TURTLE\n");
            }
            
            printf("Chip number: %d\n", animals[i].chip_number);
            printf("--------------------\n");
            found = true;
        }
    }
    if (found == false)
    {
        printf("No animals with name %s\n", name);
    }
    return found;
}

bool update_species_by_chip_number(Animal* animals, int number_of_animals, int chip_number, Species new_species)
{
    bool found = false;
    for (int i = 0; i < number_of_animals; i++)
    {
        if (animals[i].chip_number == chip_number)
        {
            animals[i].species = new_species;
            found = true;
        }
    }
    if (found == false)
    {
        printf("No animals with chip number %d\n", chip_number);
    }
    return found;
}

bool remove_animal_by_chipnumber(Animal* animals, int* number_of_animals, int chip_number)
{
    bool found = false;
    for (int i = 0; i < *number_of_animals; i++)
    {
        if (animals[i].chip_number == chip_number)
        {
            for (int j = i; j < *number_of_animals - 1; j++)
            {
                animals[j] = animals[j + 1];
            }
            *number_of_animals -= 1;
            found = true;
        }
    }
    if (found == false)
    {
        printf("No animals with chip number %d\n", chip_number);
    }
    printf("Animal removed\n");
    return found;
}

bool sort_animals_by_species_and_name(Animal* animals, int number_of_animals)
{
    if (number_of_animals == 0)
    {
        printf("No animals in the shelter\n");
        return false;
    }
    else
    {
        printf("LIST BEFORE SORTING:\n");
        printf("--------------------\n");
        for (int i = 0; i < number_of_animals; i++)
        {
            printf("Name: %s\n", animals[i].name);
            if (animals[i].species == 0)
            {
                printf("Species: CAT\n");
            }
            else if (animals[i].species == 1)
            {
                printf("Species: CHINCHILLA\n");
            }
            else if (animals[i].species == 2)
            {
                printf("Species: DOG\n");
            }
            else if (animals[i].species == 3)
            {
                printf("Species: TURTLE\n");
            }
            
            printf("Chip number: %d\n", animals[i].chip_number);
            printf("--------------------\n");
        }

        for (int i = 0; i < number_of_animals - 1; i++)
        {
            for (int j = i + 1; j < number_of_animals; j++)
            {
                if (animals[i].species > animals[j].species)
                {
                    Animal temp = animals[i];
                    animals[i] = animals[j];
                    animals[j] = temp;
                }
                else if (animals[i].species == animals[j].species)
                {
                    if (strcmp(animals[i].name, animals[j].name) > 0)
                    {
                        Animal temp = animals[i];
                        animals[i] = animals[j];
                        animals[j] = temp;
                    }
                }
            }
        }
            
        printf("LIST AFTER SORTING:\n");
        printf("--------------------\n");
        for (int i = 0; i < number_of_animals; i++)
        {
            printf("Name: %s\n", animals[i].name);
            if (animals[i].species == 0)
            {
                printf("Species: CAT\n");
            }
            else if (animals[i].species == 1)
            {
                printf("Species: CHINCHILLA\n");
            }
            else if (animals[i].species == 2)
            {
                printf("Species: DOG\n");
            }
            else if (animals[i].species == 3)
            {
                printf("Species: TURTLE\n");
            }
            
            printf("Chip number: %d\n", animals[i].chip_number);
            printf("--------------------\n");
        }

        return true;
    }
}