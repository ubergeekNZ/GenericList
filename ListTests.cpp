#include "List.h"
#include <stdlib.h>
#include "gtest/gtest.h"

using namespace std; 

#define MAX_LIST_SIZE        256
#define NUM_TEST_RUN         100


class ListTests : public ::testing::Test
{
protected:

    List<uint32_t> *test_list;

    ListTests() {}

    virtual void SetUp()
    {
        test_list = new List<uint32_t>(MAX_LIST_SIZE);
        
    }
};

TEST_F(ListTests, TestAddPeekAndRemove)
{
    // add data to the list
    for (uint32_t count =0; count < MAX_LIST_SIZE; count++)
    {
        test_list->push(count);
    }

    ASSERT_EQ(test_list->isFull(), true);

    // peek at the data to check if it is correct
    for (uint32_t count =0; count < MAX_LIST_SIZE; count++)
    {
        ASSERT_EQ(test_list->peekElement(count), count);
    }

    // remove from the head and compare the data
    for (uint32_t count =0; count < MAX_LIST_SIZE; count++)
    {
        ASSERT_EQ(test_list->pop(), count);
    }

    ASSERT_EQ(test_list->isEmpty(), true);
}

TEST_F(ListTests, TestPushPop)
{
    // add data to the list
    for (uint32_t count =0; count < MAX_LIST_SIZE; count++)
    {
        test_list->push(count);
    }

    ASSERT_EQ(test_list->isFull(), true);

    // peek at the data to check if it is correct
    for (uint32_t count =0; count < MAX_LIST_SIZE; count++)
    {
        ASSERT_EQ(test_list->peekElement(count), count);
    }

    // remove from the head and compare the data
    ASSERT_EQ(test_list->pop(), 0);
    ASSERT_EQ(test_list->pop(), 1);
    test_list->push(666);
}

TEST_F(ListTests, TestAddAndRemoveSingleItemRandomly)
{
    for (uint32_t test_run= 0; test_run < NUM_TEST_RUN; test_run++) 
    {
        for (uint32_t count =0; count < MAX_LIST_SIZE; count++)
        {
            test_list->push(count);
        }

        ASSERT_EQ(test_list->isFull(), true);

        // remove a single number randomly 
        srand(time(NULL));
        uint32_t r = rand() % MAX_LIST_SIZE;
        test_list->removeFromList(r);

        ASSERT_EQ(test_list->sizeOfList(), MAX_LIST_SIZE-1);

        for (uint32_t count =0; count < test_list->sizeOfList(); count++)
        {
            if (count < r)
            {
                ASSERT_EQ(test_list->peekElement(count), count);
            }
            
            if (count > r)
            {
                ASSERT_EQ(test_list->peekElement(count-1), count);
            }
        }

        test_list->reset();

        ASSERT_EQ(test_list->isEmpty(), true);
    }
}


TEST_F(ListTests, TestAddAndInsertion)
{
    // add data to the list
    for (uint32_t count =0; count < MAX_LIST_SIZE/2; count++)
    {
        test_list->push(count);
    }

    ASSERT_EQ(test_list->isFull(), false);

    uint32_t start = MAX_LIST_SIZE/4;

    // insert data to the list
    for (uint32_t count = 0; count < MAX_LIST_SIZE/2; count++)
    {
        test_list->insert(start, count);
    }

    ASSERT_EQ(test_list->sizeOfList(), MAX_LIST_SIZE);
    ASSERT_EQ(test_list->isFull(), true);

    uint32_t previous_count = 0;
    uint32_t insert_value = (MAX_LIST_SIZE/2) -1;

    for (uint32_t count = 0; count < MAX_LIST_SIZE; count++)
    {       
        if (count >= MAX_LIST_SIZE/4 && count < (MAX_LIST_SIZE/2 + MAX_LIST_SIZE/4))
        {
            ASSERT_EQ(test_list->pop(), insert_value);
            insert_value--;
        }   
        
        if (count < MAX_LIST_SIZE/4)
        {
            ASSERT_EQ(test_list->pop(), count);
            previous_count = count;
        }

        if (count >= (MAX_LIST_SIZE/2 + MAX_LIST_SIZE/4))
        {
            previous_count++;
            ASSERT_EQ(test_list->pop(), previous_count);
        }  
    }

    ASSERT_EQ(test_list->isEmpty(), true);
}
