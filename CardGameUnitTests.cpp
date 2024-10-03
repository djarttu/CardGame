#include <gtest/gtest.h>
#include "./Deck.hpp"
#include "./Menu.hpp"

namespace CardGameTest{
class CardGameUnitTests : public testing::Test {
  protected:
    Deck deck;        
};

TEST_F(CardGameUnitTests, AddDrawTakeTests) 
{
  constexpr uint16_t fullStack = 52;
  EXPECT_EQ(fullStack, deck.Size().second);

  deck.Add();
  EXPECT_EQ(fullStack - 1, deck.Size().second);
  EXPECT_EQ(1, deck.Size().first);

  deck.Draw();
  EXPECT_EQ(fullStack, deck.Size().second);
  EXPECT_EQ(0, deck.Size().first);

  deck.Add(12);
  EXPECT_EQ(12, deck.Size().first);
  EXPECT_EQ(fullStack - 12, deck.Size().second);

  deck.Add(12);
  EXPECT_EQ(24, deck.Size().first);
  EXPECT_EQ(fullStack - 24, deck.Size().second);

  deck.Take(12);
  EXPECT_EQ(12, deck.Size().first);
  EXPECT_EQ(fullStack - 12, deck.Size().second);

  deck.Take(10);
  EXPECT_EQ(2, deck.Size().first);
  EXPECT_EQ(fullStack - 2, deck.Size().second);
}

TEST_F(CardGameUnitTests, ShuffleTest)
{
  deck.Add(1);
  std::string beforeShuffle = deck.Reveal();
  deck.Shuffle();
  std::string afterShuffle = deck.Reveal();
  EXPECT_EQ(beforeShuffle, afterShuffle);

  deck.Add(12);
  beforeShuffle = deck.Reveal();
  const std::string beforeShuffleComp = deck.Reveal();
  EXPECT_EQ(beforeShuffle, beforeShuffleComp); 
  deck.Shuffle();
  afterShuffle = deck.Reveal();
  EXPECT_NE(beforeShuffle, afterShuffle);
}

TEST_F(CardGameUnitTests, CardFormatTest)
{
  deck.Add(1);
  std::string str = deck.Reveal();
  EXPECT_TRUE(!std::isdigit(str.at(0)) && std::isdigit(str.at(1)));
}
} //namespace