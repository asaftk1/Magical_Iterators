#include "doctest.h"
#include "sources/MagicalContainer.hpp"
#include <stdexcept>

using namespace ariel;
using namespace std;

// Test case for adding elements to the MagicalContainer
TEST_SUITE("Adding and removing element from MegicalContainer")
{
    MagicalContainer container;
    TEST_CASE("Adding elements to MagicalContainer")
    {
        container.addElement(20);
        CHECK(container.size() == 1);
        container.addElement(10);
        container.addElement(50);
        CHECK(container.size() == 3);

        CHECK_NOTHROW(container.removeElement(50)); //// should no throw exaption if the element is in the container
        CHECK_THROWS(container.removeElement(40));  //// should no throw exaption if the element is not in the container

        CHECK(container.size() == 2);
        container.removeElement(20);
        container.removeElement(10);
        CHECK(container.size() == 0);
    }
}

// Test case for the AscendingIterator
TEST_SUITE("AscendingIterator")
{
    MagicalContainer container;

    TEST_CASE("Iterating ")
    {
        container.addElement(20);
        container.addElement(35);
        container.addElement(40);
        container.addElement(11);
        container.addElement(12);
        MagicalContainer::AscendingIterator it(container);
        CHECK(*it == 20);
        ++it;
        CHECK(*it == 35);
        ++it;
        CHECK(*it == 40);
        ++it;
        CHECK(*it == 11);
        ++it;
        CHECK(*it == 12);
        ++it;
        CHECK(it == it.end());
        
    }
}

// Test case for the SideCrossIterator
TEST_SUITE("SideCrossIterator")
{
    MagicalContainer container;

    TEST_CASE("Iterating over elements")
    {
        container.addElement(20);
        container.addElement(35);
        container.addElement(40);
        container.addElement(11);
        container.addElement(12);
        MagicalContainer::SideCrossIterator it(container);
        CHECK(*it == 20);
        ++it;
        CHECK(*it == 12);
        ++it;
        CHECK(*it == 35);
        ++it;
        CHECK(*it == 11);
        ++it;
        CHECK(it == it.end());
    }

}

// Test case for the PrimeIterator
TEST_SUITE("PrimeIterator")
{
    MagicalContainer container;
    TEST_CASE("Iterating over elements")
    {
          container.addElement(2);
        container.addElement(7);
        container.addElement(40);
        container.addElement(11);
        container.addElement(12);
        MagicalContainer::PrimeIterator it(container);
        CHECK(*it == 2);
        ++it;
        CHECK(*it == 7);
        ++it;
        CHECK(*it == 11);
        ++it;
        CHECK(it == it.end());
    }

    
}
