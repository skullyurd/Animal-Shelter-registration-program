#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "animal.h"

int main()
{
    Animal animals[MAX_NUMBER_ANIMAL];
    int number_of_animals = 0;
    int option = -1;
        
    while (option != 0)
    {
        /*
         * Menu of the animal shelter
         * Mandatory assignment (option 0 to 5)
         * Optional assignment (option 6)
         */
        printf("\nMENU\n====\n");
        printf("0: Quit program\n");
        printf("1: Show all animals\n");
        printf("2: Add an animal\n");
        printf("3: Search animals by name \n");
        printf("4: Update species by id\n");
        printf("5: Remove an animal by id\n");
        printf("6: Sort animals by species and name\n");

        scanf("%d", &option);
        switch(option)
        {
            case 0: 
                printf("Quit program\n");
                break;
            case 1:
                show_animals(animals, number_of_animals);
                break;
            case 2:
                printf("\nCHOOSE SPECIES\n====\n");
                printf("0: CAT\n");
                printf("1: CHINCHILLA\n");
                printf("2: DOG\n");
                printf("3: TURTLE\n");
                int species;
                scanf("%d", &species);
                
                if (species < 0 || species > 3)
                {
                    printf("Invalid species\n");
                    printf("stopping process");
                    break;
                }

                if(species == 0)
                {
                    printf("You chose CAT\n");
                }
                else if(species == 1)
                {
                    printf("You chose CHINCHILLA\n");
                }
                else if(species == 2)
                {
                    printf("You chose DOG\n");
                }
                else if(species == 3)
                {
                    printf("You chose TURTLE\n");
                }
                else
                {
                    printf("Invalid species\n");
                    printf("stopping process");
                    break;
                }
                
                printf("Enter the name of the animal: ");
                char nameNewAnimal[MAX_LENGTH_NAME];
                scanf("%s", nameNewAnimal);
                printf("Enter the chip number of the animal: ");
                int chip_number;
                scanf("%d", &chip_number);
                Animal new_animal;
                new_animal.species = species;
                strcpy(new_animal.name, nameNewAnimal);
                new_animal.chip_number = chip_number;
                add_animal(animals, &number_of_animals, new_animal);
                break;
            case 3:
                printf("Enter the name of the animal: ");
                char nameSearchAnimal[MAX_LENGTH_NAME];
                scanf("%s", nameSearchAnimal);
                search_animals_by_name(animals, number_of_animals, nameSearchAnimal);

                break;
            case 4:
                printf("Enter the chip number of the animal: ");
                int chip_number_update;
                scanf("%d", &chip_number_update);
                printf("\nCHOOSE SPECIES\n====\n");
                printf("0: CAT\n");
                printf("1: CHINCHILLA\n");
                printf("2: DOG\n");
                printf("3: TURTLE\n");
                int species_update;
                scanf("%d", &species_update);

                if (species_update < 0 || species_update > 3)
                {
                    printf("Invalid species\n");
                    printf("stopping process");
                    break;
                }

                if(species_update == 0)
                {
                    printf("You chose CAT\n");
                }
                else if(species_update == 1)
                {
                    printf("You chose CHINCHILLA\n");
                }
                else if(species_update == 2)
                {
                    printf("You chose DOG\n");
                }
                else if(species_update == 3)
                {
                    printf("You chose TURTLE\n");
                }
                else
                {
                    printf("Invalid species\n");
                    printf("stopping process");
                    break;
                }

                update_species_by_chip_number(animals, number_of_animals, chip_number_update, species_update);
                break;
            case 5:
                printf("Enter the chip number of the animal: ");
                int chip_number_remove;
                scanf("%d", &chip_number_remove);
                remove_animal_by_chipnumber(animals, &number_of_animals, chip_number_remove);

                break;
            case 6:
                sort_animals_by_species_and_name(animals, number_of_animals);
                break;
            default:
                break;
		}
	}
    return 0;
}