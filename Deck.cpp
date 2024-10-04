#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <sstream>

#include "./Deck.hpp"

Deck::Deck()
{
	FillCardContainer();
};


std::string Deck::Add(uint16_t amount)
{
	std::stringstream ss;
	if(amount > 52 || amount < 1)
	{
		ss << "Wrong amount given";
		return ss.str();
	}   
	const std::vector<Card> availableCards = GetFromContainer(amount);
	if(availableCards.size() > 0){
		deck.insert(deck.end(), availableCards.begin(), availableCards.end());
	}
	ss << availableCards.size() << " cards added top of deck";
	return ss.str();
};

std::string Deck::Draw()
{
	std::vector<Card> drawCard;
	if(deck.size() == 0)
	{
		return "Deck is empty";
	}
	drawCard.emplace_back(deck.back());
	deck.pop_back();
	PushBackIntoContainer(drawCard);
	return "One card returned into container";
};

std::string Deck::Take(uint16_t amount){
	std::stringstream ss;
	if(deck.size() == 0)
	{
		ss << "Deck is empty, cannot take any" << std::endl;
		return ss.str();
	}
	if(amount > 52 || amount < 1)
	{
		ss << "Wrong value given" << std::endl;
		return ss.str();
	}
	 
	if(amount > deck.size())
	{
		ss << "You requested to take " << amount << " cards. Only " <<  deck.size() << " are available in the deck" << std::endl;
		amount = deck.size(); 
	}
	std::vector<Card> returnedCards;
	returnedCards.insert(returnedCards.begin(), deck.end() - amount, deck.end());
	deck.erase(deck.end() - amount, deck.end());
	PushBackIntoContainer(returnedCards);
	ss << amount << " cards returned from deck to container" << std::endl;
	return ss.str();
};

std::string Deck::Reveal()
{
	std::stringstream ss;
	if(!deck.empty())
	{
		for(const auto& card : deck)
		{
			ss << card.country << card.value << std::endl;
		}
	}
	
	else
	{
		ss << "Deck is empty \n";
	}
	std::string str = ss.str();
	return ss.str();
};

std::string Deck::RevealTop()
{
	std::stringstream ss;
	if(!deck.empty())
	{
		ss << deck.back().country << deck.back().value;
	}
	else
	{
		ss << "Deck is empty";
	}
	return ss.str();
};

std::string Deck::Shuffle()
{
	if(deck.size() == 1 || deck.empty())
	{
		return "One cannot shuffle 0 or 1 card";
	}
	std::random_device rd;
	std::mt19937 g(rd());    
	std::shuffle(deck.begin(), deck.end(), g);
	return "Shuffled puffled";
}

std::pair<uint16_t, uint16_t> Deck::Size()
{
	return std::make_pair(deck.size(), cardContainer.size());
};

const void Deck::FillCardContainer(){
	for(uint16_t i = 0; i<4; i++){
		for(uint16_t v = 1; v<14; v++){
			Card temp;
			temp.country = countries[i];
			temp.value = v;
			cardContainer.emplace_back(temp);
		}
	}
};

std::vector<Card> Deck::GetFromContainer(uint16_t amount)
{
	std::vector<Card> temporaryVec;
	if(cardContainer.size() == 0)
	{
		return temporaryVec;
	}
	if(amount > cardContainer.size())
	{
		amount = cardContainer.size(); 
	}
	for(uint16_t i = 0; i < amount; i++)
	{
		srand(unsigned(time(nullptr)));
		unsigned int randomNum = rand() % cardContainer.size();
		temporaryVec.emplace_back(cardContainer.at(randomNum));
		cardContainer.erase(cardContainer.begin() + randomNum);
	}
	return temporaryVec;
};

void Deck::PushBackIntoContainer(const std::vector<Card>& returnedCards)
{
	for(auto &card : returnedCards)
	{
		cardContainer.emplace_back(card);
	}
};
