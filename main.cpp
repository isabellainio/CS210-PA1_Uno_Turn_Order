#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;

    std::unique_ptr<List<int>> nums = makeList<int>();

    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();

    nums->addAnywhere(1, new int(99));
    nums->print();

    nums->deleteAnywhere(2);
    nums->print();

    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;

    std::unique_ptr<List<int>> more = makeList<int>();

    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();

    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::cout << std::endl << "== Uno Turn Order ==" << std::endl;

    std::unique_ptr<List<Player>> table = makeList<Player>();

    Player* isabella = new Player(4, "Isabella");
    Player* megan = new Player(3, "Megan");
    Player* alex = new Player(2, "Alex");
    Player* jordan = new Player(1, "Jordan");

    isabella->addCard(new Card("Red", "7"));
    isabella->addCard(new Card("Blue", "Reverse"));

    megan->addCard(new Card("Yellow", "3"));
    megan->addCard(new Card("Green", "5"));

    alex->addCard(new Card("Blue", "2"));
    alex->addCard(new Card("Red", "Skip"));

    jordan->addCard(new Card("Green", "9"));
    jordan->addCard(new Card("Yellow", "Draw Two"));

    table->addFront(isabella);
    table->addFront(megan);
    table->addFront(alex);
    table->addFront(jordan);

    std::cout << "Starting table:" << std::endl;
    table->print();

    std::cout << "Isabella's starting hand:" << std::endl;
    isabella->printHand();

    Player* sofia = new Player(5, "Sofia");

    sofia->addCard(new Card("Yellow", "4"));
    sofia->addCard(new Card("Red", "9"));

    std::cout << "A new player joins mid-order:" << std::endl;
    table->addAnywhere(2, sofia);
    table->print();

    std::cout << "Before reverse:" << std::endl;
    table->print();

    isabella->playCard();
    table->reverse();

    std::cout << "After reverse:" << std::endl;
    table->print();

    std::cout << "Isabella's hand after playing:" << std::endl;
    isabella->printHand();

    std::cout << "Sofia runs out of cards and leaves:" << std::endl;
    table->deleteAnywhere(2);
    table->print();

    std::unique_ptr<List<Player>> table2 = makeList<Player>();

    Player* sarah = new Player(6, "Sarah");
    Player* daniel = new Player(7, "Daniel");

    sarah->addCard(new Card("Green", "6"));
    sarah->addCard(new Card("Blue", "1"));

    daniel->addCard(new Card("Red", "4"));
    daniel->addCard(new Card("Yellow", "Skip"));

    table2->addFront(daniel);
    table2->addFront(sarah);

    std::cout << "First table before merge:" << std::endl;
    table->print();

    std::cout << "Second table before merge:" << std::endl;
    table2->print();

    std::cout << "Tables merge:" << std::endl;
    table->concat(table2.get());

    std::cout << "First table after merge:" << std::endl;
    table->print();

    std::cout << "Second table after merge:" << std::endl;
    table2->print();

    return 0;
}