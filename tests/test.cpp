#include <iostream>
#include "../src/card_model.cpp"
#include "../src/player_model.cpp"

int main() {
    Card card (2, suite_t {hearts});
    card.set_face(true);
    if(card.get_value() != 2) std::cout << "Test Failed\n";
    
    return 1;
}
