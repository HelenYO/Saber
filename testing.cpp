#include <gtest/gtest.h>
#include "lib/List.h"
#include <fstream>

namespace {
    void check(List& list1, List& list2) {
        EXPECT_EQ(list1.count, list2.count);
        for (auto i = list1.head, j = list2.head; i != nullptr; i = i->next, j = j->next) {
            EXPECT_EQ(i->data, j->data);
            if(i->rand && j->rand) {
                EXPECT_EQ(i->rand->data, j->rand->data);
            } else {
                EXPECT_EQ(i->rand, j->rand);
            }
        }
    }
}

TEST(correctness, blank) // NOLINT
{
    List list1;
    std::ofstream fout("test.txt",std::ifstream::binary);
    list1.Serialize(fout);
    List list2;
    std::ifstream fin("test.txt",std::ifstream::binary);
    list2.Deserialize(fin);
    check(list1, list2);
}

TEST(correctness, blank_nonblank) // NOLINT
{
    List list1;
    list1.InsertTail("ter");
    list1.head->rand = list1.head;
    std::ofstream fout("test.txt",std::ifstream::binary);
    list1.Serialize(fout);
    List list2;
    std::ifstream fin("test.txt",std::ifstream::binary);
    list2.Deserialize(fin);
    check(list1, list2);
}

TEST(correctness, three_three) // NOLINT
{
    List list1;
    list1.InsertTail("ter");
    std::string b = "two";
    std::string c = "three";
    list1.InsertAfter(list1.head, b);
    list1.InsertHead(c);
    list1.head->rand = list1.tail;
    list1.tail->rand = list1.head->next;
    list1.head->next->rand = list1.head;

    std::ofstream fout("test.txt",std::ifstream::binary);
    list1.Serialize(fout);
    List list2;
    std::ifstream fin("test.txt",std::ifstream::binary);
    list2.Deserialize(fin);
    check(list1, list2);
}

TEST(correctness, three_three_null) // NOLINT
{
    List list1;
    list1.InsertTail("ter");
    std::string b = "two";
    std::string c = "three";
    list1.InsertAfter(list1.head, b);
    list1.InsertHead(c);
    list1.head->rand = list1.tail;
    list1.tail->rand = nullptr;
    list1.head->next->rand = nullptr;

    std::ofstream fout("test",std::ifstream::binary);
    list1.Serialize(fout);
    List list2;
    std::ifstream fin("test",std::ifstream::binary);
    list2.Deserialize(fin);
    check(list1, list2);
}