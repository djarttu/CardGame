#include <cstdint>
#include <iostream>
#include <limits>
#include <sstream>


class Menu{
    public:
    Menu(){
        createMenuString();
    }
    
    void PrintMenu(){   
        PrintString(menuString);
    };
    
    inline uint16_t GetInput(){
        uint16_t input;
        while(!(std::cin >> input))        
        {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            PrintString("Input in wrong format, please provide integers");
		
        }
        std::cout << std::endl;
        return input;
        
    };
    
    inline void PrintString(const std::string& string)
    {
        std::cout << string << std::endl;
        return;
    }

    private:
    std::string menuString; 

    inline void createMenuString(){
        std::stringstream ss;
        ss << "\n"
        << "***Main menu***" << std::endl
        << "Add a card top of the deck: 1" << std::endl
        << "Add cards top of the deck: 2" << std::endl
        << "Draw a card from top of the deck: 3" << std::endl
        << "Take cards from the top of the deck: 4" << std::endl
        << "Shuffle deck: 5" << std::endl
        << "Deck and container sizes: 6" << std::endl
        << "Reveal: 7" << std::endl
        << "Reveal top card: 8" << std::endl
        << "Exit: 0" << std::endl;
        menuString = ss.str();
    }
};
