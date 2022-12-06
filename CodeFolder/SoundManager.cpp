#include "SoundManager.h"
#include <SFML/Audio.hpp>

using namespace sf;

SoundManager::SoundManager()
{
	// Load the sound in to the buffers
	m_Button.loadFromFile("sound/Button.wav");
	m_CookieMonster.loadFromFile("sound/GooAttack.wav");
	m_Death.loadFromFile("sound/death.wav");
	m_GooAttack.loadFromFile("sound/GooAttack.wav");
	m_SwordAttack.loadFromFile("sound/SwordAttack.wav");
	// Associate the sounds with the buffers
	m_ButtonSound.setBuffer(m_Button);
	m_CookieMonsterSound.setBuffer(m_CookieMonster);
	m_DeathSound.setBuffer(m_Death);
	m_GooAttackSound.setBuffer(m_GooAttack);
	m_SwordAttackSound.setBuffer(m_SwordAttack);

}

void SoundManager::playButton()
{
	m_ButtonSound.play();
}
void SoundManager::playDeathsound()
{
	m_DeathSound.play();
}
void SoundManager::playCookieMonsterSound()
{
	m_CookieMonsterSound.play();
}
void SoundManager::playGooAttack()
{
	m_GooAttackSound.play();
}
void SoundManager::playSwordAttack()
{
	m_SwordAttackSound.play();
}