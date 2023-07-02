#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "animal.h"
#include "unity.h"

void setUp(void)
{
    // To do: optionally add the code to be executed before each unit test
}

void tearDown(void)
{
    // To do: optionally add the code to be executed after each unit test
}

void test_show_animals(void)
{
    Animal animals[MAX_NUMBER_ANIMAL];
    int number_of_animals = 0;

    Animal animal1 = {"Frodo", DOG, 6787};
    Animal animal2 = {"Bilbo", CAT, 7650};

    TEST_ASSERT_FALSE(show_animals(animals, number_of_animals));

    add_animal(animals, &number_of_animals, animal1);
    add_animal(animals, &number_of_animals, animal2);

    TEST_ASSERT_TRUE(show_animals(animals, number_of_animals));
}

void test_add_animal(void)
{
    Animal animals[MAX_NUMBER_ANIMAL];
    int number_of_animals = 0;

    Animal animal1 = {"Frodo", DOG, 6787};
    Animal animal2 = {"Bilbo", CAT, 7650};

    TEST_ASSERT_TRUE(add_animal(animals, &number_of_animals, animal1));
    TEST_ASSERT_TRUE(add_animal(animals, &number_of_animals, animal2));

    TEST_ASSERT_EQUAL_INT(2, number_of_animals);

    TEST_ASSERT_EQUAL_STRING("Frodo", animals[0].name);
    TEST_ASSERT_EQUAL_INT(DOG, animals[0].species);
    TEST_ASSERT_EQUAL_INT(6787, animals[0].chip_number);

    TEST_ASSERT_EQUAL_STRING("Bilbo", animals[1].name);
    TEST_ASSERT_EQUAL_INT(CAT, animals[1].species);
    TEST_ASSERT_EQUAL_INT(7650, animals[1].chip_number);

}

void test_search_animals_by_name(void)
{
    Animal animals[MAX_NUMBER_ANIMAL];
    int number_of_animals = 0;

    Animal animal1 = {"Bojack", DOG, 1111};
    Animal animal2 = {"Blueberry", CAT, 2222};

    add_animal(animals, &number_of_animals, animal1);
    add_animal(animals, &number_of_animals, animal2);

    TEST_ASSERT_TRUE(search_animals_by_name(animals, number_of_animals, "Bojack"));
    TEST_ASSERT_TRUE(search_animals_by_name(animals, number_of_animals, "Blueberry"));
    TEST_ASSERT_FALSE(search_animals_by_name(animals, number_of_animals, "Bilbo"));
}

void test_update_species_by_ChipNumber(void)
{
    Animal animals[MAX_NUMBER_ANIMAL];
    int number_of_animals = 0;

    Animal animal1 = {"Bojack", DOG, 1111};
    Animal animal2 = {"Blueberry", CAT, 2222};

    add_animal(animals, &number_of_animals, animal1);
    add_animal(animals, &number_of_animals, animal2);

    TEST_ASSERT_TRUE(update_species_by_chip_number(animals, number_of_animals, 1111, CHINCHILLA));
    TEST_ASSERT_TRUE(update_species_by_chip_number(animals, number_of_animals, 2222, TURTLE));

    TEST_ASSERT_EQUAL_INT(CHINCHILLA, animals[0].species);
    TEST_ASSERT_EQUAL_INT(TURTLE, animals[1].species);

}

void test_remove_animal_by_ChipNumber(void)
{
    Animal animals[MAX_NUMBER_ANIMAL];
    int number_of_animals = 0;

    Animal animal1 = {"Bojack", DOG, 1111};
    Animal animal2 = {"Blueberry", CAT, 2222};
    Animal animal3 = {"Bilbo", CHINCHILLA, 3333};

    add_animal(animals, &number_of_animals, animal1);
    add_animal(animals, &number_of_animals, animal2);
    add_animal(animals, &number_of_animals, animal3);

    TEST_ASSERT_EQUAL_INT(3, number_of_animals);
    TEST_ASSERT_TRUE(remove_animal_by_chipnumber(animals, &number_of_animals, 1111));
    TEST_ASSERT_EQUAL_INT(2, number_of_animals);
    TEST_ASSERT_TRUE(remove_animal_by_chipnumber(animals, &number_of_animals, 2222));
    TEST_ASSERT_EQUAL_INT(1, number_of_animals);
    TEST_ASSERT_TRUE(remove_animal_by_chipnumber(animals, &number_of_animals, 3333));
    TEST_ASSERT_EQUAL_INT(0, number_of_animals);
}

void test_sort_animals_by_species_and_name(void)
{
    Animal animals[MAX_NUMBER_ANIMAL];
    int number_of_animals = 0;

    Animal animal1 = {"A", DOG, 1111};
    Animal animal2 = {"B", TURTLE, 2222};
    Animal animal3 = {"C", DOG, 3333};
    Animal animal4 = {"D", CAT, 4444};
    Animal animal5 = {"E", CHINCHILLA, 5555};
    Animal animal6 = {"F", TURTLE, 6666};
    Animal animal7 = {"G", CAT, 7777};

    add_animal(animals, &number_of_animals, animal1);
    add_animal(animals, &number_of_animals, animal2);
    add_animal(animals, &number_of_animals, animal3);
    add_animal(animals, &number_of_animals, animal4);
    add_animal(animals, &number_of_animals, animal5);
    add_animal(animals, &number_of_animals, animal6);
    add_animal(animals, &number_of_animals, animal7);

    TEST_ASSERT_TRUE(sort_animals_by_species_and_name(animals, number_of_animals));
    // Order should be : CAT, CAT, CHINCHILLA, DOG, DOG, TURTLE, TURTLE
    //Letter order should be : D, G, E, A, C, B, F
    TEST_ASSERT_EQUAL_INT(animal4.chip_number, animals[0].chip_number);
    TEST_ASSERT_EQUAL_INT(animal7.chip_number, animals[1].chip_number);
    TEST_ASSERT_EQUAL_INT(animal5.chip_number, animals[2].chip_number);
    TEST_ASSERT_EQUAL_INT(animal1.chip_number, animals[3].chip_number);
    TEST_ASSERT_EQUAL_INT(animal3.chip_number, animals[4].chip_number);
    TEST_ASSERT_EQUAL_INT(animal2.chip_number, animals[5].chip_number);
    TEST_ASSERT_EQUAL_INT(animal6.chip_number, animals[6].chip_number);
}

int main(void)
{
    UnityBegin(0);

    RUN_TEST(test_show_animals);
    RUN_TEST(test_add_animal);
    RUN_TEST(test_search_animals_by_name);
    RUN_TEST(test_update_species_by_ChipNumber);
    RUN_TEST(test_remove_animal_by_ChipNumber);
    RUN_TEST(test_sort_animals_by_species_and_name);

    return UnityEnd();
}
