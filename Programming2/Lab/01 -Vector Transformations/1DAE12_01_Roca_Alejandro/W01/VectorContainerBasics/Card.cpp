#include "pch.h"
#include "Card.h"
#include "Texture.h"

const int Card::m_MinRank{ 1 };
const int Card::m_MaxRank{ 13 };

Card::Card(Suit suit, int rank)
	:m_Suit(suit),
	m_Rank(rank)
{

	std::string path{ GetImagePath(suit, rank) };
	
	m_pTexture = new Texture(path);

	m_Width = m_pTexture->GetWidth();
	m_Height = m_pTexture->GetHeight();
}


Card::~Card()
{
	delete m_pTexture;
	m_pTexture = nullptr;
}


std::string Card::GetImagePath(Suit suit, int rank) const
{
	int number{ (int(suit) * 100) + rank };

	return std::string{ "Resources/Cards/" + std::to_string(number) + ".png"};

}

void Card::Draw(const Rectf& destRect) const
{

	m_pTexture->Draw(destRect);

}

float Card::GetWidth() const
{
	return m_Width;
}

float Card::GetHeight() const
{
	return m_Height;
}