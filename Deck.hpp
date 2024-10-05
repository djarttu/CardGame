#include <array>
#include <cstdint>
#include <vector>

class Deck{
    public:
    
    Deck();
    std::string Add(uint16_t numOfCards = 1);
    std::string Draw();
    std::string Take(uint16_t numOfCards);
    std::string Reveal();
    std::string RevealTop();
    std::string Shuffle();
    std::pair<uint16_t, uint16_t> Size();
    
    private:

    struct Card 
    {
        std::string country;
        uint16_t value;
    };
    std::array<std::string, 4> countries{"H","C","S","A"};
    std::vector<Card> cardContainer;
    std::vector<Card> deck;
    
    const void FillCardContainer();
    
    std::vector<Card> GetFromContainer(uint16_t amount);

    void PushBackIntoContainer(const std::vector<Card>& returnedCards);
};
