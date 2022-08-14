//
// Unit test. Do not alter.
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <string>
using std::to_string;

#include "inventory.h"

TEST_CASE("item") {
  Item i1 = {"Item 2", 0.05, 3};
  Item i2 = {"Item 1", 0.10, 1};
  Item i3 = {"Item 3", 0.25, 2};

  CHECK_EQ(compareByName(i1, i2), false);
  CHECK_EQ(compareByName(i1, i3), true);

  CHECK_EQ(compareByPrice(i2, i1), false);
  CHECK_EQ(compareByPrice(i2, i3), true);

  CHECK_EQ(compareByQuantity(i3, i1), true);
  CHECK_EQ(compareByQuantity(i3, i2), false);

  CHECK_EQ(itemToString(i1), string("Item 2, $0.05, 3 available"));
}

TEST_CASE("inventory") {
  Item i1 = {"Item 2", 0.05, 3};
  Item i2 = {"Item 1", 0.10, 2};
  Item i3 = {"Item 3", 0.25, 1};

  Inventory inv;

  SUBCASE("basic functionality") {
    CHECK_EQ(inv.getItemCount(), 0);
    CHECK_EQ(inv.toString(), string(""));

    CHECK_EQ(inv.addItem(i1), true);
    CHECK_EQ(inv.getItemCount(), 1);
    CHECK_EQ(inv.hasItem(i1.name), true);
    CHECK_EQ(inv.updateItem(i1.name, "Item 20", 1.05, 30), true);
    CHECK_EQ(inv.toString(), string("[1] Item 20, $1.05, 30 available\n"));

    CHECK_EQ(inv.removeItem("Item 20"), true);
    CHECK_EQ(inv.getItemCount(), 0);
    CHECK_EQ(inv.toString(), string(""));
  }

  SUBCASE("has a few items") {
    CHECK_EQ(inv.addItem(i1), true);
    CHECK_EQ(inv.addItem(i2), true);
    CHECK_EQ(inv.addItem(i3), true);

    CHECK_EQ(inv.getItemCount(), 3);

    CHECK_EQ(inv.hasItem(i1.name), true);
    CHECK_EQ(inv.hasItem(i2.name), true);
    CHECK_EQ(inv.hasItem(i3.name), true);

    CHECK_EQ(inv.toString(),
      string("[1] Item 2, $0.05, 3 available\n[2] Item 1, $0.10, 2 available\n[3] Item 3, $0.25, 1 available\n"));

    CHECK_EQ(inv.updateItem(i1.name, "Item 20", 1.05, 30), true);
    CHECK_EQ(inv.updateItem(i2.name, "Item 10", 1.10, 20), true);
    CHECK_EQ(inv.updateItem(i3.name, "Item 30", 1.25, 10), true);

    CHECK_EQ(inv.toString(),
      string("[1] Item 20, $1.05, 30 available\n[2] Item 10, $1.10, 20 available\n[3] Item 30, $1.25, 10 available\n"));

    CHECK_EQ(inv.removeItem("Item 20"), true);
    CHECK_EQ(inv.removeItem("Item 10"), true);
    CHECK_EQ(inv.removeItem("Item 30"), true);
    CHECK_EQ(inv.getItemCount(), 0);
    CHECK_EQ(inv.toString(), string(""));
  }

  SUBCASE("stress test") {
    for (size_t i = 1; i <= 100; i++) {
      Item item = {"Item " + to_string(i), 1.0, 1};
      CHECK_EQ(inv.addItem(item), true);
    }
    CHECK_EQ(inv.getItemCount(), 100);
    for (size_t i = 1; i <= 100; i++) {
      CHECK_EQ(inv.removeItem("Item " + to_string(i)), true);
    }
    CHECK_EQ(inv.getItemCount(), 0);
  }
}
