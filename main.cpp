#include <iostream>
#include "./Menu.hpp"
#include "./Deck.hpp"

int main()
{
    Deck deck;
    Menu menu;
    uint16_t choice;
    std::stringstream ss;
    do{
        menu.PrintMenu();
        choice = menu.GetInput();
        switch(choice){
            case 1:
                menu.PrintString(deck.Add());
                break;
            case 2:
                menu.PrintString("Give amount of cards to add");
                menu.PrintString(deck.Add(menu.GetInput()));
                break;
            case 3:
                menu.PrintString(deck.Draw());
                break;
            case 4:
                menu.PrintString("Give amount of cards to draw");
                menu.PrintString(deck.Take(menu.GetInput()));
                break;
            case 5:
                menu.PrintString(deck.Shuffle());
                break;
            case 6:
                ss << "Deck size: " << deck.Size().first << ", Container size: " << deck.Size().second << std::endl;
                menu.PrintString(ss.str());
                ss.str("");
                break;
            case 7:
                menu.PrintString(deck.Reveal());
                break;
            case 8: 
                menu.PrintString(deck.RevealTop());
                break;
            case 0:
                menu.PrintString("Great to see you, next time");
                break;
            default:
                menu.PrintString("Oh, you want to be nasty with me attaboy, give a proper value");
                break;
        }
    } while (choice != 0);
    return 0;
}
